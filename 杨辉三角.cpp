#include<stdio.h>
int main()
{
	int a[10][10];
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)//杨辉三角首尾的1 
	{
		a[i][0]=1;
		a[i][i]=1;
	}
	
	for(i=2;i<n;i++)//加和 
	{
		for(j=1;j<i;j++)
		a[i][j]=a[i-1][j]+a[i-1][j-1];
		
	}
	
	for(i=0;i<n;i++)// 分组输出 
	{
		for(j=0;j<=i;j++)
		printf("%5d",a[i][j]);
		printf("\n"); 
	}
	return 0;
 } 
