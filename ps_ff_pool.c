#include <stdio.h>
 
#define MAX_N (100)
 
int N;
int map[MAX_N+2][MAX_N+2]; // 1~N
 
int cnt_danji;
 
void Input_Data(void) {
    int r, c;
    scanf("%d", &N);
    for (r = 1; r <= N;r++) {
        for (c = 1; c <= N;c++) {
            scanf("%1d", &map[r][c]);
        }
    }
}
 
void Flood_Fill(int r, int c) {
    int i;
    int nr, nc;
    static int dr[] = { 0,0,1,-1,1,1,-1,-1 };
    static int dc[] = { 1,-1,0,0,1,-1,1,-1 };
    map[r][c] = 0;
 
    for (i = 0; i < 8;i++) {
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
                cnt_danji++; 
                Flood_Fill(r, c);
            }
        }
    }
}
 
int main(void) {
    int i;
    Input_Data();
    Solve();
    printf("%d\n", cnt_danji);
    return 0;
}
 