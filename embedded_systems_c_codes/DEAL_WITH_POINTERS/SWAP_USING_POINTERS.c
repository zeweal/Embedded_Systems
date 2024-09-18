#include <stdio.h>
#include <stdlib.h>
void swap(int* x,int* y){
	int temp=*x;
	*x=*y;
	*y=temp;
	printf("%d %d",*x,*y);
}
void main(){
	int j=10;
	int k=20;
	swap(&j,&k);
}