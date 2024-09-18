#include <stdio.h>
#include <stdlib.h>
 int sum(void* ptr1,void* ptr2){
	 int a=*(int*)ptr1;
	 int b=*(char*)ptr2;
 return a+b;	
}
void main(){
	int x=5;
	char y=9;
	int z= sum(&x,&y);
	printf("%d",z);
}