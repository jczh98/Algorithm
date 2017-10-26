#include <iostream>  
#include <string>  
using namespace std;  
  
int main()  
{  
    string s = "1";  
    for (int i = 1; i <= 1000; i++)  
    {  
        int len = s.length();  
        int flag = 0;  
        for (int j = len - 1; j >= 0; j--)  
        {  
            int tp = (s[j] - '0') * 2 + flag;  
            flag = tp / 10;  
            s[j] = tp % 10 + '0';  
        }  
        if (flag != 0)  
        {  
            s = "1" + s;  
        }  
          
    }  
    int len = s.length();  
    int res = 0;  
    for (int i = 0; i < len; i++)  
    {  
        res += s[i] - '0';  
    }  
    cout << res << endl;  
    system("pause");  
    return 0;  
}  