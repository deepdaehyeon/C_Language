#include <stdio.h>
#define max (100)
#define maxque (max*max)

int r,c; 
int sr,sc,er,ec; 
char map[max+2][max+2];


typedef struct{
	int r,c; 
	int time;
}QUEUE;

QUEUE que[maxque+1]; 
int rp, wp; 

void enque(QUEUE* p){
	que[wp++] = *p; 
}

void deque(QUEUE* p){
	*p = que[rp++];
}

int empty(){
	return wp==rp; 
}

int chk[max+1][max+1]; 

void inputData(){
	scanf("%d %d", &c, &r);
	scanf("%d %d %d %d", &sc, &sr, &ec, &er);
}


int bfs(){
	QUEUE data, ndata; 
	int dr[]={2,2,-2,-2, 1,1,-1,-1};
	int dc[]={1,-1,1,-1,2,-2,2,-2};

	data.c = sc; 
	data.r = sr; 
	data.time = 0; 
	chk[sr][sc] =1; 
	enque(&data);
    if (sr == er && sc == ec) return 0;

	while(!empty()){
		deque(&data);
		for(int i=0; i<8; i++){
			ndata.r = data.r + dr[i];
			ndata.c = data.c + dc[i];
			ndata.time = data.time +1; 
			if (ndata.r<1 || ndata.r >r) continue; 
			if (ndata.c<1 || ndata.c >c) continue; 
			if (chk[ndata.r][ndata.c] ==1) continue; 
			enque(&ndata); 
			if (ndata.r== er && ndata.c == ec) return ndata.time; 
		}
	}
	return -1; 	
}


int main(void)
{
	inputData();
	printf("%d\n", bfs());
	return 0;
}