#include <stdio.h> 
#include <string.h> 


char str[1000000+10];
char bomb[36];
int bomblen; 
int sptr; 

typedef struct _STACK{
  char ch; 
  int seq;
}STACK; 

STACK stack[1000000+10]; 

void inputData(){
  scanf("%s ", str);
  scanf("%s", bomb);
  bomblen = strlen(bomb);
}

void solve(){
  int last; 
  stack[sptr].ch = str[0];
  stack[sptr].seq = str[0]==bomb[0] ? 0:-1; 

  for(int i=1; str[i]; i++){
    last = stack[sptr].seq; 
    if(str[i] == bomb[last+1]){
      stack[sptr].ch = str[i];
      stack[sptr].seq = last ++;
      if (last == bomblen - 1) sptr -= bomblen; 
    }
    else{
      stack[sptr].ch = str[i];
      stack[sptr].seq = str[i]==bomb[0] ? 0:-1; 
    }
  }
}

void printOutput(){
  if (sptr ==0) printf("FRULA");
  else {
    for(int i=0; i<sptr; i++){
    printf("%c",stack[i].ch);
  }
  }

}

int main (){
  inputData(); 
  solve();
  printOutput();


  return 0; 
}

