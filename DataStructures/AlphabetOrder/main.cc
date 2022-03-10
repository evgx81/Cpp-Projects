#include "trie_tree.hh"

int main()
{
    TrieTree tree;
    tree.insert("a");
    tree.insert("b");
    tree.insert("b");
    tree.insert("aa");
    tree.insert("ab");
    tree.insert("ba");
    tree.insert("bb");
    tree.insert("bb");

    std::cout << tree.remove("a") << '\n';
    std::cout << tree.remove("ab") << '\n';
    tree.print();
    return 0;
}
