#ifndef ADJACENT_LIST_GRAPH_H
#define ADJACENT_LIST_GRAPH_H

#include <vector>
#include <set>

#include "graph.hh"

#pragma once

using std::vector;
using std::set;

class AdjacentListGraph : public Graph {
    int v_count;
    int e_count;
    vector<set<int>> g;
public:
    AdjacentListGraph(int v_count);
    ~AdjacentListGraph();

    void insert(int v, int w);
    void remove(int v, int w);
    void clear();
    int vertex_count();
    int edges_count();
    vector<int> adjacent_vertex(int v);
};

#endif