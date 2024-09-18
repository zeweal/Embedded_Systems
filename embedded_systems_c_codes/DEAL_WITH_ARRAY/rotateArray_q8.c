#include<stdio.h>
void rotateArray(int arr[], int size, int positions){
	int i,k,j;
	 int temp[size];
    for(int i=0; i<size; i++){
        temp[(i+positions)%size] = arr[i];
	}
	for(i=0;i<size;i++){
		printf("%d ",temp[i]);
	}
}
void main(){
	int aro[5]={1,2,3,4,5};
	rotateArray(aro,5,2);
}