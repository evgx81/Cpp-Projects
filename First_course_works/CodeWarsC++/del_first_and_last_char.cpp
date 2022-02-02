#include <iostream>
#include <cstring>

using namespace std; 

string sliceString (string str)
{
    return str.substr(1 , str.length() - 2);
    
}

/* string sliceString (string str )
{   
    return string(str.begin()+1,str.end()-1) ; 
}
*/

/* string sliceString (string str )
{   
    str.erase(str.begin());
    str.erase(str.length() - 1);
    return str ;
}
*/

int main(){
    string st = " Hell0 ";
    cout << sliceString(st);
    return 0;
}