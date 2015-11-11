#ifndef KGraph_h
#define KGraph_h

class KGraph
{
    private:
        struct KrVals{
            bool adjacent;
            int cyclePosRow;
            int cyclePosCol;
        };
        KrVals* Kr;

    public:
        KGraph(){}

        void setKr(int r, int n)
        {
            Kr = new KrVals[n*r];
        }
        void setR(int edge)
        {
            Kr[edge].adjacent = true;
        }

        void setCyclePosRow(int edge, int pos)
        {
            Kr[edge].cyclePosRow = pos;
        }

        void setCyclePosCol(int edge, int pos)
        {
            Kr[edge].cyclePosCol = pos;
        }

        bool getEdge(int pos)
        {
            return Kr[pos].adjacent;
        }

        int getCyclePosRow(int pos)
        {
            return Kr[pos].cyclePosRow;
        }

        int getCyclePosCol(int pos)
        {
            return Kr[pos].cyclePosCol;
        }

    ~KGraph(){}
};

#endif //KGRAPH_H
