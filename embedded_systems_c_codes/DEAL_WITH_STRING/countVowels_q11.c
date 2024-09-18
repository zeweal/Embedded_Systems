#include<stdio.h>
int countVowels(char str[]){
char i='A';
int count=-1;
int b=0;
int counter=0;	
while(i!='\0'){
		
		i=str[b];
		count++;
		b++;
	}
for(b=0;b<count;b++){
	    if(str[b]=='a'||str[b]=='o'||str[b]=='e'||str[b]=='u'||str[b]=='i'){
			counter++;
		}
}
return counter;
}
void main(){
	char s[]="hello world";
	int z=countVowels(s);
	printf("%d",z);
}