#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) 
{ 
	FILE * fp;

   fp = fopen (argv[1], "r");
	if(fp==NULL){
	printf("error");
	return 0;
	}
    int r;
int j;
//int i;
  	fscanf(fp,"%d ", &r );
    int ** matrix;
	//i=0;
	j=0;
  matrix = (int**) malloc(r * sizeof(int *));
int solution=0;
  for(int i = 0; i < r; i++){
    matrix[i] = (int *) malloc(r * sizeof(int));
  }
	//printf("%d", matrix[2][2]);
	 for(int k = 0; k < r; k++){
		
		for(int i = 0; i < r; i++){
			
			fscanf(fp,"%d", &j);
	 		matrix[k][i]=j;
			//printf("%d", j);
			if(k==0){
				solution=solution+j;
			}
		}
//printf("\n");
}
int rows=0;
int diagonals=0;
int columns=0;
int rtrue=0;
int ctrue=0;
int dtrue=0;
int add=0;

	for(int x = 0; x < r; x++){
		
		for(int y = 0; y < r; y++){
			for(int k = 0; k < r; k++){
		
				for(int i = 0; i < r; i++){
					if(matrix[k][i]==matrix[x][y]&& k!=x){
						printf("not-magic\n");
						return 0;
					}

				}
			}
		}
	}
	
	while(rows<r&&rtrue==0){
		add=0;
		
		for(int k=0; k<r;k++){
			//matrix[rows][k];
			add=add+(matrix[rows][k]);
		}
		//printf("%d:r", add);
		if(add!=solution){
			rtrue=1;
			rows=r;
		} 
		rows=rows+1;
	}
	//printf("%d", rtrue);
	
	while(columns<r&&ctrue==0){
		
		add=0;
		for(int k=0; k<r;k++){
			//matrix[rows][k];
			add=add+(matrix[k][columns]);
			
		}
		//printf("%d\n c", add);
		if(add!=solution){
			ctrue=1;
			columns=r;
		} 
		columns=columns+1;
	}
	//printf("%d", ctrue);
		
	while(diagonals<r&&dtrue==0){
		
		add=0;
		for(int k=0; k<r;k++){
			//matrix[rows][k];
			add=add+(matrix[k][diagonals]);
			
		}
		//printf("%d\n d", add);
		if(add!=solution){
			dtrue=1;
			diagonals=r;
		} 
		diagonals=diagonals+1;
	}
	if(ctrue==1 || rtrue==1 || dtrue==1){
		printf("not-magic\n");
	} else {
		printf("magic\n");
	}
    
   return 0; 
} /*int main (int argc, char** argv) {

   FILE * fp;

   fp = fopen (argv[1], "r");
   int r=0;
int num;
//int i=0;
//int j=0;
   	fscanf(fp,"%d ", &r );
	int* arr = (int *)malloc(r * r * sizeof(int));
	printf("%d", r);
	for (int i = 0; i <  r; i++){ 
      		for (int j = 0; j < r; j++){ 
			fscanf(fp,"%d ", &num );
        		&arr[i][j] = &num; 
		}
	}
for (i = 0; i <  r; i++){
      for (j = 0; j < r; j++) {
         printf("%d ", *(arr + i*r + j)); 
}
}
}*/
