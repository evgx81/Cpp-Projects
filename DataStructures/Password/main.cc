#include "trie_tree.hh"

int main() {
    int n = 3;
    std::string word = "bcbbaabaacbbcbb";

    TrieTree trie;

    for (int i = 0; i < word.size() - n; i++)
    {
        std::string tempWord = "";
        for (int j = 0; j < n; j++)
        {
            tempWord += word[i+j];
        }
        trie.insert(tempWord);
    }

	trie.print();
    trie.print_password();

    return 0;
}