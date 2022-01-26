#include <stdio.h>
#define max (100+2)
#define maxq (10000+2)

int n; 
int map[max][max];
int chk[max][max];
int wp,rp; 

typedef struct {
    int r;
    int c;  
    int sum;
} QUEUE; 

QUEUE que[maxq]; 

void Enqueue(QUEUE* p) {
    que[wp++] = *p;
}

void Dequeue(QUEUE *p) {
    *p = que[rp++];
}
 
int Empty(void) {
    return wp == rp;
}

void inputData(){
	scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%1d",&map[i][j]);
        }
    }
}

int bfs(){
    QUEUE data, ndata; 
    int sc=1, sr=1;     
    int dc[] ={0,0,1,-1};
    int dr[] ={1,-1,0,0};

    data.c = sc; 
    data.r = sr;
    data.sum = 0; 
    Enqueue(&data);

    while(!Empty()) {
        Dequeue(&data);
        for (int i=0; i<4; i++){
            ndata.c = data.c + dc[i];
            ndata.r = data.r + dr[i];
            ndata.sum = data.sum + map[ndata.r][ndata.c];
            if (ndata.c <1 || ndata.c >n ) continue; 
            if (ndata.r <1 || ndata.r >n ) continue; 
            if (chk[ndata.r][ndata.c] !=0 && chk[ndata.r][ndata.c] <= ndata.sum) continue; 
            Enqueue(&ndata); 
            chk[ndata.r][ndata.c] = ndata.sum; 
        }
    }
    return chk[n][n]; 
}


int main(void)
{
	inputData();
	printf("%d\n", bfs());
	return 0;
}