#include <stdio.h>

#define MAX_N (200000)

int N;
int num[MAX_N + 1];

void Input_Data(void)
{
	int i;
	scanf("%d",  &N);
	for (i = 0; i < N; i++)
	{
		scanf(" %d",  &num[i]);
	}
}


int counting(int d){
	int ub, lb; 
	int m, s=0, e= N-1;
	while(s<=e){
		m = (s+e)/2;
		if (d == num[m]) {
			ub = m; 
			lb = m;
			while(num[ub] == d){
				ub ++;  
			}
			while(num[lb] == d){
				lb --;  
			}
			
			return ub-lb -1 ; 
		}
		else if (d> num[m]) s = m+1; 
		else e = m-1;  
	}
	return 0; 
}


int main(void)
{
	int i,  T,  d;
	Input_Data();

	scanf("%d",  &T);
	for (i = 0; i < T; i++)
	{
		scanf("%d",  &d);
		printf("%d ", counting(d));
	}
	return 0;
}