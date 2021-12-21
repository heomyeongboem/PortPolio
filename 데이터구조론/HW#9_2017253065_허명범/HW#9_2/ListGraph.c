#include <stdio.h>
#include <stdlib.h>
#include "ListGraph.h"

// ���� �׷����� �����ϴ� ����, operations to generate a empty graph
Graph* createGraph(int type) {
	int i;
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->n = 0;
	G->type = type;
	for (i = 0; i < MAX_SIZE; i++) {
		G->adjList_H[i] = NULL;
	}
	return G;
}

// �׷����� �������� �˻�, check if the graph is empth
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

	graphNode* newnode1 = malloc(sizeof(graphNode));
	newnode1->vertex = v;
	newnode1->link = NULL;
	
	if (G->type == 0) {
	
		graphNode* newnode2 = malloc(sizeof(graphNode));
		newnode2->vertex = u;
		newnode2->link = NULL;
		
		//u->v

		if (G->adjList_H[u] == NULL) {
			newnode1->link = G->adjList_H[u];
			G->adjList_H[u] = newnode1;
		}
		else {
			graphNode* p = G->adjList_H[u];
		
			while (p != NULL) {
				if (p->vertex == v) return;
				else p = p->link;
			}
			if (p==NULL)
			{
				newnode1->link = G->adjList_H[u];
				G->adjList_H[u] = newnode1;
			}
		
		
		}
		if (G->adjList_H[v] == NULL) {
			newnode2->link = G->adjList_H[v];
			G->adjList_H[v] = newnode2;
		}
		else {
			//v->u
			graphNode* s = G->adjList_H[v];
			while (s != NULL) {
				if (s->vertex == v) break;
				else s = s->link;
			}
			if (s==NULL)
			{
				newnode2->link = G->adjList_H[v];
				G->adjList_H[v] = newnode2;
			}
		}
		/*
		if(G->adjList_H[u]==NULL) G->adjList_H[u]=newnode1;//��������� �� �߰�
		
		
		else if (G->adjList_H[u]!=NULL) {
			graphNode* p = G->adjList_H[u];
			while (p->link!=NULL) { p = p->link; }
			p->link = newnode1;
		}
		
		if(G->adjList_H[v]==NULL) G->adjList_H[v] = newnode2;	
		else if (G->adjList_H[v]!=NULL) {
			graphNode* t = G->adjList_H[u];
			while (t->link!=NULL) { t = t->link; }
			t->link = newnode2;
		}
		*/
	}

	else {
		/*
		if (G->adjList_H[u] == NULL) G->adjList_H[u] = newnode1;//��������� �� �߰�
		else if (G->adjList_H[u]!=NULL) {
			graphNode* p = G->adjList_H[u];
			while (p->link!=NULL) { p = p->link; }
			p->link = newnode1;
		}*/
		//u->v
		newnode1->link = G->adjList_H[u];
		G->adjList_H[u] = newnode1;
	}

}

// �׷��� G�� ���� v�� �����ϰ� ����� ��� ���� ����, delete vertex v to graph G and delete all connected edges
void deleteVertex(Graph* G, int v) {

	// Fill your code ���⼭ ����,,, ���� ���� �Ҷ� ������ �ִ� �׷����̸� ������ �������ִ� ���� �ƴ϶� �ٸ� �������� �� �������� ���� ���Ⱓ���� �������־���Ѵ�!!!
	//�׸��� ������ �翬���������� �� �������̳� �������̳� �̹��� �Ȱ��� �� ����.(���� ��ư� ����;;;) 
	if (G->type == 0) {
		/*
		graphNode* p = G->adjList_H[v];
		
		while (p != NULL) {
			
			graphNode* k = G->adjList_H[p->vertex];
			
			while (k->link != NULL) {
				
				if (k->vertex == v) //��Ʈ�϶� 
				{
					//k = k->link;
					
					
					
					G->adjList_H[p->vertex] = G->adjList_H[p->vertex]->link;
					break;
				}

				else if (k->link->vertex == v)
				{
					k->link = k->link->link;
				
					break;
				}
				
				else k = k->link;

			}
			p = p->link;
		}
		G->adjList_H[v] = NULL;
		*/

		graphNode* k;

		for (int i = 0; i < 4; i++)
		{
			graphNode* k = G->adjList_H[i];
			if (k != NULL) {
				while (k->link != NULL) {

					if (k->vertex == v) {
						G->adjList_H[i] = G->adjList_H[i]->link;
						break;
					}

					else if (k->link->vertex == v)
					{
						if (k->link->link == NULL)
						{
							k->link = NULL;
							break;
						}
						else {
							k->link = k->link->link;
							break;
						}

					}

					else k = k->link;

				}


			}
		}

		G->adjList_H[v] = NULL;





	}
	else {
		
		graphNode* k;

		for (int i = 0; i < 4;i++)
		{
			graphNode* k = G->adjList_H[i];
			if (k != NULL) {
				while (k->link != NULL) {

					if (k->vertex == v) {
						G->adjList_H[i] = G->adjList_H[i]->link;
						break;
					}

					else if (k->link->vertex == v)
					{
						if (k->link->link == NULL)
						{
							k->link = NULL;
							break;
						}
						else {
							k->link = k->link->link;
							break;
						}

					}

					else k = k->link;

				}


			}
		}

		G->adjList_H[v] = NULL;

	}

}

// �׷��� G�� ���� (u, v)�� ����, delete the edge(u, v) to graph G
void deleteEdge(Graph* G, int u, int v) {

	// Fill your code
	//�������� �� u->v�� v->u�� ����. �׷��Ƿ� u->v�� v->u ��� ���� ���־���Ѵ�.
	if (G->type == 0) {

		graphNode* k = G->adjList_H[u];

			while (k->link != NULL) {

				if (k->vertex == v) //��Ʈ�϶� 
				{
					G->adjList_H[u] = G->adjList_H[u]->link;
					break;
				}

				else if (k->link->vertex == v)
				{
					k->link = k->link->link;
					break;
				}

				else k = k->link;

			}


			graphNode* s = G->adjList_H[v];

			while (s->link != NULL) {

				if (s->vertex == u) //��Ʈ�϶� 
				{
					G->adjList_H[v] = G->adjList_H[v]->link;
					break;
				}

				else if (s->link->vertex == u)
				{
					s->link = s->link->link;
					break;
				}

				else s = s->link;

			}
		

	}


	else {
		//�ݸ� ���� �׷��� �� ���� u->v�� �������ָ� �ȴ�.
		graphNode* k = G->adjList_H[u];

		while (k->link != NULL) {

			if (k->vertex == v) //��Ʈ�϶� 
			{
				G->adjList_H[u] = G->adjList_H[u]->link;
				break;
			}

			else if (k->link->vertex == v)
			{
				k->link = k->link->link;
				break;
			}

			else k = k->link;

		}

	}

}

// �׷��� G�� ���ҽ� ����, unresource graph G
void destroyGraph(Graph* G) {
	int i;
	for (i = 0; i < G->n; i++) {
		if (G->adjList_H[i] != NULL)
			free(G->adjList_H[i]);
	}
	free(G);
}

// �׷��� G�� ���� ����Ʈ ���� ���, display adjacent list information for graph G
void displayGraph(Graph* G) {
	int i;
	graphNode* p;
	for (i = 0; i < G->n; i++) {
		printf("���� %d�� ��������Ʈ", i);	// Adjacent list of vertex %d
		p = G->adjList_H[i];
		while (p) {
			printf(" -> %d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}