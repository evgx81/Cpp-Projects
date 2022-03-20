#ifndef TRIE_TREE_H
#define TRIE_TREE_H

#include <iostream>

const int ALPHABET_SIZE = 2;

struct TreeNode
{
    char m_symb; // Храним в каждом узле только для вывода значения
    TreeNode* m_symbols[ALPHABET_SIZE];
    bool m_eow; // Является ли концом слова
    int m_count; // Считает количество слов дереве
public:
    TreeNode() : m_symb{}, m_eow{}, m_count{}
    {
        for (int i = 0; i < ALPHABET_SIZE; ++i)
            m_symbols[i] = nullptr;
    }

    TreeNode(const TreeNode& node) 
    {
        m_symb = node.m_symb;
        m_eow = node.m_eow;
        for (int i = 0; i < ALPHABET_SIZE; ++i)
            m_symbols[i] = node.m_symbols[i];
    }
};

class TrieTree
{
    TreeNode* m_root;
private:
    // Проверка имеет ли вершина потомков
    bool isEmpty(TreeNode*&);
    // Рекурсивная функция, которая удаляет дерево из слова и возвращает изменное дерево
    bool removeWord(TreeNode*&, std::string, int depth);
    // Рекурсивная функция печати дерева
    void printTree(TreeNode*, std::string);
private:
    bool isLeaf(TreeNode*&);
    void deleteTreeNode();
    void printTrieTree(int);
private:
    void clearNodes(TreeNode*&);
public:
    TrieTree() : m_root{new TreeNode} {}
    ~TrieTree() 
    {
        // Очищаем все поддеревья и удаляем корень
        clear(); 
    }
public:
    // Вставка слова в дерево
    void insert(std::string);
    // Проверка находится ли слово в дереве
    bool find(std::string);
    // Удаление слова из дерева
    bool remove(std::string);
    // Очистка дерева
    void clear();
    // Печать дерева
    void print();
};

#endif
    
