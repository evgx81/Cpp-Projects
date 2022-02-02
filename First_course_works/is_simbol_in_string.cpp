#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

// Проверить, находится ли введенный пользователем символ в строке

int main()
{
    int i = 0, k = 0;
    string s;
    char ch;
    cout << "String:\n";
    getline(cin, s);
    cout << "Symbol:\n";
    cin >>ch;
    
    
    while (s[i])
    {
        if (s[i] == ch) {k++; cout << "index " << i << "\n";}              
        i++;
    }
    
    if (k==0) cout << "Symbol '" << ch << "' are absent\n";
 
    system("pause");
    return 0;
}