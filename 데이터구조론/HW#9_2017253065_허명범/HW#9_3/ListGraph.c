#include <stdio.h>
#include <stdlib.h>
#include "ListGraph.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"

// ���� �׷����� �����ϴ� ����, operations to generate a empty graph
Graph* createGraph(int type) {
	int i;
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->n = 0;
	G->type = type;
	for (i = 0; i < MAX_SIZE; i++) {
		G->adjList_H[i] = NULL;
		G->visited[i] = FALSE;
		G->pred[i] = -1;
	}
	return G;
}

// �׷����� �������� �˻�, check if the graph is empty
int isEmptyGraph(Graph* G) {
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

// �׷��� G�� ����(u, v)�� ����, insert a edge(u, v) into graph G
void insertEdge(Graph* G, int u, int v) {

	// Fill your code
	graphNode* newnode1 = malloc(sizeof(graphNode));
	newnode1->link = NULL;
	newnode1->vertex = v;
	if (G->type == 0) {

		graphNode* newnode2 = malloc(sizeof(graphNode));
		newnode2->vertex = u;
		newnode2->link = NULL;

		if (G->adjList_H[u] == NULL) {
			newnode1->link = G->adjList_H[u];
			G->adjList_H[u] = newnode1;
		}
		else {
			graphNode* p = G->adjList_H[u];

			while (p != NULL) {
				if (p->vertex == v) return;//���⼭ return �� �ִ� ������ 1->2 �϶� G->adjList_H[1]�� �̹� 2���� �ִµ� 2->1�� ������ G->adjList_H[1]�� 2�� Ȯ�ν� G->adjList_H[2]���� �翬�� 1�� �ִµ� 1�� �������ϱ� ������ 
				//�ƾ� �����Ű�� �ϴ� ���̴�. (���ο�)
				else p = p->link;
			}
			if (p == NULL)
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
			if (s == NULL)
			{
				newnode2->link = G->adjList_H[v];
				G->adjList_H[v] = newnode2;
			}
		}
	}
	else {
		newnode1->link=G->adjList_H[u];
		G->adjList_H[u] = newnode1;
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
		printf("���� %d�� ��������Ʈ", i);	// Adjacent list with vertex %d
		p = G->adjList_H[i];
		while (p) {
			printf(" -> %d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

// visited[], pred[] �ʱ�ȭ, initialized visited[], pre[]
void initSearch(Graph* G) {
	int i;
	for (i = 0; i < G->n; i++) {
		G->visited[i] = FALSE;
		G->pred[i] = -1;
	}
}

// ���� �켱 Ž�� iterative version, depth first search iterative version
void dfs_iter(Graph* G, int v) {

	// Fill your code
	Stack* S = create();//���齺�� ����
	G->visited[v] = TRUE;
	push(S, v);
	printf("%d\t",v);
	while (!isEmpty(S)) //���齺���� �ƴ϶��
	{
		v = pop(S);
		graphNode* w = G->adjList_H[v];

		while (w!=NULL)//�������� �� ��������
		{
			if (G->visited[w->vertex] == FALSE) {//���� �湮���� ���� ���������̶��
				push(S, v);
				G->visited[w->vertex] = TRUE;
				printf("%d\t",w->vertex);
				v = w->vertex;//�̰ɷ� ����
				w = G->adjList_H[v];//�Ʒ��� �����ϰ� �˴ϴ�.
			}
			else {//�湮�� ���������̶�� 
				w = w->link;
			}
		}
	}
}

// ���� �켱 Ž�� recursive version, depth first search recursive version
void dfs_recur(Graph* G, int v) {

	// Fill your code
	if (v == -1)return 0; //��͸� ���鼭 ��� �ؾ� �곻�� �����ų�� ����� ��� pred[]�� ���� ��� - 1�� �ʱ�ȭ �Ǿ��ְ� 0�� pred ���� ���� �ٲ��� ���ϸ�(while ���ȿ� pred ���Խ� �� �ֱ⶧���Դϴ�.) -1�� ����Ǿ��ֱ� ������
	//����(pred)���� ���� ��ͷ� ���ƿ��� ���� ������ϸ� ������ ��� 0�� stack���� ���� ����Լ��� ���� ȣ�� �ɶ� -1�� �ְ� �Ǿ� v�� ���� -1�� �����°��� ���� �� �� �־��� v=-1�϶��� ��� ���� �������� ��������ϴ�...  
	if (G->pred[0] == 0)return 0;//�׸��� �긦 ���� ������ pred[0]�� ���� -1�ε� 0�� �Ǿ��ٴ� ���� ������ �Ŀ� ���� pop�� ����� ȿ���� ���� pop�� ����ٴ� ���� �����ֱ� ���� ��������ϴ�.

	if(G->visited[v]==FALSE)printf("%d\t", v);
	G->visited[v] = TRUE;
	graphNode* w = G->adjList_H[v];
		
	while (w != NULL) {
		if (G->visited[w->vertex] == FALSE) {
			G->pred[w->vertex] = v;
			dfs_recur(G, w->vertex);
		}
		else {
			w = w->link;
		}
	}
	//���������� ������
	dfs_recur(G, G->pred[v]);
	
	G->pred[v] = 0;//��͸� ���鼭 ��� �ؾ� �곻�� �����ų�� ����� ��� pred[]�� ���� ��� -1�� �ʱ�ȭ �Ǿ��־� ���Ḧ �ǹ��ϰ� �Ϸ��� 0�� �־�����ϴ�.

}

// �ʺ� �켱 Ž��, width first search
void bfs(Graph* G, int v) {

	// Fill your code
	Queue* Q = createQueue();
	G->visited[v] = TRUE;
	enqueue(Q, v);
	printf("%d\t",v);
	while (!isEmpty(Q))//4nd ť�� ���ٴ� ���� �� �湮�ߴٴ� ���Դϴ�. �ֳ��ϸ� ť�� Ư���� 1�� �������� 2�� �������� ... 7�� ������������ �� �� �湮�ߴٴ� �Ҹ��� �Ǳ� �����Դϴ�.
	{
		v = dequeue(Q);//3nd �� �̻� �湮���� ���� ������ ģ������ ���� ������ dequeue �� �Ͽ��� ���ư��°� �ƴϰ� �ݺ��� ������ ��ġ�� �Ͽ��� ������ 1,2 �� ������ ��ġ�� ������ݴϴ�. 
		graphNode* w = G->adjList_H[v];
		while (w != NULL) {//���������� ���������� 
			if (G->visited[w->vertex] == FALSE) {//1st�������� �� ä�� �� ģ���� �湮�� ���� ��������
				enqueue(Q, w->vertex);
				G->visited[w->vertex] = TRUE;
				printf("%d\t", w->vertex);
			}
			else {//2ndä�� �� ģ���� �ߺ��ϰ� �湮�ؼ� ������ ģ���� �ٸ� ģ��(==�� ���� ģ��)�� ä���ؼ� �ٽ� ���� ������ ��ȸ�� �ݴϴ�.
				w = w->link;
			}
		}
	}
}
