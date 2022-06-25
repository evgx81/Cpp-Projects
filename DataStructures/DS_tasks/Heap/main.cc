#include "heap.hh"

int main()
{
    PriorityQueue queue;
    queue.push(3);
    queue.push(9);
    queue.push(2);
    queue.push(1);
    queue.push(4);
    queue.push(5);
    queue.push(0);
    queue.print_as_array();
    queue.print_as_tree();
    queue.print_as_tree_iterative();
    return 0;
}