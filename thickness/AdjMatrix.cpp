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
            }
            else if(j == i)
            {
                if(color > 2*r)
                    color = 1;
                cycleN[i].setColor(j,color++);
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
        std::cout << "go1";
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

void AdjMatrix::outputMatrix()
{
    std::cout << "\nC" << n << 'K' << r << " Matrix:\n";
    for(int i = 0; i < nr; i++)
    {

        for(int j = 0; j < nr; j++)
        {
            std::cout << '(' << cycleN[i].getEdge(j) << ')';
        }
        std::cout << std::endl;
    }

    std::cout << "\nC" << n << 'K' << r << " Colors:\n";
    for(int i = 0; i < nr; i++)
    {

        for(int j = 0; j < nr; j++)
        {
            std::cout << '(' << std::setw(2) << cycleN[i].getColor(j) << ')';
        }
        std::cout << std::endl;
    }
}
