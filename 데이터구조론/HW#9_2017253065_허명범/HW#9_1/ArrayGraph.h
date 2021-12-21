#pragma once
#ifndef __ARRAY_GRAPH_H__
#define _ARRAY_GRAPH_H__

#define MAX_SIZE 100
#define DIRECT 1
#define UNDIRECT 0

// �׷����� ���� ��ķ� ǥ���ϱ� ���� ����ü ����, define structures for representing graphs as adjacent matrix
typedef struct GraphType {
	int n;
	int type;	// UNDIRECT: ������, DIRECT: ���� 
	int adjMatrix[MAX_SIZE][MAX_SIZE];
} Graph;

Graph* createGraph(int type);	// ���� �׷����� �����ϴ� ����, operations to generate a empty graph
int isEmpty(Graph* G);	// �׷����� �������� �˻�, check if the graph is empty
void insertVertex(Graph* G, int v);	// �׷��� G�� ���� v�� ����, insert vertex v into graph G
void insertEdge(Graph* G, int u, int v);	// �׷��� G�� ����(u, v)�� ����, insert a edge(u, v) into graph G
void deleteVertex(Graph* G, int v);	// �׷��� G�� ���� v�� �����ϰ� ����� ��� ���� ����, delete vertex v to graph G and delete all connected edges
void deleteEdge(Graph* G, int u, int v);  // �׷��� G�� ���� (u, v)�� ����, delete the edge(u, v) to graph G
void destroyGraph(Graph* G);	// �׷��� G�� ���ҽ� ����, unresource graph G
void displayGraph(Graph* G);	// �׷��� G�� ���� ��� ���� ���, display adjacent matrix information for graph G

#endif

