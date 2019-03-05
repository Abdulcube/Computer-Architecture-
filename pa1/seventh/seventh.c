#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main (int argc, char** argv) {
 
int cond=1;
while(argc>cond){
	int length=strlen(argv[cond]);
	//strcpy(a,argv[cond]);
	printf("%c", argv[cond][length-1]);
	cond=cond+1;
	}
}
