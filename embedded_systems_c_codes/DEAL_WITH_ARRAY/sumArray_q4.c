#include<stdio.h>
int sumArray(int arr[], int size){
	int i,sum=0;
	for(i=0;i<size;i++){
		sum+=arr[i];
	}
	return sum;
}
void main(){
	int aro[5]={1,2,3,4,7};
	int z=sumArray(aro,5);
	printf("%d",z);
}