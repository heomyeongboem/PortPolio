#include <stdio.h>
#include <stdlib.h>
#include "ListGraph.h"

// 공백 그래프를 생성하는 연산, operations to generate a empty graph
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

// 그래프가 공백인지 검사, check if the graph is empth
int isEmpty(Graph* G) {
	return G->n == 0;
}

// 그래프 G에 정점 v를 삽입, insert vertex v into graph G
void insertVertex(Graph* G, int v) {
	if ((G->n) + 1 > MAX_SIZE) {
		printf("[ERROR] 그래프 정점의 개수 초과\n");	// [ERROR] Graph vertex exceeded
		return;
	}
	G->n++;
}

// 그래프 G에 간선(u, v)를 삽입, insert a edge(u, v) into graph G
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
		if(G->adjList_H[u]==NULL) G->adjList_H[u]=newnode1;//공백상태일 때 추가
		
		
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
		if (G->adjList_H[u] == NULL) G->adjList_H[u] = newnode1;//공백상태일 때 추가
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

// 그래프 G에 정점 v를 삭제하고 연결된 모든 간선 삭제, delete vertex v to graph G and delete all connected edges
void deleteVertex(Graph* G, int v) {

	// Fill your code 여기서 교훈,,, 정점 삭제 할때 방향이 있는 그래프이면 정점만 삭제해주는 것이 아니라 다른 정점에서 이 정점으로 가는 진출간선도 삭제해주어야한다!!!
	//그리고 조금은 당연스럽겠지만 걍 무방향이나 유방향이나 이번껀 똑같은 것 같다.(괜히 어렵게 만듦;;;) 
	if (G->type == 0) {
		/*
		graphNode* p = G->adjList_H[v];
		
		while (p != NULL) {
			
			graphNode* k = G->adjList_H[p->vertex];
			
			while (k->link != NULL) {
				
				if (k->vertex == v) //루트일때 
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

// 그래프 G에 간선 (u, v)를 삭제, delete the edge(u, v) to graph G
void deleteEdge(Graph* G, int u, int v) {

	// Fill your code
	//무방향일 때 u->v와 v->u는 같다. 그러므로 u->v와 v->u 모두 삭제 해주어야한다.
	if (G->type == 0) {

		graphNode* k = G->adjList_H[u];

			while (k->link != NULL) {

				if (k->vertex == v) //루트일때 
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

				if (s->vertex == u) //루트일때 
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
		//반면 방향 그래프 일 때는 u->v만 삭제해주면 된다.
		graphNode* k = G->adjList_H[u];

		while (k->link != NULL) {

			if (k->vertex == v) //루트일때 
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

// 그래프 G의 리소스 해제, unresource graph G
void destroyGraph(Graph* G) {
	int i;
	for (i = 0; i < G->n; i++) {
		if (G->adjList_H[i] != NULL)
			free(G->adjList_H[i]);
	}
	free(G);
}

// 그래프 G의 인접 리스트 정보 출력, display adjacent list information for graph G
void displayGraph(Graph* G) {
	int i;
	graphNode* p;
	for (i = 0; i < G->n; i++) {
		printf("정점 %d의 인접리스트", i);	// Adjacent list of vertex %d
		p = G->adjList_H[i];
		while (p) {
			printf(" -> %d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}