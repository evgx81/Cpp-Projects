#include "separate_chaining_table.hh"

SeparateChainingTable::SeparateChainingTable(int tableSize)
{
    capacity = tableSize;
    size = 0;
    cells = new Node*[tableSize];
    for(int i = 0; i < tableSize; ++i)
        cells[i] = nullptr;
}

SeparateChainingTable::~SeparateChainingTable()
{
    clear();
}

int SeparateChainingTable::hash(TKey key)
{
    return abs(key / 7) % capacity;
}

void SeparateChainingTable::insert(TKey key, TValue value)
{
    int index = hash(key);
    Node* node = new Node;
    node->key = key;
    node->value = value;
    node->next = cells[index];
    cells[index] = node;
    size++;
}

bool SeparateChainingTable::remove(TKey key)
{
    int index = hash(key);
    Node* list = cells[index];
    Node* prev = nullptr;
    while(list != nullptr && list->next->key != key)
    {
        prev = list;
        list = list->next;
    }

    if(list == nullptr) 
        return false;
    if (prev == nullptr) 
        cells[index] = list->next;
    else
        prev->next = list->next;
    delete list;
    list = 0;
    size--;
    return true;

}

bool SeparateChainingTable::find(TKey key)
{
    int index = hash(key);
	if (cells[index] == 0) return false;
	else
	{
		Node* p = cells[index];
		while (p != 0 && p->key != key) p = p->next;
		if (p == 0) return false;
		else return true;
	}
}
void SeparateChainingTable::clear()
{
    for (int i = 0; i < capacity; i++)
	{
		Node* p = cells[i];
		while (p != 0)
		{
			Node* pNode = p;
			cells[i] = p->next;
			pNode->next = 0;
			delete pNode;
			pNode = 0;
			p = p->next;
		}
	}
    delete[] cells;
}
TValue SeparateChainingTable::get(TKey key)
{
    if (find(key))
	{
		int index = hash(key);
		Node* p = cells[index];
		while (p != 0 && p->key != key) p = p->next;
		return p->value;
	}
    else
        return "Объект не найден\n";
}
bool SeparateChainingTable::isEmpty()
{
    return size == 0;
}
void SeparateChainingTable::print()
{
    for (int i = 0;i < capacity;i++)
	{
		Node* p = cells[i];
		while (p != 0)
		{
			// Node* pNode = p;
            // while(pNode != nullptr)
            // {
            //     std::cout << pNode->value << ' ';
            //     pNode = pNode->next;
            // }
                std::cout << p->value << ' ';
			std::cout << "___________________________________________________________" << std::endl;
			p = p->next;
		}
	}
}
int SeparateChainingTable::get_size()
{
    return size;
} 