#include "trie_tree.hh"
#include <queue>
#include <algorithm>

void TrieTree::insert(std::string word)
{
    TreeNode* current = m_root;
    for (int i = 0; i < word.size(); ++i)
    {
        int index = word[i] - 'a';
        if (current->m_symbols[index] == nullptr)
        {
            current->m_symbols[index] = new TreeNode;
            current->m_symbols[index]->m_symb = word[i];
        }
        current = current->m_symbols[index]; 
    }

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

    return (current != nullptr && current->m_eow);
}

bool TrieTree::isEmpty(TreeNode*& node)
{
    for (int i = 0; i < ALPHABET_SIZE; ++i)
        if (node->m_symbols[i])
            return false;
    return true;
}


bool TrieTree::removeWord(TreeNode*& root, std::string key, int depth = 0)
{
    if (root == nullptr || key.empty() == true)
        return false;
 
    if (depth == key.length()) 
    {
        root->m_eow = false;
            
        if (isEmpty(root)) 
        {
            delete root;
            root = nullptr;
        }

        return true;
    }
    else
    {
        int index = key[depth] - 'a';
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
        std::cout << "Количество вхождения слова " << str << " - " << root->m_count << '\n';
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

bool compare_pairs(std::pair<std::string, int> const &p1, std::pair<std::string, int> const &p2) {
    return p1.second < p2.second;
}

void TrieTree::print_password()
{
    std::vector<std::pair<std::string, int>> word_array;
    make_vector_word_pairs(m_root, "", word_array);

    // Поиск подстроки, которая встречается чаще всего
    auto max_substr = std::max_element(word_array.cbegin(), word_array.cend(), compare_pairs); 

    // Поиск первой строки с наибольшим количеством вхождений
    int i{};
    while (i != word_array.size() && word_array[i].second != max_substr->second)
        ++i;
    
    // Вывод пароля
    std::cout << "Пароль: " << word_array[i].first << '\n';
}
    
void TrieTree::make_vector_word_pairs(TreeNode* root, std::string str, std::vector<std::pair<std::string, int>>& arr)
{
    if (root->m_eow == true)
    {
        arr.push_back({str, root->m_count});
    }
    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        TreeNode* current = root->m_symbols[i];
        if (current != nullptr)
        {
            str.push_back(current->m_symb);
            make_vector_word_pairs(current, str, arr);
            str.pop_back();
        }
    }
}