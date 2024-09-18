#include <stdio.h>
#include <stdlib.h>
void swap2(int** ptr1,int** ptr2){
int* temp=*ptr1;
*ptr1=*ptr2;
*ptr2=temp;
printf("%d    %d\n",**ptr1,**ptr2);
}
void main(){
	int x=6;
	int y=90;
	int*pp=&x;
	int*oo=&y;
	printf("%d   %d\n",*pp,*oo);
	swap2(&pp,&oo);
}