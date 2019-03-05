

#include<stdio.h>
#include<stdlib.h>

struct BST{
  int value;
  struct BST * right;    //Pointer to next node
  struct BST * left;    //Pointer to next node
  int level;
};
int check(struct BST* node, int d){
if (node == NULL) {
        return -1; 
	}
	int k=0;
	int j=0;
     k =check(node->left,d); 
     j= check(node->right, d); 
    if(node->value==d){
	//printf("y\n");
	return node->level;

	}
	if(j!=-1 ){
	return j;
	}
	if(k!=-1 ){
	return k;
	}
	return -1;

}
void traverse(struct BST* node) 
{ 
     if (node == NULL) {
        return; 
	}

     traverse(node->left); 
     traverse(node->right); 
     printf("%d", node->value); 
} 
  

struct BST*  add(struct BST* ye, int value){
 struct BST * node = (struct BST *) malloc(sizeof(struct BST));
 //ptr=ye;
struct BST * ptr=ye;
 node->value=value;
node->level=1;
 if(ptr==NULL){
   //node->level=1;
	//printf("yaba\n");
   node->right=NULL;
   node->left=NULL;
	node->level=1;
   ye=node;
	//traverse(ye);
   return ye;
 }
 
 int level=1;
 //struct BST * ptr=ye;
  struct BST * prev=NULL;
 int c=0;
 while (ptr!=NULL) {
	node->level=level;
    if(ptr->value>value){
      c=1;
    } else {
      c=-1;
    }
   prev=ptr;
    if(c<0){
      ptr=ptr->left;
      level=level+1;
	node->level=level;
    } else {
      ptr=ptr->right;
      level=level+1;
	node->level=level;
    }
	
  }
  //node->level=level;
	//ptr->level=prev->level+1;
    if(prev==NULL) {
            //empty tree
            prev= node;
        } else if(c<0) {
            prev->left=node;
        }else{
            prev->right=node;
        }
return ye;

}
int main(int argc, char** argv) {
    FILE * fp;
 // int r=0;
   fp = fopen (argv[1], "r");
	if(fp==NULL){
	printf("error");
	return 0;
	}
   char a;
	int d=0;
   struct BST * head = NULL;
  while(fscanf(fp,"%c ", &a)==1 ){
    fscanf(fp,"%d ", &d);
  /*  if(a=='d'){
    //  fscanf(fp,"%d ", &d);
      if(check(head, d)==1){
        printf("error");
      }
      delete(head, d)
    }*/
	 //printf("A= %c\n", a);
      if(a=='s'){
        if (check(head, d)!=-1){
        printf("present %d\n", check(head, d));
        } else {
        printf("absent\n");
        }

        }
      if(a=='i'){
      if(  check(head, d)==-1){
	
      head=add(head, d);
	printf("inserted %d\n", check(head, d));
      } else {
      printf("duplicate\n");
      }
      }
      //traverse(head);
      }
	
     free(head);

}



