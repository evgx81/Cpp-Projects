#include "tree.h"
#include "stack.h"
#include "queue.h"

void init(TTree& root)
{
    root = nullptr;
}

void init(TTree& root, int elem)
{
    root = new TreeNode;
    root->data = elem;
    root->right = nullptr;
    root->left = nullptr;
}

void init(TTree& root, int elem, TTree leftTree, TTree rightTree)
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

void attachLeftSon(TTree root, int elem)
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

void attachRightSon(TTree root, int elem)
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

int getRootData(TTree root)
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

void detachRightTree(TTree root, TTree& leftTree)
{
    if (isEmpty(root))
        std::cout << "Дерево пусто!\n";
    else
    {
        leftTree = root->right;
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

void preorder(TTree root, FunctionType visit)
{
	if (root != 0) {
		//std::cout << root->data << std::endl;
		visit(root->data); 
		preorder(root->left, visit);
		preorder(root->right, visit);
	}
}

void inorder(TTree root, FunctionType visit)
{
	if (root != 0) {
		inorder(root->left, visit);
		visit(root->data);
		inorder(root->right, visit);
	}
}

void postorder(TTree root, FunctionType visit)
{
	if (root != 0) {
		postorder(root->left, visit);
		postorder(root->right, visit);
		visit(root->data);
	}
}

void inorderIterative(TTree root, FunctionType visit)
{
	TStack stack;
	initStack(stack);
	TTree cur = root;
	bool done = false;
	while (!done) {
		if (cur != 0) {
			push(stack, cur);
			cur = cur->left;
		}
		else {
			if (!isEmpty(stack)) {
				pop(stack, cur);
				visit(cur->data);
				cur = cur->right;
			}
			else {
				done = true;
			} //ifelse
		} //while
	}
}

void breadthTraverse(TTree root, FunctionType visit)
{
	if (isEmpty(root)) {
		return;
	}
	TQueue head;
	TQueue tail = initQueue(head);
	TTree treeNode = root;
	enQueue(head, tail, treeNode);
	while (!isEmpty(head)) {
		deQueue(head, tail, treeNode); 
		visit(treeNode->data);
		if (treeNode->left)
			enQueue(head, tail, treeNode->left);
		if (treeNode->right)
			enQueue(head, tail, treeNode->right);		
	}
}



