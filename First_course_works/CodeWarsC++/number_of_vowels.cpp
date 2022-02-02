#include <string>
using namespace std;

/*Return the number (count) of vowels in the given string.
We will consider a, e, i, o, u as vowels for this Kata (but not y).
The input string will only consist of lower case letters and/or spaces.
*/

int getCount(const string& inputStr){
    int num_vowels = 0;
    string vowels = "aeiou";
    for(int i = 0; i < inputStr.length(); i++){
      for(int j = 0; j < vowels.length(); j++){
        if(inputStr[i] == vowels[j])
          num_vowels++;
      }
    }
    return num_vowels;
}