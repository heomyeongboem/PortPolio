#pragma once
#ifndef __LIST_GRAPH_H__
#define _LIST_GRAPH_H__

#define MAX_SIZE 100
#define DIRECT 1
#define UNDIRECT 0
#define TRUE 1
#define FALSE 0

// ���� ����Ʈ�� ��� ������ ����ü�� ����, defines the node structure of an adjacent list as a structure
typedef struct GraphNode {
	int vertex;				// ������ ��Ÿ���� ������ �ʵ�, data fields representing vertex
	struct GraphNode* link;	// ���� ���� ������ �����ϴ� ��ũ �ʵ�, link field to connect the following adjacent vertex
} graphNode;

// �׷����� ���� ����Ʈ�� ǥ���ϱ� ���� ����ü ����, define structures for representing graphs as adjacent lists
typedef struct GraphType {
	int n;
	int type;	// UNDIRECT: ������, DIRECT: ���� 
	graphNode* adjList_H[MAX_SIZE];	// �׷��� ������ ���� ��� ������, head pointer for graph vertex
	int visited[MAX_SIZE];
	int pred[MAX_SIZE];
} Graph;

Graph* createGraph(int type);				// ���� �׷����� �����ϴ� ����, operations to generate a empty graph
int isEmptyGraph(Graph* G);					// �׷����� �������� �˻�, check if the graph is empty
void insertVertex(Graph* G, int v);			// �׷��� G�� ���� v�� ����, insert vertex v into graph G
void insertEdge(Graph* G, int u, int v);	// �׷��� G�� ����(u, v)�� ����, insert a edge(u, v) into graph G
void destroyGraph(Graph* G);				// �׷��� G�� ���ҽ� ����, unresource graph G
void displayGraph(Graph* G);				// �׷��� G�� ���� ����Ʈ ���� ���, display adjacent list information for graph G

void initSearch(Graph* G);					// visited[], pred[] �ʱ�ȭ, initialized visited[], pre[]
void dfs_iter(Graph* G, int v);				// ���� �켱 Ž�� iterative version, depth first search iterative version
void dfs_recur(Graph* G, int v);			// ���� �켱 Ž�� recursive version, depth first search recursive version
void bfs(Graph* G, int v);					// �ʺ� �켱 Ž��, width first search

#endif

