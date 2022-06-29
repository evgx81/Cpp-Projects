#ifndef LINEAR_PROBING_TABLE
#define LINEAR_PROBING_TABLE

#include "hash_table.hh"

class LinearProbingTable : public HashTable {
	int capacity;
	int size;

	const int FREE = 0;
	const int BUSY = 1;
	const int REMOVED = -1;

	struct HashNode {
		TKey key;
		TValue value;
		int state;
	};

	HashNode* cells;

public:
	LinearProbingTable(int tableSize);
	LinearProbingTable(const LinearProbingTable& table);

	void insert(TKey key, TValue value);
	bool remove(TKey key);
	bool find(TKey key);

	void clear();

	int getSize();
	bool isEmpty();

	TValue get(TKey key);

	void print();

	~LinearProbingTable();

protected:
	int hash(TKey key);
private:
	void rehash();
};

#endif