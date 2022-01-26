#include <stdio.h>
 
#define MAX_CR (1000)
#define MAX_Q (MAX_CR * MAX_CR)
 
int c, r;
int sc, sr, ec, er;
int map[MAX_CR+2][MAX_CR+2];

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

void Input_Data() {
    scanf("%d %d", &c, &r);
	for(int i=1; i<=r; i++){
		for (int j=1 ; j<=c; j++){
			scanf(" %d", &map[i][j]);
		}
	}
}
 
int BFS(void) {
    int i,j;
	int cnt=0; 
    int dr[] = {0,0,1,-1};
    int dc[] = {1,-1,0,0};
    QUEUE data, ndata;
	for(i=1; i<=r; i++){
		for (j=1; j<=c; j++){
			if(map[i][j] ==1) {
				data.r = i; 
				data.c = j; 
				data.time =0; 
				Enqueue(&data);
			}
		}
	}
 
    while (!Empty()) {
        Dequeue(&data);
        for (i = 0; i < 4;i++) {
            ndata.r = data.r + dr[i];
            ndata.c = data.c + dc[i];
            ndata.time = data.time + 1;
 
            // 1~R, 1~C
            if (ndata.r < 1 || ndata.r > r) continue;
            if (ndata.c < 1 || ndata.c > c) continue;
            if (map[ndata.r][ndata.c] == -1) continue;
            if (map[ndata.r][ndata.c] == 1) continue;
			map[ndata.r][ndata.c] =1; 
            Enqueue(&ndata);
        }
    }

	for(int i=1; i<=r; i++){
		for (int j=1 ; j<=c; j++){
			if (map[i][j] !=0) cnt ++;  
		}
	}
	if (cnt ==r*c) return ndata.time-1;
	else return -1; 
}
 
int main(void) {
    Input_Data();
    printf("%d\n",BFS());
    return 0;
}