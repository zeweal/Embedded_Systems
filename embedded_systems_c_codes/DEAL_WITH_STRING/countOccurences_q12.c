#include<stdio.h>
int countCharOccurrences(char str[],char ch){
char i='A';
int count=-1;
int b=0;
int counter=0;	
while(i!='\0'){
		
		i=str[b];
		count++;
		b++;
	}
for(int k=0;k<count;k++){
	if(str[k]==ch){
		counter++;
	}
}
return counter;	
}
void main(){
	char s[]="programming";
	int z=countCharOccurrences(s,'g');
	printf("%d",z);
}