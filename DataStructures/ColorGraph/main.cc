#include "graph.hh"

int main()
{
    try
    {
        Graph graph(5);

        graph.insert(0, 1);
        graph.insert(0, 3);
        graph.insert(0, 4);
        graph.insert(1, 2);
        graph.insert(3, 2);
        graph.insert(3, 4);

        // graph.insert(0, 0);

        // graph.insert(2, 2);
        // graph.insert(1, 1);


        
        std::vector<int> colors = graph.color_graph();
        for (int i = 0; i < colors.size(); ++i)
            std::cout << "Вершина " << i << " -->  Color " << colors[i] << '\n';
        std::cout << "Хроматическое число графа: " << graph.min_graph_colors() << '\n';

        // graph.color_graph_recursive();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}