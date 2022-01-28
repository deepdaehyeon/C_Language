#include <stdio.h>
  
#define MAX_N (100000)
  
int N;
long long M;
typedef struct
{
    int F;
    int S;
}FOOD;
FOOD food[MAX_N];
  
void Input_Data(void)
{
    int i;
    scanf("%d %lld", &N, &M);
    for (i = 0; i < N; i++)
    {
        scanf("%d %d", &food[i].F, &food[i].S);
    }
}
  
int Check(int s)
{
    int i;
    long long sum_F = 0;
    for (i = 0; i < N; i++)
    {
        if (food[i].S > s) sum_F = 0;
        else
        {
            sum_F += food[i].F;
            if (sum_F >= M) return 1;
        }
    }
    return 0;
}
  
int Get_Solution(void)
{
    int s, e, m;
    int sol = -1;
    s = 0; e = 1000000000;
    while (s <= e)
    {
        m = (s + e) / 2;
        if (Check(m))
        {
            sol = m;
            e = m - 1;
        }
        else s = m + 1;
    }
    return sol;
}
  
int main(void)
{
  
    Input_Data();
  
    printf("%d\n", Get_Solution());
  
    return 0;
}