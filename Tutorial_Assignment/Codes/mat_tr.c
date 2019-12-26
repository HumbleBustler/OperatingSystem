#include "funcdec.h"

void transpose(int n, int m, int matrix1[n][m], int result[m][n])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			result[i][j]=matrix1[j][i];
		}		
	}
}
