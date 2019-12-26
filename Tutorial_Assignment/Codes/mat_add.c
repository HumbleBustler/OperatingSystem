#include "funcdec.h"

void add(int n, int m, int matrix1[n][m], int matrix2[n][m], int result[n][m])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			result[i][j]=matrix1[i][j]+matrix2[i][j];
		}		
	}
}
