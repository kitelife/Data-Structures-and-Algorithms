#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
using namespace std;

typedef struct 
{
	int edges[MAX][MAX];	//邻接矩阵
	int n;					//顶点数
	int e;					//边数
}MGraph;

bool visited[MAX];			//标记顶点是否被访问过

void createMGraph(MGraph &G)	//用引用作参数
{
	int i, j;
	int s, t;					//存储顶点编号
	int v;						//存储边的权值
	for(i=0; i<G.n; i++)		//初始化
	{
		for(j=0; j<G.n; j++)
		{
			G.edges[i][j] = 0;
		}
		visited[i]=false;
	}
	for(i=0; i<G.e; i++)		//对矩阵相邻的边赋权值
	{
		scanf("%d %d %d", &s, &t, &v);		//对输入边的顶点编号以及权值
		G.edges[s][t] = v;
	}
}

void DFS(MGraph G, int v)		//深度优先搜索
{
	int i;
	printf("%d ", v);			//访问结点v
	visited[v]=true;
	for(i=0; i<G.n; i++)		//访问与v相邻的未被访问过的结点
	{
		if(G.edges[v][i]!=0 && visited[i]==false)
		{
			DFS(G,i);
		}
	}
}

void DFS1(MGraph G, int v)		//非递归实现
{
	stack<int> s;
	printf("%d ", v);			//访问初始结点
	visited[v]=true;
	s.push(v);					//入栈
	while(!s.empty())
	{
		int i, j;
		i = s.top();			//取栈顶元素
		for(j=0; j<G.n; j++)	//访问与顶点i相邻的顶点
		{
			if(G.edges[i][j]!=0 && visited[j]==false)
			{
				printf("%d ", j);	//访问
				visited[j]=true;
				s.push(j);			//访问完后入栈
				break;				//找到一个相邻未访问的顶点，访问之后则跳出循环
			}
		}
		if(j==G.n)				//如果与i相邻的顶点都被访问过，则将顶点i出栈
			s.pop();
	}
}

void BFS(MGraph G, int v)		//广度优先搜索
{
	queue<int> Q;
	printf("%d ", v);
	Q.push(v);
	while(!Q.empty())
	{
		int i, j;
		i = Q.front();		//取队首顶点
		Q.pop();
		for(j=0; j<G.n; j++)	//广度遍历
		{
			if(G.edges[i][j]!=0 && visited[j]==false)
			{
				printf("%d ", j);
				visited[j]=true;
				Q.push(j);
			}
		}
	}
}

int main(void)
{
	int n, e;		//建立的图的顶点数和边数
	while(scanf("%d %d", &n, &e)==2 && n>0)
	{
		MGraph G;
		G.n = n;
		G.e = e;
		createMGraph(G);
		DFS(G, 0);
		printf("\n");
		//DFS1(G, 0);
		//printf("\n");
		//BFS(G, 0);
		//printf("\n");
	}
	return 0;
}
