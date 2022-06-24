#include "disjoint_sets.hh"

DisjointSets::DisjointSets(int size) {
    p.resize(size);
    rk.resize(size);
    for (int i = 0; i < size; i++) {
        p[i] = i;
        rk[i] = 1;
    }
}

int DisjointSets::get_root(int v) {
    if (p[v] == v) {
        return v;
    } else {
        return p[v] = get_root(p[v]);
    }
}

bool DisjointSets::merge(int a, int b) {
    int ra = get_root(a), rb = get_root(b);

    if (ra == rb) {
        return false;
    } else {
        if (rk[ra] < rk[rb]) {
            p[ra] = rb;
        } else if (rk[ra] > rk[rb]) {
            p[rb] = ra;
        } else {
            p[rb] = ra;
            rk[ra]++;
        }
        return true;
    }
}

size_t DisjointSets::size() {
    return p.size();
}
