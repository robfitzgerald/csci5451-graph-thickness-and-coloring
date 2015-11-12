#ifndef AdjMatrix_h
#define AdjMatrix_h
#include <vector>
#include "KGraph.h"

class AdjMatrix
{
    private:
        int n;
        int r;
        int nr;
        int vertex;
        int numOfEdges;

        struct Edges{
            int plane = 0;
            int vert1 = 0;
            int vert2 = 1;
        };

        KGraph* cycleN;
        std::vector<Edges> planeList;

    public:
        AdjMatrix(int nIn, int rIn);

        // Setters
        void loadMatrix();
        void outputMatrix();
        void fixColors();
        void makePlanes();
        void addEdges(int plane, int start, int beg, int end);
        void addNKr();

        // Getters
        int get(int i, int j)
        {
            cycleN[i].getColor(j);
        }


        // Destructor
        ~AdjMatrix();
};

#endif