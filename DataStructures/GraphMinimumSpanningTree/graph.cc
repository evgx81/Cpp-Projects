#include <string>
#include "graph.hh"

AdjacentListGraph::AdjacentListGraph(int v_count)
{
    g.resize(v_count);
    this->v_count = v_count;
    this->e_count = 0;
}

AdjacentListGraph::~AdjacentListGraph()
{
    clear();
}

void AdjacentListGraph::insert(int v, int w, int weight)
{
    if (v > v_count || w > v_count) {
        v_count = v > w ? v : w;
        g.resize(v_count);
    }

    g[v].insert(std::make_pair(w, weight));
    g[w].insert(std::make_pair(v, weight));
    e_count++;
}

void AdjacentListGraph::remove(int v, int w)
{
    if (v > v_count || w > v_count) {
        return;
    }

    auto find_v = std::find_if(g[v].cbegin(), g[v].cend(), [&w](const std::pair<int, int>& m_pair) {return m_pair.first == w;});
    auto find_w = std::find_if(g[w].cbegin(), g[w].cend(), [&v](const std::pair<int, int>& m_pair) {return m_pair.first == v;});

    if (find_v != g[v].cend() || find_w != g[w].cend()) {
        g[v].erase(find_v);
        g[w].erase(find_w);
        e_count--;
    }
}

void AdjacentListGraph::clear()
{
    for (int i = 0; i < v_count; i++) {
        g[i].clear();
    }
    g.clear();
    this->e_count = 0;
}

int AdjacentListGraph::vertex_count()
{
    return v_count;
}

int AdjacentListGraph::edges_count()
{
    return e_count;
}

std::vector<std::pair<int, int>> AdjacentListGraph::adjacent_vertex(int v)
{
    if (v > v_count) {
        throw std::string("vertex not found");
    }

    std::vector<std::pair<int, int>> adjacent_vertexes_vector;
    std::copy(g[v].begin(), g[v].end(), std::back_inserter(adjacent_vertexes_vector));

    return adjacent_vertexes_vector;
}

void AdjacentListGraph::print()
{
    for (int i = 0; i < g.size(); ++i)
    {
        for (auto iter = g[i].begin(); iter != g[i].end(); ++iter)
        {
            std::pair<int, int> curr = *iter;
            std::cout << i << ": " << "{" << curr.first << ", " << curr.second << "}\t";
        }
        std::cout << '\n';
    }
}

std::vector<Edge> AdjacentListGraph::get_edges() {
    std::vector<Edge> res;
    size_t n = g.size();
    for (int i = 0; i < n; i++) {
        std::set<std::pair<int,int>> adj_list = g[i];
        for (auto curr: adj_list) {
            int curr_w = curr.first; 
            int curr_weig = curr.second;

            Edge ed(i, curr_w, curr_weig);

            auto ed_it = std::find_if(
                    res.begin(),
                    res.end(),
                    [&ed](const Edge& h) { return (ed.v1 == h.v1 && ed.v2 == h.v2 || ed.v2 == h.v1 && ed.v1 == h.v2) && ed.wt == h.wt; }
                    );

            if (ed_it == res.end()) {
                res.push_back(ed);
            }
        }
    }
    return res;
}