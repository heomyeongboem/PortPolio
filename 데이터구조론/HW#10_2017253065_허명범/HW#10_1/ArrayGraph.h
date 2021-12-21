#pragma once
#ifndef __ARRAY_GRAPH_H__
#define _ARRAY_GRAPH_H__

#define MAX_SIZE 10
#define INF 987654321
#define NONE 9999

// �׷����� ���� ��ķ� ǥ���ϱ� ���� ����ü ����, define structures for representing graphs as adjacency matrices
typedef struct GraphType {
	int n;
	int cost[MAX_SIZE][MAX_SIZE];
	int dist[MAX_SIZE];
	int pred[MAX_SIZE];
	int S[MAX_SIZE];
	int A[MAX_SIZE][MAX_SIZE];
} Graph;

Graph* createGraph();									// ���� �׷����� �����ϴ� ����, operations that generate a empty graph
int isEmpty(Graph* G);									// �׷����� �������� �˻�, check if the graph is empty
void insertVertex(Graph* G, int v);						// �׷��� G�� ���� v�� ����, insert vertex v into graph G
void insertEdge(Graph* G, int u, int v, int weight);	// �׷��� G�� ����(u, v)�� ����, insert edge(u, v) into graph G
void deleteVertex(Graph* G, int v);						// �׷��� G�� ���� v�� �����ϰ� ����� ��� ���� ����, delete vertex v in graph G and delete all connected edges
void deleteEdge(Graph* G, int u, int v);				// �׷��� G�� ���� (u, v)�� ����, delete edge(u, v) on graph G
void destroyGraph(Graph* G);							// �׷��� G�� ���ҽ� ����, unresource graph G
void displayGraph(Graph* G);							// �׷��� G�� ���� ��� ���� ���, display adjacency matrix information for graph G

int nextVertex(Graph* G);								// �ּ� ����� ���� ���� ������ ã�� ����, operation that finds the next vertex with a minimum cost
void dijkstra(Graph* G, int v);							// Dijkstra Algorithm
int bellmanFord(Graph* G, int v);						// Bellman-Ford Algorithm
void floyd(Graph* G);									// Floyd-Warshall Algorithm
void printShortestPath(Graph* G, int src, int dst);		// �ִܰ�� ���, display shortest path
int printShortestPathCost(Graph* G, int src, int dst);	// �ִܰ�� ��� ���, display shortest path cost
void printAllPairShortestCost(Graph* G);				// ��� ���� �� ������ �ִ� ��� ��� ���, display shorteet path cost between all pairs of vertices

#endif
