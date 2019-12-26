#include <stdio.h>
#include <math.h>
#include "funcdec.h"

void print(int m,int n,int mat[m][n]){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
	printf("\n");
}
int main(){
	int m=4,n=4;
	int mat1[4][4] = {{1, 2, 3, 1}, 
                      {2, 3, 2, 4}, 
                      {1, 5, 3, 3}, 
                      {6, 1, 2, 2}}; 
    int mat2[4][4] = {{1, 4, 3, 0}, 
                      {1, 1, 2, 4}, 
                      {1, 3, 4, 7}, 
                      {5, 1, 2, 2}}; 
    int rev[n][m],result[m][n];
	printf("Matrix 1 is:\n");print(m,n,mat1);
	printf("Matrix 2 is:\n");print(m,n,mat2);
	printf("Addition of Matrix 1 and 2 is :\n");
	add(n,m,mat1,mat2,result);print(m,n,result);
	printf("Substract of Matrix 1 and 2 is :\n");
	substract(n,m,mat1,mat2,result);print(m,n,result);
	printf("Multiplication of Matrix 1 with 6 is :\n");
	multiply(n,m,mat1,6,result);print(m,n,result);
	printf("Transpose of Matrix 2 is :\n");
	transpose(n,m,mat2,rev);print(n,m,rev);	
	printf("Matrix 1's determinant is :%d\n",determinant(m,mat1));
	printf("Matrix 2's determinant is :%d\n",determinant(m,mat2));
return 0;
}
