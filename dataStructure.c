#pragma warning(disable: 4996)
#pragma warning(disable: 4477)
#pragma warning(disable: 4313)

// 1-1 sequence data 

#if 0

// 1-1 
#if 0

/***********************************************************/
// [1-1.1] ������ �𵨸�
/***********************************************************/

#if 1

#include <stdio.h>
#include <string.h>

typedef struct _score 
{
	int id;
	int jumsu;
	char name[10];
}SCORE;

#define MAX_ST		20

SCORE exam[MAX_ST];

int Print_All_Data(void);
int Print_Data(int no);
int Count_Data(void);
int Create_Data(SCORE * p);
int Insert_Data(SCORE * p);
int Delete_Data(int id);
int Search_Complete_Data(SCORE * p);
int Search_Data(int n, SCORE * p, int (*comp)(SCORE * x, SCORE* y));
int Compare_Id(SCORE * x, SCORE* y);
int Compare_Name(SCORE * x, SCORE* y);
int Compare_Jumsu(SCORE * x, SCORE* y);
int Sort_Bubble(SCORE * d, int order, int (*comp)(SCORE * x, SCORE * y));
int Sort_Select(SCORE * d, int order, int (*comp)(SCORE * x, SCORE * y));
int Sort_Insertion(SCORE * d, int order, int (*comp)(SCORE * x, SCORE * y));
int Insert_and_Sort_Data(SCORE * p);
int Copy_Data(int n, SCORE * p);
int Copy_All_Data(SCORE * p, int max);
int Print_All_Buffer(SCORE * d, int max);
int Sort_Quick(SCORE *d, int order, int m, int n, int (*comp)(SCORE * x, SCORE * y));

SCORE test[10] = {{10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
                               {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}}; 

void Make_Test_Data(int n)
{
	int i; 

	for(i=0; i<n; i++)
	{
		exam[i] = test[i];
	}
}

#endif

/***********************************************************/
// [1-1.2] �迭�� ��� �ڷ� �μ�
/***********************************************************/

#if 1

int Print_All_Data(void)
{
	int i;
	for (i =0; i<MAX_ST; i++){
		if (exam[i].id==0){
			break; 
		}
		printf(" ID = %d, NAME = %s, SCORE = %d\n", exam[i].id, exam[i].name, exam[i].jumsu);
	}
	return i; 
}

#endif

/***********************************************************/
// [1-1.3] Ư�� ��ҹ�ȣ�� �����͸� �μ�
/***********************************************************/

#if 1

int Print_Data(int no)
{
	if (exam[no].id ==0) return -1; 
	printf(" ID = %d, NAME = %s, SCORE = %d\n", exam[no].id, exam[no].name, exam[no].jumsu);
	return 1; 
}

#endif

/***********************************************************/
// [1-1.4] �迭�� �ִ� ��� �ڷ��� ���� ���
/***********************************************************/

#if 1

int Count_Data(void)
{
	int i;
	for (i =0; i<MAX_ST; i++){
		if (exam[i].id==0){
			break; 
		}
	}
	return i; 
}

#endif

#if 1

int Create_Data(SCORE * p)
{

	printf("사번입력 :");
	scanf(" %d", &p->id);
	printf("이름 :");
	scanf(" %s", p->name);
	printf("점수 :");
	scanf(" %d", &p->jumsu);
	return 1; 
}

#endif

#if 0

int main(void)
{
	int i;

	for(i=0; i<3; i++)
	{
		Create_Data(&exam[i]);
		printf("\nCount = %d\n", Count_Data());
		printf("Print Result = %d\n", Print_Data(i));
		printf("Printed Data Count = %d\n", Print_All_Data());
	}
}

#endif

/***********************************************************/
// [1-1.6] ������ �ϳ��� �����Ͽ� �迭�� �߰��� �����ϴ� �Լ�
/***********************************************************/

#if 1

int Insert_Data(SCORE * p)
{
	int i; 
	for(i=0; i<MAX_ST; i++){
		if (exam[i].id !=0){
			if (exam[i].id == p->id){
				return -2; 
			}
		}
		else {
			exam[i] = *p;
			return i;
		}
	}
	return -1; 
}

#endif

#if 0

int main(void)
{
	SCORE tmp;

	do
	{
		Create_Data(&tmp);
		printf("\n\nInsert Result = %d\n", Insert_Data(&tmp));
		printf("Printed Data Count = %d\n", Print_All_Data());
	}while(getch() != 'x');
}

#endif

/***********************************************************/
// [1-1.7] ������ ����� ������ ���� ����� �����ϴ� �Լ�
/***********************************************************/

#if 1

int Delete_Data(int id)
{
	int i ; 
	int idx; 
	for(i=0; i<MAX_ST; i++){
		if (exam[i].id ==0){
			break; 
		}
		else if (exam[i].id==id){
			idx = i; 
			while (i+1<MAX_ST && exam[i+1].id !=0 ){
				exam[i]=exam[i+1];
				i++; 
			}
			exam[i].id = 0; 

			return idx; 
		}
	}
	return -1; 
}

#endif

#if 0

int main(void)
{
	int i;
	int x; 

	Make_Test_Data(5);
	printf("Printed Data Count = %d\n", Print_All_Data());

	while(1)
	{
		scanf("%d", &i);
		printf("\n\nDelete Element = %d\n", Delete_Data(i));
		printf("Printed Data Count = %d\n", Print_All_Data());
	}
}

#endif

/***********************************************************/
// [1-1.8] ��� ����� ��ġ�ϴ� �����͸� Ž���ϴ� �Լ�
/***********************************************************/

#if 1

int Search_Complete_Data(SCORE * p)
{
	int i; 
	for (i=0; i<MAX_ST; i++){
		if (memcmp(&exam[i], p, sizeof(exam[0]))==0){
			return i; 
		}
	}
	return -1; 
}

#endif

#if 0

int main(void)
{
	SCORE tmp;

	Make_Test_Data(8);
	printf("Printed Data Count = %d\n", Print_All_Data());

	while(1)
	{
		printf("\ninsert data\n");
		Create_Data(&tmp);
		printf("\n\nSearched Element = %d\n", Search_Complete_Data(&tmp));
		printf("Printed Data Count = %d\n", Print_All_Data());
	}
}

#endif

/***********************************************************/
// [1-1.9] ���ϴ� ����� ���� �����͸� Ž���ϴ� �Լ�, �񱳸� ���� call back �Լ��� ����
/***********************************************************/

#if 1

int Search_Data(int n, SCORE * p, int (*comp)(SCORE * x, SCORE* y))
{
	int i; 
	for (i=n;i<MAX_ST;i++){
		if(exam[i].id ==0) break; 
		else if(comp(&exam[i], p)==0){
			return i; 
		}
	}
	return i ==n? -2 : -1; 
}

int Compare_Id(SCORE * x, SCORE* y)
{
	return (x->id - y->id) ;
}

int Compare_Name(SCORE * x, SCORE* y)
{
	return strcmp(x->name, y->name);
}

int Compare_Jumsu(SCORE * x, SCORE* y)
{
	return (x->jumsu - y->jumsu) ;
}

#endif

#if 0

int main(void)
{
	int n;
	SCORE tmp;

	Make_Test_Data(8);
	printf("Printed Data Count = %d\n", Print_All_Data());

	while(1)
	{
		printf("\ninsert data\n");
		Create_Data(&tmp);

		printf("\nSearched Element (ID) = %d\n", n=Search_Data(0, &tmp, Compare_Id));
		Print_Data(n);

		n = 0;

		do
		{
			printf("\nSearched Element (Name) = %d\n", n=Search_Data(n, &tmp, Compare_Name));
			Print_Data(n);
			n++;
		}while(n > 0);

		n = 0;

		do
		{
			printf("\nSearched Element (Jumsu) = %d\n", n=Search_Data(n, &tmp, Compare_Jumsu));
			Print_Data(n);
			n++;
		}while(n > 0);

		printf("\nPrinted Data Count = %d\n", Print_All_Data());

	}
}

#endif

/***********************************************************/
// [1-1.10] �ڷḦ ������Ʈ�� �����ϴ� �Լ�
/***********************************************************/

#if 1

int Sort_Bubble(SCORE * d, int order, int (*comp)(SCORE * x, SCORE * y))
{
	int n,i;
	for (i=0; i<MAX_ST; i++){
		if (d[i].id==0) break;
	} 
	n = i; 
	for (i=0; i<n-1; i++){
		for (int j=0; j<n-i-1; j++){
			if (comp(&d[j], &d[j+1])*order >0){
				SCORE tmp; 
				tmp = d[j];
				d[j] = d[j+1];
				d[j+1] = tmp; 
			}
		}
	}
	return n; 
}

#endif

#if 0

int main(void)
{
	Make_Test_Data(8);
	printf("Printed Data Count = %d\n", Print_All_Data());

	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Bubble(exam, 1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Bubble(exam, -1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Bubble(exam, 1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Bubble(exam, -1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Bubble(exam, 1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Bubble(exam, -1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
}

#endif

/***********************************************************/
// [1-1.11] �ڷḦ ���� ���ķ� �����ϴ� �Լ�
/***********************************************************/

#if 1

int Sort_Select(SCORE * d, int order, int (*comp)(SCORE * x, SCORE * y))
{
	int i,n,j ; 
	SCORE tmp; 
	for (i=0;i<MAX_ST; i++){
		if (d[i].id ==0) break; 
	}
	n =i; 
	for (i=0; i<n ; i++){
		int maxi=0; 
		for (j=1; j<n-i ; j++){
			if(comp( &d[maxi], &d[j]) * order >0 ){
				maxi = j; 
			}
		}
		tmp= d[maxi];
		d[maxi] = d[n-i-1];
		d[n-i-1] = tmp; 
	} 
	return n; 

}

#endif

#if 0

int main(void)
{
	Make_Test_Data(8);
	printf("Printed Data Count = %d\n", Print_All_Data());

	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Select(exam, 1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Select(exam, -1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Select(exam, 1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Select(exam, -1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Select(exam, 1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Select(exam, -1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
}

#endif

/***********************************************************/
// [1-1.12] �ڷḦ ���� ���ķ� �����ϴ� �Լ�
/***********************************************************/

#if 1

int Sort_Insertion(SCORE * d, int order, int (*comp)(SCORE * x, SCORE * y))
{
	int i,j,n ; 
	SCORE tmp; 
	for (i=0;i<MAX_ST; i++){
		if (d[i].id ==0) break; 
	}
	n =i; 

	for(i=1; i<n;i++){
		for (j=0; j<i; j++){
			if (comp(&d[j], &d[i])* order > 0){
				tmp = d[i];
				for (int k=i; k>j;k--){
					d[k] = d[k-1]; 
				}
				d[j] = tmp; 
			break ; 
			}
		}
	} 
	return n; 
}

#endif

#if 0

int main(void)
{
	Make_Test_Data(8);
	printf("Printed Data Count = %d\n", Print_All_Data());

	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Insertion(exam, 1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Insertion(exam, -1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Insertion(exam, 1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Insertion(exam, -1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Insertion(exam, 1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Insertion(exam, -1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
}

#endif

#if 1

int Insert_and_Sort_Data(SCORE * p)
{
	int i, j; 
	SCORE tmp; 

	for (i=0;i<MAX_ST; i++){
		if (exam[i].id ==0)	break;
		if (exam[i].id ==p->id) return -2; 
	}
	if (i==MAX_ST) return -1; 

	for(j=i; j>=1; j--){
		if (p->id - exam[j-1].id <0) break; 
		else exam[j]= exam[j-1];
	}
	exam[j] =*p; 
	return j; 
}

#endif

#if 0

int main(void)
{
	int i;
	SCORE tmp;

	for(i=0; i<sizeof(test)/sizeof(test[0]); i++)
	{
		printf("\n\nInsert = %d\n", Insert_and_Sort_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
	}

	tmp.id = 4;
	printf("\n\nInsert = %d\n", Insert_and_Sort_Data(&tmp));
	printf("Printed Data Count = %d\n", Print_All_Data());
}

#endif

/***********************************************************/
// [1-1.14] ������ �����͸� ����ü�� �����Ͽ� �ִ� �Լ� 
/***********************************************************/

#if 1

int Copy_Data(int n, SCORE * p)
{
	if (exam[n].id ==0){
		return -1; 
	}
	else {
		*p = exam[n];
		return 1; 
	}
}

#endif

#if 0
int main(void)
{
	SCORE tmp;

	Make_Test_Data(8);
	printf("Printed Data Count = %d\n", Print_All_Data());

	printf("Data Copy Result = %d\n", Copy_Data(3, &tmp));
	printf("ID: %d, Name: %s, Score: %d\n", tmp.id, tmp.name, tmp.jumsu);
	printf("Data Copy Result = %d\n", Copy_Data(9, &tmp));
}

#endif

#if 1

int Print_All_Buffer(SCORE * d, int max)
{
	int i; 
	for (i=0; i<max; i++){
		if(Print_Data(i)==-1){
			break; 
		}
	}
	return i; 
}

#endif

#if 0

int main(void)
{
	Make_Test_Data(10);
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("All Buffer Print = %d\n", Print_All_Buffer(exam, 10));
	printf("All Buffer Print = %d\n", Print_All_Buffer(exam, 4));
}

#endif

#if 1

int Copy_All_Data(SCORE * p, int max)
{
	int i; 
	for (i=0; i<max; i++){
		if (exam[i].id ==0) break; 
		p[i] = exam[i];
	}
	return i;
}

#endif

#if 0

SCORE tmp[MAX_ST];

int main(void)
{
	Make_Test_Data(10);
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("All Data Copy Result = %d\n", Copy_All_Data(tmp, 10));
	printf("All Buffer Print = %d\n", Print_All_Buffer(tmp, 10));
	printf("Sorted Data Count = %d\n", Sort_Insertion(tmp, 1, Compare_Jumsu));
	printf("All Buffer Print = %d\n", Print_All_Buffer(tmp, 10));
}

#endif

/***********************************************************/
// [1-1.17] Quick Sort �Լ� ����
/***********************************************************/

#if 1


int Sort_Quick(SCORE *d, int order, int m, int n, int (*comp)(SCORE * x, SCORE * y))
{
	int pivot, less, th;
     
    while (m<=n) {
        if (d[n].id != 0) break;
        n--;
    }
    if (m >= n) return 1;
     
    for (pivot = n, less = m, th = m; pivot > less;less++) {
        if (order * comp(&d[less], &d[pivot]) < 0) {
            if (less != th) {
                SCORE temp;
                temp = d[less];
                d[less] = d[th];
                d[th] = temp;
            }
            th++;
        }
    }
 
    if (pivot != th) {
        SCORE temp;
        temp = d[pivot];
        d[pivot] = d[th];
        d[th] = temp;
    }
 
    Sort_Quick(d, order, m, th-1, comp); // m ~ th-1
    Sort_Quick(d, order, th+1, n, comp); // th + 1 ~ n;
    return n - m + 1;
}

#endif

#if 0

int main(void)
{
	Make_Test_Data(8);
	printf("Printed Data Count = %d\n", Print_All_Data());

	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Quick(exam, 1, 0, MAX_ST-1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Quick(exam, -1, 0, MAX_ST-1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Quick(exam, 1, 0, MAX_ST-1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Quick(exam, -1, 0, MAX_ST-1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Quick(exam, 1, 0, MAX_ST-1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Quick(exam, -1, 0, MAX_ST-1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
}


#endif 

#endif 
#endif 

// 1-2 linked data

#if 0
#if 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

typedef struct _score 
{
	int id;
	int jumsu;
	char name[10];
	struct _score  * next; 
}SCORE;

SCORE Head;

#define MAX_ST		20

SCORE exam[MAX_ST];


int Print_All_Data(void);
int Print_Data(int no);
int Count_Data(void);
int Create_Data(SCORE * p);
int Insert_Data(SCORE * p);
int Insert_Node(SCORE * head, SCORE * d);
int Print_All_Node(SCORE * head);
SCORE * Search_Id_Node(SCORE * head, int id);
int Count_Node(SCORE * head);
int Print_Node(SCORE * head, int id); 
int Delete_Node(SCORE * head, int id);
int Copy_All_Node(SCORE * head, SCORE * buf);
int Count_Name_Node(SCORE * head, char * name);
int Count_Score_Node(SCORE * head, int jumsu);
int Copy_Name_Node(SCORE * head, char * name, SCORE * buf);
int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf);

SCORE test[MAX_ST] = {{10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
                               {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}, \
                               {15, 90, "ki"}, {11, 20, "kong"}, {14, 40, "shin"}, {12, 50, "son"}, {17, 48, "lee"}, \
                               {20, 100, "min"}, {19, 80, "you"}, {13, 45, "song"}, {16, 54, "no"}, {18, 100, "yang"}}; 

void Make_Test_Data(int n)
{
	int i;

	for(i=0; i<n; i++)
	{
		exam[i] = test[i];
	}
}

#endif

#if 1

int Create_Data(SCORE * p)
{
	printf("\n����� �Է��Ͻÿ� => ");
	scanf("%d", &p->id);
	printf("�̸��� �Է��Ͻÿ� => ");
	scanf("%s", p->name);
	printf("������ �Է��Ͻÿ� => ");
	scanf("%d", &p->jumsu);
	p->next = (SCORE *)0x0;

	return 1;
}

int Print_All_Data(void)
{
	int i;

	printf("Head.next = 0x%.8X\n", Head.next);

	for(i=0; i<MAX_ST; i++)
	{
		if(exam[i].id == 0) break;
		printf("[%d] addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", i, &exam[i], exam[i].id, exam[i].name, exam[i].jumsu, exam[i].next);
	}

	return i;
}

int Print_Data(int no)
{
	if(exam[no].id == 0) return -1;
	printf("[%d] addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", no, &exam[no], exam[no].id, exam[no].name, exam[no].jumsu, exam[no].next);
	return 1;
}

int Count_Data(void)
{
	int i;

	for(i=0; i<MAX_ST; i++)
	{
		if(exam[i].id == 0) break;
	}

	return i;
}

int Insert_Data(SCORE * p)
{
	int i;

	for(i=0; i<MAX_ST; i++)
	{
		if(exam[i].id == 0) 
		{
			exam[i] = (*p);
			return i;
		}

		if(exam[i].id == p->id)
		{
			return -2;
		}
	}

	return -1;
}

#endif


#if 1

int Insert_Node(SCORE * head, SCORE * d)
{	
	SCORE * prev=head;
	while(prev->next){
		if(d->id < prev->next->id) break;
		if(d->id == prev->next->id) return -2; 
		prev= prev->next;
	} 

	d-> next = prev-> next; 
	prev->next = d ; 
	return 1; 
}

#endif

#if 0

int main(void)
{
	int i;
	int r;

	for(i=0; i<8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
		printf("Printed Data Count = %d\n", Print_All_Data());
	}
}

#endif

#if 1

int Print_All_Node(SCORE * head)
{
	SCORE * tmp = head; 
	int i=0; 
	while(tmp->next){
		tmp = tmp->next;
		printf("[%d] addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", i, tmp, tmp->id, tmp->name, tmp->jumsu, tmp->next);
		i++; 
	}
	return i; 
}

SCORE * Search_Id_Node(SCORE * head, int id)
{
	SCORE * node = head->next; 
	while(node){
		if (node->id == id) return node; 
		node = node -> next ;
	}
	return (SCORE *) 0; 
}
#endif

#if 0

int main(void)
{
	int i;
	int r;
	SCORE * p; 

	for(i=0; i<8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
		printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	}

	printf("Searched Node Address = 0x%.8X\n", p = Search_Id_Node(&Head, 8));
	
	if(p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", p->id, p->name, p->jumsu, p->next);
	}

	printf("Searched Node Address = 0x%.8X\n", p = Search_Id_Node(&Head, 7));

	if(p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", p->id, p->name, p->jumsu, p->next);
	}
}

#endif


#if 1

int Count_Node(SCORE * head)
{
	SCORE * node = head;
	int i=0 ;  
	while(node->next){
		i++;
		node = node->next; 
	}
	return i;
}

#endif

#if 1

int Print_Node(SCORE * head, int id)
{
	SCORE * tmp = Search_Id_Node(head, id);
	if (tmp){
	printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", tmp, tmp->id, tmp->name, tmp->jumsu, tmp->next);
	return 1; 
	}
	return 0;
}

#endif

#if 0

int main(void)
{
	int i;
	int r;

	for(i=0; i<8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
		printf("Printed Node Count = %d\n", Print_All_Node(&Head));
		printf("Node Count = %d\n", Count_Node(&Head));
	}

	printf("Print Node Result = %d\n", Print_Node(&Head, 8));
	printf("Print Node Result = %d\n", Print_Node(&Head, 7));
}

#endif

#if 1

int Delete_Node(SCORE * head, int id)
{
	SCORE * prev =  head; 
	while(prev->next){
		if(prev-> next-> id == id){
			prev->next -> id =0; 
			prev -> next = prev->next->next ; 
			return 1;
		}
		prev = prev-> next ;
	}
	return -1; 

}

#endif

#if 0

int main(void)
{
	int i;
	int r;

	for(i=0; i<8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 8)); 
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 7)); 
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 1)); 
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 10)); 
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
}

#endif

#if 1

int Copy_All_Node(SCORE * head, SCORE * buf)
{
	SCORE * node = head->next; 
	int i=0;
	while(node){
		buf[i] = *node;  
		buf[i].next = &buf[i+1]; 
		i++;
		node = node->next;
	}
	buf[i-1].next = (SCORE *) 0;
	if (i==0){
		return -1; 
	}
	return 1; 
}

#endif

#if 0

int main(void)
{
	int i;
	int r;
	SCORE * p;
	SCORE new_head;

	for(i=0; i<8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Node Count = %d\n", r = Count_Node(&Head)); 

	p = calloc(r, sizeof(SCORE));
	printf("Copy All Node Result = %d\n", Copy_All_Node(&Head, p)); 
	new_head.next = p;
	printf("Printed Node Count = %d\n", Print_All_Node(&new_head));
	free(p);
}

#endif

#if 1

int Count_Name_Node(SCORE * head, char * name)
{
	int n = 0;

	for(;;)
	{
		if(head->next == (SCORE *)0x0) return n;
		if(!strcmp(head->next->name, name)) n++;
		head = head -> next;		
	}
}

int Count_Score_Node(SCORE * head, int jumsu)
{
	int n = 0;

	for(;;)
	{
		if(head->next == (SCORE *)0x0) return n;
		if(head->next->jumsu == jumsu) n++;
		head = head -> next;		
	}
}

int Copy_Name_Node(SCORE * head, char * name, SCORE * buf)
{
	SCORE * node = head->next; 
	int i=0;
	while(node){
		if (strcmp(node->name, name)==0){
			buf[i] = *node; 
			buf[i].next = &buf[i+1]; 
			i++;
		}
		node = node->next;
	}
	buf[i-1].next = (SCORE *) 0;
	return i; 
}

int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf)
{
	SCORE * node = head->next; 
	int i=0;
	while(node){
		if (node->jumsu == jumsu){
			buf[i] = *node; 
			buf[i].next = &buf[i+1]; 
			i++;
		}
		node = node->next;
	}
	buf[i-1].next = (SCORE *) 0;
	return i; 

}

#endif

#if 0

int main(void)
{
	int i;
	int r;
	SCORE * p;
	SCORE new_head;

	for(i=0; i<20; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	
	printf("Name Node Count = %d\n", r = Count_Name_Node(&Head, "lew"));
	p = calloc(r, sizeof(SCORE));
	printf("Copy Name Node Result = %d\n", Copy_Name_Node(&Head, "lew", p));
	new_head.next = p;
	printf("Printed Node Count = %d\n", Print_All_Node(&new_head));
	free(p);

	printf("Score Node Count = %d\n", r = Count_Score_Node(&Head, 100)); 
	p = calloc(r, sizeof(SCORE));
	printf("Copy Score Node Result = %d\n", Copy_Score_Node(&Head, 100, p)); 
	new_head.next = p;
	printf("Printed Node Count = %d\n", Print_All_Node(&new_head));
	free(p);
}

#endif




#endif

// 1-3 다중 link
#if 0

#if 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

typedef struct _score 
{
	int id;
	int jumsu;
	char name[10];
	struct _score  * nid; 
	struct _score  * njumsu; 
}SCORE;

SCORE Head;

#define MAX_ST		20

SCORE exam[MAX_ST];

int Print_All_Data(void);
int Print_Data(int no);
int Count_Data(void);
int Create_Data(SCORE * p);
int Insert_Data(SCORE * p);
int Insert_Node(SCORE * head, SCORE * d);
int Print_All_Node(SCORE * head);
int Print_All_Id_Node(SCORE * head);
int Print_All_Jumsu_Node(SCORE * head);
SCORE * Search_Id_Node(SCORE * head, int id);
SCORE * Search_Jumsu_Node(SCORE * head, int jumsu);
int Count_Node(SCORE * head);
int Print_Id_Node(SCORE * head, int id); 
int Print_Jumsu_Node(SCORE * head, int jumsu); 
int Delete_Id_Node(SCORE * head, int id);
void Delete_One_Jumsu_Node(SCORE * head, int jumsu, int id);
int Delete_Jumsu_Node(SCORE * head, int id);
int Copy_All_Node(SCORE * head, SCORE * buf);
int Count_Name_Node(SCORE * head, char * name);
int Count_Score_Node(SCORE * head, int jumsu);
int Copy_Name_Node(SCORE * head, char * name, SCORE * buf);
int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf);

SCORE test[MAX_ST] = {{10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
                               {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}, \
                               {15, 90, "ki"}, {11, 20, "kong"}, {14, 40, "shin"}, {12, 50, "son"}, {17, 48, "lee"}, \
                               {20, 100, "min"}, {19, 80, "you"}, {13, 45, "song"}, {16, 54, "no"}, {18, 100, "yang"}}; 

void Make_Test_Data(int n)
{
	int i;

	for(i=0; i<n; i++)
	{
		exam[i] = test[i];
	}
}

int Create_Data(SCORE * p)
{
	printf("\n����� �Է��Ͻÿ� => ");
	scanf("%d", &p->id);
	printf("�̸��� �Է��Ͻÿ� => ");
	scanf("%s", p->name);
	printf("������ �Է��Ͻÿ� => ");
	scanf("%d", &p->jumsu);
	p->nid = (SCORE *)0x0;
	p->njumsu = (SCORE *)0x0;

	return 1;
}

int Print_All_Data(void)
{
	int i;

	printf("Head.nid = 0x%.8X, Head.njumsu = 0x%.8X\n", Head.nid, Head.njumsu);

	for(i=0; i<MAX_ST; i++)
	{
		if(exam[i].id == 0) break;
		printf("[%d] addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X, njumsu = 0x%.8X\n", i, &exam[i], exam[i].id, exam[i].name, exam[i].jumsu, exam[i].nid, exam[i].njumsu);
	}

	return i;
}

int Print_Data(int no)
{
	if(exam[no].id == 0) return -1;
	printf("[%d] addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X, njumsu = 0x%.8X\n", no, &exam[no], exam[no].id, exam[no].name, exam[no].jumsu, exam[no].nid, exam[no].njumsu);
	return 1;
}

int Count_Data(void)
{
	int i;

	for(i=0; i<MAX_ST; i++)
	{
		if(exam[i].id == 0) break;
	}

	return i;
}

int Insert_Data(SCORE * p)
{
	int i;

	for(i=0; i<MAX_ST; i++)
	{
		if(exam[i].id == 0) 
		{
			exam[i] = (*p);
			return i;
		}

		if(exam[i].id == p->id)
		{
			return -2;
		}
	}

	return -1;
}

#endif

#if 1
int Insert_Node(SCORE * head, SCORE * d)
{
	SCORE * prev=head; 
	while (prev->nid){
		if (d ->id < prev->nid-> id ){
			break; 
		}
		if (d ->nid == prev -> nid) return -2; 
		prev = prev->nid; 

	}
	d ->nid = prev->nid; 
	prev -> nid = d; 

	prev = head;
	while (prev->njumsu){
		if (d ->jumsu < prev->njumsu-> jumsu ){
			break; 
		}
		prev = prev->njumsu; 

	}
	d ->njumsu = prev->njumsu; 
	prev -> njumsu = d;

	return 1; 
}

#endif

#if 0

int main(void)
{
	int i;
	int r;

	for(i=0; i<8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
		printf("Printed Data Count = %d\n", Print_All_Data());
	}
}
#endif

#if 1

int Print_All_Node(SCORE * head)
{
	Print_All_Id_Node(head);
	return Print_All_Jumsu_Node(head);
}

int Print_All_Id_Node(SCORE * head)
{
	SCORE * node=head->nid; 
	int no=0; 
	while(node){
		printf("[%d] addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X, njumsu = 0x%.8X\n", no, node, node->id, node->name, node->jumsu, node->nid, node->njumsu); 
		node = node->nid;
		no ++; 
	}
	return no; 
}

int Print_All_Jumsu_Node(SCORE * head)
{
	SCORE * node=head->njumsu; 
	int no=0; 
	while(node){
		printf("[%d] addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X, njumsu = 0x%.8X\n", no, node, node->id, node->name, node->jumsu, node->nid, node->njumsu); 
		node = node->njumsu;
		no ++; 
	}
	return no;
}

SCORE * Search_Id_Node(SCORE * head, int id)
{
	SCORE * node=head->nid; 
	while(node){
		if (node->id == id){
			return node; 
		}
		node = node->nid;
	}
	return (SCORE *) 0;
}

SCORE * Search_Jumsu_Node(SCORE * head, int jumsu)
{
	SCORE * node=head->njumsu; 
	while(node){
		if (node->jumsu == jumsu){
			return node; 
		}
		node = node->njumsu;
	}
	return (SCORE *) 0;
}

#endif

#if 0

int main(void)
{
	int i;
	int r;
	SCORE * p; 

	for(i=0; i<8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
		printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	}

	printf("[Id] Searched Node Address = 0x%.8X\n", p = Search_Id_Node(&Head, 8));
	
	if(p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X\n", p->id, p->name, p->jumsu, p->nid);
	}

	printf("[Id] Searched Node Address = 0x%.8X\n", p = Search_Id_Node(&Head, 7));

	if(p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X\n", p->id, p->name, p->jumsu, p->nid);
	}

	p = &Head;

	for(;;)
	{
		printf("p = 0x%.8X", p);
		printf("[Jumsu] Searched Node Address = 0x%.8X\n", p = Search_Jumsu_Node(p, 50));
		if(p == (SCORE *)0x0) break;
		printf("ID=%d, NAME=%s, SCORE=%d, njumsu = 0x%.8X\n", p->id, p->name, p->jumsu, p->njumsu);
	}
}

#endif

#if 1

int Count_Node(SCORE * head)
{
	int i;

	for(i=0 ; i<MAX_ST ; i++)
	{
		if(head->nid == (SCORE *)0x0) return i;
		head = head->nid;		
	}
	return i;
}

int Print_Id_Node(SCORE * head, int id)
{
	SCORE * p = Search_Id_Node(head, id);

	if(p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X\n", p->id, p->name, p->jumsu, p->nid);
		return 1;
	}

	return -1;
}

int Print_Jumsu_Node(SCORE * head, int jumsu)
{
	SCORE * p = head;
	int r = -1;

	for(;;)
	{
		p = Search_Jumsu_Node(p, jumsu);
		if(p == (SCORE *)0x0) break;
		printf("ID=%d, NAME=%s, SCORE=%d, njumsu = 0x%.8X\n", p->id, p->name, p->jumsu, p->njumsu);
		r = 1;
	}

	return r;
}

#endif

#if 0

int main(void)
{
	int i;
	int r;

	for(i=0; i<8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
		printf("Printed Node Count = %d\n", Print_All_Node(&Head));
		printf("Node Count = %d\n", Count_Node(&Head));
	}

	printf("Print Id(8) Node Result = %d\n", Print_Id_Node(&Head, 8));
	printf("Print Id(7) Node Result = %d\n", Print_Id_Node(&Head, 7));
	printf("Print Jumsu(50) Node Result = %d\n", Print_Jumsu_Node(&Head, 50));
	printf("Print Jumsu(100) Node Result = %d\n", Print_Jumsu_Node(&Head, 100));
	printf("Print Jumsu(31) Node Result = %d\n", Print_Jumsu_Node(&Head, 31));
}

#endif

#if 1

int Delete_Id_Node(SCORE * head, int id)
{
	SCORE * node= head; 
	while(node->nid){
		if(node->nid-> id == id){
			Delete_One_Jumsu_Node(head, node->nid->jumsu, id);
			node -> nid -> id =0; 
			node-> nid = node-> nid -> nid; 
			return 1; 
		}
		node = node->nid; 
	}
	return -1; 
}

void Delete_One_Jumsu_Node(SCORE * head, int jumsu, int id)
{
	SCORE * node= head; 
	while(node->njumsu){
		if(node->njumsu-> id == id){
			node-> njumsu = node-> njumsu -> njumsu; 
			break; 
		}
		node = node->njumsu; 
	}
}

int Delete_Jumsu_Node(SCORE * head, int jumsu)
{
	SCORE * p= head;
	int cnt=0;  

	while(1){
		p = Search_Jumsu_Node(p, jumsu);
		if (p== (SCORE*)0) break; 
		Delete_Id_Node(p, p->id);
		cnt++;
	}
	if (cnt==0) return -1; 
	return cnt; 
}
#endif

#if 0
int main(void)
{
	int i;
	int r;

	for(i=0; i<MAX_ST; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Id(8) Node Result = %d\n", Delete_Id_Node(&Head, 8)); 
	printf("Delete Id(7) Node Result = %d\n", Delete_Id_Node(&Head, 7)); 
	printf("Delete Id(1) Node Result = %d\n", Delete_Id_Node(&Head, 1)); 
	printf("Delete Id(10) Node Result = %d\n", Delete_Id_Node(&Head, 10)); 
	printf("Delete Id(25) Node Result = %d\n", Delete_Id_Node(&Head, 25)); 
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Jumsu(45) Node Result = %d\n", Delete_Jumsu_Node(&Head, 45)); 
	printf("Delete Jumsu(20) Node Result = %d\n", Delete_Jumsu_Node(&Head, 20)); 
	printf("Delete Jumsu(90) Node Result = %d\n", Delete_Jumsu_Node(&Head, 90)); 
	printf("Delete Jumsu(100) Node Result = %d\n", Delete_Jumsu_Node(&Head, 100)); 
	printf("Delete Jumsu(97) Node Result = %d\n", Delete_Jumsu_Node(&Head, 97)); 
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
}

#endif

#if 0

int Count_Name_Node(SCORE * head, char * name)
{
	int n = 0;

	for(;;)
	{
		if(head->nid == (SCORE *)0x0) return n;
		if(!strcmp(head->nid->name, name)) n++;
		head = head -> nid;
	}
}

int Count_Score_Node(SCORE * head, int jumsu)
{
	int n = 0;

	for(;;)
	{
		if(head->njumsu == (SCORE *)0x0) return n;
		if(head->njumsu->jumsu == jumsu) n++;
		head = head -> njumsu;		
	}
}

int Copy_Name_Node(SCORE * head, char * name, SCORE * buf)
{
	// ���⼭���� �ۼ�






}

int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf)
{
	// ���⼭���� �ۼ�






}

#endif

#if 0

void main(void)
{
	int i;
	int r;
	SCORE * p;
	SCORE new_head;

	for(i=0; i<20; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	
	printf("Name Node Count = %d\n", r = Count_Name_Node(&Head, "lew")); 
	p = calloc(r, sizeof(SCORE));
	printf("Copy Name Node Result = %d\n", Copy_Name_Node(&Head, "lew", p)); 
	new_head.nid = p;
	printf("Printed Node Count = %d\n", Print_All_Id_Node(&new_head));
	free(p);

	printf("Score Node Count = %d\n", r = Count_Score_Node(&Head, 100)); 
	p = calloc(r, sizeof(SCORE));
	printf("Copy Score Node Result = %d\n", Copy_Score_Node(&Head, 100, p)); 
	new_head.njumsu = p;
	printf("Printed Node Count = %d\n", Print_All_Jumsu_Node(&new_head));
	free(p);
}

#endif

#endif

// 1-4 이중 link
#if 0


#if 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _score 
{
	int id;
	int jumsu;
	char name[10];
	struct _score  * next; 
	struct _score  * prev; 
}SCORE;

SCORE Head;

#define MAX_ST		20

SCORE exam[MAX_ST];

// �������� ����Ǵ� ��� �Լ��� �� �κп� ������ �߰��Ѵ�

int Print_All_Data(void);
int Print_Data(int no);
int Count_Data(void);
int Create_Data(SCORE * p);
int Insert_Data(SCORE * p);
int Insert_Node(SCORE * head, SCORE * d);
int Print_All_Node(SCORE * head);
int Print_All_Node_Reverse(SCORE * head);
SCORE * Search_Id_Node(SCORE * head, int id);
int Count_Node(SCORE * head);
int Delete_Node(SCORE * head, int id);
int Copy_All_Node(SCORE * head, SCORE * buf);
int Count_Name_Node(SCORE * head, char * name);
int Count_Score_Node(SCORE * head, int jumsu);
int Copy_Name_Node(SCORE * head, char * name, SCORE * buf);
int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf);
int Print_Selected_Node(SCORE *head, int id, int num);
int Print_Selected_Node_Reverse(SCORE *head, int id, int num);

SCORE test[MAX_ST] = {{10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
                               {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}, \
                               {15, 90, "ki"}, {11, 20, "kong"}, {14, 40, "shin"}, {12, 50, "son"}, {17, 48, "lee"}, \
                               {20, 100, "min"}, {19, 80, "you"}, {13, 45, "song"}, {16, 54, "no"}, {18, 100, "yang"}}; 

void Make_Test_Data(int n)
{
	int i;

	for(i=0; i<n; i++)
	{
		exam[i] = test[i];
	}
}

int Create_Data(SCORE * p)
{
	printf("\n����� �Է��Ͻÿ� => ");
	scanf("%d", &p->id);
	printf("�̸��� �Է��Ͻÿ� => ");
	scanf("%s", p->name);
	printf("������ �Է��Ͻÿ� => ");
	scanf("%d", &p->jumsu);
	p->next = (SCORE *)0x0;
	p->prev = (SCORE *)0x0;

	return 1;
}

int Print_All_Data(void)
{
	int i;

	printf("Head= 0x%.8X, Head.next=0x%.8X, Head.prev=0x%.8X\n", &Head, Head.next, Head.prev);

	for(i=0; i<MAX_ST; i++)
	{
		if(exam[i].id == 0) break;
		printf("[%d] addr=0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", i, &exam[i], exam[i].id, exam[i].name, exam[i].jumsu, exam[i].next, exam[i].prev);
	}

	return i;
}

int Print_Data(int no)
{
	if(exam[no].id == 0) return -1;
	printf("[%d] addr=0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", no, &exam[no], exam[no].id, exam[no].name, exam[no].jumsu, exam[no].next, exam[no].prev);
	return 1;
}

int Count_Data(void)
{
	int i;

	for(i=0; i<MAX_ST; i++)
	{
		if(exam[i].id == 0) break;
	}

	return i;
}

int Insert_Data(SCORE * p)
{
	int i;

	for(i=0; i<MAX_ST; i++)
	{
		if(exam[i].id == 0) 
		{
			exam[i] = (*p);
			return i;
		}

		if(exam[i].id == p->id)
		{
			return -2;
		}
	}

	return -1;
}

int Print_All_Node(SCORE * head)
{
	int i;

	printf("Head.next = 0x%.8X Head.prev = 0x%.8X\n", head->next, head->prev);

	for(i=0 ; i<MAX_ST ; i++)
	{
		if(head->next == (SCORE *)0x0) return i;
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", head->next, head->next->id, head->next->name, head->next->jumsu, head->next->next, head->next->prev);
		head = head->next;		
	}
	return i;
}

int Count_Node(SCORE * head)
{
	int i;

	for(i=0 ; i<MAX_ST ; i++)
	{
		if(head->next == (SCORE *)0x0) return i;
		head = head->next;		
	}
	return i;
}

int Copy_All_Node(SCORE * head, SCORE * buf)
{
	int i;
	if(head->next == (SCORE *)0x0) return -1;

	for(i=0 ; i<MAX_ST ; i++)
	{
		if(head->next == (SCORE *)0x0) break;
		buf[i] = *head->next;
		buf[i].next = &buf[i+1];
		head = head->next;
	}
	
	buf[i-1].next = (SCORE *)0x0;
	return i;
}

int Count_Name_Node(SCORE * head, char * name)
{
	int n = 0;

	for(;;)
	{
		if(head->next == (SCORE *)0x0) return n;
		if(!strcmp(head->next->name, name)) n++;
		head = head -> next;		
	}
}

int Count_Score_Node(SCORE * head, int jumsu)
{
	int n = 0;

	for(;;)
	{
		if(head->next == (SCORE *)0x0) return n;
		if(head->next->jumsu == jumsu) n++;
		head = head -> next;		
	}
}

int Copy_Name_Node(SCORE * head, char * name, SCORE * buf)
{
	int n = 0;

	for(;;)
	{
		if(head->next == (SCORE *)0x0) break;
		if(!strcmp(head->next->name, name))
		{
			buf[n] = *head->next;
			buf[n].next = &buf[n+1];
			n++;
		}
		head = head -> next;		
	}
	if (n > 0) buf[n - 1].next = (SCORE *)0x0;
	return n;
}

int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf)
{
	int n = 0;

	for(;;)
	{
		if(head->next == (SCORE *)0x0) break;
		if(head->next->jumsu == jumsu)
		{
			buf[n] = *head->next;
			buf[n].next = &buf[n+1];
			n++;
		}
		head = head -> next;		
	}
	if(n > 0) buf[n-1].next = (SCORE *)0x0;
	return n;
}

#endif

/***********************************************************/
// [1-4.2] ������ �ϳ��� �����Ͽ� Linked List�� �߰��ϴ� �Լ�
/***********************************************************/

#if 1

int Insert_Node(SCORE * head, SCORE * d)
{
	SCORE *prev = head;
    while (prev->next) {
        if (d->id < prev->next->id) break;
        if (d->id == prev->next->id) return -2;
        prev = prev->next;
    }
 
    // prev 노드 뒤에 d 자료 연결!
    // 새노드 연결관계 설정
    d->next = prev->next;
    d->prev = prev;
 
    // 앞자료next, 뒷자료 prev -> 새노드
    if (d->next) d->next->prev = d;
    d->prev->next = d;
 
    return 1;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	for(i=0; i<8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
		printf("Printed Data Count = %d\n", Print_All_Data());
	}
}

#endif

/***********************************************************/
// [1-4.3] �־��� ����� node�� ã�Ƽ� �����ϴ� �Լ�
/***********************************************************/

#if 1

SCORE * Search_Id_Node(SCORE * head, int id)
{
	SCORE *node = head->next;
 
    while (node) {
        if (node->id == id) return node;
        node = node->next;
    }
    return (SCORE*)0;


}

int Delete_Node(SCORE * head, int id)
{
	SCORE *delnode = Search_Id_Node(head, id);
    if (delnode == (SCORE*)0) return -1;
 
    // 앞자료(delnode->prev)의 next <- 삭제할 자료의 next
    delnode->prev->next = delnode->next;
    // 뒷자료(delnode->next)의 prev <- 삭제할 자료의 prev (뒷자료가 존재할때만..)
    if(delnode->next) delnode->next->prev = delnode->prev;
 
    // 할당관리 주체에게 공간 반납!
    delnode->id = 0;
 
    return 1;

}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	for(i=0; i<8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("[8] Delete Node Result = %d\n", Delete_Node(&Head, 8)); 
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("[7] Delete Node Result = %d\n", Delete_Node(&Head, 7)); 
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("[1] Delete Node Result = %d\n", Delete_Node(&Head, 1)); 
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("[10] Delete Node Result = %d\n", Delete_Node(&Head, 10)); 
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
}

#endif

/***********************************************************/
// [1-4.4] ���� ��ũ ����� ���� 1, �������� �˻�
/***********************************************************/

#if 0

int Print_All_Node_Reverse(SCORE * head)
{
	int i;

	printf("Head.next = 0x%.8X Head.prev = 0x%.8X\n", head->next, head->prev);

	// ���⼭���� �ۼ�






	printf("Tail.next = 0x%.8X Tail.prev = 0x%.8X\n", head->next, head->prev);

	// ���⼭���� �ۼ�






}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	for(i=0; i<8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count(Up) = %d\n", Print_All_Node(&Head));
	printf("Printed Node Count(Down) = %d\n", Print_All_Node_Reverse(&Head));
	printf("[8] Delete Node Result = %d\n", Delete_Node(&Head, 8)); 
	printf("Printed Node Count(Down) = %d\n", Print_All_Node_Reverse(&Head));
}

#endif

/***********************************************************/
// [1-4.5] ���� ��ũ ����� ���� 2, ���������� ���� ���� �μ�
/***********************************************************/

#if 0

int Print_Selected_Node(SCORE * head, int id, int num)
{
	// ���⼭���� �ۼ�






}

int Print_Selected_Node_Reverse(SCORE *head, int id, int num)
{
	// ���⼭���� �ۼ�






}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	for(i=0; i<MAX_ST; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count(Up) = %d\n", Print_All_Node(&Head));
	printf("Printed Node Count(Down) = %d\n", Print_All_Node_Reverse(&Head));

	r = Print_Selected_Node(&Head, 7, 3);
	printf("Printed Data Number => %d\n", r);

	r = Print_Selected_Node(&Head, 19, 3);
	printf("Printed Data Number => %d\n", r);

	r = Print_Selected_Node_Reverse(&Head, 7, 3);
	printf("Printed Data Number => %d\n", r);

	r = Print_Selected_Node_Reverse(&Head, 2, 3);
	printf("Printed Data Number => %d\n", r);
}

#endif

#endif

// 1-5 stack 
#if 1

#include <stdio.h>

#define MAX_STACK		10
#define STACK_EMPTY	MAX_STACK
#define STACK_FULL		0

int Push_Stack(int data);
int Pop_Stack(int *p);
int Print_Stack(void);
int Count_Full_Data_Stack(void);
int Count_Empty_Data_Stack(void);

int a[MAX_STACK+1] = {1,2,3,4,5,6,7,8,9,10,11};
int Stack[MAX_STACK];
int Sptr = STACK_EMPTY;

int Push_Stack(int data)
{
	// full descend stack! 
	// descending 이므로 data가 증가할수록 sptr이 감소
	if (Sptr == STACK_FULL) return -1;
    Stack[--Sptr] = data; // 감소시킨 상태에서 data 넣기

    return 1;
}

int Pop_Stack(int *p)
{
	if (Sptr == STACK_EMPTY) return -1;
    *p = Stack[Sptr++]; // data 빼고 sptr 증가
    return 1;
}

int Print_Stack(void)
{
	int i;

	for(i = Sptr; i < MAX_STACK; i++)
	{
		printf("STACK[%d] = %d\n", i, Stack[i]);
	}
	return MAX_STACK - Sptr;
}

int Count_Full_Data_Stack(void)
{
	return STACK_EMPTY - Sptr;
}

int Count_Empty_Data_Stack(void)
{
	return Sptr - STACK_FULL;
}

int main(void)
{
	int i;

	for(i=0; i<(MAX_STACK+1); i++)
	{
		printf("%d, ", a[i]);
	}
	
	printf("\n");

	for(i=0; i<5; i++)
	{
		printf("Push Result = %d\n", Push_Stack(a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d ", Count_Full_Data_Stack());
		printf("Empty = %d\n", Count_Empty_Data_Stack());
		printf("Sptr = %d\n", Sptr);
	}

	for(i=0; i<5; i++)
	{
		printf("Pop Result = %d\n", Pop_Stack(&a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d ", Count_Full_Data_Stack());
		printf("Empty = %d\n", Count_Empty_Data_Stack());
		printf("Sptr = %d\n", Sptr);
	}

	for(i=0; i<(MAX_STACK+1); i++)
	{
		printf("%d, ", a[i]);
	}
	
	printf("\n");

	for(i=0; i<(MAX_STACK+1); i++)
	{
		printf("Push Result = %d\n", Push_Stack(a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d ", Count_Full_Data_Stack());
		printf("Empty = %d\n", Count_Empty_Data_Stack());
		printf("Sptr = %d\n", Sptr);
	}

	for(i=0; i<(MAX_STACK+1); i++)
	{
		printf("Pop Result = %d\n", Pop_Stack(&a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d ", Count_Full_Data_Stack());
		printf("Empty = %d\n", Count_Empty_Data_Stack());
		printf("Sptr = %d\n", Sptr);
	}

	for(i=0; i<(MAX_STACK+1); i++)
	{
		printf("%d, ", a[i]);
	}
	
	printf("\n");
}

#endif

// [1-6] Linear Queue
#if 0

#include <stdio.h>

#define MAX_Q			5
#define Q_EMPTY		0
#define Q_FULL			MAX_Q

int In_Queue(int data);
int Out_Queue(int *p);
int Print_Queue(void);
int Count_Full_Data_Queue(void);
int Count_Empty_Data_Queue(void);

int a[MAX_Q+1] = {1,2,3,4,5,6};
int Queue[MAX_Q];
int Wrptr = Q_EMPTY;
int Rdptr = Q_EMPTY;

int In_Queue(int data)
{
	int i;
    if (Wrptr == Q_FULL) {
        if (Rdptr == 0) return -1; // 정리 불가 - -1리턴
        for (i = 0; i < Wrptr - Rdptr;i++) { // 정리 가능 상황 -> 정리
            Queue[i] = Queue[Rdptr + i];
        }
        Wrptr -= Rdptr;
        Rdptr = 0;
    }
    Queue[Wrptr++] = data;
    return 1;
}

int Out_Queue(int *p)
{
 	if (Wrptr == Rdptr) return -1;// 비워져있다!
    *p = Queue[Rdptr++];
    return 1;

}

int Print_Queue(void)
{
	int i;

	for(i=Rdptr; i<Wrptr; i++)
	{
		printf("Queue[%d] = %d\n", i, Queue[i]);
	}

	return Wrptr - Rdptr;
}

int Count_Full_Data_Queue(void)
{
	return Wrptr - Rdptr;
}

int Count_Empty_Data_Queue(void)
{
	return MAX_Q - (Wrptr - Rdptr);
}

void main(void)
{
	int i;

	for(i=0; i<(MAX_Q+1); i++)
	{
		printf("%d, ", a[i]);
	}
	
	printf("\n");

	for(i=0; i<3; i++)
	{
		printf("Queue Result = %d\n", In_Queue(a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for(i=0; i<3; i++)
	{
		a[i] = 0;
	}

	for(i=0; i<3; i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for(i=0; i<(MAX_Q+1); i++)
	{
		printf("%d, ", a[i]);
	}

	printf("\n");

	for(i=0; i<(MAX_Q+1); i++)
	{
		printf("Queue Result = %d\n", In_Queue(a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for(i=0; i<(MAX_Q+1); i++)
	{
		a[i] = 0;
	}

	for(i=0; i<(MAX_Q+1); i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for(i=0; i<(MAX_Q+1); i++)
	{
		printf("%d, ", a[i]);
	}

	printf("\n");
}

#endif

// [1-7] Circular Queue
#if 1
#include <stdio.h>		

#define MAX_Q		8
#define Q_MIN		0
#define Q_MAX		MAX_Q

int In_Queue(int data);
int Out_Queue(int *p);
int Print_Queue(void);
int Count_Full_Data_Queue(void);
int Count_Empty_Data_Queue(void);

int a[MAX_Q+1] = {1,2,3,4,5,6,7,8,9};
int Queue[MAX_Q];
int Wrptr = Q_MIN;
int Rdptr = Q_MIN;

int In_Queue(int data)
{
	if ((Wrptr + 1) % MAX_Q == Rdptr) return -1;
    Queue[Wrptr] = data;
    Wrptr = (Wrptr + 1) % MAX_Q;
    return 1;
}

int Out_Queue(int *p)
{
	if(Rdptr == Wrptr) return -1; 
	*p = Queue[Rdptr]; 
	Rdptr = (Rdptr+1)% MAX_Q; 
	return 1;

}

int Print_Queue(void)
{
	int i;
	int rd = Rdptr;
	int n = Count_Full_Data_Queue();

	for(i=0; i<n; i++)
	{
		printf("Queue[%d] = %d\n", rd, Queue[rd]);
		rd++;
		rd %= MAX_Q;
	}

	return n; 
}

int Count_Full_Data_Queue(void)
{
	if(Rdptr > Wrptr) return MAX_Q - (Rdptr - Wrptr);
	return Wrptr - Rdptr;
}

int Count_Empty_Data_Queue(void)
{
	return MAX_Q - Count_Full_Data_Queue() - 1;
}

void main(void)
{
	int i;

	for(i=0; i<(MAX_Q+1); i++)
	{
		printf("%d, ", a[i]);
	}
	
	printf("\n");

	for(i=0; i<3; i++)
	{
		printf("Queue Result = %d\n", In_Queue(a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for(i=0; i<3; i++)
	{
		a[i] = 0;
	}

	for(i=0; i<3; i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for(i=0; i<(MAX_Q+1); i++)
	{
		printf("%d, ", a[i]);
	}

	printf("\n");

	for(i=0; i<(MAX_Q+1); i++)
	{
		printf("Queue Result = %d\n", In_Queue(a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for(i=0; i<(MAX_Q+1); i++)
	{
		a[i] = 0;
	}

	for(i=0; i<(MAX_Q+1); i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for(i=0; i<(MAX_Q+1); i++)
	{
		printf("%d, ", a[i]);
	}

	printf("\n");
}

#endif

// 2-1 heap linked list 
#if 0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _score 
{
	int id;
	int jumsu;
	char name[10];
	struct _score  * next; 
}SCORE;

SCORE Head;


int Print_All_Data(void);
int Print_Data(int no);
int Count_Data(void);
int Create_Data(SCORE * p);
int Insert_Data(SCORE * p);
int Insert_Node(SCORE * head, SCORE * d);
int Print_All_Node(SCORE * head);
SCORE * Search_Id_Node(SCORE * head, int id);
int Count_Node(SCORE * head);
int Print_Node(SCORE * head, int id); 
int Delete_Node(SCORE * head, int id);
int Copy_All_Node(SCORE * head, SCORE * buf);
int Count_Name_Node(SCORE * head, char * name);
int Count_Score_Node(SCORE * head, int jumsu);
int Copy_Name_Node(SCORE * head, char * name, SCORE * buf);
int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf);

#define MAX_ST  20

SCORE test[MAX_ST] = {{10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
                               {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}, \
                               {15, 90, "ki"}, {11, 20, "kong"}, {14, 40, "shin"}, {12, 50, "son"}, {17, 48, "lee"}, \
                               {20, 100, "min"}, {19, 80, "you"}, {13, 45, "song"}, {16, 54, "no"}, {18, 100, "yang"}}; 

int Create_Data(SCORE * p)
{
	printf("\n����� �Է��Ͻÿ� => ");
	scanf("%d", &p->id);
	printf("�̸��� �Է��Ͻÿ� => ");
	scanf("%s", p->name);
	printf("������ �Է��Ͻÿ� => ");
	scanf("%d", &p->jumsu);
	p->next = (SCORE *)0x0;

	return 1;
}

int Print_All_Node(SCORE * head)
{
	int n = 0;

	printf("Head.next = 0x%.8X\n", head->next);

	for(;;)
	{
		if(head->next == (SCORE *)0x0) return n;
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", head->next, head->next->id, head->next->name, head->next->jumsu, head->next->next);
		n++;
		head = head -> next;		
	}
}

SCORE * Search_Id_Node(SCORE * head, int id)
{
	for(;;)
	{
		if(head->next == (SCORE *)0x0) return (SCORE *)0x0;
		if(head->next->id == id) return head->next; 
		head = head -> next;		
	}
}

int Count_Node(SCORE * head)
{
	int n = 0;

	for(;;)
	{
		if(head->next == (SCORE *)0x0) return n;
		n++;
		head = head -> next;		
	}
}

int Print_Node(SCORE * head, int id)
{
	SCORE * p = Search_Id_Node(head, id);

	if(p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", p->id, p->name, p->jumsu, p->next);
		return 1;
	}

	return -1;
}

int Copy_All_Node(SCORE * head, SCORE * buf)
{
	int n = 0;

	if(head->next == (SCORE *)0x0) return -1;

	for(;;)
	{
		if(head->next == (SCORE *)0x0) break;
		buf[n] = *head->next;
		buf[n].next = &buf[n+1];
		n++;
		head = head->next;
	}
	buf[n-1].next = NULL;
	return n;
}

int Count_Name_Node(SCORE * head, char * name)
{
	int n = 0;

	for(;;)
	{
		if(head->next == (SCORE *)0x0) return n;
		if(!strcmp(head->next->name, name)) n++;
		head = head -> next;		
	}
}

int Count_Score_Node(SCORE * head, int jumsu)
{
	int n = 0;

	for(;;)
	{
		if(head->next == (SCORE *)0x0) return n;
		if(head->next->jumsu == jumsu) n++;
		head = head -> next;		
	}
}

int Copy_Name_Node(SCORE * head, char * name, SCORE * buf)
{
	int n = 0;

	for(;;)
	{
		if(head->next == (SCORE *)0x0) break;
		if(!strcmp(head->next->name, name))
		{
			buf[n] = *head->next;
			buf[n].next = &buf[n+1];
			n++;
		}
		head = head -> next;		
	}
	if (n > 0) buf[n - 1].next = (SCORE *)0x0;
	return n;
}

int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf)
{
	int n = 0;

	for(;;)
	{
		if(head->next == (SCORE *)0x0) break;
		if(head->next->jumsu == jumsu)
		{
			buf[n] = *head->next;
			buf[n].next = &buf[n+1];
			n++;
		}
		head = head -> next;		
	}
	if(n > 0) buf[n-1].next = (SCORE *)0x0;
	return n;
}

/***********************************************************/
// [2-1.2] ���޹��� �����͸� ���� �����ϰ� Linked List�� �߰��ϴ� �Լ� (calloc ���)
/***********************************************************/

#if 1

int Insert_Node(SCORE * head, SCORE * d)
{
	SCORE * newnode; 
	SCORE * prev = head; 
	while(prev->next){
		if (d -> id < prev -> next -> id ) break; 
		if (d-> id == prev -> next -> id) return -2; 
		prev = prev ->next ;
	}
	newnode = (SCORE *) calloc(1, sizeof(SCORE));
	if (newnode == (SCORE *) 0 ) return -1; 

	*newnode = *d; 
	newnode-> next = prev-> next; 
	prev -> next = newnode; 
	return 1; 
}

#endif

#if 0

int main(void)
{
	int i;
	SCORE * p;

	for(i=0; i<8; i++)
	{
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &test[i]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));

	printf("Searched Node Address = 0x%.8X\n", p = Search_Id_Node(&Head, 8));
	
	if(p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", p->id, p->name, p->jumsu, p->next);
	}

	printf("Searched Node Address = 0x%.8X\n", p = Search_Id_Node(&Head, 7));

	if(p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", p->id, p->name, p->jumsu, p->next);
	}
}

#endif

/***********************************************************/
// [2-1.3] ���޹��� ����� �ڷḦ ��ũ�� ������ �����ϴ� �Լ� (free ���)
/***********************************************************/

#if 1

int Delete_Node(SCORE * head, int id)
{
	SCORE * prev = head; 

	while(prev-> next){
		if (prev->next-> id == id) {
			SCORE * delnode = prev -> next;
			prev->next = delnode-> next ;
			free(delnode); 
			return 1; 
		} 
		prev = prev-> next ; 
	}
	return -1; 
}

#endif

#if 0

int main(void)
{
	int i;

	for(i=0; i<8; i++)
	{
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &test[i]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 8)); 
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 7)); 
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 1)); 
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 10)); 
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
}

#endif

#endif

/***********************************************************/
// [2-2] heap multi linked list 
/***********************************************************/

#if 0

#if 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

typedef struct _score 
{
	int id;
	int jumsu;
	char name[10];
	struct _score  * nid; 
	struct _score  * njumsu; 
}SCORE;

SCORE Head;

#define MAX_ST		20

SCORE exam[MAX_ST];


int Print_All_Data(void);
int Print_Data(int no);
int Count_Data(void);
int Create_Data(SCORE * p);
int Insert_Data(SCORE * p);
int Insert_Node(SCORE * head, SCORE * d);
int Print_All_Node(SCORE * head);
int Print_All_Id_Node(SCORE * head);
int Print_All_Jumsu_Node(SCORE * head);
SCORE * Search_Id_Node(SCORE * head, int id);
SCORE * Search_Jumsu_Node(SCORE * head, int jumsu);
int Count_Node(SCORE * head);
int Print_Id_Node(SCORE * head, int id); 
int Print_Jumsu_Node(SCORE * head, int jumsu); 
int Delete_Id_Node(SCORE * head, int id);
void Delete_One_Jumsu_Node(SCORE * head, int jumsu, int id);
int Delete_Jumsu_Node(SCORE * head, int id);
int Copy_All_Node(SCORE * head, SCORE * buf);
int Count_Name_Node(SCORE * head, char * name);
int Count_Score_Node(SCORE * head, int jumsu);
int Copy_Name_Node(SCORE * head, char * name, SCORE * buf);
int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf);

SCORE test[MAX_ST] = {{10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
                               {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}, \
                               {15, 90, "ki"}, {11, 20, "kong"}, {14, 40, "shin"}, {12, 50, "son"}, {17, 48, "lee"}, \
                               {20, 100, "min"}, {19, 80, "you"}, {13, 45, "song"}, {16, 54, "no"}, {18, 100, "yang"}}; 

int Create_Data(SCORE * p)
{
	printf("\n����� �Է��Ͻÿ� => ");
	scanf("%d", &p->id);
	printf("�̸��� �Է��Ͻÿ� => ");
	scanf("%s", p->name);
	printf("������ �Է��Ͻÿ� => ");
	scanf("%d", &p->jumsu);
	p->nid = (SCORE *)0x0;
	p->njumsu = (SCORE *)0x0;

	return 1;
}


int Print_All_Node(SCORE * head)
{
	Print_All_Id_Node(head);
	return Print_All_Jumsu_Node(head);
}

int Print_All_Id_Node(SCORE * head)
{
	int i=0;

	printf("[Id] Head.nid = 0x%.8X\n", head->nid);

	for(;;)
	{
		if(head->nid == (SCORE *)0x0) return i;
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X\n", head->nid, head->nid->id, head->nid->name, head->nid->jumsu, head->nid->nid);
		head = head->nid;
		i++;
	}
}

int Print_All_Jumsu_Node(SCORE * head)
{
	int i=0;

	printf("[Jumsu] Head.njumsu = 0x%.8X\n", head->njumsu);

	for(;;)
	{
		if(head->njumsu == (SCORE *)0x0) return i;
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, njumsu = 0x%.8X\n", head->njumsu, head->njumsu->id, head->njumsu->name, head->njumsu->jumsu, head->njumsu->njumsu);
		head = head->njumsu;
		i++;
	}
}

SCORE * Search_Id_Node(SCORE * head, int id)
{
	for(;;)
	{
		if(head->nid == (SCORE *)0x0) return (SCORE *)0x0;
		if(head->nid->id == id) return head->nid;
		head = head->nid;		
	}
}

SCORE * Search_Jumsu_Node(SCORE * head, int jumsu)
{
	for(;;)
	{
		if(head->njumsu == (SCORE *)0x0) return (SCORE *)0x0;
		if(head->njumsu->jumsu == jumsu) return head->njumsu;
		head = head->njumsu;		
	}
}

int Count_Node(SCORE * head)
{
	int n=0;

	for(;;)
	{
		if(head->nid == (SCORE *)0x0) return n;
		head = head->nid;
		n++;
	}
}

int Print_Id_Node(SCORE * head, int id)
{
	SCORE * p = Search_Id_Node(head, id);

	if(p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X\n", p->id, p->name, p->jumsu, p->nid);
		return 1;
	}

	return -1;
}

int Print_Jumsu_Node(SCORE * head, int jumsu)
{
	SCORE * p = head;
	int r = -1;

	for(;;)
	{
		p = Search_Jumsu_Node(p, jumsu);
		if(p == (SCORE *)0x0) break;
		printf("ID=%d, NAME=%s, SCORE=%d, njumsu = 0x%.8X\n", p->id, p->name, p->jumsu, p->njumsu);
		r = 1;
	}

	return r;
}

int Count_Name_Node(SCORE * head, char * name)
{
	int n = 0;

	for(;;)
	{
		if(head->nid == (SCORE *)0x0) return n;
		if(!strcmp(head->nid->name, name)) n++;
		head = head -> nid;		
	}
}

int Count_Score_Node(SCORE * head, int jumsu)
{
	int n = 0;

	for(;;)
	{
		if(head->njumsu == (SCORE *)0x0) return n;
		if(head->njumsu->jumsu == jumsu) n++;
		head = head -> njumsu;		
	}
}

int Copy_Name_Node(SCORE * head, char * name, SCORE * buf)
{
	int n = 0;

	for(;;)
	{
		if(head->nid == (SCORE *)0x0) break;
		if(!strcmp(head->nid->name, name))
		{
			buf[n] = *head->nid;
			buf[n].nid = &buf[n+1];
			n++;
		}
		head = head -> nid;		
	}
	if (n > 0) buf[n - 1].nid = (SCORE *)0x0;
	return n;
}

int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf)
{
	int n = 0;

	for(;;)
	{
		if(head->njumsu == (SCORE *)0x0) break;
		if(head->njumsu->jumsu == jumsu)
		{
			buf[n] = *head->njumsu;
			buf[n].njumsu = &buf[n+1];
			n++;
		}
		head = head -> njumsu;		
	}
	if(n > 0) buf[n-1].njumsu = (SCORE *)0x0;
	return n;
}

#endif

/***********************************************************/
// [2-2.1] ������ �ϳ��� �����Ͽ� Linked List�� �߰��ϴ� �Լ�  (calloc ���)
/***********************************************************/

#if 0

int Insert_Node(SCORE * head, SCORE * d)
{
	// ���⼭���� �ۼ�






}

#endif

#if 0

void main(void)
{
	int i;

	for(i=0; i<8; i++)
	{
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &test[i]));
		printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	}
}

#endif

/***********************************************************/
// [2-2.2] link�� ���� �־��� ����� node�� ã�Ƽ� �����ϴ� �Լ� (free ���)
/***********************************************************/

#if 0

int Delete_Id_Node(SCORE * head, int id)
{
	// ���⼭���� �ۼ�






}

void Delete_One_Jumsu_Node(SCORE * head, int jumsu, int id)
{
	// ���⼭���� �ۼ�






}

int Delete_Jumsu_Node(SCORE * head, int jumsu)
{
	// ���⼭���� �ۼ�






}

#endif

#if 0

void main(void)
{
	int i;

	for(i=0; i<MAX_ST; i++)
	{
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &test[i]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Id(8) Node Result = %d\n", Delete_Id_Node(&Head, 8)); 
	printf("Delete Id(7) Node Result = %d\n", Delete_Id_Node(&Head, 7)); 
	printf("Delete Id(1) Node Result = %d\n", Delete_Id_Node(&Head, 1)); 
	printf("Delete Id(10) Node Result = %d\n", Delete_Id_Node(&Head, 10)); 
	printf("Delete Id(25) Node Result = %d\n", Delete_Id_Node(&Head, 25)); 
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Jumsu(45) Node Result = %d\n", Delete_Jumsu_Node(&Head, 45)); 
	printf("Delete Jumsu(20) Node Result = %d\n", Delete_Jumsu_Node(&Head, 20)); 
	printf("Delete Jumsu(90) Node Result = %d\n", Delete_Jumsu_Node(&Head, 90)); 
	printf("Delete Jumsu(100) Node Result = %d\n", Delete_Jumsu_Node(&Head, 100)); 
	printf("Delete Jumsu(87) Node Result = %d\n", Delete_Jumsu_Node(&Head, 97)); 
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
}

#endif

#endif

/***********************************************************/
// [2-3] heap double linked list 
/***********************************************************/

#if 0

// [2-3.1] double Linked List 

#if 0

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

typedef struct _score 
{
	int id;
	int jumsu;
	char name[10];
	struct _score  * next;
	struct _score  * prev;
}SCORE;

SCORE Head;

#define MAX_ST		20


// �������� ����Ǵ� ��� �Լ��� �� �κп� ������ �߰��Ѵ�

int Print_All_Data(void);
int Print_Data(int no);
int Count_Data(void);
int Create_Data(SCORE * p);
int Insert_Data(SCORE * p);
int Insert_Node(SCORE * head, SCORE * d);
int Print_All_Node(SCORE * head);
int Print_All_Node_Reverse(SCORE * head);
SCORE * Search_Id_Node(SCORE * head, int id);
int Count_Node(SCORE * head);
int Print_Node(SCORE * head, int id); 
int Delete_Node(SCORE * head, int id);
int Copy_All_Node(SCORE * head, SCORE * buf);
int Count_Name_Node(SCORE * head, char * name);
int Count_Score_Node(SCORE * head, int jumsu);
int Copy_Name_Node(SCORE * head, char * name, SCORE * buf);
int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf);
int Print_Selected_Node(SCORE *head, int id, int num);
int Print_Selected_Node_Reverse(SCORE *head, int id, int num);

SCORE test[MAX_ST] = {{10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
                               {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}, \
                               {15, 90, "ki"}, {11, 20, "kong"}, {14, 40, "shin"}, {12, 50, "son"}, {17, 48, "lee"}, \
                               {20, 100, "min"}, {19, 80, "you"}, {13, 45, "song"}, {16, 54, "no"}, {18, 100, "yang"}}; 


int Create_Data(SCORE * p)
{
	printf("\n����� �Է��Ͻÿ� => ");
	scanf("%d", &p->id);
	printf("�̸��� �Է��Ͻÿ� => ");
	scanf("%s", p->name);
	printf("������ �Է��Ͻÿ� => ");
	scanf("%d", &p->jumsu);
	p->next = (SCORE *)0x0;
	p->prev = (SCORE *)0x0;

	return 1;
}

SCORE * Search_Id_Node(SCORE * head, int id)
{
	for(;;)
	{
		if(head->next == (SCORE *)0x0) return (SCORE *)0x0;
		if(head->next->id == id) return head->next;      
		head = head->next;		
	}
}

int Count_Node(SCORE * head)
{
	int i=0;

	for(;;)
	{
		if(head->next == (SCORE *)0x0) return i;
		head = head->next;		
		i++;
	}
}

int Print_Node(SCORE * head, int id)
{
	SCORE * p = Search_Id_Node(head, id);

	if(p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", p->id, p->name, p->jumsu, p->next, p->prev);
		return 1;
	}

	return -1;
}

int Copy_All_Node(SCORE * head, SCORE * buf)
{
	int n = 0;

	if(head->next == (SCORE *)0x0) return -1;

	for(;;)
	{
		if(head->next == (SCORE *)0x0) break;
		buf[n] = *head->next;
		buf[n].next = &buf[n+1];
		n++;
		head = head->next;
	}
	buf[n-1].next = NULL;
	return n;
}

int Count_Name_Node(SCORE * head, char * name)
{
	int n = 0;

	for(;;)
	{
		if(head->next == (SCORE *)0x0) return n;
		if(!strcmp(head->next->name, name)) n++;
		head = head -> next;		
	}
}

int Count_Score_Node(SCORE * head, int jumsu)
{
	int n = 0;

	for(;;)
	{
		if(head->next == (SCORE *)0x0) return n;
		if(head->next->jumsu == jumsu) n++;
		head = head -> next;		
	}
}

int Copy_Name_Node(SCORE * head, char * name, SCORE * buf)
{
	int n = 0;

	for(;;)
	{
		if(head->next == (SCORE *)0x0) break;
		if(!strcmp(head->next->name, name))
		{
			buf[n] = *head->next;
			buf[n].next = &buf[n+1];
			n++;
		}
		head = head -> next;		
	}
	if (n > 0) buf[n - 1].next = (SCORE *)0x0;
	return n;
}

int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf)
{
	int n = 0;

	for(;;)
	{
		if(head->next == (SCORE *)0x0) break;
		if(head->next->jumsu == jumsu)
		{
			buf[n] = *head->next;
			buf[n].next = &buf[n+1];
			n++;
		}
		head = head -> next;		
	}
	if(n > 0) buf[n-1].next = (SCORE *)0x0;
	return n;
}

int Print_All_Node(SCORE * head)
{
	int i=0;

	printf("Head.next = 0x%.8X Head.prev = 0x%.8X\n", head->next, head->prev);

	for(;;)
	{
		if(head->next == (SCORE *)0x0) return i;
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", head->next, head->next->id, head->next->name, head->next->jumsu, head->next->next, head->next->prev);
		head = head->next;		
		i++;
	}
}

int Print_All_Node_Reverse(SCORE * head)
{
	int i=0;

	printf("Head.next = 0x%.8X Head.prev = 0x%.8X\n", head->next, head->prev);

	while(head->next != (SCORE *)0x0)
	{
		head = head->next;
	}

	printf("Tail.next = 0x%.8X Tail.prev = 0x%.8X\n", head->next, head->prev);

	for(;;)
	{
		if(head->prev == (SCORE *)0x0) return i;
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", head, head->id, head->name, head->jumsu, head->next, head->prev);
		head = head->prev;		
		i++;
	}
}

int Print_Selected_Node(SCORE * head, int id, int num)
{
	int i = 0;

	head = Search_Id_Node(head, id);
	
	if(head == (SCORE *)0x0) return -1;

	while(i<num)
	{
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", head, head->id, head->name, head->jumsu, head->next, head->prev);
		i++;
		if(head->next == (SCORE *)0x0) break;
		head = head->next;		
	}

	return i;
}

int Print_Selected_Node_Reverse(SCORE *head, int id, int num)
{
	int i = 0;

	head = Search_Id_Node(head, id);
	
	if(head == (SCORE *)0x0) return -1;

	while(i<num)
	{
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", head, head->id, head->name, head->jumsu, head->next, head->prev);
		i++;
		if(head->prev->prev == (SCORE *)0x0) break;
		head = head->prev;		
	}

	return i;
}

#endif

/***********************************************************/
// [2-3.2] ������ �ϳ��� �����Ͽ� Linked List�� �߰��ϴ� �Լ� (calloc ���)
/***********************************************************/

#if 1

int Insert_Node(SCORE * head, SCORE * d)
{
	SCORE * node=head; 
	SCORE * newnode; 

	while(node->next){
		if(d->id == node->next->id) return -2; 
		if(d->id < node->next->id) break; 
		node = node->next ;
	}
	newnode = (SCORE *) calloc(1, sizeof(SCORE));
	if (newnode == (SCORE *) 0 ) return -1; 
	*newnode = *d; 

	newnode -> next = node-> next;
	newnode -> prev = node ;

	node-> next = newnode; 
	if (newnode->next) newnode->next -> prev = newnode;  
	return 1; 
}

#endif

#if 0

int main(void)
{
	int i;

	for(i=0; i<8; i++)
	{
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &test[i]));
		printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	}
}

#endif

/***********************************************************/
// [2-3.3] �־��� ����� node�� ã�Ƽ� �����ϴ� �Լ�
/***********************************************************/

#if 1

int Delete_Node(SCORE * head, int id)
{
	SCORE * node=head; 

	while(node->next){
		if(id == node->next->id) {
			SCORE * delnode;
			delnode = node-> next; 
			if (delnode-> next) delnode->next-> prev = node;
			node->next = delnode->next; 
			free(delnode);
			return 1; 
		}
		node = node->next ;
	}
	return -1; 
}

#endif

#if 0

int main(void)
{
	int i;

	for(i=0; i<8; i++)
	{
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &test[i]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 8)); 
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 7)); 
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 1)); 
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 10)); 
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
}

#endif

#endif

/***********************************************************/
// [2-4] heap stack
/***********************************************************/

#if 0

#include <stdio.h>
#include <stdlib.h>

typedef struct _stk
{
	int num;
	struct _stk * next; 
}STACK;

STACK * Sptr = (STACK *)0;
STACK a[10] = {{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0},{10,0}};

int Push_Stack(STACK * data);
int Pop_Stack(STACK * p);
int Print_Stack(void);
int Count_Full_Data_Stack(void);

int Push_Stack(STACK *data)
{
	STACK *newnode = (STACK*)calloc(1, sizeof(STACK));
    if (newnode == (STACK*)0) return -1;
 
    *newnode = *data;
 
    newnode->next = Sptr;
    Sptr = newnode;
    return 1;
}

int Pop_Stack(STACK *p)
{
	STACK* delnode;
    if (Sptr == (STACK*)0) return -1;
 
    delnode = Sptr;
     
    *p = *Sptr;
    Sptr = Sptr->next;
 
    free(delnode);
 
    return 1;
}

int Print_Stack(void)
{
	// 여기서부터 작성
    int cnt = 0;
    STACK* node = Sptr;
    while (node) {
        printf("%d ", node->num);
        cnt++;
        node = node->next;
    }
    printf("\n");
    return cnt;
}

int Count_Full_Data_Stack(void)
{
	int cnt = 0;
    STACK* node = Sptr;
    while (node) {
        cnt++;
        node = node->next;
    }
    return cnt;
}

int main(void)
{
	int i;

	for(i=0; i<5; i++)
	{
		printf("Push Result = %d\n", Push_Stack(&a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d\n", Count_Full_Data_Stack());
	}

	for(i=0; i<6; i++)
	{
		printf("Pop Result = %d\n", Pop_Stack(&a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d\n ", Count_Full_Data_Stack());
	}

	for(i=0; i<3; i++)
	{
		printf("Push Result = %d\n", Push_Stack(&a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d\n", Count_Full_Data_Stack());
	}

	for(i=0; i<5; i++)
	{
		printf("Pop Result = %d\n", Pop_Stack(&a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d\n ", Count_Full_Data_Stack());
	}

	printf("\n");
}

#endif

/***********************************************************/
// [2-5] heap Linear Queue
/***********************************************************/

#if 0

#include <stdio.h>
#include <stdlib.h>

typedef struct _que
{
	int num;
	struct _que * next; 
}QUEUE;

QUEUE * Wrptr = (QUEUE *)0;;
QUEUE * Rdptr = (QUEUE *)0;;

QUEUE a[10] = {{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0},{10,0}};

int In_Queue(QUEUE * data);
int Out_Queue(QUEUE * p);
int Print_Queue(void);
int Count_Full_Data_Queue(void);

int In_Queue(QUEUE * data)
{
	QUEUE * newque = (QUEUE *) calloc(1, sizeof(QUEUE));
	if(newque == (QUEUE *) 0) return -1; 
	*newque = *data ;
	newque -> next = (QUEUE *)0;

	if (Rdptr ==(QUEUE *) 0 ) {
		Rdptr = newque; 
		Wrptr = newque; 	
	}
	else {
		Wrptr -> next = newque; 
		Wrptr = newque; 
	}

	return 1; 
}

int Out_Queue(QUEUE * p)
{

	QUEUE * delnode = Rdptr ;

	if(Rdptr == (QUEUE *)0) return -1; 
	*p = *Rdptr;

	if(Rdptr == Wrptr) {
		Rdptr = (QUEUE *)0;
		Wrptr = (QUEUE *)0;
	}
	else {
		Rdptr = Rdptr->next; 
	}
	free(delnode);
	return 1; 
}

int Print_Queue(void)
{
	QUEUE * node= Rdptr; 
	int cnt=0; 

	while(node){
		printf("address: 0x%.8X, contents: %d\n", node,  node->num);
		cnt ++; 
		if (node == Wrptr) break; 
		node = node->next; 
	}
	return cnt; 

}

int Count_Full_Data_Queue(void)
{
	QUEUE * node= Rdptr; 
	int cnt=0; 

	while(node){	
		cnt ++; 
		if (node == Wrptr) break; 
		node = node->next; 
	}
	return cnt; 
}

int main(void)
{
	int i;

	for(i=0; i<3; i++)
	{
		printf("Queue Result = %d\n", In_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d\n", Count_Full_Data_Queue());
	}

	for(i=0; i<2; i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d\n", Count_Full_Data_Queue());
	}

	for(i=0; i<4; i++)
	{
		printf("Queue Result = %d\n", In_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d\n", Count_Full_Data_Queue());
	}

	for(i=0; i<7; i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d\n", Count_Full_Data_Queue());
	}

	for(i=0; i<3; i++)
	{
		printf("Queue Result = %d\n", In_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d\n", Count_Full_Data_Queue());
	}

	for(i=0; i<3; i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d\n", Count_Full_Data_Queue());
	}
}

#endif

/***********************************************************/
// [3-1] ���� Tree�� �μ�
/***********************************************************/

#if 0

#include <stdio.h>

struct node
{
	char *name;
	struct node *left;
	struct node *right;
};

void Print_All_Node1(struct node *p);
void Print_All_Node2(struct node *p);
void Print_All_Node3(struct node *p);

int main(void)
{
	struct node root, node1, node2, node3, node4;

	root.left = &node1;
	root.right = &node2;
	root.name = "root";
	node1.left = &node3;
	node1.right = &node4;
	node1.name = "node1";
	node2.left = NULL;
	node2.right = NULL;
	node2.name = "node2";
	node3.left = NULL;
	node3.right = NULL;
	node3.name = "node3";
	node4.left = NULL;
	node4.right = NULL;
	node4.name = "node4";

	printf("In-order Traverse===============\n");
	Print_All_Node1(&root);
	printf("Pre-order Traverse===============\n");
	Print_All_Node2(&root);
	printf("Post-order Traverse===============\n");
	Print_All_Node3(&root);
}

void Print_All_Node1(struct node *p)
{
	if(p->left) Print_All_Node1(p->left);
	printf("Name = %s\n", p->name);
	if(p->right) Print_All_Node1(p->right);
}

void Print_All_Node2(struct node *p)
{
	printf("Name = %s\n", p->name);
	if(p->left) Print_All_Node2(p->left);
	if(p->right) Print_All_Node2(p->right);
}

void Print_All_Node3(struct node *p)
{
	if(p->left) Print_All_Node3(p->left);
	if(p->right) Print_All_Node3(p->right);
	printf("Name = %s\n", p->name);
}

#endif

/***********************************************************/
// [3-2] 이진트리
/***********************************************************/

#if 0

/***********************************************************/
// [3-2.1] ���� Ʈ���� ���� �⺻ �Լ���
/***********************************************************/

#if 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
	struct _score  * left;
	struct _score  * right;
	struct _score  * parent;
}SCORE;

SCORE *Root;

#define MAX_ST		20

// �������� ����Ǵ� ��� �Լ��� �� �κп� ������ �߰��Ѵ�

void Print_All_Node(SCORE * p);
void Delete_All_Node(SCORE * p);
int Insert_Node(SCORE * head, SCORE * d);
SCORE * Search_Node(SCORE * head, int id);
int Delete_Node(SCORE * head, int id);
SCORE * Creat_Node(SCORE * d);
int Create_Data(SCORE * p);

SCORE test[MAX_ST] = { { 10, 50, "kim" }, { 2, 80, "lew" }, { 8, 50, "lew" }, { 4, 45, "lee" }, { 1, 90, "song" }, \
{3, 45, "kim"}, { 5, 50, "song" }, { 9, 100, "lee" }, { 7, 75, "moon" }, { 6, 90, "park" }, \
{15, 90, "ki"}, { 11, 20, "kong" }, { 14, 40, "shin" }, { 12, 50, "son" }, { 17, 48, "lee" }, \
{20, 100, "min"}, { 19, 80, "you" }, { 13, 45, "song" }, { 16, 54, "no" }, { 18, 100, "yang" } };

int Create_Data(SCORE * p)
{
	printf("\n����� �Է��Ͻÿ� => ");
	scanf("%d", &p->id);
	printf("�̸��� �Է��Ͻÿ� => ");
	scanf("%s", p->name);
	printf("������ �Է��Ͻÿ� => ");
	scanf("%d", &p->jumsu);
	p->left = (SCORE *)0x0;
	p->right = (SCORE *)0x0;

	return 1;
}

void Print_All_Node(SCORE * p)
{

	if (p == (SCORE *)0)
	{
		printf("No Data\n");
		return;
	}

	if (p->left) Print_All_Node(p->left);
	printf("addr=0x%.8X, ID=%d, left=0x%.8X, right=0x%.8X, parent=0x%.8X\n", p, p->id, p->left, p->right, p->parent );
	if (p->right) Print_All_Node(p->right);
}

#endif

/***********************************************************/
// [3-2.2] ������ �ϳ��� �����Ͽ� Linked List�� �߰��ϴ� �Լ� (calloc ���)
/***********************************************************/

#if 1

SCORE * Creat_Node(SCORE * d)
{
	SCORE * p;

	p = calloc(1, sizeof(SCORE));
	if (p == (void *)0x0) return p;
	*p = *d;
	p->parent =(SCORE *)0 ;
	p->left  = (SCORE *)0 ;
	p->right = (SCORE *)0;  
	return p;
}

int Insert_Node(SCORE * head, SCORE * d)
{
	// 여기서부터 작성
    SCORE *newnode;
    SCORE *parent;
 
    newnode = Creat_Node(d);
    if (newnode == (SCORE*)0) return -1;
 
    if (head == (SCORE*)0) { // 최초 노드의 추가!
        Root = newnode;
    }
    else {
        parent = head;
        while (parent) {
            if (parent->id == newnode->id) {
                free(newnode);
                return -2;
            }
 
            if (parent->id > newnode->id) { // 왼쪽
                if (parent->left) parent = parent->left;
                else {
                    // newnode -> parent의 왼쪽 자식으로 연결!
                    parent->left = newnode;
                    newnode->parent = parent;
                    break;
                }
            }
            else {
                if (parent->right) parent = parent->right;
                else {
                    // newnode -> parent의 오른쪽 자식으로 연결!
                    parent->right = newnode;
                    newnode->parent = parent;
                    break;
                }
            }
        }
    }
    return 1;
}

#endif

#if 0

int main(void)
{
	int i;
	int r;

	for (i = 0; i<MAX_ST; i++)
	{
		printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", i, r = Insert_Node(Root, &test[i]), test[i].id);
		Print_All_Node(Root);
	}
}

#endif

/***********************************************************/
// [3-2.3] �־��� ����� node�� ã�Ƽ� ����� �ּҸ� �����ϴ� �Լ�
/***********************************************************/

#if 1

SCORE * Search_Node(SCORE * head, int id)
{
	SCORE * node = head ; 
	
	while(node){
		if (node ->id ==id) return node; 
		else if(node->id< id){
			if(node->right) node = node->right; 
			else{
				break;
			}
		}
		else {
			if(node->left) node = node->left; 
			else{
				break;
			}
		}
	}
	return (SCORE *)0 ;

}

#endif

#if 0

int main(void)
{
	int i;
	int r;
	SCORE * p;

	for (i = 0; i<8; i++)
	{
		printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", i, r = Insert_Node(Root, &test[i]), test[i].id);
	}

	Print_All_Node(Root);

	printf("Search Result = 0x%.8X\n", p = Search_Node(Root, 1));
	if (p) 	printf("addr=0x%.8X, ID=%d, left=0x%.8X, right=0x%.8X, parent=0x%.8X\n", p, p->id, p->left, p->right, p->parent );

	printf("Search Result = 0x%.8X\n", p = Search_Node(Root, 10));
	if (p)  printf("addr=0x%.8X, ID=%d, left=0x%.8X, right=0x%.8X, parent=0x%.8X\n", p, p->id, p->left, p->right, p->parent );

	printf("Search Result = 0x%.8X\n", p = Search_Node(Root, 9));
	if (p) 	printf("addr=0x%.8X, ID=%d, left=0x%.8X, right=0x%.8X, parent=0x%.8X\n", p, p->id, p->left, p->right, p->parent );

	printf("Search Result = 0x%.8X\n", p = Search_Node(Root, 4));
	if (p) 	printf("addr=0x%.8X, ID=%d, left=0x%.8X, right=0x%.8X, parent=0x%.8X\n", p, p->id, p->left, p->right, p->parent );

	printf("Search Result = 0x%.8X\n", p = Search_Node(Root, 7));
	if (p) 	printf("addr=0x%.8X, ID=%d, left=0x%.8X, right=0x%.8X, parent=0x%.8X\n", p, p->id, p->left, p->right, p->parent );
}


#endif

/***********************************************************/
// [3-2.4] �־��� ����� node�� ã�Ƽ� �����ϴ� �Լ�
/***********************************************************/

#if 1

void Delete_All_Node(SCORE * p)
{
	if (p->left) Delete_All_Node(p->left);
	if (p->right) Delete_All_Node(p->right);
	if (p == Root) Root  = (SCORE *)0;
	free(p);
}

#endif

/***********************************************************/
// [3-2.5] Leaf ����� ����
/***********************************************************/

#if 0

// ������ ��� ��尡 leaf�� ��� ���� �Լ�
// main �Լ����� "�ڽ� ���� ����� ����" �κи� ����

int Delete_Node(SCORE * head, int id)
{
	SCORE * r;

	r = Search_Node(head,id);

	if (r == NULL) return -1;


	free(r);
	return 1;
}

#endif

/***********************************************************/
// [3-2.6] Leaf �Ǵ� �ڽ��� �ϳ��� ��� ����
/***********************************************************/

#if 0

// ������ ��� ��尡 leaf �Ǵ� �ڽ��� �ϳ��� ��� ���� �Լ�
// main �Լ����� "�ڽ� ���� ����� ����" �κа� "�ڽ��� 1�� ����� ����" ���� ����

int Delete_Node(SCORE * head, int id)
{
	SCORE * r;
	SCORE * next; 

	r = Search_Node(head,id);

	// Ž�� ���� 
	if (r == NULL) return -1;

	// [1] �İ��� ����
	// leaf�̸� next�� NULL
	// �ڽ��� �ϳ��� ������ ����� left �Ǵ� right�� �����ϴ� �İ��� �ּҸ� next�� ����
	// �ڽ��� �ϳ��� NULL�� �ƴ� r->left �Ǵ� r->right�� �����Ѵ�

	// ���⼭���� �ۼ�






	// [2] �ڽ��� �ϳ� �ִ� ����� �İ��� parent�� ������ ����� �θ�� ����
	// �İ����� parent ��(next->parent)�� ������ ����� parent ��(r->parent)�� ����

	// ���⼭���� �ۼ�






	// [3] ������ ����� �θ��� left �Ǵ� right�� �İ��� ����
	// ������ ��尡 leaf ��� ������ Root�� ��� Root�� �İ��� �ּ�(next) ����
	// Root�� �ƴϸ� ���� ��带 �����ϰ� �ִ� �θ��� left �Ǵ� right�� �İ��� �ּ�(next) ����
	// leaf�� ���� �İ��ڿ� NULL�� �����Ͽ� �ξ����Ƿ� ������ �����Ͽ� �ۼ��� �ʿ䰡 ����

	// ���⼭���� �ۼ�






	free(r);
	return 1;
}

#endif

/***********************************************************/
// [3-2.7] �ڽ��� ���� ��� ����
/***********************************************************/

#if 0

// ������ ��� ��尡 �ڽ� �� �� ������ �����ϴ� ���� ���� �Լ�
// main �Լ����� ��� �ܰ踦 ���� �ǽ�

int Delete_Node(SCORE * head, int id)
{
	SCORE * next;			// �İ��� ���� ����
	SCORE * r;				// ������ ��� ���� ����

	r = Search_Node(head,id);
	if (r == NULL) return -1;

	// �ڽ��� ���̸� �İ��� Ž�� �� �İ��ڸ� ������ ����� �����Ϳ� �����ϰ� ���������� r�� �İ��� �ּ� ����

	if ((r->left != NULL) && (r->right != NULL))
	{
		// �ʿ�� �������� �����Ӱ� �����Ͽ� ���
		// �İ��� ������ ������ ��忡 ������ �� parent, left, right�� ���� ���� ����� ���� �����ؾ� �Ѵ�
		// �� ��ũ���� �״�� �����ϰ� ������ ������ �����Ͽ��� �Ѵ�

		// ���⼭���� �ۼ�






	}

	// �ڽ��� ���̸� r�� ������ ��� �ּҰ� ����Ǿ� �ְ� �ϳ��ų� leaf�̸� ó������ ���� ����� ��� ����
	// ���� �Ʒ� �ڵ�� �ڽ� ���� �����ϰ� ���� leaf �� �ڽ� �ϳ��� ��� ���� �ڵ�� ������

	if(r->left) next = r->left;
	else next =  r->right;

	if(next) next->parent = r->parent;

	if(r != Root)
	{
		if(r == r->parent->left ) r->parent->left = next;
		else  r->parent->right = next;
	}
	else
	{
		Root = next;
	}

	free(r);
	return 1;
}

#endif

#if 0

// [3-2.5], [3-2.6], [3-2.7] �������� ����ϴ� main() �Լ�

void main(void)
{
	int i;
	int r;

	/* �ڽ� ���� ����� ���� */

#if 0

	// 1. Root Only ����	

	printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", 0, r = Insert_Node(Root, &test[0]), test[0].id);
	Print_All_Node(Root);
	printf("Delete Node #10 Result = %d\n", Delete_Node(Root, 10));
	Print_All_Node(Root);

#endif

#if 0

	// 2. Left Leaf ��� ���� 

	for (i = 0; i<7; i++)
	{
		printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", i, r = Insert_Node(Root, &test[i]), test[i].id);
	}
	Print_All_Node(Root);
	printf("Delete Node #3 Result = %d, Root = %d\n", Delete_Node(Root, 3), Root->id);
	printf("Delete Node #1 Result = %d, Root = %d\n", Delete_Node(Root, 1), Root->id);
	Print_All_Node(Root);
	Delete_All_Node(Root);

#endif

#if 0

	// 3. Right Leaf ��� ���� 

	for (i = 0; i<20; i++)
	{
		printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", i, r = Insert_Node(Root, &test[i]), test[i].id);
	}
	Print_All_Node(Root);
	printf("Delete Node #13 Result = %d, Root = %d\n", Delete_Node(Root, 13), Root->id);
	printf("Delete Node #9 Result = %d, Root = %d\n", Delete_Node(Root, 9), Root->id);
	Print_All_Node(Root);
	Delete_All_Node(Root);

#endif

	/* �ڽ��� 1�� ����� ���� */

#if 0

	// 1. Left�� �ִ� Root ���� 

	for (i = 0; i<10; i++) printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", i, r = Insert_Node(Root, &test[i]), test[i].id);
	Print_All_Node(Root);
	printf("Delete Node #10 Result = %d, Root = %d\n", Delete_Node(Root, 10), Root->id);
	Print_All_Node(Root);
	Delete_All_Node(Root);

#endif

#if 0

	// 2. Right�� �ִ� Root ���� 

	printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", 0, r = Insert_Node(Root, &test[0]), test[0].id);
	for (i = 10; i<20; i++) printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", i, r = Insert_Node(Root, &test[i]), test[i].id);
	Print_All_Node(Root);
	printf("Delete Node #10 Result = %d, Root = %d\n", Delete_Node(Root, 10), Root->id);
	printf("Delete Node #8 Result = %d, Root = %d\n", Delete_Node(Root, 8), Root->id);
	Print_All_Node(Root);
	Delete_All_Node(Root);

#endif

#if 0

	// 3. Left�� �ִ� ��� ���� 

	for (i = 0; i<20; i++) printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", i, r = Insert_Node(Root, &test[i]), test[i].id);
	Print_All_Node(Root);
	printf("Delete Node #7 Result = %d, Root = %d\n", Delete_Node(Root, 7), Root->id);
	printf("Delete Node #19 Result = %d, Root = %d\n", Delete_Node(Root, 19), Root->id);
	printf("Delete Node #14 Result = %d, Root = %d\n", Delete_Node(Root, 14), Root->id);
	Print_All_Node(Root);
	Delete_All_Node(Root);

#endif

#if 0

	// 4. Right�� �ִ� ��� ���� 

	for (i = 0; i<20; i++) printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", i, r = Insert_Node(Root, &test[i]), test[i].id);
	Print_All_Node(Root);
	printf("Delete Node #5 Result = %d, Root = %d\n", Delete_Node(Root, 5), Root->id);
	printf("Delete Node #12 Result = %d, Root = %d\n", Delete_Node(Root, 12), Root->id);
	printf("Delete Node #11 Result = %d, Root = %d\n", Delete_Node(Root, 11), Root->id);
	Print_All_Node(Root);
	Delete_All_Node(Root);

#endif

	/* �ڽ��� ���� ����� ����  */

#if 0

	// 1. Root ���� 

	for (i = 0; i<20; i++) printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", i, r = Insert_Node(Root, &test[i]), test[i].id);
	Print_All_Node(Root);
	printf("Delete Node #10 Result = %d, Root = %d\n", Delete_Node(Root, 10), Root->id);
	Print_All_Node(Root);
	Delete_All_Node(Root);

#endif

#if 0

	// 2. �߰� ��� ���� 

	for (i = 0; i<20; i++) printf("[Loop: %d] Insert Node Result=%d, ID=%d\n", i, r = Insert_Node(Root, &test[i]), test[i].id);
	Print_All_Node(Root);
	printf("Delete Node #2 Result = %d, Root = %d\n", Delete_Node(Root, 2), Root->id);
	Print_All_Node(Root);
	printf("Delete Node #15 Result = %d, Root = %d\n", Delete_Node(Root, 15), Root->id);
	Print_All_Node(Root);
	printf("Delete Node #3 Result = %d, Root = %d\n", Delete_Node(Root, 3), Root->id);
	Print_All_Node(Root);
	printf("Delete Node #4 Result = %d, Root = %d\n", Delete_Node(Root, 4), Root->id);
	Print_All_Node(Root);
	Delete_All_Node(Root);

#endif
}

#endif

#endif

/***********************************************************/
// [3-3] Hash Table
/***********************************************************/

#if 0

/***********************************************************/
// [3-3.1] Hash Table�� ���� �⺻ �Լ���
/***********************************************************/

#if 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _score 
{
	int id;
	int jumsu;
	char name[10];
}SCORE;

#define MAX_ST		20
#define HASH_KEY	10
#define STEP		1

SCORE Hash_table[MAX_ST];

// �������� ����Ǵ� ��� �Լ��� �� �κп� ������ �߰��Ѵ�

int Create_Data(SCORE * p);
int Get_Hash_Key(int id);
void Init_Hash_Table(void);
void Print_All_Data(void);
int Insert_Data(SCORE * d);
SCORE * Search_Data(int id);
int Delete_Data(int id);

SCORE test[MAX_ST+2] = {{10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
                               {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}, \
                               {15, 90, "ki"}, {11, 20, "kong"}, {14, 40, "shin"}, {12, 50, "son"}, {17, 48, "lee"}, \
                               {20, 100, "min"}, {19, 80, "you"}, {13, 45, "song"}, {16, 54, "no"}, {18, 100, "yang"}, \
							   {21, 58, "seo"}, {23, 88, "oh"}}; 

int Create_Data(SCORE * p)
{
	printf("\n����� �Է��Ͻÿ� => ");
	scanf("%d", &p->id);
	printf("�̸��� �Է��Ͻÿ� => ");
	scanf("%s", p->name);
	printf("������ �Է��Ͻÿ� => ");
	scanf("%d", &p->jumsu);

	return 1;
}

int Get_Hash_Key(int id)
{
	return id % HASH_KEY;
}

void Init_Hash_Table(void)
{
	int i;

	for(i=0; i<MAX_ST; i++)
	{
		Hash_table[i].id = -1;
	}
}

#endif

#if 1

void Print_All_Data(void)
{
	int i;

	for(i=0; i<MAX_ST; i++)
	{
		if(Hash_table[i].id != -1) printf("[%d] ID: %d, NAME: %s\n", i, Hash_table[i].id, Hash_table[i].name);
	}
}

#endif

#if 1

int main(void)
{
	int i;
	int r;

	Init_Hash_Table();

	for(i=0; i<(MAX_ST+2); i++)
	{
		printf("[Loop: %d] Inserted Position=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
		Print_All_Data();
	}
}

#endif

/***********************************************************/
// [3-3.3] Search
/***********************************************************/

#if 1

SCORE * Search_Data(int id)
{
	int hash = Get_Hash_Key(id) ; 
	int org_hash = hash; 
	do {
		if (Hash_table[hash].id ==-1) break; 
		if (Hash_table[hash].id == id) return &Hash_table[hash]; 
		hash = (hash+1)%HASH_KEY; 
	}while(org_hash != hash);
	return (SCORE *) 0; 

}

#endif

#if 0

int main(void)
{
	int i;
	int r;
	SCORE * p;

	Init_Hash_Table();

	for(i=0; i<15; i++)
	{
		printf("[Loop: %d] Inserted Position=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
	}

	Print_All_Data();
	printf("Serch Result=0x%.8X\n", p = Search_Data(3));
	if(p) printf("ID=%d, NAME=%s\n", p->id, p->name);
	printf("Serch Result=0x%.8X\n", p = Search_Data(12));
	if(p) printf("ID=%d, NAME=%s\n", p->id, p->name);
	printf("Serch Result=0x%.8X\n", p = Search_Data(25));
	if(p) printf("ID=%d, NAME=%s\n", p->id, p->name);
}

#endif

/***********************************************************/
// [3-3.5] ���� ��� ID�� -2�� �ϵ��� delete �Լ� ���踦 �ٽ� �����Ѵ�
// ���� ������ �޶����鼭 Insert ������ �����Ǿ�� �Ѵ�. 
// ������ Insert �Լ��� ����Ǹ� [3-3.2]���� ����� Insert_Data �Լ��� �����Ѵ�
/***********************************************************/

#if 1

int Delete_Data(int id)
{
	SCORE * p; 
	p = Search_Data(id);
	if(p == (SCORE *) 0) return -1; 
	p->id = -2; 
	return 1;
}

int Insert_Data(SCORE * d)
{
	int hash = Get_Hash_Key(d->id) ; 
	int org_hash =0;
	if(Search_Data(d->id)) return -2;  

	do{
		if(Hash_table[hash].id == -1 ||Hash_table[hash].id ==-2) {
			Hash_table[hash] = *d ; 
			return hash;
		} 
		hash = (hash +STEP) % HASH_KEY; 
	}while(org_hash != hash) ; 
	return -1; 
}

void Print_All_Data(void)
{
	int i;

	for(i=0; i<MAX_ST; i++)
	{
		if((Hash_table[i].id != -1) && (Hash_table[i].id != -2)) printf("[%d] ID: %d, NAME: %s\n", i, Hash_table[i].id, Hash_table[i].name);
	}
}

#endif

#if 0

int main(void)
{
	int i;
	int r;

	Init_Hash_Table();

	for(i=0; i<15; i++)
	{
		printf("[Loop: %d] Inserted Position=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
	}

	Print_All_Data();
	printf("[3] Delete Result=%d\n", r = Delete_Data(3));
	printf("[12] Delete Result=%d\n", r = Delete_Data(12));
	printf("[25] Delete Result=%d\n", r = Delete_Data(25));
	printf("[3] Delete Result=%d\n", r = Delete_Data(3));
	printf("[12] Delete Result=%d\n", r = Delete_Data(12));
	Print_All_Data();

	printf("Inserted Position=%d, ID=%d\n", r = Insert_Data(&test[13]), test[13].id);
	printf("Inserted Position=%d, ID=%d\n", r = Insert_Data(&test[5]), test[5].id);
	Print_All_Data();
}

#endif

#endif

/***********************************************************/
// [3-4] Hash Table => 개방형
/***********************************************************/

#if 0

/***********************************************************/
// [3-4.1] Hash Table�� ���� �⺻ �Լ���
/***********************************************************/

#if 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _score 
{
	int id;
	int jumsu;
	char name[10];
}SCORE;

#define MAX_ST		20

#if 0
	#define HASH_KEY	10
	#define STEP		1
#else
	#define HASH_KEY	7  // ������ �Ҽ�
	#define STEP		9  // ���̺��� ��Ҽ��� ���� �� ������ ��
#endif

SCORE Hash_table[MAX_ST];

// �������� ����Ǵ� ��� �Լ��� �� �κп� ������ �߰��Ѵ�

int Create_Data(SCORE * p);
int Get_Hash_Key(int id);
void Init_Hash_Table(void);
void Print_All_Data(void);
int Insert_Data(SCORE * d);
SCORE * Search_Data(int id);
int Delete_Data(int id);

SCORE test[MAX_ST+2] = {{10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
                               {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}, \
                               {15, 90, "ki"}, {11, 20, "kong"}, {14, 40, "shin"}, {12, 50, "son"}, {17, 48, "lee"}, \
                               {20, 100, "min"}, {19, 80, "you"}, {13, 45, "song"}, {16, 54, "no"}, {18, 100, "yang"}, \
							   {21, 58, "seo"}, {23, 88, "oh"}}; 

int Create_Data(SCORE * p)
{
	printf("\n����� �Է��Ͻÿ� => ");
	scanf("%d", &p->id);
	printf("�̸��� �Է��Ͻÿ� => ");
	scanf("%s", p->name);
	printf("������ �Է��Ͻÿ� => ");
	scanf("%d", &p->jumsu);

	return 1;
}

int Get_Hash_Key(int id)
{
	return id % HASH_KEY;
}

void Init_Hash_Table(void)
{
	int i;

	for(i=0; i<MAX_ST; i++)
	{
		Hash_table[i].id = -1;
	}
}

void Print_All_Data(void)
{
	int i;

	for(i=0; i<MAX_ST; i++)
	{
		if((Hash_table[i].id != -1) && (Hash_table[i].id != -2)) printf("[%d] ID: %d, NAME: %s\n", i, Hash_table[i].id, Hash_table[i].name);
	}
}

int Delete_Data(int id)
{
	SCORE * p;

	p = Search_Data(id);
	if(p == (SCORE *)0) return -1;
	p->id = -2;
	return 1;
}

int Insert_Data(SCORE * d)
{
	int pos, key;
	int cnt = 0, ret = -1;
	static int insert_cnt;

	// if (Search_Data(d->id) != NULL) return -2;

	pos = key = Get_Hash_Key(d->id);

	for(;;)
	{
		cnt++;

		if((Hash_table[pos].id == -1) || (Hash_table[pos].id == -2))
		{
			Hash_table[pos] = *d;
			ret = pos;
			break;
		}

		pos += STEP;
		if(pos >= MAX_ST) pos %= MAX_ST;
		if(pos == key) break;
	}

	insert_cnt += cnt;
	printf("cnt = %d, total insert count = %d\n", cnt, insert_cnt);
	return ret;
}

SCORE * Search_Data(int id)
{
	int pos, key;
	int cnt = 0;
	SCORE *ret = (SCORE *)0;
	static int search_cnt; 

	pos = key = Get_Hash_Key(id);

	for(;;)
	{
		cnt++;

		if(Hash_table[pos].id == id) 
		{
			ret = &Hash_table[pos];
		}
		if(Hash_table[pos].id == -1) break;
		pos += STEP;
		if(pos >= MAX_ST) pos %= MAX_ST;
		if(pos == key) break;
	}

	search_cnt += cnt;
	printf("cnt = %d, total search count = %d\n", cnt, search_cnt);
	return ret;
}
#endif

/***********************************************************/
// [3-4.2] Insert ȿ��
/***********************************************************/

#if 0

int main(void)
{
	int i;
	int r;

	Init_Hash_Table();

	for(i=0; i<MAX_ST; i++)
	{
		printf("[Loop: %d] Inserted Position=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
		Print_All_Data();
	}
}

#endif

/***********************************************************/
// [3-4.3] Search ȿ��
/***********************************************************/

#if 0

int main(void)
{
	int i;
	int r;
	SCORE * p;

	Init_Hash_Table();

	for(i=0; i<15; i++)
	{
		printf("[Loop: %d] Inserted Position=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
	}

	Print_All_Data();
	printf("Serch Result=0x%.8X\n", p = Search_Data(3));
	if(p) printf("ID=%d, NAME=%s\n", p->id, p->name);
	printf("Serch Result=0x%.8X\n", p = Search_Data(12));
	if(p) printf("ID=%d, NAME=%s\n", p->id, p->name);
	printf("Serch Result=0x%.8X\n", p = Search_Data(25));
	if(p) printf("ID=%d, NAME=%s\n", p->id, p->name);
}

#endif

/***********************************************************/
// [3-4.4] Insert, Search, Delete
/***********************************************************/

#if 0

int main(void)
{
	int i;
	int r;

	Init_Hash_Table();

	for(i=0; i<15; i++)
	{
		printf("[Loop: %d] Inserted Position=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
	}

	Print_All_Data();
	printf("[3] Delete Result=%d\n", r = Delete_Data(3));
	printf("[12] Delete Result=%d\n", r = Delete_Data(12));
	printf("[25] Delete Result=%d\n", r = Delete_Data(25));
	printf("[3] Delete Result=%d\n", r = Delete_Data(3));
	printf("[12] Delete Result=%d\n", r = Delete_Data(12));
	Print_All_Data();

	printf("Inserted Position=%d, ID=%d\n", r = Insert_Data(&test[13]), test[13].id);
	printf("Inserted Position=%d, ID=%d\n", r = Insert_Data(&test[5]), test[5].id);
	Print_All_Data();
}

#endif

#endif

/***********************************************************/
// [3-5] Hash Table => Chainning ����� ����
/***********************************************************/

#if 0

/***********************************************************/
// [3-5.1] Hash Table�� ���� �⺻ �Լ���
/***********************************************************/

#if 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _score 
{
	int id;
	int jumsu;
	char name[10];
	struct _score * next;
}SCORE;

#define MAX_ST		20
#define HASH_KEY	5

SCORE Hash_table[MAX_ST];

int Create_Data(SCORE * p);
int Get_Hash_Key(int id);
void Init_Hash_Table(void);
void Print_All_Data(void);
int Insert_Data(SCORE * d);
SCORE * Search_Data(int id);
int Delete_Data(int id);

SCORE test[MAX_ST+2] = {{10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"},\
                               {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}, \
                               {15, 90, "ki"}, {11, 20, "kong"}, {14, 40, "shin"}, {12, 50, "son"}, {17, 48, "lee"}, \
                               {20, 100, "min"}, {19, 80, "you"}, {13, 45, "song"}, {16, 54, "no"}, {18, 100, "yang"}, \
							   {21, 58, "seo"}, {23, 88, "oh"}}; 

int Create_Data(SCORE * p)
{
	printf("\n����� �Է��Ͻÿ� => ");
	scanf("%d", &p->id);
	printf("�̸��� �Է��Ͻÿ� => ");
	scanf("%s", p->name);
	printf("������ �Է��Ͻÿ� => ");
	scanf("%d", &p->jumsu);

	return 1;
}

int Get_Hash_Key(int id)
{
	return id % HASH_KEY;
}

void Init_Hash_Table(void)
{
	int i;

	for(i=0; i<MAX_ST; i++)
	{
		Hash_table[i].next = (SCORE *)0;
	}
}

void Print_All_Data(void)
{
	int i;
	SCORE * p;

	for(i=0; i<MAX_ST; i++)
	{
		p = Hash_table[i].next;

		for(;;)
		{
			if(p == (SCORE *)0) break;
			printf("[%d] address:0x%.8X, ID: %d, NAME: %s, next: 0x%.8X\n", i, p, p->id, p->name, p->next);
			p = p->next;
		}
	}
}

#endif

/***********************************************************/
// [3-5.2] Insert
/***********************************************************/

#if 1

int Insert_Data(SCORE * d)
{
	int hash = d->id % HASH_KEY; 
	SCORE * node = &Hash_table[hash]; 
	SCORE * newnode = (SCORE *) calloc(1, sizeof(SCORE));
	if (newnode == (SCORE *)0) return -1; 
	*newnode = *d;

	while (node->next){
		if (node->next->id == d->id) return -2; 
		if (node->next ->id ==-1){
			break; 
		}
		node = node->next; 
	}
	node->next = newnode; 
	newnode -> next = (SCORE *) 0;
	return 1; 
}


#endif

#if 0

int main(void)
{
	int i;
	int r;

	Init_Hash_Table();

	for(i=0; i<MAX_ST; i++)
	{
		printf("[Loop: %d] Insert Result=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
		Print_All_Data();
	}
}

#endif

/***********************************************************/
// [3-5.3] Delete
/***********************************************************/

#if 1

int Delete_Data(int id)
{
	SCORE * delnode; 
	int hash = Get_Hash_Key(id); 
	SCORE * node= &Hash_table[hash];

	while (node->next){
		if (node->next -> id == id) {
			delnode = node->next; 
			node->next = delnode->next; 
			free(delnode); 
			return 1; 
		}
		node = node->next; 
	}
	return -1; 
}

#endif

#if 0

int main(void)
{
	int i;
	int r;

	Init_Hash_Table();

	for(i=0; i<MAX_ST; i++) printf("[Loop: %d] Insert Result=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
	Print_All_Data();

	printf("[1] Delete Result=%d\n", r = Delete_Data(1));
	printf("[11] Delete Result=%d\n", r = Delete_Data(11));
	printf("[16] Delete Result=%d\n", r = Delete_Data(16));
	printf("[9] Delete Result=%d\n", r = Delete_Data(9));
	printf("[10] Delete Result=%d\n", r = Delete_Data(10));
	Print_All_Data();

	printf("Inserted Position=%d, ID=%d\n", r = Insert_Data(&test[1]), test[1].id);
	printf("Inserted Position=%d, ID=%d\n", r = Insert_Data(&test[11]), test[11].id);
	Print_All_Data();
}

#endif

/***********************************************************/
// [3-5.4] Search
/***********************************************************/

#if 1

SCORE * Search_Data(int id)
{
	int hash = Get_Hash_Key(id); 
	SCORE * node = & Hash_table[hash]; 

	while(node->next){
		if (node->next->id == id) return node->next; 
		node= node->next; 
	}
	return (SCORE *) 0; 
}

#endif

#if 0

int main(void)
{
	int i;
	int r;
	SCORE * p;

	Init_Hash_Table();

	for(i=0; i<MAX_ST; i++) printf("[Loop: %d] Insert Result=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
	Print_All_Data();

	printf("Serch Result=0x%.8X\n", p = Search_Data(3));
	if(p) printf("address:0x%.8X, ID: %d, NAME: %s, next: 0x%.8X\n", p, p->id, p->name, p->next);
	printf("Serch Result=0x%.8X\n", p = Search_Data(12));
	if(p) printf("address:0x%.8X, ID: %d, NAME: %s, next: 0x%.8X\n", p, p->id, p->name, p->next);
	printf("Serch Result=0x%.8X\n", p = Search_Data(25));
	if(p) printf("address:0x%.8X, ID: %d, NAME: %s, next: 0x%.8X\n", p, p->id, p->name, p->next);
}

#endif

#endif

/***********************************************************/
// [3-6] Hash Table => ���� ����� ���� Chainning ���
/***********************************************************/

#if 0

/***********************************************************/
// [3-6.1] Hash Table�� ���� �⺻ �Լ���
/***********************************************************/

#if 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
	struct _score * next;
}SCORE;

#define MAX_ST		20
#define HASH_KEY	5

SCORE Hash_table[HASH_KEY];



int Create_Data(SCORE * p);
int Get_Hash_Key(int id);
void Init_Hash_Table(void);
void Print_All_Data(void);
int Insert_Data(SCORE * d);
SCORE * Search_Data(int id);
int Delete_Data(int id);

SCORE test[MAX_ST + 2] = { { 10, 50, "kim" }, { 2, 80, "lew" }, { 8, 50, "lew" }, { 4, 45, "lee" }, { 1, 90, "song" }, \
{3, 45, "kim"}, { 5, 50, "song" }, { 9, 100, "lee" }, { 7, 75, "moon" }, { 6, 90, "park" }, \
{15, 90, "ki"}, { 11, 20, "kong" }, { 14, 40, "shin" }, { 12, 50, "son" }, { 17, 48, "lee" }, \
{20, 100, "min"}, { 19, 80, "you" }, { 13, 45, "song" }, { 16, 54, "no" }, { 18, 100, "yang" }, \
{21, 58, "seo"}, { 23, 88, "oh" } };

int Create_Data(SCORE * p)
{
	printf("\n����� �Է��Ͻÿ� => ");
	scanf("%d", &p->id);
	printf("�̸��� �Է��Ͻÿ� => ");
	scanf("%s", p->name);
	printf("������ �Է��Ͻÿ� => ");
	scanf("%d", &p->jumsu);

	return 1;
}

int Get_Hash_Key(int id)
{
	return id % HASH_KEY;
}

void Init_Hash_Table(void)
{
	int i;

	for (i = 0; i < MAX_ST; i++)
	{
		Hash_table[i].next = (SCORE *)0;
	}
}

void Print_All_Data(void)
{
	int i;
	SCORE * p;

	for (i = 0; i < MAX_ST; i++)
	{
		p = Hash_table[i].next;

		for (;;)
		{
			if (p == (SCORE *)0) break;
			printf("[%d] address:0x%.8X, ID: %d, NAME: %s, next: 0x%.8X\n", i, p, p->id, p->name, p->next);
			p = p->next;
		}
	}
}

#endif

/***********************************************************/
// [3-6.2] Insert
/***********************************************************/

#if 1

int Insert_Data(SCORE * d)
{
	int hash;
    SCORE *newnode;
    // 여기서부터 작성
    if (Search_Data(d->id)) return -2;
 
    hash = Get_Hash_Key(d->id);
    newnode = (SCORE*)calloc(1, sizeof(SCORE));
    if (newnode == (SCORE*)0) return -1;
 
    *newnode = *d;
 
    newnode->next = Hash_table[hash].next;
    Hash_table[hash].next = newnode;
 
    return 1;
}

#endif

#if 0	

void main(void)
{
	int i;
	int r;

	Init_Hash_Table();

	for (i = 0; i < MAX_ST; i++)
	{
		printf("[Loop: %d] Insert Result=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
		Print_All_Data();
	}
}

#endif

/***********************************************************/
// [3-6.3] Delete
/***********************************************************/

#if 1

int Delete_Data(int id)
{
	int hash = Get_Hash_Key(id); 
	SCORE * node = &Hash_table[hash]; 
	while(node->next){
		if(node->next -> id == id){
			SCORE * delnode =  node->next; 
			node-> next = delnode->next; 
			free(delnode); 
		return 1; 
		}
		node= node-> next; 
	}
	return -1; 
}

#endif

#if 0

int main(void)
{
	int i;
	int r;

	Init_Hash_Table();

	for (i = 0; i < MAX_ST; i++) printf("[Loop: %d] Insert Result=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
	Print_All_Data();

	printf("[1] Delete Result=%d\n", r = Delete_Data(1));
	printf("[11] Delete Result=%d\n", r = Delete_Data(11));
	printf("[16] Delete Result=%d\n", r = Delete_Data(16));
	printf("[9] Delete Result=%d\n", r = Delete_Data(9));
	printf("[10] Delete Result=%d\n", r = Delete_Data(10));
	Print_All_Data();

	printf("Inserted Position=%d, ID=%d\n", r = Insert_Data(&test[1]), test[1].id);
	printf("Inserted Position=%d, ID=%d\n", r = Insert_Data(&test[11]), test[11].id);
	Print_All_Data();
}

#endif

/***********************************************************/
// [3-6.4] Search
/***********************************************************/

#if 1

SCORE * Search_Data(int id)
{
	// 여기서부터 작성
    int hash = Get_Hash_Key(id);
    SCORE* node = Hash_table[hash].next;
    while (node) {
        if (node->id == id) return node;
        node = node->next;
    }
    return (SCORE*)0;






}

#endif


#if 0

void main(void)
{
	int i;
	int r;
	SCORE * p;

	Init_Hash_Table();

	for (i = 0; i < MAX_ST; i++) printf("[Loop: %d] Insert Result=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
	Print_All_Data();

	printf("Serch Result=0x%.8X\n", p = Search_Data(3));
	if (p) printf("[%d] address:0x%.8X, ID: %d, NAME: %s, next: 0x%.8X\n", i, p, p->id, p->name, p->next);
	printf("Serch Result=0x%.8X\n", p = Search_Data(12));
	if (p) printf("[%d] address:0x%.8X, ID: %d, NAME: %s, next: 0x%.8X\n", i, p, p->id, p->name, p->next);
	printf("Serch Result=0x%.8X\n", p = Search_Data(25));
	if (p) printf("[%d] address:0x%.8X, ID: %d, NAME: %s, next: 0x%.8X\n", i, p, p->id, p->name, p->next);
}

#endif

#endif