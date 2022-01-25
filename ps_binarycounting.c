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

int bnsearch_lower( int s, int e, int d){
	
	int m, sol=-1 ; 
	while(s<=e){
		m = (s+e)/2; 
		if (num[m] >= d){
			sol =m;
			e = m-1;
		}
		else s = m+1;
	}
	return sol;

}

int bnsearch_upper( int s, int e, int d){
	int m, sol=-1 ; 
	while(s<=e){
		m = (s+e)/2; 
		if (num[m] <= d){
			sol =m;
			s = m+1;
		}
		else e = m-1;
	}
	return sol;
}


int solve(int d){
	int ub, lb; 
	int cnt=0; 
	int m, s=0, e= N-1;
	lb = bnsearch_lower(s, e, d);
	if (lb != -1 && num[lb] <= d) {
		ub = bnsearch_upper(s, e,d);
		cnt = ub-lb+1; 
	}
	return cnt; 
}


int main(void)
{
	int i,  T,  d;
	Input_Data();
	scanf("%d",  &T);
	for (i = 0; i < T; i++)
	{
		scanf("%d",  &d);
		printf("%d ", solve(d));
	}
	return 0;
}