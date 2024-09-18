#include <stdio.h>
#include <stdlib.h>
void data(void*x,int n){
	for(int i=0;i<n;i++){
		printf("%p --> %d\n",x,*(char*)x);
		x+=1;
	}
}
void main(){
	int z=50;
	data(&z,5);
}