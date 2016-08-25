#include <cstdio>

char c;
bool f=true;

int main(){
	while((c=getchar())!=EOF){
		if(c=='"')printf("%s",f?"``":"''"),f=!f;
		else printf("%c",c); 
	}	
	return 0;
}
