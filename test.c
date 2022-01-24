#include <stdio.h> 

int sol,n; 
int queue[80000+10];
int wp, rp; 

void inputData(){
  scanf("%d ",&n);
  for(int i=0; i<n; i++){
    scanf(" %d",&queue[i]);
  }
}

void solve(){
  for(rp=0;rp<n;rp++){
    int i = rp+1; 
    while(queue[i]<queue[rp] && i<n){
      sol++;
      i++;
    }
  }
}


int main(){
  inputData();
  solve();
  printf("%d", sol); 
  return 0; 
}