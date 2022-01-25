#include <stdio.h>
#include <stdlib.h>
 
#define MAX_N (1000)
 
int N;
int pos[MAX_N];
 
void Input_Data(void) {
    int i;
    scanf("%d", &N);
    for (i = 0; i < N;i++) {
        scanf("%d", &pos[i]);
    }
}
 
int comp(const void* p1, const void* p2) {
    return *(int*)p1 - *(int*)p2;
}
 
int Binary_Search_Lower(int s, int e, int d) {
    // d 이상의 데이터 중 최소값
    int m, sol = -1;
    while (s<=e) {
        m = (s + e) / 2;
        if (pos[m] >= d) {
            sol = m;
            e = m - 1;
        }
        else s = m + 1;
    }
    return sol;
}
 
int Binary_Search_Upper(int s, int e, int d) {
    // d 이하의 데이터 중 최대값
    int m, sol = -1;
    while (s<=e) {
        m = (s + e) / 2;
        if (pos[m] <= d) {
            sol = m;
            s = m + 1;
        }
        else e = m - 1;
    }
    return sol;
}
 
int Solve(void) {
    int s1, s2;
    int rs, re;
    int dist;
    int lower, upper;
    int cnt = 0;
    qsort(pos, N, sizeof(pos[0]), comp);
    for (s1 = 0; s1 < N;s1++) {
        for (s2 = s1 + 1; s2 < N;s2++) {
            dist = pos[s2] - pos[s1];
            rs = pos[s2] + dist;
            re = pos[s2] + 2 * dist;
            lower = Binary_Search_Lower(s2 + 1, N - 1, rs);
            if (lower != -1 && pos[lower] <= re) {
                upper = Binary_Search_Upper(s2 + 1, N - 1, re);
                cnt += upper - lower + 1;
            }
        }
    }
    return cnt;
}
 
int main(void) {
    Input_Data();
 
    printf("%d\n", Solve());
 
    return 0;