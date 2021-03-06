#include <algorithm>
#include <string>
#include <iostream>
#include "heap.hh"
#include <iomanip> 

using std::swap;
using std::string;
using std::cout;
using std::endl;

PriorityQueue::PriorityQueue() = default;

PriorityQueue::~PriorityQueue() {
    clear();
}

void PriorityQueue::push(int value) {
    elements.push_back(value);
    shift_up(size() - 1);
}

int PriorityQueue::top() {
    if (is_empty()) {
        throw string("Queue is empty!");
    }

    return elements.front();
}

void PriorityQueue::pop() {
    if (is_empty()) {
        throw string("Queue is empty!");
    }

    elements[0] = elements.back();
    elements.pop_back();
    shift_down(0, size());
}

void PriorityQueue::clear() {
    elements.clear();
}

void PriorityQueue::print_as_array() {
    for (int el : elements) {
        cout << el << " ";
    }
    cout << endl;
}

void PriorityQueue::print_as_tree_inner(int index = 0, int level = 0) {
    
    if (index * 2 + 2 < size()) print_as_tree_inner(index * 2 + 2, level + 3);

    for (int i = 0; i < level; i++)
        std::cout << ' ';
    cout << elements[index] << '\n';

    if (index * 2 + 1 < size()) print_as_tree_inner(index * 2 + 1, level + 3);
}

void PriorityQueue::print_as_tree()
{
    print_as_tree_inner(0, 0);
}

void PriorityQueue::print_as_tree_iterative()
{
    // Количество использованных вершин
    int proceed_count = 1;
    int heap_size = size();
    for (int i = 0; i < heap_size; ++i)
    {   
        int indent = heap_size - i;

        if (i == proceed_count)
        {
            cout << '\n' << '\n';
            proceed_count = proceed_count * 2 + 1;
        }

        while (indent != 0)
        {
            std::cout << ' ' << ' ';
            --indent;
        }
       
        cout << ' ' << elements[i] << ' ';
    }
    cout << '\n';
}

int PriorityQueue::size() {
    return elements.size();
}

bool PriorityQueue::is_empty() {
    return size() == 0;
}

void PriorityQueue::shift_up(int current) {
    int parent = (current - 1) / 2;

    while (current > 0 && elements[parent] < elements[current]) {
        swap(elements[current], elements[parent]);
        current = parent;
        parent = (current - 1) / 2;
    }
}

void PriorityQueue::shift_down(int current, int n) {
    int largest = current;
    int l = 2 * current + 1;
    int r = 2 * current + 2;

    while ((l < n && elements[largest] < elements[l]) || (r < n && elements[largest] < elements[r])) {
        if (l < n && elements[l] > elements[largest])
            largest = l;

        if (r < n && elements[r] > elements[largest])
            largest = r;

        if (largest != current) {
            swap(elements[current], elements[largest]);
            current = largest;
            l = 2 * current + 1;
            r = 2 * current + 2;
        }
    }
}