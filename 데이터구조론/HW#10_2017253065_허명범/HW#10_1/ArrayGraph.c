#include <stdio.h>
#include <stdlib.h>
#include "ArrayGraph.h"
#include "ArrayStack.h"

// ���� �׷����� �����ϴ� ����, operations that generate a empty graph
Graph* createGraph() {
	int i, j;
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->n = 0;
	for (i = 0; i < MAX_SIZE; i++) {
		for (j = 0; j < MAX_SIZE; j++) {
			if (i == j)
				G->cost[i][j] = 0;
			else
				G->cost[i][j] = INF;
			G->A[i][j] = INF;
		}
		G->dist[i] = INF;
		G->pred[i] = NONE;
		G->S[i] = 0;
	}
	return G;
}

// �׷����� �������� �˻�, check if the graph is empty	
int isEmpty(Graph* G) {
	return G->n == 0;
}

// �׷��� G�� ���� v�� ����, insert vertex v into graph G
void insertVertex(Graph* G, int v) {
	if ((G->n) + 1 > MAX_SIZE) {
		printf("[ERROR] �׷��� ������ ���� �ʰ�\n");	// [ERROR] Exceeding the number of graph vertices
		return;
	}
	G->n++;
}

// �׷��� G�� ����(u, v)�� ����, insert edge(u, v) into graph G
void insertEdge(Graph* G, int u, int v, int weight) {
	G->cost[u][v] = weight;
}

// �׷��� G�� ���� v�� �����ϰ� ����� ��� ���� ����, delete vertex v in graph G and delete all connected edges
void deleteVertex(Graph* G, int v) {
	int i;
	for (i = 0; i < G->n; i++) {
		G->cost[i][v] = INF;
		G->cost[v][i] = INF;
	}
}

// �׷��� G�� ���� (u, v)�� ����, delete edge(u, v) on graph G
void deleteEdge(Graph* G, int u, int v) {
	G->cost[u][v] = INF;
}

// �׷��� G�� ���ҽ� ����, unresource graph G
void destroyGraph(Graph* G) {
	int i, j;
	for (i = 0; i < G->n; i++) {
		for (j = 0; j < G->n; j++) {
			if (i != j)
				G->cost[i][j] = INF;
		}
		G->dist[i] = INF;
		G->pred[i] = NONE;
	}
	G->n = 0;
}

// �׷��� G�� ���� ��� ���� ���, display adjacency matrix information for graph G
void displayGraph(Graph* G) {
	int i, j;
	for (i = 0; i < G->n; i++) {
		for (j = 0; j < G->n; j++) {
			if (G->cost[i][j] == INF)
				printf("INF\t");
			else
				printf("%2d\t", G->cost[i][j]);
		}
		printf("\n");
	}
}

// �ּ� ����� ���� ���� ������ ã�� ����, operation that finds the next vertex with a minimum cost
// Dijkstra Algorithm ������ �ʿ��� ��� �̿�, use when needed to implement Dijkstra Algorithm 
int nextVertex(Graph* G) {
	int i, minCost, minVertex;
	minCost = INF;
	minVertex = -1;
	for (i = 0; i < G->n; i++) {
		if (G->dist[i] < minCost && !G->S[i]) {//S[i]�� FALSE �϶� ��ȯ ��, ä�� �ȵ� ģ���鸸 ��ȯ�� �ٴ� ���̴�.
			minCost = G->dist[i];
			minVertex = i;
		}
	}
	return minVertex;
}

// Dijkstra Algorithm
void dijkstra(Graph* G, int v) {

	// Fill your code
	G->S[v] = TRUE;//�� TRUE�� ���� S�� �� ������ ���ְԵȴٴ� ���� �ǹ�
	for (int i = 0; i < G->n; i++) {
		G->dist[i] = G->cost[v][i];//dist �ʱ�ȭ
		if (G->cost[v][i] != INF)G->pred[i] = v;//������ �����Ƿ� �� ���� ������ v�� �־��ٴ� ���� �˷���
		else//���� ������ �ǹ�
		{
			G->pred[i] = INF;
		}
	}
	for (int i = 0; i<G->n-1; i++) {
		
		int u = nextVertex(G);//dist �迭���� �ּڰ��� ������ �������� ���İ��� ������ �ǹ�, �� ���� ������ �ƴ�
		G->S[u] = TRUE;//�� TRUE�� ���� S�� �� ������ ���ְԵȴٴ� ���� �ǹ�
				
		for (int w = 0; w < G->n; w++) {//relaxation
			
			if (G->dist[w] > G->dist[u] + G->cost[u][w]) {
				G->dist[w] = G->dist[u] + G->cost[u][w];
				G->pred[w] = u;
			}
		}
	}
}

// Bellman-Ford Algorithm
int bellmanFord(Graph* G, int v) {

	// Fill your code

	G->dist[v] = 0;//���� ������ 0�� �־��ְ� ������ ������ ���� dist���� INF�� �־��ݴϴ�.
	for (int i = 1; i < G->n; i++) {
		G->dist[i] = INF;
	}
	for (int i = 0; i < G->n; i++)//
	{
		for (int u = 0; u < G->n; u++) {

			for (int w = 0; w < G->n; w++) {
				if (G->dist[w] > G->dist[u] + G->cost[u][w]) {
					G->dist[w] = G->dist[u] + G->cost[u][w];
					G->pred[w] = u;
				}
			}

		}
	}
	return TRUE;
}


// Floyd-Warshall Algorithm
void floyd(Graph* G) {

	// Fill your code
	//A^-1��� �����
	for (int i = 0;i<G->n ; i++) {
	
		for (int j = 0; j < G->n; j++) {
			G->A[i][j] = G->cost[i][j];
		}
	}
	for (int k = 0; k < G->n; k++) //��� ������ ���Ͽ� A^0,1,2,3,4��� �����
	{

		for (int i = 0; i < G->n; i++) //i�� ���������� �ǹ� �ƹ��� �ۿ� for ���� ���� 0�� ���Ѱſ��� A^0�� ����� �ǹ� �� �ȿ��� ����1�� �������� �� ���� �ִ�!!!!
		{
			for (int j = 0; j < G->n; j++) //���⼭ j�� �������� �ǹ�
			{
				if (G->A[i][k] + G->A[k][j] < G->A[i][j]) G->A[i][j] = G->A[i][k] + G->A[k][j];//G->A[i][k] + G->A[k][j]�� ������ ������ ��Ÿ���� G->A[i][j]�� �ȴ�.   
				//��, G->A[i][k] + G->A[k][j] �� ����k �� ������ ���� �ǹ��ϰ� G->A[i][j]�� ��ġ�� �ʾ������� �ִ� ��θ� �ǹ��Ѵ�. �ᱹ���� �� �� ���� �� �۳Ŀ� ���� ��ģ ���� �� ������ k������ ��ģ ���� �ִ� ��ο� �־��ش�.
			//������ �����غ��� ����� ��ġ�� ������ �������� ���¿��� ������������ ���� ������ for �� ������ ��� ���� ������ ���� �ִ� ��θ� ������ְ� ���������� ���� for ���� �ٽ� ���� �������� 1�϶� 2�϶� 3�϶� k������ ���� ���� ������� 
			//�ƴϸ� ������ �ʾ����� �� ��������� ���� �� ����� ����� ä���� �̾��شٰ� ���� �� �� ����.!!!
			}
		}
	}

}

// �ִܰ�� ���, display shortest path
void printShortestPath(Graph* G, int src, int dst) {
	printf("%c -> %c �ִ� ���: %c", src + 65, dst + 65, src + 65);	// "%c -> %c Shortest Path: %c"
	int v = dst;
	Stack* stack = createStack();

	// Fill your code
	
	push(stack, v);//�̷��߸� ó�� ���� ������ stack �� push ���� �� �ִ�. !!!
	
	while (G->pred[v]!= src) //���������� ���� ������ ���� ������ stack�� ������� push
	{

		push(stack, G->pred[v]);
		v = G->pred[v];
	
	}
	
	while (stack->top!=-1) //������ �������� ����ض�
	{

		//f (isEmpty(stack)) return 0;
		printf("\t%c", pop(stack) + 65);
		
	}
	

	printf("\n");
	clearStack(stack);
}

// �ִܰ�� ��� ���, display shortest path cost
int printShortestPathCost(Graph* G, int src, int dst) {
	printf("%c -> %c �ִ� ��� ���: %d\n", src + 65, dst + 65, G->dist[dst]);	// "%c -> %c Shortest Path Cost: %d"
}

// ��� ���� �� ������ �ִ� ��� ��� ���, display shorteet path cost between all pairs of vertices
void printAllPairShortestCost(Graph* G) {
	int i, j;

	for (i = 0; i < G->n; i++) {
		for (j = 0; j < G->n; j++) {
			if (G->A[i][j] == INF)
				printf("INF\t");
			else
				printf("%2d\t", G->A[i][j]);
		}
		printf("\n");
	}
}