#include<stdio.h>
#include<stdlib.h>

struct listnode{
  int value;
  struct listnode * next;	//Pointer to next node
};
int traverse(struct listnode* mylist, int length){
  int x=0;
  struct listnode * t1 = mylist;
  printf("%d\n", length);
  while(length > 1 ){

    printf("%d\t", t1->value);
    t1 = t1->next;
    x=x+1;
	length=length-1;
	

  }
	if (length==1){
	printf("%d\n", t1->value);
}

  return x;
}
int check(int num, struct listnode* mylist){

  struct listnode * t1 = mylist;

  while(t1 != NULL){
    //printf("%d\n", t1->value);
    if(t1->value==num){
      return 1;
    }
    t1 = t1->next;
  }

  return 0;
}
/*void delete(int num, struct listnode* mylist){

  struct listnode * t1 = mylist;
  if(t1->value==num){
    t1=t1->next;
    return;
  }
  while(t1 != NULL){
    printf("%d\n", t1->value);
    if(t1->next->value==num){
      t1->next=t1->next->next;
      return;
    }
    t1 = t1->next;
  }

  return;
}*/
void add(int num, struct listnode* ye ){
    if(check(num, ye)==1){
      return;
    } else {
 struct listnode * temp = (struct listnode *) malloc(sizeof(struct listnode));
      temp->value = num;		//Assigns first a to first element in list
      temp->next = ye;		//Must use arrow operator bc structure
       ye = temp;
    }
    //traverse(ye);
}
int main (int argc, char** argv) {

   char a;
   FILE * fp;
   fp = fopen (argv[1], "r");
	if(fp==NULL){
	printf("error");
	return 0;
	}
   int i=0;

  // printf("%d\n", );
   struct listnode * head = NULL;
  int levels=0;
   while(fscanf(fp,"%c ", &a)==1 ){
    //printf("initial %c\n", a );
      i=i+1;
  //   printf("Read String %d |%d|\n", i, &a );
      //struct listnode * temp = (struct listnode *) malloc(sizeof(struct listnode));
      int d;

      int deletes=1;
      struct listnode * t1=head;
      if(a=='d'){
        //printf("Done 5?\n" );
        fscanf(fp,"%d ", &d);

          if(check(d, head)==1){
              //printf("Done 4?\n" );
            while(deletes==1){
                //printf("Done 1?\n" );
              //  traverse(head);
              //  printf("%d\n",t1->value );

                if (t1->value==d&& t1->next==NULL){
                  //printf("Done 6?\n" );
                    head=NULL;
                    deletes=0;


                } else if (t1->value==d&& t1->next!=NULL){
                  //printf("Done 7?\n" );
                    head=head->next;
                    deletes=0;
                }else if(t1->next->value==d&& t1->next->next!=NULL){

                //  printf("Done 2?\n" );

                t1->next=t1->next->next;
                deletes=0;
              } else if(t1->next->value==d&& t1->next->next==NULL){
                  t1->next=NULL;
                  deletes=0;
              }else{
                t1=t1->next;
                levels=levels+1;
              }
            //  printf("Done 8?\n" );
            }
            levels=levels-1;
      }
    //  printf("levels deleted: %d\n", levels );
  //    traverse(head);
      //printf("Done 6?\n" );
      }
    int add=0;

      if(a=='i'){
        fscanf(fp,"%d ", &d);
          //printf("add %d\n", d );
        //  printf("%d\n", check(d, head));
        if(levels==0){
          if(check(d, head)!=1){
            struct listnode * temp = (struct listnode *) malloc(sizeof(struct listnode));
             temp->value = d;		//Assigns first a to first element in list
             temp->next = head;		//Must use arrow operator bc structure
              head = temp;
              levels=levels+1;

            }
        } else{

          if(check(d, head)!=1){


            while(add!=1){

              if(t1->next==NULL&& t1->value>d){
                struct listnode * temp = (struct listnode *) malloc(sizeof(struct listnode));
                 temp->value = d;		//Assigns first a to first element in list
                 temp->next = head;		//Must use arrow operator bc structure
                  head = temp;
                  levels=levels+1;
                //  printf("\nadd1\n" );
                   add=1;

              }  else if(t1->next==NULL&& t1->value<d){
                  struct listnode * temp = (struct listnode *) malloc(sizeof(struct listnode));
                   temp->value = d;		//Assigns first a to first element in list
                   t1->next = temp;		//Must use arrow operator bc structure
                    levels=levels+1;
                    //printf("\nadd2\n" );
                     add=1;
                } else if(t1->value<d && t1->next->value<d){

                t1=t1->next;
                add=0;
                  //printf("\nadd3\n" );
              //  printf("levels added2: yega %d\n", levels );
                } else if(t1->next->value>d && t1->value<d){
                //printf("Done 5?\n" );
                struct listnode * temp = (struct listnode *) malloc(sizeof(struct listnode));
                   temp->value = d;		//Assigns first a to first element in list
                   temp->next = t1->next;		//Must use arrow operator bc structure
                    t1->next = temp;
                 levels=levels+1;
                 add=1;
                //   printf("\nadd4\n" );
              } else if(t1->value>d && head==t1){
                struct listnode * temp = (struct listnode *) malloc(sizeof(struct listnode));
                   temp->value = d;		//Assigns first a to first element in list
                  temp->next = head;		//Must use arrow operator bc structure
                  head = temp;
                  levels=levels+1;
              //  traverse(head);
                add=1;
              } else{
                add=1;
              //  printf("ERROR YOUNGBULL\n" );
              }
            }
          }
        }

          //printf("levels added: %d\n", levels );


  //    traverse(head);
    }


      // printf("The a of the %dth value: %d\n",i, a);
    /*  printf("\n-------------\n" );
        printf("D: %d\n", d );
        traverse(head);
        printf("\n-------------\n" );*/
  //    printf("Done 7?\n" );
    }
  //  printf("Levels: %d\n", levels);
    //printf("\n__________\n" );
    traverse(head, levels);
  //  printf("\n__________\n" );
    return 0;
  }

