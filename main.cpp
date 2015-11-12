/******************************************************************************
* DESCRIPTION
* 
* Name:       Matt Scheidler
* Class:      3543-001
* Assignment: Lab 03
* Due Date:   12/02/15
* File Name:  main.cpp
* 
******************************************************************************/

#include <iostream>
#include <iomanip>
#include <limits>
#include <stdlib.h> // used for EXIT_SUCCESS and EXIT_FAILURE
#include "AdjMatrix.h"
//#include "numberOfPlanes.hpp"
#include "numberOfPlanes.hpp"

int main( )
{
    int n = 0, r = 0;

    std::cout << "Enter a value for n: ";
    std::cin >> n;
    std::cout << "Enter a value for r: ";
    std::cin >> r;

    AdjMatrix test000(n,r);
    test000.loadMatrix();
    test000.outputMatrix();

    //numberOfPlanes(0,test000);
    //test000.makePlanes();

    return EXIT_SUCCESS;
}

