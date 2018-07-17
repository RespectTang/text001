/*
��Ŀ���ݣ�
��5������(A,B,C,D,E),����ÿ�����е��������е�ֱ�������֪����������֮��ֻ��һ����·��
����ӳ���A������������е����·�����롣
��������
4�����ݣ� ��һ����A��(B,C,D,E)��ֱ����룬�ڶ�����B����C,D,E����ֱ����룬
����4����D��E��ֱ����롣
�������
A���е�(B,C,D,E)����̾��롣
��������
2 3 4 5  
3 4 2 
4 3   
3
�������
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
		dist[i]=cost[s][i];//�洢����
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
				mindis=dist[i];//��¼�о���ľ��� 
				minpnt=i;//��¼�о���Ľڵ� 
			}
		}
		
		boolina[minpnt]=1;
		
		for(i=0;i<n;i++)
		{
			if(!boolina[i]&&dist[i]>dist[minpnt]+cost[minpnt][i])
			{
				dist[i]=dist[minpnt]+cost[minpnt][i];//�ж���С���벢�洢��dist 
				pre[i]=minpnt;//pre�洢��С����ڵ� 
				
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
	
	for(i=0;i<n;i++)//�������ݣ��������֮��û�о��룬�����Ϊ����� 
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




