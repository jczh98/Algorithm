#include <cstdio>
#include <cstring>
#include <cctype>

const char rev[]={"A   3  HIL JM O   2TUVWXY51SE Z  8 "};
const char* msg[]={" -- is not a palindrome."," -- is a regular palindrome."," -- is a mirrored string.",
" -- is a mirrored palindrome."};
char s[100];
int len,p,m;

bool JudgeP(){
	for(int i=0;i<(len+1)/2;i++){
		if(s[i]!=s[len-1-i])return false;
	}
	return true;
}
char Trans(char c){
	if(isalpha(c))return rev[c-'A'];
	return rev[c-'0'+25];
}
bool JudgeM(){
	for(int i=0;i<(len+1)/2;i++){
		if(Trans(s[i])!=s[len-1-i])return false;
	}
	return true;
}
int main(){
	while(scanf("%s",s)!=EOF){
		len=strlen(s);
		p=JudgeP();
		m=JudgeM();
		printf("%s%s\n\n",s,msg[m*2+p]);
	}	
	return 0;
}
