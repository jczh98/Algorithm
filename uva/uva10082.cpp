#include <cstdio>

char s[]={"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"};
char c;int i;

int main(){
	while((c=getchar())!=EOF){
		for(i=1;s[i]&&s[i]!=c;i++);
		if(s[i])putchar(s[i-1]);
		else putchar(c);
	}	
	return 0;
}
