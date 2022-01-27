#include <stdio.h>
#define MAXN (11)
int N;
int flag[MAXN]; 

int map[MAXN][MAXN];
int ans =1000000000; 

void InputData(void){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            scanf(" %d", &map[i][j]);
        }
    }
}

void build(int i, int sum){
    int nsum; 
    if (i==N){
        if (sum <ans) ans = sum; 
    }

    for(int j=0; j<N; j++){
        if(flag[j]) continue; 
        nsum = sum + map[i][j];
        flag[j] =1; 
        build(i+1, nsum);
        flag[j] =0; 
    }
}


void solve(){
    build(0,0);
}


int main(void){

    InputData();//입력받는 부분
    solve();
    printf("%d\n", ans);//출력하는 부분
    return 0;
}