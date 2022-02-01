#include "tree.h"
#include "singly_list.h"

using namespace std;
void printNode(int & elem);
void redoubleNode(int & elem);
void changeNode(int &);



TTree copy(TTree root)
{
	if (root != nullptr)
	{
		TTree copyTree = new TreeNode;
		copyTree->data = root->data;
		copyTree->right = copy(root->right);
		copyTree->left = copy(root->left);
		return copyTree;
	}
	else
		return nullptr;

}

void makeCopies(TTree root, TList& list)
{
	if (root != 0) {
		makeCopies(root->left, list);
		if(root->data == 0)
		{	
			TTree copyTree = copy(root);
			addToHead(list, copyTree);	
		}
		makeCopies(root->right, list);
	}
}

void print(TTree root, int h)
{
    if (root != nullptr)
    {
        print(root->right, h + 1);
        for (int i = 0; i < h; i++)
            std::cout << ' ';
        std::cout << root->data << '\n';
        print(root->left, h + 1);
    }
	cout << '\n'; 
}

void printTree(TList& listTree)
{
	TList p = listTree;
	while(p != nullptr)
	{
		print(p->data, 0);
		cout << '\n';
		p = p->next;
	}
}


int main() {

	TList treeList;
	init(treeList);

    TTree root, root1, root2, root3, left;
	init(root1);
	init(root2);
	init(root3, 0);
	attachLeftSon(root3, -80);
	attachRightSon(root3, 90);
	init(left);

	setRootData(root1, 0);
	attachLeftSon(root1, 10);
	attachRightSon(root1, 1);
	
	setRootData(root2, 100);
	attachLeftSon(root2, 0);
	attachRightSubtree(root2, root1);

	init(root, 0, root2, root3);

	makeCopies(root, treeList);

	printTree(treeList);
	cout << '\n';

    return 0;
}

void printNode(int & elem) {
	std::cout << elem << " ";
}

void redoubleNode(int & elem) {
	elem = 2 * elem;
}

void changeNode(int & elem) {
	elem = elem % 3 ? elem : 0;
}