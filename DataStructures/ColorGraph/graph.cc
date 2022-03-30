#include "graph.hh"

Graph::Graph(int vertex_count)
{
    // Выделяем память под массив
    m_adjacency_list.resize(vertex_count);
    m_vertex_count = vertex_count;
    m_edges_count = 0;
}

void Graph::clear()
{
    for (int i = 0; i < m_vertex_count; ++i)
        m_adjacency_list[i].clear();
    m_edges_count = 0;
}

Graph::~Graph()
{
    // Освободаем память, выделенную под списки
    clear();
    // Освобождаем память, выделенную под массив
    m_adjacency_list.clear();
    // В графе нет вершин
    m_vertex_count = 0;
}

Graph::Graph(const Graph& graph)
{
    m_vertex_count = graph.m_vertex_count;
    m_edges_count = graph.m_edges_count;

    m_adjacency_list.resize(graph.m_vertex_count);
    
    for (int i = 0; i < graph.m_vertex_count; ++i)
        std::copy(graph.m_adjacency_list[i].begin(), graph.m_adjacency_list[i].end(), std::back_inserter(m_adjacency_list[i]));
}

void Graph::insert(int v, int w)
{
    // Если данных вершин в графе нет
    if (v >= m_vertex_count || w >= m_vertex_count)
        throw std::range_error("The number of vertex is bigger than the size of adjacency list!");
        
    m_adjacency_list[v].push_back(w);
    m_adjacency_list[w].push_back(v);
    m_edges_count++;
}

void Graph::remove(int v, int w)
{
    // Если данных вершин в графе нет
    if (v >= m_vertex_count || w >= m_vertex_count)
        throw std::range_error("Removing the nonexistent edge!");

    // С помощью функции find находим итератор, который указывает на ячейку списка со значением w или v
    // С помощью функции erase удаляем данный элемент
    auto find_v = std::find(m_adjacency_list[v].cbegin(), m_adjacency_list[v].cend(), w);
    auto find_w = std::find(m_adjacency_list[w].cbegin(), m_adjacency_list[w].cend(), v);
    
    // Если мы прошли по списку, но не нашли данного ребра, то вызываем исключение
    if (find_v == m_adjacency_list[v].cend() || find_w == m_adjacency_list[w].cend())
        throw std::range_error("There isn't such edge in the graph");

    m_adjacency_list[v].erase(find_v);
    m_adjacency_list[w].erase(find_w);
    --m_edges_count;
}

int Graph::get_vertexes_number()
{
    return m_vertex_count;
}

int Graph::get_edges_number()
{
    return m_edges_count;
}

void Graph::print()
{
    for (int i = 0; i < m_vertex_count; ++i)
    {
        if (m_adjacency_list[i].empty() == false)
        {
            std::cout  << i  << " --> ";
            for (auto iter = m_adjacency_list[i].cbegin(); iter != m_adjacency_list[i].cend(); ++iter)
                std::cout << '{' << i << ", " << (*iter) << '}' << ' ';
            std::cout << '\n';
        }
    }
}

bool Graph::isEmpty()
{
    return m_vertex_count == 0;
}

int Graph::min_graph_colors()
{
    // Получаем вектор, который состоит из цветов графа
    std::vector<int> graph_colors = color_graph();
    std::set<int> set_colors;
    for (auto& elem : graph_colors)
        set_colors.insert(elem);
    return set_colors.size();
}

std::vector<int> Graph::color_graph()
{
    // Вектор, который будет хранить номера цветов
    // Если цвет не присвоен, то его номер -1 
    std::vector<int> colors(m_vertex_count, -1);

    // У вершины с номером 0 будет цвет номер 0
    colors[0] = 0;

    // Вектор, который будет хранить доступные цвета
    // Значение true будет означать, что какой-то смежной вершине вершины i присвоен цвет, иначе - цвет не присвоен 
    std::vector<bool> available_colors(m_vertex_count, false);

    // Рассматриваем оставшиеcя m_vertex_count-1 вершины 
    for (int u = 1; u < m_vertex_count; u++)
    {    
        // Обрабатываем все смежные вершины и помечаем все вершины, которых есть цвет как true
        // Если у вершины цвет true, то рассматриваем этот цвет как недоступный, иначе он доступен и им можно пометить вершину
        for (auto iter = m_adjacency_list[u].cbegin(); iter != m_adjacency_list[u].cend(); ++iter)
        {
            // Находим индекс покрашенной вершины в массиве цветов
            int colored_index = colors[(*iter)];
            if (colored_index != -1)
            {
                available_colors[colored_index] = true;
            }
                
        }

        // Потом обходя массив доступных цветов, как только встретим первый доступный цвет
        // Доступный цвет - это первый найденный false
            
        // Проходим по массиву цветов и ищем первый доступный цвет
        int cr{};
        while(available_colors[cr] != false && cr != m_vertex_count)
            ++cr; 

        // Присваиваем найденный цвет вершине
        colors[u] = cr;

        // Переназначаем все цвета как false(доступные) перед переходом на следующую вершину 
        for (int i = 0; i < m_vertex_count; ++i)
        {
            if (colors[i] != -1)
                available_colors[i] = false;
        }
    }

    return colors;
}

        