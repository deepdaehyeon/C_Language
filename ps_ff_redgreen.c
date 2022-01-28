#include <stdio.h>
#define MAX_N (100)
 
int N;
char map[MAX_N+2][MAX_N+2]; // 1~N
int cnt, cnt_rg;
 
void Input_Data(void) {
    int r;
    scanf("%d", &N);
    for (r = 1; r <= N;r++) {
        scanf("%s", &map[r][1]);
    }
}
 
void Flood_Fill(int r, int c, char color) {
    int i;
    int nr, nc;
    static int dr[] = { 0,0,1,-1};
    static int dc[] = { 1,-1,0,0};
    if (color == 'B') map[r][c] = 'X';
    else map[r][c] = 'Y';
 
    for (i = 0; i < 4;i++) {
        nr = r + dr[i];
        nc = c + dc[i];
        if (nr < 1 || nr > N) continue;
        if (nc < 1 || nc > N) continue;
        if (map[nr][nc] == color)  Flood_Fill(nr, nc, color);
    }
}

void Flood_Fill_rg(int r, int c, char color) {
    int i;
    int nr, nc;
    static int dr2[] = { 0,0,1,-1};
    static int dc2[] = { 1,-1,0,0};
    map[r][c] = '0';
 
    for (i = 0; i < 4;i++) {
        nr = r + dr2[i];
        nc = c + dc2[i];
        if (nr < 1 || nr > N) continue;
        if (nc < 1 || nc > N) continue;
        if (map[nr][nc] == color)  Flood_Fill_rg(nr, nc, color);
    }
}
 
void Solve(void) {
    int r, c;
    for (r = 1; r <= N;r++) {
        for (c = 1; c <= N;c++) {
            if (map[r][c] == 'X') continue; 
            if (map[r][c] == 'Y') continue; 
            cnt++; 
            Flood_Fill(r, c, map[r][c]);
        }
    }

    for (r = 1; r <= N;r++) {
        for (c = 1; c <= N;c++) {
            if (map[r][c] == '0') continue; 
            cnt_rg++; 
            Flood_Fill_rg(r, c, map[r][c]);
        }
    }

}

 
int main(void) {
    int i;
    Input_Data();
    Solve();
    printf("%d %d", cnt, cnt_rg);
    return 0;
}
 