#include<stdio.h>
void mergeArrays(int arr1[], int size1,int arr2[], int size2, int result[]){
	int i;
	for(i=0;i<size1;i++){
		result[i]=arr1[i];
	}
	for(i=0;i<(size2);i++){
		result[size1+i]=arr2[i];
	}
	
	for(i=0; i<(size1+size2)-1; i++){
        for(int j=i+1; j<(size1+size2); j++){
            if(result[i]>result[j]){
                int temp=result[i];
                result[i]=result[j];
                result[j]=temp;
            }
        }
    }
	for(i=0;i<(size1+size2);i++){
		printf("%d ", result[i]);
	}
}
void main(){
	int aro1[3]={1,7,5};
	int aro2[3]={2,4,6};
	int res[6];
	mergeArrays(aro1,3,aro2,3,res);
}