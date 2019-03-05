#include<stdio.h>
#include<stdlib.h>

struct listnode{
  int value;
  struct listnode * next;	//Pointer to next node
};


int isEven(int number);
int isEven(int number){
  //printf("Is %d even \n", number);
       if(number % 2 == 0){
         //printf("Even: %d \n", number);
         return -1;
       } else {
         //printf("Odd: %d \n", number);
         return 1;
       }

}
//#include <stdio.h>
//Linked List as user defined type


void traverseA(int * arr, int length){
   // printf("\n");
  for(int k=0; k<length-1; k++){
    printf("%d	", arr[k]);
  }
	printf("%d", arr[length-1]);
    
}
void traverse(struct listnode* mylist){

  struct listnode * t1 = mylist;

  while(t1 != NULL){
    printf("%d\n", t1->value);
    t1 = t1->next;
  }

  return;
}
void sort(int *number, int n) {

    /* Sort the given array number, of length n */
    int temp = 0, j, i;

    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            if (number[j] > number[j + 1]) {
                temp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = temp;
            }
        }
    }
}

int* array(struct listnode* mylist, int length){

    struct listnode * t1 = mylist;
    int odd=0;
    int even=0;
    int evens[length];
    int odds[length];
    while(t1 != NULL){

      if(isEven(t1->value)==-1){
        evens[even]=t1->value;
        even=even+1;
      }else{
        odds[odd]=t1->value;
        odd=odd+1;
      }
      t1 = t1->next;
    }
   // traverseA(odds, odd);
   // traverseA(evens, even);
    int i=0;
    int g=0;
    sort(evens, even);
    sort(odds, odd);
    int *all = malloc (sizeof (int) * length);
    
    while(even!=0){
      all[i]= evens[i];
      i=i+1;
      even=even-1;
    }
    while(odd!=0){
      all[i]= odds[g];
      i=i+1;
      g=g+1;
      odd=odd-1;
    }
    return all;
}

int main (int argc, char** argv) {
   //char str1[1000];
   int a;
   
  // TO manually enter a file name:
   //printf("Enter file name: ");
  // scanf("%s", str1);
  // printf("Entered File Name: %s\n", str1);
   FILE * fp;

   fp = fopen (argv[1], "r");
	if(fp==NULL){
	printf("error");
	return 0;
	}
   int i=0;
   fscanf(fp,"%s ", argv[1] );
    argc = atoi(argv[1]);
  // fscanf(fp,"%s %s %s", str1, str2, str3 );
 // printf("%d\n", argc);
  struct listnode * head = NULL;
   while(fscanf(fp,"%d ", &a)==1 ){
     i=i+1;
 //   printf("Read String %d |%d|\n", i, &a );
     struct listnode * temp = (struct listnode *) malloc(sizeof(struct listnode));


     // printf("The a of the %dth value: %d\n",i, a);
     temp->value = a;		//Assigns first a to first element in list
     temp->next = head;		//Must use arrow operator bc structure
      head = temp;		//Adding to beginning of list
   }
//printf("\n");


  int* ans=array(head, argc);

  traverseA(ans,argc);
 

   return(0);
}
