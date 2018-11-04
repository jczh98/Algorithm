#include <stdlib.h>
#include <string.h>
#include <algorithm>
/*
AC O(N^2)
phidnight
*/
#include <cstdio>

int pr=47;
int main() {
    //freopen("out.txt", "w", stdout);
	int N=2000,ans=0;
	printf("%d\n",N);
	int sumx=0;
	for(int i=0;i<pr;i++) {
		if(sumx==N) break;
		for(int j=0;j<pr;j++) {
			if(sumx==N) break;
			int sumy=0;
			for(int k=0;k<pr;k++) {
				if(sumy==N) break;
				for(int l=0;l<pr;l++) {
					if(sumy==N) break;
					if((j+k*i)%pr==l) {
                        //ans++;
						printf("1");
					} else {
						printf("0");
					}
					sumy++;
				}
			}
			sumx++;
			printf("\n");
		}
	}
    //printf("%d\n",ans);
	return 0;
}
