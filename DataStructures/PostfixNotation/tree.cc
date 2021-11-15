#include "tree.hh"

void init(TTree& root)
{
    root = nullptr;
}

void init(TTree& root, char elem)
{
    root = new TreeNode;
    root->data = elem;
    root->right = nullptr;
    root->left = nullptr;
}

void init(TTree& root, char elem, TTree leftTree, TTree rightTree)
{
    init(root, elem);
    attachLeftSubtree(root, leftTree);
    attachRightSubtree(root, rightTree);
}


void attachLeftSubtree(TTree root, TTree subTree)
{
    if (isEmpty(root))
        std::cout << "Дерево пусто!\n";
    else
    {
        if (root->left != nullptr)
            std::cout << "Левое поддерево не пусто!\n";
        else
            root->left = subTree;
    }
}

void attachRightSubtree(TTree root, TTree subTree)
{
    if (isEmpty(root))
        std::cout << "Дерево пусто!\n";
    else
    {
        if (root->right != nullptr)
            std::cout << "Правое поддерево не пусто!\n";
        else
            root->right = subTree;
    }
}

bool isEmpty(TTree root)
{
    return root == nullptr;
}

void attachLeftSon(TTree root, char elem)
{
    if (isEmpty(root))
        std::cout << "Дерево пусто!\n";
    else
    {
        TTree p = new TreeNode;
        p->data = elem;
        p->left = nullptr;
        p->right = nullptr;
        root->left = p;
    }
}

void attachRightSon(TTree root, char elem)
{
    if (isEmpty(root))
        std::cout << "Дерево пусто!\n";
    else
    {
        TTree p = new TreeNode;
        p->data = elem;
        p->left = nullptr;
        p->right = nullptr;
        root->right = p;
    }
}

void destroy(TTree& root)
{
    if (root != nullptr)
    {
        destroy(root->left);
        destroy(root->right);
        delete root;
        root = nullptr;
    }
}

char getRootData(TTree root)
{
    if(!isEmpty(root))
        return root->data;
    else
    {
        std::cout << "Дерево пусто!\n";
        return 0;
    }
}

void setRootData(TTree& root, int elem)
{
    if(!isEmpty(root))
        root->data = elem;
    else
    {
        init(root, elem);
    }

}

void detachLeftTree(TTree root, TTree& leftTree)
{
    if (isEmpty(root))
        std::cout << "Дерево пусто!\n";
    else
    {
        leftTree = root->left;
        root->left = 0;
    }
}

void detachRightTree(TTree root, TTree& rightTree)
{
    if (isEmpty(root))
        std::cout << "Дерево пусто!\n";
    else
    {
        rightTree = root->right;
        root->right = 0;
    }
}

TTree getLeftSubtree(TTree root)
{
    TTree subTree;
    if (isEmpty(root))
        subTree = nullptr;
    else
        copyTree(root->left, subTree);
    return subTree;
}

TTree getRightSubtree(TTree root)
{
    TTree subTree;
    if (isEmpty(root))
        subTree = nullptr;
    else
        copyTree(root->right, subTree);
    return subTree;
}

void copyTree(TTree root, TTree& newRoot)
{
    if (root != nullptr)
    {
        newRoot = new TreeNode;
        newRoot->data = root->data;
        newRoot->left = nullptr;
        newRoot->right =  nullptr;
        copyTree(root->left, newRoot->left);
        copyTree(root->right, newRoot->right);
    }
    else
        newRoot = nullptr;
}