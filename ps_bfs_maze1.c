#include <stdio.h>
 
#define MAX_CR (100)
 
int C, R;
int sc, sr, ec, er;
char map[MAX_CR+2][MAX_CR+2];
 
// 상태 저장 Queue : Circular vs Linear!
#define MAX_Q (MAX_CR * MAX_CR)
typedef struct {
    int r, c; // 상태
    int time; // 상태에대한 연산 결과
}QUEUE;
 
QUEUE queue[MAX_Q];
int wp, rp;
 
void Enqueue(QUEUE* p) {
    queue[wp++] = *p;
}

void Dequeue(QUEUE *p) {
    *p = queue[rp++];
}
 
int Empty(void) {
    return wp == rp;
}
 
int chk[MAX_CR+1][MAX_CR+1];
 
void Input_Data(void) {
    int r;
    scanf("%d %d", &C, &R);
    scanf("%d %d %d %d", &sc, &sr, &ec, &er);
    for (r = 1; r <= R;r++) {
        scanf("%s", &map[r][1]);
    }
}
 
int BFS(void) {
    int i;
    int dr[] = {0,0,1,-1};
    int dc[] = {1,-1,0,0};
    QUEUE data, ndata;
    // 초기 상태 정의
    data.r = sr; data.c = sc; data.time = 0;
    Enqueue(&data);
    chk[sr][sc] = 1;
    if (sr == er && sc == ec) return 0;
 
    while (!Empty()) {
        Dequeue(&data);
        for (i = 0; i < 4;i++) {
            // 상태 발전 연산
            ndata.r = data.r + dr[i];
            ndata.c = data.c + dc[i];
            ndata.time = data.time + 1;
 
            // 1~R, 1~C
            if (ndata.r < 1 || ndata.r > R) continue;
            if (ndata.c < 1 || ndata.c > C) continue;
            if (map[ndata.r][ndata.c] == '1') continue;
            if (chk[ndata.r][ndata.c] == 1) continue;
 
            if (ndata.r == er && ndata.c == ec) {
                return ndata.time;
            }
 
            Enqueue(&ndata);
            chk[ndata.r][ndata.c] = 1;
        }
    }
    return -1;
}
 
int main(void) {
    Input_Data();
 
    printf("%d\n",BFS());
 
    return 0;
}