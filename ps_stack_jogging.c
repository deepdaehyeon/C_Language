#include <stdio.h> 
#include <string.h> 


int a[100000+10];
int stack[100000+10];
int sptr= -1;
int n; 
int sol; 

void inputData(){
    int tmp; 
    scanf("%d ", &n); 
    for(int i=0; i<n; i++){
        scanf(" %d %d", &tmp, &a[i]);
    }
}

void solve(){
    stack[++sptr] = a[0];
    for(int i=1; i<n; i++){
        if(a[i] < stack[sptr]){
            stack[sptr] = a[i];
        }
        else{
            stack[++sptr] = a[i];
        }
    }
    sol = sptr; 
}

int main (){
    inputData(); 
    solve();
    printf("%d", sol);
    return 0; 
}

