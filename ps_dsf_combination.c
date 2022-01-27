#include <stdio.h>
 
int T; 
int N, K; 
int di[21]; 
int flag; 

void inputData(){
    scanf(" %d %d", &N, &K);
    for (int i=0; i<N; i++){
        scanf(" %d", &di[i]);
    }
}

void comb(int i, int sum){
    if (flag==1) return; 

    for(int j=i+1; j<N; j++){
        int nsum = sum +di[j];
        if (nsum == K){
            flag = 1; 
        } 
        else comb(j, nsum);
    }
}

void solve(){
    flag =0; 
    comb(-1,0);
    if (flag ==0) printf("NO\n");
    else printf("YES\n");
}

int main(void)
{
    scanf("%d ", &T);
    for(int i=0; i<T; i++){
        inputData();
        solve();
    }
    return 0;
}