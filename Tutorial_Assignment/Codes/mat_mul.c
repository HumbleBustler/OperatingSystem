#include "funcdec.h"
#include<math.h>

void multiply(int n, int m, int matrix[n][m], int y,int result[n][m]){

	for(int i=0;i<n;i++)
	{	for(int j=0;j<n;j++){
			result[i][j]=y*matrix[i][j];
		}		
	}
}
