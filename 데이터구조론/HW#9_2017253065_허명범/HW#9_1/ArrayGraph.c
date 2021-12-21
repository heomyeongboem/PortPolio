#include <stdio.h>
#include <stdlib.h>
#include "ArrayGraph.h"



// ���� �׷����� �����ϴ� ����, operations to generate a empty graph
Graph* createGraph(int type) {
	int i, j;
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->n = 0;
	G->type = type;
	for (i = 0; i < MAX_SIZE; i++) {
		for (j = 0; j < MAX_SIZE; j++)
			G->adjMatrix[i][j] = 0;
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
		printf("[ERROR] �׷��� ������ ���� �ʰ�\n");	// [ERROR] Graph vertex exceeded
		return;
	}
    G->n++;
}

// �׷��� G�� ����(u, v)�� ����, insert a edge(u, v) into graph G
void insertEdge(Graph* G, int u, int v) {

	// Fill your code

	if (G->type == 0) //������ �׷����̹Ƿ� ���� �߰��� [u][v]�Ӹ� �ƴ϶�[v][u]���� 1�� �߰�
	{
		G->adjMatrix[u][v] = 1;
		G->adjMatrix[v][u] = 1;
	
	}
	else {
		G->adjMatrix[u][v] = 1;
	
	}
}

// �׷��� G�� ���� v�� �����ϰ� ����� ��� ���� ����, delete vertex v to graph G and delete all connected edges
void deleteVertex(Graph* G, int v) {

	// Fill your code
	if (G->type == 0) //������ �׷����̹Ƿ� ���������� [v][i]�Ӹ� �ƴ϶�[i][v]���� 0����(���������̹Ƿ�)
	{
		for (int i = 0; i < 4; i++) {
			if (G->adjMatrix[v][i] == 1)
			{
				G->adjMatrix[v][i] = 0;
				G->adjMatrix[i][v] = 0;
			
			}
		}	
	}
	else {//��� [v][i]���� 0�� ���� ���ָ� �� �� �˾����� ���԰����� �ֱ� ������ [i][v]���� 0�� ����������Ѵ�.
		for (int i = 0; i < 4; i++) {
			if (G->adjMatrix[v][i] == 1) G->adjMatrix[v][i] = 0;	
			if (G->adjMatrix[i][v] == 1) G->adjMatrix[i][v] = 0;
			
		}
	}

}

// �׷��� G�� ���� (u, v)�� ����, delete the edge(u, v) to graph G
void deleteEdge(Graph* G, int u, int v) {

	// Fill your code
	if (G->type == 0) //������ �׷����̹Ƿ� ���� ������ [u][v]�Ӹ� �ƴ϶�[v][u]���� 0�� ����
	{
		G->adjMatrix[u][v] = 0;
		G->adjMatrix[v][u] = 0;
		//G->n = -2;
	}
	else {//��� �������� �ٸ��� ������ �����̹Ƿ� [v][u]�� ������ �����൵ �ȴ�.
		G->adjMatrix[u][v] = 0;
		//G->n = -1;
	}

}

// �׷��� G�� ���ҽ� ����, unresource graph G
void destroyGraph(Graph* G) {
	int i, j;
	for (i = 0; i < G->n; i++) {
		for (j = 0; j < G->n; j++)
			G->adjMatrix[i][j] = 0;
	}
	G->n = 0;
}

// �׷��� G�� ���� ��� ���� ���, display adjacent matrix information for graph G
void displayGraph(Graph* G) {
	int i, j;
	for (i = 0; i < G->n; i++) {
		for (j = 0; j < G->n; j++)
			printf("%2d\t", G->adjMatrix[i][j]);
		printf("\n");
	}
}