#ifndef KGraph_h
#define KGraph_h

class KGraph
{
    private:
        struct KrVals{
            bool adjacent;
            bool cEven = 0;
            int cyclePosRow;
            int cyclePosCol;
            int color;
        };
        KrVals* Kr;

    public:
        KGraph(){}

        // Setters
        void setKr(int r, int n){Kr = new KrVals[n*r];}
        void setR(int edge){Kr[edge].adjacent = true;}
        void setColor(int edge, int colorIn){Kr[edge].color = colorIn;}
        void setCEven(int edge, bool flip){Kr[edge].cEven = flip;}
        void setCyclePosRow(int edge, int pos){Kr[edge].cyclePosRow = pos;}
        void setCyclePosCol(int edge, int pos){Kr[edge].cyclePosCol = pos;}

        // Getters
        bool getEdge(int pos){return Kr[pos].adjacent;}
        int getColor(int pos){return Kr[pos].color;}
        int getCyclePosRow(int pos){ return Kr[pos].cyclePosRow;}
        int getCyclePosCol(int pos){return Kr[pos].cyclePosCol;}

    ~KGraph(){}
};

#endif //KGRAPH_H
