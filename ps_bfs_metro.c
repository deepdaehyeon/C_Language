#include <stdio.h>
#define max (101)
#define maxq (10000)

int n, m; 
int dist[max][max];
int chk[max];
int prev[max];
int wp,rp; 

typedef struct {
    int s; 
    int time;
} QUEUE; 

QUEUE que[maxq]; 

void enque(QUEUE* p){
	que[wp++] = *p; 
}

void deque(QUEUE* p){
	*p = que[rp++];
}

int empty(){
	return wp==rp; 
}

void inputData(){
	scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf(" %d",&dist[i][j]);
        }
    }
}


void trace(int a){
    if (a !=0){
        trace(prev[a]);
        printf("%d ", a);
    } 
}

int bfs(){
    QUEUE data, ndata; 
    data.s =1; 
    data.time = 0; 
    enque(&data);

    while(!empty()){
        deque(&data); 
        for (int i=2; i<=n; i++){
            ndata.s = i; 
            ndata.time = data.time + dist[data.s][ndata.s] ;
            if (chk[i] != 0 && chk[i] <= ndata.time) continue; 
            enque(&ndata); 
            chk[i] = ndata.time; 
            prev[i] = data.s; 
        }
    }
    return chk[m];
}


int main(void)
{
	inputData();
	printf("%d\n", bfs());
    trace(m);
	return 0;
}