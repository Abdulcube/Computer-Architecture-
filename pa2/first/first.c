#include <stdio.h>
#include <stdlib.h>

void traverse(double ** matrix, int rows, int  columns){
  for(int k = 0; k < rows; k++){
     for(int i = 0; i < columns; i++){
         printf("%0.0lf\t", matrix[k][i]);
     }
      printf("\n");
  }

}
void traverseF(double ** matrix, int rows){
  for(int k = 0; k < rows; k++){
    // printf("%0.0lf\n", matrix[k][0]);
  }
}
//%0.0lf\n
double ** multiply(double ** matrix1, int r, int m, double ** matrix2, int u, int p){
  /*  r=rows,  m=columns, u=rows, p=columns */
  if(m!=u){
        printf("bad-matrices\n");
        return 0;
    }
    double multiply=0;
    double ** matrix3;
    matrix3 = (double**) malloc(r * sizeof(double *));
    for(int i = 0; i < r; i++){
            matrix3[i] = (double *) malloc(p * sizeof(double));
    }
    for(int k = 0; k<r; k++){
        for(int i = 0; i < p; i++){
            multiply=0;
            for(int b=0; b<m; b++){
                multiply=0;
                for(int f=0; f<u; f++){
                      multiply=multiply+(matrix1[k][f]*matrix2[f][i]);
                }
            }
            matrix3[k][i]=multiply;
      }
    }
//  printf("r: %d, p: %d\n",r, p );
//  traverse(matrix3, r, p);
  return matrix3;
}

double ** subtract(double ** matrix, int columns, int row, int subtract){
  for (int i = 0; i < columns; i++) {

    double j=matrix[row][i]-matrix[subtract][i];
    if(j==-0.0){
      j=+0.0;

    }
    matrix[row][i]=j;
  }


  return matrix;
}

double ** transpose(double ** matrix, int rows, int  columns){
  double ** answer;
    answer = (double**) malloc(columns * sizeof(double *));
  for(int i = 0; i < columns; i++){
        answer[i] = (double *) malloc(rows * sizeof(double));
  }
  for(int k = 0; k < rows; k++){
     for(int i = 0; i < columns; i++){
         answer[i][k]=matrix[k][i];
     }
  }
  //traverse(answer, columns, rows);
    return answer;
}

double ** subtractC(double ** matrix, int columns, int row, int subtract, double constant){

  for (int i = 0; i < columns; i++) {
      //printf("Before  %lf\n", matrix[row][i]);
    matrix[row][i]=matrix[row][i]-(matrix[subtract][i]*constant) ;
    //printf("%lf= X-(%lf*%lf)\n", matrix[row][i], matrix[subtract][i], constant);
  }

  return matrix;
}

double ** constant(double ** matrix, int columns, int row, double constant){

  for (int i = 0; i < columns; i++) {
    double j=matrix[row][i]/constant;
    if(j==-0.0){
      j=0.0;
    }
    matrix[row][i]=j;
  //  printf("Const: %lf, answer: %lf, column numb: %lf\n", constant, matrix[row][i]/constant, matrix[row][i]*constant);
  }
  return matrix;
}

double ** inverse(double ** matrix, int attributes){

  double ** answer;
    answer = (double**) malloc(attributes * sizeof(double *));
  for(int i = 0; i < attributes; i++){
        answer[i] = (double *) malloc(attributes  * sizeof(double));
  }

  for(int k = 0; k < attributes; k++){
     for(int i = 0; i < attributes; i++){
       if(k==i){
         answer[k][i]=1;
       } else {
         answer[k][i]=0;
       }
     }
   }
   int j = 0;
  // traverse(matrix, attributes, attributes);

   while(j<attributes){


     answer=constant(answer, attributes, j, matrix[j][j]);
    matrix=constant(matrix, attributes, j, matrix[j][j]);
     for (int k = j+1; k < attributes; k++) {
      // printf("%d, %d, %lf\n", k, j, matrix[k][j]);
    //  matrix=subtractC(matrix, attributes, k,  j, matrix[k][j]);
      answer=subtractC(answer, attributes, k,  j, matrix[k][j]);
      matrix=subtractC(matrix, attributes, k,  j, matrix[k][j]);
        //printf(" %lf\n", matrix[k][j+1]);
      //  traverse(answer, attributes, attributes);

     }
 //printf("\nSecond part start\n");
      if(j!=0){
       for (int i = j-1; i >= 0; i--) {
         //printf("%d, %d, %lf\n", j, i, matrix[i][j]);
          answer=subtractC(answer, attributes, i,  j, matrix[i][j]);
          matrix=subtractC(matrix, attributes, i,  j, matrix[i][j]);
           //printf("\n");
          // traverse(answer, attributes, attributes);
       }
     }
  //   printf("\n");
     j++;
   }

  return answer;
}


int main(int argc, char** argv){
    FILE* training;
    training=fopen(argv[1],"r");
    if(training==NULL){
      //printf("error\n");
      return 0;
    }
    int attributes=0;
    fscanf(training, "%d", &attributes);
    int examples=0;
    fscanf(training, "%d", &examples);
    double ** matrix;
    attributes++;
    matrix = (double **) malloc(examples * sizeof(double *));
    //rows
    double ** price= (double **) malloc(examples * sizeof(double *));

    for(int i = 0; i < examples; i++){
      matrix[i] = (double *) malloc(attributes * sizeof(double));
      price[i]=(double *) malloc(1 * sizeof(double));
      //columns
    }

    for(int k = 0; k < examples; k++){
       matrix[k][0]=1.0;
    }
    double j=0;
    for(int k = 0; k < examples; k++){
            for(int i = 1; i < attributes; i++){

             fscanf(training,"%lf ,", &j);
               matrix[k][i]=j;

     }
     fscanf(training,"%lf ,", &j);
     price[k][0]=j;
         //    printf("j: %f\n", j);
         }

    // test file input

    FILE* test;
    test=fopen(argv[2],"r");
    if(test==NULL){
      printf("error\n");
      return 0;
    }
    int points=0;
    fscanf(test, "%d", &points);
    double ** matrix2;
    matrix2 = (double **) malloc(points * sizeof(double *));
    for(int i = 0; i < points; i++){
      matrix2[i] = (double *) malloc(attributes  * sizeof(double));
      //columns
    }


    for(int k = 0; k < points; k++){
       matrix2[k][0]=1;
       for(int i = 1; i< attributes; i++){
         fscanf(test,"%lf ,", &j);
         matrix2[k][i]=j;
        //printf("%lf\t", j);
      //   printf("%lf\t", matrix2[k][i]);
     }
    }
//printf("\n attributes: %d, examples: %d, \n", attributes, examples);

    double ** trans=transpose(matrix, examples, attributes);

    double ** out=multiply(trans, attributes, examples, price, examples, 1);
    // multiply matrix: attributes, 1

    double ** ya=multiply(trans, attributes, examples, matrix, examples, attributes);
    // matrix: examples, examples

    double ** inv=inverse(ya, attributes);

    double ** answer=multiply(inv, attributes, attributes, out, attributes, 1);

      //traverse(answer,attributes, 1 );
   //   printf("\n ********\n");
    answer=multiply(matrix2, points, attributes, answer, attributes, 1);
     traverse(answer,points, 1 );
  }


