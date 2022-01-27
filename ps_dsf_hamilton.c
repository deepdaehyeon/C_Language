#include <stdio.h>
#define MAXN (20)
int N;
int flag[MAXN]; 

int map[MAXN][MAXN];
int ans =0xffff; 

void InputData(void){
    scanf("%d ", &N);
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            scanf(" %d", &map[i][j]);
        }
    }
}

void move(int times, int state, int sum){
    int nsum ; 
    if(times==N-1){
        nsum = sum+ map[state][0];  
        if (ans> nsum) ans = nsum ; 
        return;
    }

    for(int j=1; j<N; j++ ){
        if (flag[j]) continue; 
        if (map[state][j] ==0) continue; 
        flag[j] = 1;
        nsum = sum+ map[state][j]; 
        move(times+1, j, nsum);
        flag[j] = 0; 
    }
}

void solve(){
    move(0,0,0);
}


int main(void){
    InputData();//입력받는 부분
    solve();
    printf("%d\n", ans);//출력하는 부분
    return 0;
}