#include "graph.hh"
#include "disjoint_sets.hh"
#include <queue>

typedef std::pair<int, int> iPair;

struct ComparePairs {
    bool operator()(iPair const& p1, iPair const& p2) {
        // Сравниваем пары по весу
        return p1.second > p2.second;
    }
};


void primMST(AdjacentListGraph graph) {

    std::vector<bool> used(graph.vertex_count(), false);

    // Вес минимального остовного дерева
    int mst_weight = 0;

    std::priority_queue<iPair, std::vector<iPair>, ComparePairs> q;

    q.push({0, 0});

    while (!q.empty()) 
    {
        // Извлекаем пару из очереди
        std::pair<int, int> c = q.top();
        q.pop();

        int curr_vertex = c.first;
        int curr_weight = c.second;

        // Если данная вершина еще не использована, то помечаем ее как использованную и рассматриваем смежные вершины
        if (used[curr_vertex] == false) {
            used[curr_vertex] = true;
            mst_weight += curr_weight;

            std::vector<std::pair<int,int>> adjacent_vertexes = graph.adjacent_vertex(curr_vertex);

            
            for (std::pair<int, int> e : adjacent_vertexes)
            {
                int u = e.first;
                int len_vu = e.second;

                if (used[u] == false) {
                    q.push({u, len_vu});
                }
            }
        }
    }

    std::cout << "Minimum weight: " << mst_weight << '\n';
}

bool compareEdges(Edge& e1, Edge& e2){
    return e1.wt < e2.wt;
}

void kruskalMST(AdjacentListGraph g) {
    // Вес минимального остовного дерева
    int mst_weight = 0;

    // Инициализируем структуру непересекающихся множеств
    DisjointSets comp(g.vertex_count());

    std::vector<Edge> edges = g.get_edges();

    // Сортируем ребра в порядке возрастания их весов
    std::sort(edges.begin(), edges.end(), compareEdges);

    // Проходим по всем отсортированным ребрам
    for (auto edge: edges) {
        // Проверяем образует ли ребро цикл (Цикл образуется, если вершины v1 и v2 принадлежат одному множеству)
        if (comp.merge(edge.v1, edge.v2)) {
            // Добавляем вес этого ребра к весу минимального остовного дерева
            mst_weight += edge.wt;
        }
    }
    std::cout << "Minimum spanning tree weight: " << mst_weight << '\n';
}


int main() 
{

    AdjacentListGraph graph(6);
    graph.insert(0, 1, 6);
    graph.insert(0, 2, 3);
    graph.insert(0, 3, 5);
    graph.insert(1, 2, 5);
    graph.insert(1, 4, 3);
    graph.insert(2, 3, 5);
    graph.insert(2, 4, 6);
    graph.insert(2, 5, 4);
    graph.insert(3, 5, 2);
    graph.insert(4, 5, 6);


    // graph.insert(0, 1, 3);
    // graph.insert(0, 2, 4);
    // graph.insert(0, 4, 1);
    // graph.insert(1, 2, 5);
    // graph.insert(2, 4, 6);
    // graph.insert(2, 3, 2);
    // graph.insert(3, 4, 7);

    // graph.insert(0, 1, 4);
    // graph.insert(0, 7, 8);
    // graph.insert(1, 2, 8);
    // graph.insert(1, 7, 11);
    // graph.insert(2, 3, 7);
    // graph.insert(2, 8, 2);
    // graph.insert(2, 5, 4);
    // graph.insert(3, 4, 9);
    // graph.insert(3, 5, 14);
    // graph.insert(4, 5, 10);
    // graph.insert(5, 6, 2);
    // graph.insert(6, 7, 1);
    // graph.insert(6, 8, 6);
    // graph.insert(7, 8, 7);

    // Минимальное остовное дерево по алгоритму Прима
    primMST(graph);
    // Минимальное остовное дерево по алгоритму Краскала
    kruskalMST(graph);
    return 0;
}