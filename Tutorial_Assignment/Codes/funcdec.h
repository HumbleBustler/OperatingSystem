#ifndef _FUNCDECL_H_
#define _FUNCDECL_H_

	void add(int n, int m, int matrix1[n][m], int matrix2[n][m], int result[n][m]);
	void transpose(int n, int m, int matrix1[n][m], int result[m][n]);
	void substract(int n, int m, int matrix1[n][m], int matrix2[n][m], int result[n][m]);
	int determinant(int n, int mat[n][n]); 
	void multiply(int n, int m, int matrix[n][m], int y,int result[n][m]);
#endif
