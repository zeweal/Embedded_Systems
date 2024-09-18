#include<stdio.h>
int isSorted(int arr[], int size){
	int i,k;
	for(i=0;i<size-1;i++){
		
		if(arr[i] <= arr[i+1]){
			k=1;
		}
		else{
			k=0;
			break;
		}
	}
	return k;
}
void main(){
	int aro[5]={1,2,3,6,16};
	int z= isSorted(aro,5);
	printf("%d",z);
}