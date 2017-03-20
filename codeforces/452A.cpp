#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
string evlove[]={"jolteon", "flareon", "umbreon", "leafeon", "glaceon", "sylveon"};
int n;
char s[100000];
int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    if(n==8)printf("vaporeon\n");
    else if(n==6) printf("espeon\n");
    else
    {
        for(int i=0;i<6;i++)
        {
            int f=0;
            for(int j=0;j<7;j++)
            {
                if(s[j]>='a'&&s[j]<='z'&&s[j]!=evlove[i][j])
                {
                    f=1;break;
                }
            }
            if(!f)
            {
                cout<<evlove[i]<<endl;
                break;
            }
        }
    }
    return 0;
}
