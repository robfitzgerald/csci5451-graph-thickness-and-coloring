//
//  numberOfPlanes.cpp
//  
//
//  Created by Matthew Kalan on 11/11/15.
//
//

#include "numberOfPlanes.hpp"
#include "rjf_graphMatrix.h"

void numberOfPlanes(int size, graphMatrix matrix){
    int max = size/2;
    int [][]planes = new int[max][max];
    int color;
    for(int i=0;i < max; ++i){ //Step through each vertex picking it's color
        color = matrix.get(i,i);
        for(int j = 0;j<max;++j){ //Step through through vertices
            if(matrix.get(j,j)== color){    //if the vertice is the current color add it to the
                                                        //kemp chain
                for(int k = 0; k<max; ++k){ //find all kemp chains including that color
                    if(planes[j][k] == 0 && matrix.get(j,k) !=0){ //If that edge is unplaned
                        planes[j][k] = i+1; //Assign it a plane
                    }
                }
            }
        }
    }
    //this is just a safety check to make sure all edges are being given an plane.
    for(int i=0;i < max; ++i){
        for(int j = 0;j<max;++j){
            if(matrix.get(j,k) !=0 && planes[i][j] == 0){
                planes[i][j] = -1;
            }
        }
    }
    //Print Out Plane Matrix
    std::cout<<"Plane Assignments:\n";
    for(int i = 0; i < max; ++i){
        for(int j=0; j< max;++j){
            std::cout << planes[i][j] << " ";
        }
        std::cout <<"\n";
    }
    delete [] planes;
}
