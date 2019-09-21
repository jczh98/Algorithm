#include <stdio.h>
#include <string.h>

char in[100];
int score, n, m, sitecnt[20000],date;

struct student {
    int level, site, date, number, score;
    char id[30];
} stu[20000], stu2[20000];
struct node {
    int site, nt;
} sitent[20000];
int type, sco,site;
char lev[10];
void sort_(struct node *a, int len) {
    if (len <= 1) return;
    int i = 0, j = len-1;
    struct node tmp = a[0];
    while (i < j) {
        while((a[j].nt>tmp.nt||(a[i].nt==tmp.nt&&a[i].site<tmp.site))&&i<j)j--;a[i]=a[j];
        while((a[i].nt<tmp.nt||(a[i].nt==tmp.nt&&a[i].site>=tmp.site))&&i<j)i++;a[j]=a[i];
    }
    a[i]=tmp;
    sort_(a,i);sort_(a+1+i,len-i-1);
}
void sort(struct student *a, int len) {
    if (len <= 1) return;
    int i = 0, j = len-1;
    struct student tmp = a[0];
    while(i < j) {
        while((a[j].score>tmp.score||(a[j].score==tmp.score&&strcmp(a[j].id,tmp.id)<0))&&i<j)j--; a[i] = a[j];
        while((a[i].score<tmp.score||(a[i].score==tmp.score&&strcmp(a[i].id, tmp.id)>=0))&&i<j)i++; a[j] = a[i];
    }
    a[i] = tmp;
    sort(a, i); sort(a+i+1, len-i-1);
}
int cal(char *a, int i, int j) {
    int sum = 0;
    for (int x = i; x <= j; ++x) {
        sum = sum * 10 + a[x]-'0';
    }
    return sum;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d", stu[i].id, &stu[i].score);
        stu[i].site = cal(stu[i].id, 1,3);
        stu[i].date = cal(stu[i].id,4,9);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%s", lev);
            int len = 0;
            memset(stu2, 0, sizeof(stu2));
            for (int j = 0; j < n; ++j) {
                if (stu[j].id[0] == lev[0]) {
                    stu2[len++] = stu[j];
                }
            }
            sort(stu2, len);
            printf("Case %d: %d %s\n", i, type, lev);
            if (len == 0) {
                printf("NA\n");
                continue;
            }
            printf("%d\n", len);
            for (int j = len-1; j >= 0; --j) {
                printf("%s %d\n", stu2[j].id, stu2[j].score);
            }
        } else if (type == 2) {
            scanf("%d", &site);
            int cnt = 0, ans = 0;
            for (int j = 0; j < n; ++j) {
                if (stu[j].site == site) {
                    cnt++;
                    ans += stu[j].score;
                }
            }
            printf("Case %d: %d %d\n", i, type, site);
            if (cnt == 0) {
                printf("NA\n");
                continue;
            }
            printf("%d %d\n", cnt, ans);
        } else if (type == 3) {
            scanf("%d", &date);
            int len = 0;
            memset(sitent, 0, sizeof(sitent));
            memset(sitecnt, 0, sizeof(sitecnt));
            for (int j = 0; j < n; ++j) {
                if (stu[j].date == date) {
                    sitecnt[stu[j].site]++;
                }
            }
            for (int j = 101; j <= 999; ++j) {
                if (sitecnt[j] != 0) {
                    sitent[len].site = j;
                    sitent[len++].nt = sitecnt[j];
                }
            }
            sort_(sitent, len);
            printf("Case %d: %d %d\n", i, type, date);
            if (len == 0) {
                printf("NA\n");
                continue;
            }
            for (int j = len-1; j>= 0; --j) {
                printf("%d %d\n", sitent[j].site, sitent[j].nt);
            }
        }
    }
    return 0;
}
