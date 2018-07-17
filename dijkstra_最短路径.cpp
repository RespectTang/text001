/*
题目内容：
有5个城市(A,B,C,D,E),其中每个城市到其他城市的直达距离已知，两个城市之间只有一条公路。
计算从城市A到其他任意城市的最短路径距离。
输入描述
4行数据， 第一行是A到(B,C,D,E)的直达距离，第二行是B到（C,D,E）的直达距离，
，第4行是D到E的直达距离。
输出描述
A城市到(B,C,D,E)的最短距离。
输入样例
2 3 4 5  
3 4 2 
4 3   
3
输出样例
2 3 4 4
*/

#include<stdio.h>
#include<iostream>
using namespace std;
#define INF 100000

int dijkstra(int cost[5][5],int n,int s,int dist[],int pre[])//n==5,s==0
{
	int i,j,k,count;
	int boolina[10000];
	int mindis;
	int minpnt;
	
	for(i=0;i<n;i++)
	{
		dist[i]=cost[s][i];//存储距离
		pre[i]=s;
		boolina[i]=0; 
	}
	
	boolina[s]=1;
	
	for(count=1;count<n;count++)
	{
		mindis=INF;
		for(i=0;i<n;i++)
		{
			if(!boolina[i]&&mindis>dist[i])
			{
				mindis=dist[i];//记录有距离的距离 
				minpnt=i;//记录有距离的节点 
			}
		}
		
		boolina[minpnt]=1;
		
		for(i=0;i<n;i++)
		{
			if(!boolina[i]&&dist[i]>dist[minpnt]+cost[minpnt][i])
			{
				dist[i]=dist[minpnt]+cost[minpnt][i];//判断最小距离并存储于dist 
				pre[i]=minpnt;//pre存储最小距离节点 
				
			}
		}
	}
	return i;	
} 



int main()
{
	int n=5;
	int cost[5][5],i,j,k;
	int dist[10000];
	int pre[10000];
	
	for(i=0;i<n;i++)//输入数据，如果两点之间没有距离，则距离为无穷大 
		for(j=1;j<n;j++)
		{
			if(i<j)
			scanf("%d",&cost[i][j]);
			//cin >> cost[i][j];
			else
			cost[i][j]=INF;	
	 	} 
	dijkstra(cost,5,0,dist,pre);
	for(i=1;i<n;i++)
	printf("%d ",dist[i]);
	printf("\n")
	//cout<<dist[i]<<" ";
	
	return 0;
}




