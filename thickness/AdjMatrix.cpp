#include <iostream>
#include <iomanip>
#include <limits>
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

            if(j != i && cycleN[i].getCyclePosRow(j)-cycleN[i].getCyclePosCol(j) == 0)
            {
                cycleN[i].setR(j);
            }
            else if(cycleN[i].getCyclePosRow(j)-cycleN[i].getCyclePosCol(j) == 1 ||
                    n-cycleN[i].getCyclePosRow(j) == 0 && n-cycleN[i].getCyclePosCol(j) == 4)
            {
                cycleN[i].setR(j);
            }
        }
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
                      /*<< ':'
                      << cycleN[i].getCyclePosRow(j)
                      << ',' << cycleN[i].getCyclePosCol(j)<< ") ";*/
        }
        std::cout << std::endl;
    }
}
