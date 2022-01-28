#include <stdio.h>
 
#define MAX_N (25)
 
int N;
int map[MAX_N+2][MAX_N+2]; // 1~N
 
int cnt_danji;
int size_danji[(MAX_N+1)*(MAX_N + 1)/2];
 
int comp(const void *p1, const void* p2) {
    return *(int*)p1 - *(int*)p2;
}
 
void Input_Data(void) {
    int r, c;
    scanf("%d", &N);
    for (r = 1; r <= N;r++) {
        for (c = 1; c <= N;c++) {
            scanf("%1d", &map[r][c]);
        }
    }
}
 
int cnt_ff;
void Flood_Fill(int r, int c) {
    int i;
    int nr, nc;
    static int dr[] = { 0,0,1,-1 };
    static int dc[] = { 1,-1,0,0 };
 
    cnt_ff++;
    map[r][c] = 0;
 
    for (i = 0; i < 4;i++) {
        nr = r + dr[i];
        nc = c + dc[i];
        if (nr < 1 || nr > N) continue;
        if (nc < 1 || nc > N) continue;
        if (map[nr][nc] == 0) continue;
        Flood_Fill(nr, nc);
    }
}
 
void Solve(void) {
    int r, c;
 
    for (r = 1; r <= N;r++) {
        for (c = 1; c <= N;c++) {
            if (map[r][c] == 1) {
                cnt_ff = 0;
                Flood_Fill(r, c);
                size_danji[cnt_danji++] = cnt_ff;
            }
        }
    }
}
 
int main(void) {
    int i;
    Input_Data();
    Solve();
    qsort(size_danji, cnt_danji, sizeof(size_danji[0]), comp);
    printf("%d\n", cnt_danji);
    for (i = 0; i < cnt_danji;i++) {
        printf("%d\n", size_danji[i]);
    }
    return 0;
}
 