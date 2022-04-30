#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <set>
#include <vector>
#include <iterator>

struct Edge {
    int v1;
    int v2;
    int wt;

    Edge(int _v1, int _v2, int _wt) : v1(_v1), v2(_v2), wt(_wt) {};
    Edge(const Edge& edge)
    {
        v1 = edge.v1;
        v2 = edge.v2;
        wt = edge.wt;
    }
};

class AdjacentListGraph
{
    int v_count;
    int e_count;
    std::vector<std::set<std::pair<int, int>>> g;
public:
    AdjacentListGraph(int v_count);
    ~AdjacentListGraph();
public:
    void insert(int, int, int);
    void remove(int, int);
    void clear();
    int vertex_count();
    int edges_count();
    std::vector<std::pair<int,int>> adjacent_vertex(int);
    void print();
    std::vector<Edge> get_edges();
};

#endif