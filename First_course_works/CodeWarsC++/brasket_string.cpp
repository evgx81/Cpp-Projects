#include <iostream>
#include <cctype>
bool isUniqueSymbol(char s, const int index, const std::string& word){
    if(isupper(s))
        s = tolower(s);

    bool unique = true;
    for(int i = 0; i < index; i++){
        if(tolower(word[i]) == s)
            unique = false;
    }
    for(int j = index + 1; j < word.length(); j++){
        if(tolower(word[j]) == s)
            unique = false;
    }
    return unique;
}

std::string duplicate_encoder(const std::string& word){
    std::string res = ""; 
    res = word;
    for(int i = 0; i < word.length(); i++){
        if(isUniqueSymbol(word[i], i, word))
            res[i] = '(';
        if(!isUniqueSymbol(word[i], i, word))
            res[i] = ')';
    }
  
    return res; 
}



int main(){
    std::string str = "Supralapsarian"; 
    std::cout << duplicate_encoder(str);
    return 0;
}
