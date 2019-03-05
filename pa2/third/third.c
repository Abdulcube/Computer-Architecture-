#include <stdio.h>
#include <stdlib.h>

int ** matrix=NULL;

void traverse(){
  for(int k = 0; k < 9; k++){
     for(int i = 0; i < 9; i++){
         printf("%d\t", matrix[k][i]);
     }
      printf("\n");
  }
}

int isColumns(int column, int number){
  for(int k = 0; k < 9; k++){
    if(matrix[k][column]==number){
      return 1;
    }
  }
  return -1;
}

int isrow(int row, int number){
  for(int k = 0; k < 9; k++){
    if(matrix[row][k]==number){
      return 1;
    }
  }
  return -1;
}

int isbox(int row, int column, int number){
  int ro=-1;
  int col=-1;

  if(row<=2 && column<=2){
    //box 1
    ro=0;
    col=0;
  } else if(column<=5 && column>2 && row<=2){
    //box 2
    ro=0;
    col=3;
  } else if(column<=8 && column>5 && row<=2){
  //box 3
    ro=0;
    col=6;
  } else if(column<=2 && row>2 && row<=5){
  //box 4
  ro=3;
  col=0;
  } else if(column<=5 && column>2 && row>2 && row<=5){
  //box 5
    ro=3;
    col=3;
  } else if(column<=8 && column>5 && row>2 && row<=5){
    //box 6
    ro=3;
    col=6;
  } else if(column<=2 && row>5 && row<=8){
    //box 7
    ro=6;
    col=0;

  } else if(column<=5 && column>2 && row>5 && row<=8){
  //box 8
    ro=6;
    col=3;
  } else if(column<=8 && column>5 && row>5 && row<=8){
      //box 9
      ro=6;
      col=6;
  }

  if(ro==-1|| col==-1){
    printf("ABu ABDA comeone\n");
  }

  for(int k = ro; k < ro+2; k++){
    for(int r = col; r < col+2; r++){

      if(matrix[k][r]==number){

        return 1;
      }
    }
  }
  return -1;
}

int complete(){

  for(int k = 0; k < 9; k++){
    for(int r = 0; r < 9; r++){
    	if(matrix[k][r]==0){
    		return -1;
    	}
    }
  }
//  printf("lo\n");
  return 1;
}

int nextR(){
  for (int i = 0; i < 9; i++) {
    for (int k = 0; k < 9; k++) {
      if(matrix[i][k]==0){
        return i;
      }
    }
  }
  return -1;
}

int nextC(){
  for (int i = 0; i < 9; i++) {
    for (int k = 0; k < 9; k++) {
      if(matrix[i][k]==0){
        return k;
      }
    }
  }
  return -1;
}


int checker(){
  for(int k = 0; k < 9; k++){
    for(int r = 0; r < 9; r++){
      int x=matrix[k][r];
      matrix[k][r]=0;
      if(x!=0){
        if(isColumns(r,x)==1||isrow(k,x)==1||isbox(k,r,x)==1){
          return -1;
        }
      }
      matrix[k][r]=x;
    }
  }
  return 1;
}




int solve(){
  if(complete()==1){
  //  printf("++++++++++++\n");
    return 1;
  }
  int result=-1;
  int r=nextR();
  int c=nextC();
  //printf("r: %d, c: %d\n", r, c );
  for (int i = 1; i <= 9; i++) {
    //printf("I: %d,column: %d, Row: %d, box: %d\n", i ,isColumns(c, i), isrow(r, i),isbox(r, c, i) );
    if(isColumns(c, i)==-1 && isrow(r, i)==-1 && isbox(r, c, i)==-1){
      //printf("i: %d, row: %d, column: %d\n", i, r, c);
      matrix[r][c]=i;
    //  printf("?\n");
    //  traverse();
    //  printf("\n");

     result =solve();
     //printf("y\n");

    }
  //  printf("z\n");
    if(result==1){
    //  printf("result==1\n");
       break;
    }
  }
//printf("q\n");
  if(result==1){
  //  printf("return 1\n");
    return 1;
  } else {
    matrix[r][c]=0;
  //    printf("return 2 r: %d, c: %d\n", r, c );
  return -1;
}
}

 int main(int argc, char** argv){
   FILE* doc;
   doc=fopen(argv[1],"r");
   if(doc==NULL){
     printf("error");
     return 0;
   }
   char j;

   int f=0;
   matrix = (int **) malloc(9 * sizeof(int *));
   //rows
   for(int i = 0; i < 9; i++){
     matrix[i] = (int *) malloc(9 * sizeof(int));
     //columns
   }
   for(int k = 0; k < 9; k++){
       for(int i = 0; i < 9; i++){
      fscanf(doc,"%c ,", &j);
      if(j=='-'){
        f=0;
      } else {
        f=j-'0';
      }
       matrix[k][i]=f;
    //	printf("j: %f\n", j);
    }
  }
	//int x=-1;
	
	//traverse();
	
  
  solve();
	
  

  for(int k = 0; k < 9; k++){
     for(int i = 0; i < 9; i++){
         printf("%d", matrix[k][i]);
					if(i!=8){
						printf("\t");
					}
  		}
      printf("\n");
  }
  
   return 0;
 }

