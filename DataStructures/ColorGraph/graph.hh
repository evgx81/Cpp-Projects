#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <list>
#include <algorithm>
#include <iterator>
#include <set>

class Graph
{
    // Количество вершин в графе
    int m_vertex_count;
    // Количество ребер в графе
    int m_edges_count;
    // Лист смежности графа
    std::vector<std::list<int>> m_adjacency_list;
public:
    Graph(int);
    ~Graph();
    Graph(const Graph&);
public:
    // Добавление ребра в граф
    void insert(int, int);
    // Удаление ребра
    void remove(int, int);
    // Количество вершин в графе
    int get_vertexes_number();
    // Количество связей в графе
    int get_edges_number();
    // Функция очистки графа
    void clear();
    // Функция печати графа
    void print();
    // Проверка графа на пустоту
    bool isEmpty();
public:
    // Функция возвращает вектор, которые сожержит цвет каждой вершины графа - без рекурсии
    std::vector<int> color_graph();
    // Функция для поиска минимального числа красок для раскраски графа() 
    int min_graph_colors();
};

        
#endif