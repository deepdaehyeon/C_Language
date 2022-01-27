#include <stdio.h>
#define MAXN (20)
int N;
int sl, sr;
int M;
int seq[MAXN+10];
int ans =1000000000; 

void InputData(void){
    scanf("%d", &N);
    scanf("%d %d", &sl, &sr);
    scanf("%d", &M);
    for (int i=0; i<M; i++){
        scanf("%d", &seq[i]);
    }
}

void move(int l, int r, int i, int sum){
    if (i==M) {
        if (sum< ans){
            ans = sum; 
        }
        return ; 
    }

    if(seq[i]<l) {
        sum += l-seq[i];
        move(seq[i], r, i+1, sum); 
    }
    else if (seq[i]>r){
        sum += seq[i]-r;
        move(l, seq[i],i+1, sum); 
    }
    else {
        move(l, seq[i],i+1, sum+ r-seq[i]); 
        move(seq[i], r, i+1, sum+ seq[i]-l); 
    }
}

void solve(){
    move(sl,sr,0,0);
}


int main(void){

    InputData();//입력받는 부분
    solve();
    printf("%d\n", ans);//출력하는 부분
    return 0;
}