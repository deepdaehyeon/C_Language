#include <stdio.h>
#define max (100+2)
#define maxq (10000*10)

int n; 
int er,ec; 
int map[max][max];
int chk[max][max];

int wp,rp; 

typedef struct {
    int r;
    int c;  
    int power;
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
	scanf("%d %d", &er, &ec);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf(" %d",&map[i][j]);
        }
    }
}

int climing(int s, int e){
    if (s==e) return 0; 
    if (s>e) return s-e; 
    else return (e-s)*(e-s); 
}


int bfs(){
    QUEUE data, ndata; 
    int i ; 
    int dc[] = {0,0,1,-1};
    int dr[] = {1,-1,0,0};

    data.c = 0; 
    data.r = 0;
    data.power = 0; 
    Enqueue(&data);

    while(!Empty()) {
        Dequeue(&data);
        if (chk[data.r][data.c] != data.power) continue; 
        for (i=0; i<4; i++){
            ndata.c = data.c + dc[i];
            ndata.r = data.r + dr[i];
            if (ndata.c <0 || ndata.c >n+1 ) continue; 
            if (ndata.r <0 || ndata.r >n+1 ) continue; 

            ndata.power = data.power + climing(map[data.r][data.c], map[ndata.r][ndata.c]);

            if (chk[ndata.r][ndata.c] !=0 && chk[ndata.r][ndata.c] <= ndata.power) continue; 
            Enqueue(&ndata); 
            chk[ndata.r][ndata.c] = ndata.power; 
        }
    }
    return chk[er][ec]; 
}


int main(void)
{
	inputData();
	printf("%d\n", bfs());
	return 0;
}