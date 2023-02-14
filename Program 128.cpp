// Longest substring which is also palindrome  
#include <iostream>
using namespace std;

bool is_palindrome(string s)
{
    int flag = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != s[s.length() - i - 1])
        {
            flag = -1;
            break;
        }
    }
    if (flag == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main() {

    string s = "QharahE";
    int l = 0; 
    for (int i = 0; i < s.length(); i++)
    {
        
        for (int j = 1; j <= s.length(); j++)
        {
           string dummy = s.substr(i,j);
           if (is_palindrome(dummy))
           {
               if(l<dummy.length())
               {
                   l = dummy.length(); 
               }
           }
        }
    }
    cout << l; 
    return 0;
}
