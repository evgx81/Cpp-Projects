#ifndef TREE_H
#define TREE_H

#include <iostream>

struct TreeNode
{
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : left{nullptr}, right{nullptr} {};
};

typedef TreeNode* TTree;

// Создание пустого дерева
void init(TTree&);

// Создание бинарного дерева, содержащего 1 узел
void init(TTree&, char);

// Создание бинарного дерева по корню и 2-м бинарным поддеревьям
void init(TTree&, char, TTree, TTree);

// Присоединение левого поддерева
void attachLeftSubtree(TTree, TTree);

// Присоединение правого поддерева
void attachRightSubtree(TTree, TTree);

// Проверка на пустоту
bool isEmpty(TTree);

// Присоединение левого дочернего узла
void attachLeftSon(TTree, char);

// Присоединение правого дочернего узла
void attachRightSon(TTree, char);

// Получение значения корня
char getRootData(TTree);

// Удаление дерева
void destroy(TTree&);

// Присваивание значения корню
void setRootData(TTree&, char);

// Отсоединение левого поддерева
void detachLeftTree(TTree, TTree&);

// Отсоединение правого поддерева
void detachRightTree(TTree, TTree&);

// Получение копии левого поддерева
TTree getLeftSubtree(TTree);

// Получение копии правого поддерва
TTree getRightSubtree(TTree);

// Копирование дерева
void copyTree(TTree, TTree&);

#endif