#include <bits/stdc++.h>
using namespace std;
int N = 150, min_unit = 13, sum_x = 0, sum_y = 0;
int main() {
    printf("%d\n", N);
    for(int i = 0; i < min_unit; i++) {
        if(sum_x == N) break;
        for(int j = 0; j < min_unit; j++) {
            if(sum_x == N) break;
            sum_y = 0;
            for(int k = 0; k < min_unit; k++) {
                if(sum_y == N) break;
                for(int l = 0; l < min_unit; l++) {
                    if(sum_y == N) break;
                    if((j + k * i) % min_unit == l) {
                        printf("O");
                    }else printf(".");
                    sum_y++;
                }
            }
            sum_x++;
            printf("\n");
        }
    }
}

