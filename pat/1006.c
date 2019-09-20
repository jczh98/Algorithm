#include <stdio.h>
#include <string.h>

char name[100], intime[100], outtime[100];
char unlock[100] = "23:59:99", lock[100] = "00:00:00", ansname1[100], ansname2[100];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s%s%s", name, intime, outtime);
        if (strcmp(intime, unlock) < 0) {
            strcpy(unlock, intime);
            strcpy(ansname1, name);
        }
        if (strcmp(outtime, lock) > 0) {
            strcpy(lock, outtime);
            strcpy(ansname2, name);
        }
    }
    printf("%s %s\n", ansname1, ansname2);
    return 0;
}
