#include <stdio.h>
#include <stdlib.h>

int n, m; 
int a[10000+1];


void Input_Data(void)
{
	scanf("%d ", &n);
	for(int i=1; i<=n; i++){
		scanf(" %d", &a[i]);
	}
	scanf("%d", &m);
}

int comp(const void *a, const void * b){
	int num1 = *(int *)a; 
	int num2 = *(int *)b; 
	return num1-num2;
}

int solve(){
	int k; 
	qsort(a, n+1, sizeof(int), comp);
	
	a[0] = 0; 
	for(int i=0; i<n; i++){
		m -=a[i]; 
		k = m/(n-i); 
		if( k <= a[i+1]) return k; 
	}
	return a[n]; 
}


int main(void)
{
	Input_Data();
	printf("%d", solve());
	return 0;
}