#include <iostream>
#include <algorithm>
#include "balda.hh"


int main()
{

    std::vector<std::string> words = {"spot", "so", "to", "spots", "son", "sons"};
    std::string word = "sport";
    Balda balda{word, words};

    std::cout << balda << '\n';
    
    balda.analyze_game();

    std::cout << balda << '\n';
    return 0;
}