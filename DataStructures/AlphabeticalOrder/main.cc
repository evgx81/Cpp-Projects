#include "trie_tree.hh"
#include <fstream>

int main()
{
    std::ifstream fin("text.txt", std::ios::in);
    if (!fin.is_open()) {
        std::cerr << "Unable to open file for reading!\n";
        return 1;
    }

    // Инициализируем trie-дерево
    TrieTree tree;
    
    // Помещаем считанный объект в trie-дерево
    std::string word;
    while(!fin.eof())
    {
        fin >> word;
        tree.insert(word);
    }

    fin.close();

    // Печатаем количество вхождения каждого слова в текст
    tree.print();
    return 0;
}
