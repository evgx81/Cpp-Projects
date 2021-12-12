#include "tree.h"
#include "queue.h"
#include "stack.h"
void printNode(int & elem);
void redoubleNode(int & elem);
void changeNode(int &);

void print(TTree root, int h)
{
    if (root != nullptr)
    {
        print(root->right, h + 1);
        for (int i = 0; i < h; i++)
            std::cout << ' ';
        std::cout << root->data << '\n';
        print(root->left, h+1);
    }
}

int sum(TTree root)
{
    if (root != nullptr)
        return sum(root->right) + sum(root->left) + root->data;
    else
        return 0;
}

int sumOfLeaves(TTree root)
{   
    if (root == nullptr)
        return 0;
    else if (root->left == nullptr && root->right == nullptr)
        return root->data;
    else 
        return sumOfLeaves(root->right) + sumOfLeaves(root->left);
}

int sumWithoutLeaves(TTree root)
{   
    if (root == nullptr)
        return 0;
    else if (root->left == nullptr && root->right == nullptr)
        return 0;
    else 
        return sumOfLeaves(root->right) + sumOfLeaves(root->left) + root->data;
}

int sumOnLayer(TTree root, int height)
{
    if (height < 1 || root == nullptr)
        return 0;
    else if (height == 1)
        return root->data;
    else
        return sumOnLayer(root->right, height--) + sumOnLayer(root->left, height--);
}

//Дано бинарное дерево. Найти количество отрицательных элементов. Использовать рекурсивную ПРОЦЕДУРУ.
void countNegElements(TTree root, int& n)
{
    if (root != nullptr)
	{
		if (root->data < 0)
        	n++;
		countNegElements(root->right, n);
		countNegElements(root->left, n);
	}
	
    
}

//Дано бинарное дерево. Найти максимальный по модулю элемент. Использовать рекурсивную ФУНКЦИЮ.
int maxAbsElem(TTree root)
{
    if(root == nullptr)
		return 0;
	return std::max(std::abs(root->data), std::max(abs(maxAbsElem(root->left)), abs(maxAbsElem(root->right))));
}

// Дано бинарное дерево. Найти количество элементов на n-м уровне. Использовать рекурсивную ФУНКЦИЮ.
int countElementsOnLevel(TTree root, int layer)
{
	if(layer < 1 || root == nullptr)
		return 0;
	else if (layer == 1)
		return 1;
	else
		return countElementsOnLevel(root->right, layer - 1) + countElementsOnLevel(root->left, layer - 1);

}

void countElementsOnLevel(TTree root, int layer, int& count)
{
	if (root != nullptr)
	{
		if(layer == 1)
			count++;
		countElementsOnLevel(root->left, layer - 1, count);
		countElementsOnLevel(root->right, layer - 1, count);

	}

}


void countMaxElements(TTree root, int& max_elem, int& count)
{
	if (root != nullptr)
	{
		if (root->data == max_elem)
			++count;
		else if (root->data > max_elem) 
		{
			max_elem = root->data;
			count = 1;
		}
		countMaxElements(root->left, max_elem, count);
		countMaxElements(root->right, max_elem, count);
	}
}

int findMaxBreadth(TTree root)
{
	TQueue queue;
	TQueue tail = initQueue(queue);
	int max = root->data;
	enQueue(queue, tail, root);
	TTree curr = root;
	while (!isEmpty(queue))
	{
		getFront(queue, curr);
		deQueue(queue);
		if (curr->data > max)
			max = curr->data;

		if (!isEmpty(curr->left))
			enQueue(queue, tail, curr->left);
		if (!isEmpty(curr->right))
			enQueue(queue, tail, curr->right);
	}
	return max;
}

int findMinBreadth(TTree root)
{
	TQueue queue;
	TQueue tail = initQueue(queue);
	int min = root->data;
	enQueue(queue, tail, root);
	TTree curr = root;
	while (!isEmpty(queue))
	{
		getFront(queue, curr);
		deQueue(queue);
		if (curr->data < min)
			min = curr->data;

		if (!isEmpty(curr->left))
			enQueue(queue, tail, curr->left);
		if (!isEmpty(curr->right))
			enQueue(queue, tail, curr->right);
	}
	return min;
}

int findMaxDepth(TTree root)
{
	TStack stack;
	initStack(stack);
	TTree curr = root;
	int max = root->data;
	bool flag = false;
	while(!flag)
	{
		if (!isEmpty(curr)) 
		{
			push(stack, curr);
			curr = curr->left;
		}
		else
		{
			if(!isEmpty(stack))
			{
				pop(stack, curr);
				if (curr->data > max)
					max = curr->data;
				curr = curr->right;
			}
			else
				flag = true;
		}
	}
	return max;
}

void copyWithoutLeaves(TTree root, TTree& copyTree)
{
	if(root != nullptr && (root->left != nullptr || root->right != nullptr))
	{
		copyTree = new TreeNode;
		copyTree->data = root->data;
		copyWithoutLeaves(root->left, copyTree->left);
		copyWithoutLeaves(root->right, copyTree->right);
	}
	else
		copyTree = nullptr;
}

TTree copyWithoutLeaves(TTree root)
{
	if (root != nullptr && (root->left != nullptr || root->right != nullptr))
	{
		TTree copyTree = new TreeNode;
		copyTree->data = root->data;
		copyTree->right = copyWithoutLeaves(root->right);
		copyTree->left = copyWithoutLeaves(root->left);
		return copyTree;
	}
	else
		return nullptr;

}

bool isInTree(TTree root, int elem)
{
	if (root != nullptr)
	{
		if (root->data == elem)
			return true;
		else
			return isInTree(root->left, elem) || isInTree(root->right, elem) || isInTree(root, elem);
	}
	else
		return false;
}

void isInTree(TTree root, int elem, bool& flag)
{
	if (root != nullptr)
	{
		if (root->data == elem)
			flag = true;
		else
			isInTree(root->right, elem, flag);
			isInTree(root->left, elem, flag);
	}
}

// Дано бинарное дерево поменять местами минимальный и максимальный элементы
void changeMaxAndMin(TTree& root, int& min, int& max)
{
	if (root != nullptr)
	{
		if (root->data == max)
			root->data = min;
		else if (root->data == min)
			root->data = max;


		changeMaxAndMin(root->left, min, max);
		changeMaxAndMin(root->right, min, max);
	}
}

// Дано бинарное дерево. Построить копию его n-го уровня
TTree copyOnLevel(TTree root, int level)
{
	if (root != nullptr && level != 0)
	{
		TTree copyTree = new TreeNode;
		copyTree->data = root->data;
		copyTree->left = copyOnLevel(root->left, level - 1);
		copyTree->right = copyOnLevel(root->right, level - 1);
		return copyTree;
	}
	else
		return nullptr;
}

void copyOnLevel(TTree root, TTree& copyTree, int level)
{
	if (root != nullptr && level != 0)
	{
		copyTree = new TreeNode;
		copyTree->data = root->data;
		copyOnLevel(root->left, copyTree->left, level - 1);
		copyOnLevel(root->right, copyTree->right, level - 1);
	}
	else
		copyTree = nullptr;
}

void destroyLeaves(TTree& root)
{
	if (root != nullptr)
	{
		if(root->left == nullptr && root->right == nullptr)
		{	
			delete root;
			root = nullptr;
		}
		else
		{
			destroyLeaves(root->left);
			destroyLeaves(root->right);
		}
		
	}
}

TTree copyTillNegative(TTree root)
{
	if (root != nullptr && root->data > 0)
	{
		TTree copyTree = new TreeNode;
		copyTree->data = root->data;
		copyTree->left = copyTillNegative(root->left);
		copyTree->right = copyTillNegative(root->right);
		return copyTree;
	}
	else
		return nullptr;
}

int main() {
	TTree root, root1, root2, root3, left;
	init(root1);
	init(root2);
	init(root3, 30);
	attachLeftSon(root3, -80);
	attachRightSon(root3, 90);
	init(left);

	setRootData(root1, 5);
	attachLeftSon(root1, 10);
	attachRightSon(root1, 100);
	
	setRootData(root2, 100);
	attachLeftSon(root2, -20);
	attachRightSubtree(root2, root1);

	init(root, 40, root2, root3);

	inorder(root, printNode);
	std::cout << std::endl;

	// std::cout << "Breadth traverse: ";
	// breadthTraverse(root, printNode);
	// std::cout << std::endl;

	// std::cout << "Iterative traverse: "; 
	// inorderIterative(root, printNode);
	// std::cout << std::endl;

	// inorder(root, changeNode);
	// inorder(root, printNode);
	// std::cout << std::endl;

	// inorder(getLeftSubtree(root), printNode);
	// std::cout << std::endl;

	// detachLeftTree(root, left);
	// inorder(left, printNode);
	// std::cout << std::endl;

	// inorder(root, printNode);
	// std::cout << std::endl;

	// inorder(root, redoubleNode);
	// inorder(root, printNode);
	// std::cout << std::endl;
	
	std::cout << "Сумма всех элементов дерева: " << sum(root) << '\n';
	std::cout << "---------------\n";

	int c{};
	countNegElements(root, c);
	std::cout << "Количество отрицательных элементов: " << c << '\n';
	std::cout << "---------------\n";

	int h = 2;
	std::cout << "[Функция] Количество элементов на уровне " << h << " равно "<< countElementsOnLevel(root, h) << '\n';
	std::cout << "---------------\n";

	int m{};
	countElementsOnLevel(root, h, m);
	std::cout << "[Процедура] Количество элементов на уровне " << h << " равно " << m << '\n';
	std::cout << "---------------\n";

	int g = root->data;
	int count{};
	countMaxElements(root, g, count); 
	std::cout << "Количество максимальных элементов: " << count << '\n';
	std::cout << "---------------\n";

	std::cout << "Максимальный по модулю элемент: " << maxAbsElem(root) << '\n';
	std::cout << "---------------\n";

	std::cout << "Сумма элементов на уровне " << h << " равна "<< sumOnLayer(root, h) << '\n';
	std::cout << "---------------\n";

	std::cout << "[Обход в ширину] Максимальный элемент: " << findMaxBreadth(root) << '\n';
	std::cout << "---------------\n";

	std::cout << "[Обход в глубину] Максимальный элемент: " << findMaxDepth(root) << '\n';
	std::cout << "---------------\n";

	TTree copyTree1;
	copyWithoutLeaves(root, copyTree1);
	std::cout << "[Процедура] Копия без листьев: ";
	inorder(copyTree1, printNode);
	std::cout << '\n';
	std::cout << "---------------\n";

	std::cout << "[Функция] Копия без листьев: ";
	inorder(copyWithoutLeaves(root), printNode);
	std::cout << '\n';
	std::cout << "---------------\n";

	std::cout << "[Функция] Находится ли элемент в дереве: ";
	std::cout << isInTree(root1, 10) << '\n';
	std::cout << "---------------\n";

	std::cout << "[Процедура] Находится ли элемент в дереве: ";
	bool flag;
	isInTree(root, -30, flag);
	std::cout << flag << '\n';
	std::cout << "---------------\n";

	int levelTree{2};
	std::cout << "[Функция] Скопированное дерево уровня " << levelTree << '\n';
	inorder(copyOnLevel(root, levelTree), printNode);
	std::cout << '\n';
	std::cout << "---------------\n";

	TTree copyLevel;
	copyOnLevel(root, copyLevel, levelTree);
	std::cout << "[Процедура] Скопированное дерево уровня " << levelTree << '\n';
	inorder(copyLevel, printNode);
	std::cout << '\n';
	std::cout << "---------------\n";

	inorder(root, printNode);
	std::cout << '\n';
	std::cout << "Дерево, после того, как в нем поменяли местами минимальный и максимальный элементы:\n";
	int m_min = findMinBreadth(root);
	int m_max = findMaxBreadth(root);
	// changeMaxAndMin(root, m_min, m_max);
	inorder(root, printNode);
	std::cout << '\n';
	std::cout << "---------------\n";

	std::cout << "Дерево без листьев: ";
	// destroyLeaves(root);
	inorder(root, printNode);
	std::cout << '\n';
	std::cout << "---------------\n";

	std::cout << "Дерево до первых отрицательных элементов: ";
	inorder(copyTillNegative(root), printNode);
	std::cout << '\n';
	std::cout << "---------------\n";

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