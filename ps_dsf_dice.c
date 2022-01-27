#include <stdio.h>
#define MAX_N (5)
 
int N, M;
 
int dice[MAX_N]; // dice[n] : n 순서에 던진 주사위의 숫자!
int flag[7]; // flag[숫자] : (현재 발전 중인)경우의 수에서 숫자의 선택 여부!
 
void Dice1(int n) {
    int i;
    if (n >= N) {
        for (i = 0; i < N; i++) printf("%d ", dice[i]);
        printf("\n");
        return;
    }
 
    for (i = 1; i <= 6;i++) {
        dice[n] = i;
        Dice1(n + 1);
    }
}
 
void Dice2(int n, int s) {
    int i;
 
    if (n >= N) {
        for (i = 0; i < N; i++) printf("%d ", dice[i]);
        printf("\n");
        return;
    }
 
    for (i = s; i <= 6;i++) {
        dice[n] = i;
        Dice2(n+1, i);
    }
}
 
void Dice3(int n) {
    int i;
 
    if (n >= N) {
        for (i = 0; i < N; i++) printf("%d ", dice[i]);
        printf("\n");
        return;
    }
 
    for (i = 1; i <= 6;i++) {
        if (flag[i]) continue;
         
        dice[n] = i;
        flag[i] = 1;
        Dice3(n + 1);
        flag[i] = 0;
    }
}
 
int main(void) {
    scanf("%d %d", &N, &M);
 
    switch (M) {
    case 1: Dice1(0); break;
    case 2: Dice2(0, 1); break;
    case 3: Dice3(0);  break;
    }
 
    return 0;
}