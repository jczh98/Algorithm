#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char s[1001];
int main()
{
    scanf("%s",s);
    sort(s,s+strlen(s));
    printf("%s",s);
    return 0;
}
