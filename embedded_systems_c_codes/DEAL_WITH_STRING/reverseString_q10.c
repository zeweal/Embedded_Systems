#include<stdio.h>
void reverseString(char str[]){

	char i='A';
	int count=-1;
	int b=0,k=0;
	while(i!='\0'){
		
		i=str[b];
		count++;
		b++;
	}
	int m=count-1;
	while(k!=m){
		char temp =str[k];
		str[k]=str[m];
		str[m]=temp;
		m--;
		k++;
	}
	for(b=0;b<count;b++){
		printf("%c",str[b]);
	}

}
void main(){
	char st[]="Hello";
	reverseString(st);
}