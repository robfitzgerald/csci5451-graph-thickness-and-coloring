#include <iostream>
#include <iomanip>
#include <limits>
#include <math.h>
#include "AdjMatrix.h"

// Constructors
AdjMatrix::AdjMatrix(int nIn, int rIn)
{
    n = nIn;
    r = rIn;
    nr = n*r;
    vertex = 1;
    numOfEdges = 0;

    cycleN = new KGraph[nr];

    for(int i = 0; i < nr; i++)
    {
        cycleN[i].setKr(r,n);
    }
}

// Destructor
AdjMatrix::~AdjMatrix(){}

void AdjMatrix::loadMatrix()
{
    int color = 1;

    for(int i = 0, posRow = 0; i < nr; i++)
    {
        for(int j = 0, posCol = 0; j < nr; j++)
        {
            if(i%r == 0 && j == 0)
            {
                cycleN[i].setCyclePosRow(j,++posRow);
            }
            else
            {
                cycleN[i].setCyclePosRow(j,posRow);
            }

            if(j%r == 0)
            {
                cycleN[i].setCyclePosCol(j,++posCol);
            }
            else
            {
                cycleN[i].setCyclePosCol(j,posCol);
            }

            if(j < i && cycleN[i].getCyclePosRow(j)-cycleN[i].getCyclePosCol(j) == 0)
            {
                cycleN[i].setR(j);
                numOfEdges++;
            }
            else if(j == i)
            {
                if(color > 2*r)
                    color = 1;
                cycleN[i].setColor(j,color++);
                cycleN[i].setVertexNum(j,vertex++);
            }
            else if(cycleN[i].getCyclePosRow(j)-cycleN[i].getCyclePosCol(j) == 1 ||
                    n-cycleN[i].getCyclePosRow(j) == 0 && n-cycleN[i].getCyclePosCol(j) == 4)
            {
                cycleN[i].setR(j);
            }
        }
    }
    if(n%2)
    {
        fixColors();
    }

    makePlanes();
}

void AdjMatrix::fixColors()
{
    int mxSize = nr-1,
        removed = 2*ceil(r/2),
        colorsCurrent = 2*r,
        colorsNeeded = (3*r - floor(r/2));
    int temp[removed];

    for(int i = 1, j = 0; i <= floor(r/2); i++, j+=2)
    {
        temp[j] = cycleN[nr-r-i].getColor(nr-r-i);
        temp[j+1] = cycleN[r-i].getColor(r-i);
        cycleN[r-i].setColor(r-i,colorsCurrent+i);
        cycleN[nr-r-i].setColor(nr-r-i, colorsCurrent+i);
    }

    for(int j = 0; j < r; j++)
    {
        if(r%2 && j+1 == r)
            cycleN[mxSize-j].setColor(mxSize-j,colorsNeeded);
        else
            cycleN[mxSize-j].setColor(mxSize-j,temp[j]);
    }
}

void AdjMatrix::makePlanes()
{
    for(int i = 1; i <= r; i++) // planes
    {
        int tempPlane = i;
        int start = i;
        int beg = r+1, end = 2*r;

        while(start <= nr)           // connections
        {
            addEdges(tempPlane, start, beg, end);
            start += 2*r;
            /*if(n%2 == 0 && start > nr)
            {
                start -= 1;
                beg -= 1;
                end -= 1;
            }*/

            if(start <= nr || n%2 == 0)
                addEdges(tempPlane, start, beg, end);
            beg += 2*r;
            end += 2*r;
        }
    }
}

void AdjMatrix::addEdges(int tempPlane, int start, int beg, int end)
{
    if(beg-nr > 0)
    {
        start = tempPlane;
        beg -= r;
        end -= r;
    }

    if(n%2 == 0 && start > nr)
    {
        start = tempPlane;
        //beg -= r;
        //end -= r;
    }

    for(int i = beg; i <= end; i++)
    {
        Edges temp;
        temp.plane = tempPlane;
        temp.vert1 = start;
        temp.vert2 = i;

        planeList.push_back(temp);
    }
}

void AdjMatrix::addNKr()
{

}

void AdjMatrix::outputMatrix()
{
    /*std::cout << "\nC" << n << 'K' << r << " Matrix:\n";
    for(int i = 0; i < nr; i++)
    {

        for(int j = 0; j < nr; j++)
        {
            std::cout << '(' << cycleN[i].getEdge(j) << ')';
        }
        std::cout << std::endl;
    }*/

    std::cout << "\nC" << n << 'K' << r << "\nColors Required: "
              << 3*r - floor(r/2) << "\n";
    for(int i = 0; i < nr; i++)
    {
        for(int j = 0; j < nr; j++)
        {
            if(cycleN[i].getColor(j))
                std::cout << '(' << std::setw(2) << cycleN[i].getColor(j) << ')';
        }
        if((i+1)%r == 0)
            std::cout << std::endl;
    }

    /*std::cout << "\nVertices:" << std::endl;

    for(int i = 0; i < nr; i++)
    {
        for(int j = 0; j < nr; j++)
        {
            if(cycleN[i].getVertexNum(j))
                std::cout << '(' << std::setw(2) << cycleN[i].getVertexNum(j) << ')';
        }
        if((i+1)%r == 0)
            std::cout << std::endl;
    }*/

    std::cout << "\nPlanes:" << std::endl;
    for(int i = 0; i < planeList.size(); i++)
    {
        if((i)%r == 0)
            std::cout << planeList[i].plane;

        std::cout << " (" << planeList[i].vert1
                  << ',' << planeList[i].vert2 << ") ";
        if((i+1)%r == 0)
            std::cout << std::endl;
        if( (i+1)%nr == 0)
            std::cout << std::endl;
    }
}
