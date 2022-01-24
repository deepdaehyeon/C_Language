#include <stdio.h> 
#include <string.h> 


int a[80000+10];
int stack[80000+10];
int sptr= 0;

int n; 
int sol; 

void inputData(){
    scanf("%d ", &n); 
    for(int i=0; i<n; i++){
        scanf(" %d", &a[i]);
    }
}

void solve(){
    stack[sptr]= a[0];
    for(int i=1; i<n; i++){
        if (stack[sptr]>a[i]){
            stack[++sptr] = a[i];
        }
        else{
            while(stack[sptr]<=a[i]){
                sol += sptr; 
                sptr --; 
            }
            stack[++sptr] = a[i];
        }
    }
}

int main (){
    inputData(); 
    solve();
    printf("%d", sol);
    return 0; 
}

