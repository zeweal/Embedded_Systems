#include<stdio.h>
void reverseArray(int arr[], int size){
	int i;
	for(i=0;i<(size/2);i++){
		int temp;
		temp=arr[i];
		arr[i]=arr[size-i-1];
		arr[size-i-1]= temp;
	}
	printf("{");
	for(i=0;i<size-1;i++){
		printf("%d, ",arr[i]);
	}
	printf("%d}",arr[size-1]);

}
void main(){
	int aro[5]={1,2,3,4,5};
	printf("aro = ");
	reverseArray(aro,5);
}