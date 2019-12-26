#include "funcdec.h"
#include<math.h>

int determinant(int n, int mat[n][n])
{
	int num1,num2,det=1,index,total=1;
	int temp[n+1];
	for(int i=0;i<n;i++)
	{
		index = i;
		while(mat[index][i]==0 && index<n)
	{
	index++;
	}
	if(index==n)
	{
		continue;
	}
	if(index!=i)
	{
		for(int j=0;j<n;j++)
		{
			int t=mat[index][j];
			mat[index][j]=mat[i][j];
			mat[i][j]=t;
		}
		det=det*pow(-1,index-i);
	}
	for(int j=0;j<n;j++)
	{
		temp[j]=mat[i][j];
		}
		for(int j=i+1;j<n;j++)
		{
			num1=temp[i];
			num2=mat[j][i];
			for(int k=0;k<n;k++)
			{
				mat[j][k]=(num1*mat[j][k])-(num2*temp[k]);
			}
				total=total*num1;
			}
		}
		for(int i=0;i<n;i++)
		{
			det=det*mat[i][i];
	}
	return(det/total);
}
