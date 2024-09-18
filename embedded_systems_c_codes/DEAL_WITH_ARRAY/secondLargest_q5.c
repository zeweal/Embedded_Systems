#include<stdio.h>
int findSecondLargest(int arr[], int size){
    int i,max=0,k,maxx=0;
	for(i=0;i<size;i++){
		if(arr[i]>max){
			max=arr[i];
			k=i;
		}
	}
	int temp;
	temp=arr[k];
	arr[k]=arr[0];
	arr[0]=temp;
	for(int j=1;j<size;j++){
		if(arr[j]>maxx){
			maxx=arr[j];
		}
	}
	return maxx;
}
void main(){
	int aro[5]={5,1,4,3,2};
	int z=findSecondLargest(aro,5);
	printf("%d",z);
}