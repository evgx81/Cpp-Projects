#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "adjacent_matrix_graph.hh"
#include "adjacent_list_graph.hh"

// Recursive implementation of DFS for graph.
void dfs_recursive(int cur_vertex, std::vector<bool>& visited, Graph* g) {
    visited[cur_vertex] = true;
    std::cout << cur_vertex << " ";

    std::vector<int> adj = g->adjacent_vertex(cur_vertex);
    for (auto i : adj) {
        if (!visited[i]) {
            dfs_recursive(i, visited, g);
        }
    }
}

// Entry point of recursive implementation of DFS.
void dfs_recursive_init(Graph* g) {
    int cur_vertex = 0;

    int size = g->vertex_count();
    std::vector<bool> visited(size, false);

    dfs_recursive(cur_vertex, visited, g);
}

// Depth-First Search
void dfs(Graph* g) {
    int cur_vertex = 0;
    int size = g->vertex_count();
    std::vector<bool> visited(size, false);

    std::stack<int> s;
    s.push(cur_vertex);
    visited[cur_vertex] = true;

    while (!s.empty()) {
        cur_vertex = s.top();
        s.pop();

        std::cout << cur_vertex << " ";

        std::vector<int> adj = g->adjacent_vertex(cur_vertex);
        for (auto i : adj) {
            if (!visited[i]) {
                s.push(i);
                visited[i] = true;
            }
        }
    }
}

// Breadth-First Search
void bfs(Graph* g) {
    int cur_vertex = 0;

    int size = g->vertex_count();
    std::vector<bool> visited(size, false);

    std::queue<int> q;
    q.push(cur_vertex);
    visited[cur_vertex] = true;

    while (!q.empty()) {
        cur_vertex = q.front();
        q.pop();

        std::cout << cur_vertex << " ";

        std::vector<int> adj = g->adjacent_vertex(cur_vertex);
        for (auto i : adj) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

// Example of DFS and BFS algorithms for graph.
int main() {
    //Graph* g = new AdjacentMatrixGraph(8);
    Graph* g = new AdjacentListGraph(8);
    g->insert(0, 1);
    g->insert(0, 7);
    g->insert(0, 2);

    g->insert(1, 7);
    g->insert(7, 2);

    g->insert(7, 4);

    g->insert(5, 3);
    g->insert(4, 3);
    g->insert(4, 5);

    g->insert(0, 5);
    g->insert(6, 4);
    g->insert(0, 6);

    std::cout << "Обход в глубину: ";
    dfs(g);
    std::cout << '\n';

    std::cout << "Обход в ширину: ";
    bfs(g);
    std::cout << '\n';

    std::cout << "Обход в ширину (рекурсивный): ";
    dfs_recursive_init(g);
    std::cout << '\n';
}