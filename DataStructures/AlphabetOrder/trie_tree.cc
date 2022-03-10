#include "trie_tree.hh"
#include <queue>

void TrieTree::insert(std::string word)
{
    // Начиная с корня, будем искать место для вставки
    TreeNode* current = m_root;
    for (int i = 0; i < word.size(); ++i)
    {
        // Получаем соответсвующую позицию слова в алфавите
        int index = word[i] - 'a';
        // Если это место в дереве пусто, то создаем новый узел дерева и инициализируем нвой переменной
        if (current->m_symbols[index] == nullptr)
        {
            current->m_symbols[index] = new TreeNode;
            current->m_symbols[index]->m_symb = word[i];
        }

        // Если это место уже занято, то спускаемя вниз по дереву
        current = current->m_symbols[index]; 
    }
    // Обозначаем последний символ как конец слова
    current->m_eow = true; 
    current->m_count++;
}

bool TrieTree::find(std::string word)
{
    TreeNode* current = m_root;
    for (int i = 0; i < word.size(); i++)
    {
        int index = word[i] - 'a';
        if (current->m_symbols[index] == nullptr)
            return false;
        current = current->m_symbols[index]; 
    }
    // Дойдя до конца слова, все предшествующие буквы есть в слове
    // Проверяем последний символ слова, если он есть в дереве, то и само слово есть, иначе слова нет
    return (current != nullptr && current->m_eow);
}

bool TrieTree::isEmpty(TreeNode*& node)
{
    for (int i = 0; i < ALPHABET_SIZE; ++i)
        if (node->m_symbols[i])
            return false; // У дерева есть потомок
    return true;
}


bool TrieTree::removeWord(TreeNode*& root, std::string key, int depth = 0)
{
    // Если дерево пусто или переданное слово пусто, то удалить слово нельзя 
    if (root == nullptr || key.empty() == true)
        return false;
 
    // Если глубина погружения равна длине слова (достигли последнего символа)
    if (depth == key.length()) {
 
        // Данная вершина больше не является концом слова
        if (root->m_eow == true)
            root->m_eow = false;
            
        // Если вершина не является префиксом какого-либо слова, то удаляем эту вершину
        if (isEmpty(root)) {
            delete root;
            root = nullptr;
        }

        return true;
    }
    else
    {
        // Если не достигли конца слова, находим индекс элемента в таблице ACSII
        int index = key[depth] - 'a';
        // Спускаемся вниз к этой вершине
        return removeWord(root->m_symbols[index], key, depth + 1);
    }
}


bool TrieTree::remove(std::string word)
{
    return removeWord(m_root, word);
}


void TrieTree::printTree(TreeNode* root, std::string str = "")
{
    if (root->m_eow == true)
    {
        std::cout << str << ' ';
        std::cout << root->m_count << '\n';
    }
    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        TreeNode* current = root->m_symbols[i];
        if (current != nullptr)
        {
            str.push_back(current->m_symb);
            printTree(current, str);
            str.pop_back();
        }
    }

}

void TrieTree::print()
{
    printTree(m_root);
}

void TrieTree::clearNodes(TreeNode*& root)
{
    if(root == nullptr)
        return;

    std::queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty())
    {
        for (int i = 0; i < ALPHABET_SIZE; ++i)
        {
            if (queue.front()->m_symbols[i] != nullptr)
                queue.push(queue.front()->m_symbols[i]);
        }
        delete queue.front();
        queue.pop();
    }
}

void TrieTree::clear()
{
    clearNodes(m_root);
}
    
