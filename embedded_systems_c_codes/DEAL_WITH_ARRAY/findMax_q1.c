#include<stdio.h>
int findMax(int arr[],int size){
	int i,max=0;
	for(i=0;i<size;i++){
		if(arr[i] > max){
			max=arr[i];
		}
	}
	
	return max;
}
void main(){
	int aro[5]={5,8,2,9,1};
	int z= findMax(aro,5);
	printf("The output is %d",z);
}