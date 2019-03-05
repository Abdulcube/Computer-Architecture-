#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define SIZE 10000

struct node {
   int data;
   //int key;
   struct node *next;
};
typedef struct node node;

int code(int data) {
	if(data<0){
	data=data*-1;
	}
   return data % 10000;
}


struct node **hashmap =NULL;

struct node* create(int value){
struct node *step = (struct node* )calloc(2,sizeof(struct node*));
step->data=value;
step->next=NULL; 
return step;
}
void createTable(){
hashmap = (struct node**) calloc(1,sizeof(struct node*)* 10000);
return;
}

void add(struct node* ye){
	//printf(" ooga booga\n");
	int key=code(ye->data);
	//printf("key: %d ", key);
	struct node *step = NULL;
 	 if(hashmap[key]==NULL){
  	 	 hashmap[key]=ye;
  	//  printf("first in spot\n");
 	   return;
 	 }

  	for(step=hashmap[key]; step!=NULL; step=step->next){

  		
  	}
  		ye->next=hashmap[key];
  		hashmap[key] = ye;
  		//printf("method 2\n");
  	return;
  	}
int check(int data){
	//printf(" ooga booga\n");
	int key=code(data);
//printf("check :  %d, key: %d\n", data, key);
	struct node *step = NULL;
 	 if(hashmap[key]==NULL){
  	 	 
  	 // printf("first in spot\n");
 	   return -1;
 	 }
	if(hashmap[key]->data==data){
	//printf("second in spot\n");
	return 1;
	}
	
//printf("check2 \n");
  	for(step=hashmap[key]; step!=NULL; step=step->next){
		//printf("Step: %d\n", step->data);
  		if(data==step->data){
       		//printf("check :  %d, key: %d\n", step->data, data);
		
  		    return 1;
  		}
  	}
  		//printf("check23 \n");
  		//printf("method 2\n");
  	return -1;
  	}

/*int check(int b){
	//printf("check %d\n", b);
  int key;
  struct node *temp = NULL;
  key =code(b);
//printf("check 35:  %d, key: %d,", b, key);
  if(hashmap[key] ==NULL){
  //  printf("absent\n");
    return -1;
  }
//printf("check2: %d\n", b);
	if(hashmap[key]->data==b){
	return 1;
	}
//printf("check 3:  %d\n", b);

for(temp=hashmap[key]; temp !=NULL; temp = temp->next){
	if(b==temp->data){
	//printf("present\n");
	 return 1;
	}
}
//printf("check 4:  %d\n", b);
	//printf("absent\n");
	return -1;
}*/

int main (int argc, char** argv) {
	
   char a;
int d=0;

   FILE * fp;
   fp = fopen (argv[1], "r");
	if(fp==NULL){
	printf("error");
	
	} else {
   createTable();
	
	
   while(fscanf(fp,"%c ", &a)==1 ){
    fscanf(fp,"%d ", &d);
	//printf("scan\n");
      if(a=='s'){
	//printf("search: %d\n", d);
	
         if (check(d)==1){
            printf("present\n");
          } else {
            printf("absent\n");
          }
        }
      if(a=='i'){
	
          if( check(d)==-1){
		
		
		struct node* assum=create(d);
	
		
              	add(assum);
               printf("inserted\n");
		//printf("check 3: %d\n", check(d));
           } else {
             printf("duplicate\n");
           }
         }
	
      }
}

}
