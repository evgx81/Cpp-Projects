#ifndef DISJOINT_SETS_H
#define DISJOINT_SETS_H

#include <vector>

class DisjointSets {
    std::vector<int> p;
    std::vector<int> rk;
public:
    explicit DisjointSets(int size);

    int get_root(int v);
    size_t size();
    bool merge(int a, int b);
};

#endif