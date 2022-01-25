#include <stdio.h>
#include <stdlib.h>

int n, m; 
int a[1000000+1];


void Input_Data(void)
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf(" %d", &a[i]);
	}
}

int comp(const void *a, const void * b){
	int num1 = *(int *)a; 
	int num2 = *(int *)b; 
	return -(num1-num2);
}

int solve(){
	int h; 
	a[n] = 0; 
	qsort(a, n+1, sizeof(int), comp);
	for (int i=0; i<n; i++){
		if (m <= (a[i]-a[i+1])*(i+1)) 
		{	
			h = a[i]-m/(i+1);
			if (m %(i+1) !=0) h--;  
			return h;
		}
		m -= (a[i]-a[i+1])*(i+1); 
	}
	return 0; 

}


int main(void)
{
	Input_Data();
	printf("%d", solve());
	return 0;
}