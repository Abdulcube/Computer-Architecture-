

#include<stdio.h>
#include<stdlib.h>

struct BST{
  int value;
  struct BST * right;    //Pointer to next node
  struct BST * left;    //Pointer to next node
  int level;
};
int check(struct BST* node, int d, int level){
if (node == NULL) {
        return -1; 
	}
	level=level+1;
	int k=0;
/*printf(" root value %d\n", root->value);
	printf(" left value %d\n", root->left->value);
	printf(" minimum value %d\n", temp->value);*/
	int j=0;
     k =check(node->left,d, level); 
     j= check(node->right, d, level); 
    if(node->value==d){
	//printf("y\n");
	//printf("check xl %d\n", node->value );
	return level;

	}
	if(j!=-1 ){
	return j;
	}
	if(k!=-1 ){
	return k;
	}
	return -1;

}
struct BST* minValueNode(struct BST* node) 
{ 
    struct BST* theOneTHaTTHEMANDEMARE = node; 
  
    /* loop down to find the leftmost leaf */
    while (theOneTHaTTHEMANDEMARE->left != NULL) 
        theOneTHaTTHEMANDEMARE = theOneTHaTTHEMANDEMARE->left; 
  
    return theOneTHaTTHEMANDEMARE; 
}
struct BST* levels(struct BST* node, int level){
	//printf("jsdfhdsfhkjasdfgdsjfhdskfgdskhjgf\n");
	if (node == NULL) {
        return NULL; 
	}

	level=level+1;
	
	levels(node->right, level);
	node->level=level;
	//level=level+1;
	//printf("node : %d , level : %d\n", node->value, level);
	
    	levels(node->left, level);
	return node;

}
/*struct BST* rebalance(struct BST* root, int key){
	while
	return root;
}*/
struct BST* delete(struct BST* root, int key){
 /*printf(" root value %d\n", root->value);
	printf(" left value %d\n", root->left->value);
	printf(" minimum value %d\n", temp->value);*/
    // base case 
    if (root == NULL){
	 return root;
	 }
    if (key < root->value) {
        root->left = delete(root->left, key); 
  
   } else if (key > root->value) {
        root->right = delete(root->right, key); 
    } else{ 
	/*printf(" root value %d\n", root->value);
	printf(" left value %d\n", root->left->value);
	printf(" minimum value %d\n", temp->value);*/
        if (root->left == NULL) { 
            struct BST *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) { 
            struct BST *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        struct BST* temp = minValueNode(root->right);
	/*printf(" root value %d\n", root->value);
	printf(" left value %d\n", root->left->value);
	printf(" minimum value %d\n", temp->value);*/
        root->value = temp->value; 
  
        root->right = delete(root->right, temp->value); 
    } 
   //levels(root, 0);
	
  return root;

}

void please(struct BST* node, int d, int levels) 
{  
     if (node == NULL) {
        return; 
	}
	levels=levels+1;
     please(node->left, d, levels);  
	if(node->value==d){
		printf(" %d\n", levels);
	}
     please(node->right, d, levels); 
     
} 
void traverse(struct BST* node) 
{  
     if (node == NULL) {
        return; 
	}

     traverse(node->left);  
	/* just for the mandem ;)printf("-------Value :%d Level :%d\n", node->value, node->level);*/
     traverse(node->right); 
     
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
      c=-1;
    } else {
      c=1;
    }/*printf(" root value %d\n", root->value);
	printf(" left value %d\n", root->left->value);
	printf(" minimum value %d\n", temp->value);*/
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
    if(a=='d'){
	//traverse(head);
    //  fscanf(fp,"%d ", &d);
      if(check(head, d, 0)==-1){
        printf("fail\n");
      } else{
      	head=delete(head, d);
	head=levels(head,0);
	
	printf("success\n");
	traverse(head);
	}
	head=levels(head, 0);
    }
	 //printf("A= %c\n", a);
      if(a=='s'){
	//printf("present");
        if (check(head, d, 0)!=-1){
	//head=levels(head,0);
	
        printf("present");
	
	please(head, d, 0);
	traverse(head);
        } else {
        printf("absent\n");
        }

        }
      if(a=='i'){
      if(  check(head, d, 0)==-1){
	
      head=add(head, d);
	levels(head, 0);
	printf("inserted");
	 please(head, d, 0);
	
      } else {
      printf("duplicate\n");
      }
      }
      //traverse(head);
	//head=levels(head,0);
      }

}


