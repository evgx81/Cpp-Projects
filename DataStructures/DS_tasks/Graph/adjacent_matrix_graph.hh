#ifndef ADJACENT_MATRIX_GRAPH_H
#define ADJACENT_MATRIX_GRAPH_H

#include "graph.hh"

class AdjacentMatrixGraph : public Graph 
{
    int v_count;
    int e_count;
    std::vector<std::vector<bool>> g;

public:
    AdjacentMatrixGraph(int v_count);
    ~AdjacentMatrixGraph();

    void insert(int v, int w);
    void remove(int v, int w);
    void clear();
    int vertex_count();
    int edges_count();
    std::vector<int> adjacent_vertex(int v);
};

#endif