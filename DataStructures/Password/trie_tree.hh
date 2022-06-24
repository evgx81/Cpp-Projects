#ifndef TRIE_TREE_H
#define TRIE_TREE_H

#include <iostream>
#include <vector>

const int ALPHABET_SIZE = 3;
struct TreeNode
{
    char m_symb; // Храним в каждом узле только для вывода значения
    TreeNode* m_symbols[ALPHABET_SIZE];
    bool m_eow; // Является ли концом слова
    int m_count; // Определяет количество вхождений подстроки
public:
    TreeNode() : m_symb{}, m_eow{}
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
private:
    // Функция, которая создает вектор пар <"подстрока", "количество вхождений подстроки"> 
    void make_vector_word_pairs(TreeNode*, std::string, std::vector<std::pair<std::string, int>>&);
public:
    // Функция печати найденного пароля 
    void print_password();
};


#endif