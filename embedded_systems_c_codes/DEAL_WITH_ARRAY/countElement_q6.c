#include<stdio.h>
int countOccurrences(int arr[], int size, int element){
	int count=0;
	for(int i=0;i<size;i++){
		if(arr[i]==element){
			count++ ;
		}
	}
	return count;
}
void main(){
	int aro[]={1,2,3,4,3,2,3};
	int z= countOccurrences(aro,7,3);
	int x= countOccurrences(aro,7,2);
	printf("%d\n%d",z,x);
}