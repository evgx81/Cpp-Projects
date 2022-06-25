#ifndef HEAP_H
#define HEAP_H

#include <vector>

using std::vector;

class PriorityQueue {
private:
    vector<int> elements;
private:
    void shift_up(int);
    void shift_down(int, int);
private:
    void print_as_tree_inner(int, int);
public:
    PriorityQueue();
    ~PriorityQueue();
public:
    // container modifiers
    void push(int);
    void pop();
    int top();
    void clear();
    void print_as_array();
    void print_as_tree();
    void print_as_tree_iterative();
    // getters
    bool is_empty();
    int size();
};

#endif