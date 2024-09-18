#include<stdio.h>
void removeSpaces(char str[]){
	char i='A';
    int count=-1;
    int b=0;
    int counter=0;	
    while(i!='\0'){
		
		i=str[b];
		count++;
		b++;
	}
	int size=count;
	for(b=0;b<count;b++){
		if(str[b]==' '){
			continue;
		}
		printf("%c",str[b]);
	}
}
void main(){
	char s[]="h e l l o w o r l d";
	removeSpaces(s);
}