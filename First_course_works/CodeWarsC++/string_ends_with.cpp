#include <iostream>
#include <cstring>
bool solution(std::string const &str, std::string const &ending) {
    bool ans = false;
    if (str.length() >= ending.length()){
        std::string cop = str.substr(str.size() - ending.size(), ending.size());
        if(cop == ending)
            ans = true;
    }
    return ans;
}

int main(){
    std::cout << solution("abcde", "abc34323423");
    return 0;
}
