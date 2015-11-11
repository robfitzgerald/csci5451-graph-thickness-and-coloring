#ifndef AdjMatrix_h
#define AdjMatrix_h
#include "KGraph.h"

class AdjMatrix
{
    private:
        int n;
        int r;
        int nr;

        KGraph* cycleN;

    public:
        AdjMatrix(int nIn, int rIn);

        // Setters
        void loadMatrix();
        void outputMatrix();

        // Getters


        // Destructor
        ~AdjMatrix();
};

#endif