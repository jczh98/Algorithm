#include <stdio.h>
#include <string.h>
char n[1000];
int rev[1000];
char *trans[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main() {
    scanf("%s", n);
    int len = strlen(n);
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += n[i] - '0';
    }
    len = 0;
    if (sum == 0) {
        printf("zero\n");
        return 0;
    }
    while(sum) {
        rev[len++] = sum % 10;
        sum /= 10;
    }
    for (int i = len - 1; i >= 0; --i) {
        printf("%s%c", trans[rev[i]], " \n"[i==0]);
    }
    return 0;
}
