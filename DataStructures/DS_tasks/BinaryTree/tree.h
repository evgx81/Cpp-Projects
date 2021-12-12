#ifndef TREE_H
#define TREE_H

#include <iostream>

struct TreeNode
{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
};

typedef TreeNode* TTree;

typedef void(*FunctionType) (int& TreeNode);

// Создание пустого дерева
void init(TTree&);

// Создание бинарного дерева, содержащего 1 узел
void init(TTree&, int);

// Создание бинарного дерева по корню и 2-м бинарным поддеревьям
void init(TTree&, int, TTree, TTree);

// Присоединение левого поддерева
void attachLeftSubtree(TTree, TTree);

// Присоединение правого поддерева
void attachRightSubtree(TTree, TTree);

// Проверка на пустоту
bool isEmpty(TTree);

// Присоединение левого дочернего узла
void attachLeftSon(TTree, int);

// Присоединение правого дочернего узла
void attachRightSon(TTree, int);

// Получение значения корня
int getRootData(TTree);

// Присваивание значения корню
void setRootData(TTree&, int);

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

// Прямой обход дерева
void preorder(TTree, FunctionType);

// Симметричный обход дерева
void inorder(TTree, FunctionType);

// Обратный обход дерева
void postorder(TTree, FunctionType);

// Итеративный обход в глубину
void inorderIterative(TTree, FunctionType);

// Обход в ширину
void breadthTraverse(TTree, FunctionType);

#endif