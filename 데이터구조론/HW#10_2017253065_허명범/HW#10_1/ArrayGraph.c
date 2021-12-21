#include <stdio.h>
#include <stdlib.h>
#include "ArrayGraph.h"
#include "ArrayStack.h"

// 공백 그래프를 생성하는 연산, operations that generate a empty graph
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

// 그래프가 공백인지 검사, check if the graph is empty	
int isEmpty(Graph* G) {
	return G->n == 0;
}

// 그래프 G에 정점 v를 삽입, insert vertex v into graph G
void insertVertex(Graph* G, int v) {
	if ((G->n) + 1 > MAX_SIZE) {
		printf("[ERROR] 그래프 정점의 개수 초과\n");	// [ERROR] Exceeding the number of graph vertices
		return;
	}
	G->n++;
}

// 그래프 G에 간선(u, v)를 삽입, insert edge(u, v) into graph G
void insertEdge(Graph* G, int u, int v, int weight) {
	G->cost[u][v] = weight;
}

// 그래프 G에 정점 v를 삭제하고 연결된 모든 간선 삭제, delete vertex v in graph G and delete all connected edges
void deleteVertex(Graph* G, int v) {
	int i;
	for (i = 0; i < G->n; i++) {
		G->cost[i][v] = INF;
		G->cost[v][i] = INF;
	}
}

// 그래프 G에 간선 (u, v)를 삭제, delete edge(u, v) on graph G
void deleteEdge(Graph* G, int u, int v) {
	G->cost[u][v] = INF;
}

// 그래프 G의 리소스 해제, unresource graph G
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

// 그래프 G의 인접 행렬 정보 출력, display adjacency matrix information for graph G
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

// 최소 비용을 갖는 다음 정점을 찾는 연산, operation that finds the next vertex with a minimum cost
// Dijkstra Algorithm 구현시 필요할 경우 이용, use when needed to implement Dijkstra Algorithm 
int nextVertex(Graph* G) {
	int i, minCost, minVertex;
	minCost = INF;
	minVertex = -1;
	for (i = 0; i < G->n; i++) {
		if (G->dist[i] < minCost && !G->S[i]) {//S[i]가 FALSE 일때 반환 즉, 채택 안된 친구들만 반환한 다는 말이다.
			minCost = G->dist[i];
			minVertex = i;
		}
	}
	return minVertex;
}

// Dijkstra Algorithm
void dijkstra(Graph* G, int v) {

	// Fill your code
	G->S[v] = TRUE;//이 TRUE가 집합 S에 이 정점이 들어가있게된다는 것을 의미
	for (int i = 0; i < G->n; i++) {
		G->dist[i] = G->cost[v][i];//dist 초기화
		if (G->cost[v][i] != INF)G->pred[i] = v;//간선이 있으므로 이 정점 전에는 v가 있었다는 것을 알려줌
		else//간선 없음을 의미
		{
			G->pred[i] = INF;
		}
	}
	for (int i = 0; i<G->n-1; i++) {
		
		int u = nextVertex(G);//dist 배열에서 최솟값을 가지는 정점으로 거쳐가는 정점을 의미, 단 시작 정점이 아님
		G->S[u] = TRUE;//이 TRUE가 집합 S에 이 정점이 들어가있게된다는 것을 의미
				
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

	G->dist[v] = 0;//시작 정점만 0을 넣어주고 나머지 정점에 대한 dist에는 INF을 넣어줍니다.
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
	//A^-1행렬 만들기
	for (int i = 0;i<G->n ; i++) {
	
		for (int j = 0; j < G->n; j++) {
			G->A[i][j] = G->cost[i][j];
		}
	}
	for (int k = 0; k < G->n; k++) //모든 정점에 대하여 A^0,1,2,3,4행렬 만들기
	{

		for (int i = 0; i < G->n; i++) //i는 시작정점을 의미 아무리 밖에 for 문이 정점 0에 대한거여도 A^0은 행렬을 의미 그 안에는 정점1이 시작점이 될 수도 있다!!!!
		{
			for (int j = 0; j < G->n; j++) //여기서 j는 도착지를 의미
			{
				if (G->A[i][k] + G->A[k][j] < G->A[i][j]) G->A[i][j] = G->A[i][k] + G->A[k][j];//G->A[i][k] + G->A[k][j]는 벡터의 합으로 나타내면 G->A[i][j]가 된다.   
				//즉, G->A[i][k] + G->A[k][j] 는 정점k 을 거쳤을 때를 의미하고 G->A[i][j]는 거치지 않았을때의 최단 경로를 의미한다. 결국에는 둘 중 누가 더 작냐에 따라 거친 것이 더 작으면 k정점을 거친 값을 최단 경로에 넣어준다.
			//돌이켜 생각해보면 행렬은 거치는 정점을 지정해준 상태에서 시작정점으로 도착 정점을 for 문 돌려서 모든 도착 정점에 대한 최단 경로를 만들어주고 시작정점에 대한 for 문을 다시 돌려 시작점이 1일때 2일때 3일때 k정점을 지난 것이 가까운지 
			//아니면 지나지 않았을때 더 가까운지를 비교해 더 가까운 방법을 채택해 이어준다고 보면 될 것 같다.!!!
			}
		}
	}

}

// 최단경로 출력, display shortest path
void printShortestPath(Graph* G, int src, int dst) {
	printf("%c -> %c 최단 경로: %c", src + 65, dst + 65, src + 65);	// "%c -> %c Shortest Path: %c"
	int v = dst;
	Stack* stack = createStack();

	// Fill your code
	
	push(stack, v);//이래야만 처음 도착 지점을 stack 에 push 해줄 수 있다. !!!
	
	while (G->pred[v]!= src) //도착지점이 시작 정점을 만날 때까지 stack에 순서대로 push
	{

		push(stack, G->pred[v]);
		v = G->pred[v];
	
	}
	
	while (stack->top!=-1) //스택이 빌때까지 출력해라
	{

		//f (isEmpty(stack)) return 0;
		printf("\t%c", pop(stack) + 65);
		
	}
	

	printf("\n");
	clearStack(stack);
}

// 최단경로 비용 출력, display shortest path cost
int printShortestPathCost(Graph* G, int src, int dst) {
	printf("%c -> %c 최단 경로 비용: %d\n", src + 65, dst + 65, G->dist[dst]);	// "%c -> %c Shortest Path Cost: %d"
}

// 모든 정점 쌍 사이의 최단 경로 비용 출력, display shorteet path cost between all pairs of vertices
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