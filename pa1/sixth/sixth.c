#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct listnode{
  char* value;
  struct listnode * next;	//Pointer to next node
};
int vowel(char c){
int isLowercaseVowel, isUppercaseVowel;
	//1 if vowel
	//0 if cons
// evaluates to 1 (true) if c is a lowercase vowel
    isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');

    // evaluates to 1 (true) if c is an uppercase vowel
    isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    // evaluates to 1 (true) if either isLowercaseVowel or isUppercaseVowel is true
    if (isLowercaseVowel || isUppercaseVowel){
        return 1;
    }else{
        return 0;
    }
}

int main (int argc, char** argv) {


   char a[2500];
   
   int i=1;
int length=1;
	
	int yeet=0;
int vow=1;
int cond=1;
//printf("%d\n", argc);
 while(argc>cond){

	
	strcpy(a,argv[cond]);
	if(yeet==1){
	printf(" ");
	}
	yeet=1;
	i=1;
	vow=1;
	
	length=strlen(a);
	
	if(length!=0){
	
		if(vowel(a[0])==1){
		
			printf("%syay", a);

		} else {
			if(vowel(a[1])==1){
				while( i<length){
					printf("%c", a[i]);
					i=i+1;
				}
			
				printf("%cay", a[0]);
				i=i+1;
			} else {

		
			for(vow=1; vowel(a[vow]);vow++){}
			
			i=vow+1;
			while( i<length){
				
				printf("%c", a[i]);
				i=i+1;
			}
			i=0;
			while(vow>=i){
				
				printf("%c", a[i]);
				i=i+1;
			}
			printf("ay");
			
		}
	
	}
}
cond=cond+1;	
}
printf("\n");
}
