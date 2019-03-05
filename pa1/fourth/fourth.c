#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) { 
	FILE * fp;

   fp = fopen (argv[1], "r");
	if(fp==NULL){
	printf("error");
	return 0;
	}
    int r;
int j;
int m;
  	fscanf(fp,"%d ", &r );
	fscanf(fp,"%d ", &m );
    int ** matrix;
	//i=0;
	j=0;
  matrix = (int**) malloc(r * sizeof(int *));
//int solution=0;
  for(int i = 0; i < r; i++){
    matrix[i] = (int *) malloc(m * sizeof(int));
  }
	//printf("%d", matrix[2][2]);
	 for(int k = 0; k < r; k++){
		
		for(int i = 0; i < m; i++){
			
			fscanf(fp,"%d", &j);
	 		matrix[k][i]=j;
			//printf("%d ", j);
			
		}
	//printf("\n");

	}
//printf("\n");
//printf("err01\n");
	int u;
	int p;
	fscanf(fp,"%d ", &u );
	fscanf(fp,"%d ", &p );
	//printf("err02\n");
  	int ** matrix2;
	matrix2 = (int**) malloc(u * sizeof(int *));
	//printf("err03\n");
	for(int i = 0; i < u; i++){
   	 matrix2[i] = (int *) malloc(p * sizeof(int));
 	 }
	//printf("err04\n");
	for(int k = 0; k < u; k++){
		//printf("err0%d\n", k);
		for(int i = 0; i < p; i++){
			//printf("err0%d/%d\n", k,i);
			fscanf(fp,"%d", &j);
	 		matrix2[k][i]=j;
			//printf("%d ", j);
			
		}
	//printf("\n");
}
	if(m!=u){
		printf("bad-matrices\n");
		return 0;
	}
	//int result=0;
	int multiply=0;
	int ** matrix3;
	matrix3 = (int**) malloc(r * sizeof(int *));
	for(int i = 0; i < r; i++){
    		matrix3[i] = (int *) malloc(p * sizeof(int));
	}
	//printf("\n");
	//int y=0;
	//int e=0;
	/*if(p<r){
	y=p;
	e=r;
	} else { 
	y=r;
	e=p;
	}*/
	for(int k = 0; k<r; k++){
	
		
		for(int i = 0; i < p; i++){
			multiply=0;
			
			for(int b=0; b<m; b++){
				multiply=0;
				
				for(int f=0; f<u; f++){
				
				//printf("(%d, %d, k= %d, i= %d, b= %d, f= %d) \n",matrix[k][b], matrix2[f][i], k, i, b, f);
				
				multiply=multiply+(matrix[k][f]*matrix2[f][i]);
				//printf("que?: %d\n", multiply);
				}
				
			}
			matrix3[k][i]=multiply;
			//printf(" 4: %d\t", multiply);
  		}
		//printf("\n");
			
	}
	int first=1;
	for(int k = 0; k<r; k++){
		for(int i = 0; i < p; i++){
			if (first==0){
				printf("\t");
			}
			printf("%d", matrix3[k][i]);
			first=0;
		}
		first=1;
		printf("\n");
	}
}
