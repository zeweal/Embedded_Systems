#include<stdio.h>
int removeDuplicates(int arr[], int size){
	int i,j;
	int *ptr=arr;
	for(i=1;i<size;i++){
		if(*ptr==arr[i]){
		for(j=i+1;j<size;j++){
			if(arr[i]==arr[j]){
				size--;
			}
		}
         size--;
		}
		ptr++;
	}
	return size;
}
void main(){
	int aro[]={1,2,2,3,3,4};
	int z=removeDuplicates(aro,6);
	printf("%d",z);
}