#include<stdio.h>
#include<stdlib.h>

void dupPointer(int*);
int* dupPointerFix(int*);

int main(void){
	int *ptr;
	//dupPointer(ptr);   //<---Problematic!
	int* ptr2 = dupPointerFix(ptr);  //Either return a pointer or skip the funtion altogether > One way to fix it
	//ptr = (int *)malloc(sizeof(int));
	//*ptr = 5;
	*ptr2 = 5;   //This statement is fine.
	//printf("%d\n",*ptr);
	printf("%d\n",*ptr2);
	if(ptr==NULL)printf("\tPOINTER TROUBLES\n");
	getchar();
}

/*
Uncomment this function to reveal the troubles
*/

/*void dupPointer(int* p){
	p = (int *)malloc(sizeof(int));
}*/

int* dupPointerFix(int* p){
	p = (int *)malloc(sizeof(int));
	return p;
}
