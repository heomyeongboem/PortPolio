#include <stdio.h>
#include <stdlib.h>
#include "ListGraph.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"

// 공백 그래프를 생성하는 연산, operations to generate a empty graph
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

// 그래프가 공백인지 검사, check if the graph is empty
int isEmptyGraph(Graph* G) {
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

// 그래프 G에 간선(u, v)를 삽입, insert a edge(u, v) into graph G
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
				if (p->vertex == v) return;//여기서 return 을 넣는 이유는 1->2 일때 G->adjList_H[1]에 이미 2값이 있는데 2->1이 들어오면 G->adjList_H[1]에 2를 확인시 G->adjList_H[2]에도 당연히 1이 있는데 1이 들어오려하기 때문에 
				//아얘 종료시키려 하는 것이다. (공부용)
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
		printf("정점 %d의 인접리스트", i);	// Adjacent list with vertex %d
		p = G->adjList_H[i];
		while (p) {
			printf(" -> %d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

// visited[], pred[] 초기화, initialized visited[], pre[]
void initSearch(Graph* G) {
	int i;
	for (i = 0; i < G->n; i++) {
		G->visited[i] = FALSE;
		G->pred[i] = -1;
	}
}

// 깊이 우선 탐색 iterative version, depth first search iterative version
void dfs_iter(Graph* G, int v) {

	// Fill your code
	Stack* S = create();//공백스택 생성
	G->visited[v] = TRUE;
	push(S, v);
	printf("%d\t",v);
	while (!isEmpty(S)) //공백스택이 아니라면
	{
		v = pop(S);
		graphNode* w = G->adjList_H[v];

		while (w!=NULL)//인접정점 다 돌때까지
		{
			if (G->visited[w->vertex] == FALSE) {//아직 방문하지 않은 인접정점이라면
				push(S, v);
				G->visited[w->vertex] = TRUE;
				printf("%d\t",w->vertex);
				v = w->vertex;//이걸로 인해
				w = G->adjList_H[v];//아래로 진입하게 됩니다.
			}
			else {//방문한 인접정점이라면 
				w = w->link;
			}
		}
	}
}

// 깊이 우선 탐색 recursive version, depth first search recursive version
void dfs_recur(Graph* G, int v) {

	// Fill your code
	if (v == -1)return 0; //재귀를 쓰면서 어떻게 해야 얘내를 종료시킬까 고민한 결과 pred[]의 값은 모두 - 1로 초기화 되어있고 0의 pred 값은 제가 바꾸지 못하며(while 문안에 pred 대입식 이 있기때문입니다.) -1로 저장되어있기 때문에
	//스택(pred)으로 인한 재귀로 돌아오는 것을 디버깅하며 관찰한 결과 0이 stack으로 인해 재귀함수에 의해 호출 될때 -1를 넣게 되어 v에 값이 -1이 들어오는것을 관찰 할 수 있었고 v=-1일때를 재귀 종료 조건으로 만들었습니다...  
	if (G->pred[0] == 0)return 0;//그리고 얘를 넣은 이유는 pred[0]의 값이 -1인데 0이 되었다는 것은 마지막 식에 의한 pop과 비슷한 효과로 인해 pop이 비었다는 것을 보여주기 위해 만들었습니다.

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
	//인접정점이 없을때
	dfs_recur(G, G->pred[v]);
	
	G->pred[v] = 0;//재귀를 쓰면서 어떻게 해야 얘내를 종료시킬까 고민한 결과 pred[]의 값은 모두 -1로 초기화 되어있어 종료를 의미하게 하려고 0을 넣어줬습니다.

}

// 너비 우선 탐색, width first search
void bfs(Graph* G, int v) {

	// Fill your code
	Queue* Q = createQueue();
	G->visited[v] = TRUE;
	enqueue(Q, v);
	printf("%d\t",v);
	while (!isEmpty(Q))//4nd 큐가 없다는 것은 다 방문했다는 것입니다. 왜냐하면 큐의 특성상 1의 인접정점 2의 인접정점 ... 7의 인접정점까지 싹 다 방문했다는 소리가 되기 때문입니다.
	{
		v = dequeue(Q);//3nd 더 이상 방문하지 않은 인접한 친구들이 없기 때문에 dequeue 로 하여금 돌아가는건 아니고 반복의 과정을 거치게 하여서 일일히 1,2 의 과정을 거치게 만들어줍니다. 
		graphNode* w = G->adjList_H[v];
		while (w != NULL) {//인접정점이 없을때까지 
			if (G->visited[w->vertex] == FALSE) {//1st인접정점 중 채택 된 친구가 방문을 아직 안했을때
				enqueue(Q, w->vertex);
				G->visited[w->vertex] = TRUE;
				printf("%d\t", w->vertex);
			}
			else {//2nd채택 된 친구가 야비하게 방문해서 인접한 친구중 다른 친구(==그 다음 친구)를 채택해서 다시 선별 과정의 기회를 줍니다.
				w = w->link;
			}
		}
	}
}
