#include <stdio.h>

#define MAX_N (50000)

int N;
int num[MAX_N + 1];

void Input_Data(void)
{
	int i;
	scanf("%d",  &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d",  &num[i]);
	}
}


int bnsearch(int s, int e, int d){
  while(s<=e){
    int m = (s+e)/2;
    if (num[m]==d) return m; 
    else if(num[m]>d) e = m-1; 
    else s= m+1; 
  }
  return -1; 
}


int main(void)
{
	int i,  T,  d,  ret;

	Input_Data();

	scanf("%d",  &T);
	for (i = 0; i < T; i++)
	{
		scanf("%d",  &d);
    ret = bnsearch(1,T,d);
    if (ret ==-1) printf("0\n");
    else  printf("%d\n", ret);
	}

	return 0;
}