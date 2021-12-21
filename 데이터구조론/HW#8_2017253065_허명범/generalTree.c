#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable : 4996)

#define MAX_CHILD 10

typedef struct ano* nodeptr;
typedef struct ano {
	char name[30];
	float gpa;
	char place[100];
	nodeptr links[MAX_CHILD];
}nodetype;

nodeptr root = NULL;
nodeptr stack[100];
int top = -1;


int read_upper(FILE* fp, char buf[20][50]); 	// ������ ������ ��ݺ��� �� �� �д� �Լ�, function that reads a single line at the top of a data file
void read_store_lower_data(FILE* fp);			// ������ ������ �Ϲݺ��� �� �� �д� �Լ�, function that reads a single line frome the bottom half of the data file
void print_general_tree(nodeptr curr);			// ��� ����� ������ ���, output the contents of all nodes
void make_node_and_attach_to_parent(nodeptr parent, char* tname, int loc);	// parent�� loc ��ġ�� �ڽ� ��带 ����� �Ŵް� �̸��� tname�� �־���, create a child node in the loc location of the parents, hang it, and insert the name tname
void push_stack(nodeptr nptr);
void pop_stack();

nodeptr search_node(nodeptr cur, char name[]);	// �̸����� ��� Ž��, searching nodes by name
void calc_height(nodeptr cur, int par_height, int* tree_height);	// Find the height of the whole tree
int calc_depth(nodeptr cur, int par_height, char* sname);		// Find the depth of a specific person
int find_ancestors(nodeptr cur, char* sname);	// Find all ancestors of a specific person
void calc_descendants(nodeptr cur, int* cnt);	// Find the number of descendants of a specific person

int main() {
	char buf[20][50];
	char line[100];
	char command[100];
	char name[10];
	int num_persons, k, i, res;
	nodeptr np;

	FILE* fp;
	fp = fopen("tree_data.txt", "r");
	if (!fp) {
		printf("file open error\n");
		return 0;
	}

	do {
		num_persons = read_upper(fp, buf);	// read one line of several names
		if (num_persons == 0)	// '-' in first letter of the first person's name
			break;
		if (!root) {	// no node in the tree
			np = (nodeptr)malloc(sizeof(nodetype));
			strcpy(np->name, buf[0]);	// �θ� �̸� ����, put parent name
			root = np;
			np->links[0] = NULL;
			for (k = 1; k < num_persons; k++)	// �ڽĵ��� ����� �Ŵ���, making child and hanging them
				make_node_and_attach_to_parent(np, buf[k], k - 1);
			// put NULL in links field after the last child
			np->links[k - 1] = NULL;
		}
		else {	// ordinary case of a tree with one or more nodes
			np = search_node(root, buf[0]);
			if (!np) {
				printf("Error: 2° �� ������ ù �̸� ��尡 ����\n");	// Error: No first name node less than second line
				getchar();
			}
			for (k = 1; k < num_persons; k++)
				make_node_and_attach_to_parent(np, buf[k], k - 1);
			// put NULL in links field after the last child
			np->links[k - 1] = NULL;
		}
	} while (1);

	// �� ��忡 ���� �����͸� �о ����, read and save data for each node
	read_store_lower_data(fp);

	// Ʈ�� ���� ��� ����� �����͸� preorder ������� ���, output data from all nodes in the tree in a preorder manner
	print_general_tree(root);

	do {
		printf("Type a command> ");
		gets(line);

		i = 0;
		while (line[i] == ' ' || line[i] == '\t') i++;	// move to 1st letter of the command
		k = 0;
		while (!(line[i] == ' ' || line[i] == '\t' || line[i] == '\0')) {
			command[k] = line[i];
			i++; k++;
		}
		command[k] = '\0';	// finish the command

		if (strcmp(command, "ex") == 0)
			break;
		else if (strcmp(command, "ht") == 0) {
			int tree_height = 0;
			calc_height(root, 0, &tree_height);
			printf("Height of the tree : %d \n", tree_height);
			continue;
		}

		// read a name given after the command
		k = 0;
		while (line[i] == ' ' || line[i] == '\t') i++;	// move to 1st letter of the command
		while (!(line[i] == ' ' || line[i] == '\t' || line[i] == '\0')) {
			name[k] = line[i];
			i++; k++;
		}
		name[k] = '\0';

		if (strcmp(command, "se") == 0) {
			np = search_node(root, name);
			if (np)
				printf("Search success: %s %5.2f %s\n", np->name, np->gpa, np->place);
			else
				printf("Such a person does not exist\n");
		}
		else if (strcmp(command, "dp") == 0) {
			res = calc_depth(root, 0, name);
			if (!res)
				printf("Such a name does not exist in the tree\n");
		}
		else if (strcmp(command, "ac") == 0) {
			top = -1;
			res = find_ancestors(root, name);
			if (!res)
				printf("Such a name does not exist in the tree\n");
		}
		else if (strcmp(command, "nm") == 0) {
			int cnt = 0;
			np = search_node(root, name);
			calc_descendants(np, &cnt);
			printf("%d ��\n", cnt);	// order
		}
		else {
			printf("Wrong command\n");
		}
	} while (1);

	return 0;
}

// ������ ������ ��ݺ��� �� �� �д� �Լ�, function that reads a single line at the top of a data file
// �� ���� �о 2���� �迭 buf�� �ְ�, ��� ���� ��ȯ, read one line and put it in a tow-dimensional array buf, returning the number of people
// 0�� --- ���� ���� ��쿡 ��ȯ��, 0 returned when --- line read
int read_upper(FILE* fp, char buf[20][50]) {
	// read "parent-children" lines to create the tree
	int i, j, k;
	char line[400];
	char* cp;
	cp = fgets(line, 400, fp);
	if (!cp) {
		// fail in reading
		printf("Impossible for the control to reach here\n");
		return 0;
	}
	else {
		if (line[0] == '-')  // ���� ��ܺ� �б� ����, end file top read
			return 0;

		i = 0;		// number of names read so far
		j = 0; 		// index to line
		while (1) {
			k = 0; 	// index to a character of the i-th name
			while (line[j] != ' ' && line[j] != '\n') {
				buf[i][k] = line[j];
				j++; k++;
			}
			buf[i][k] = '\0';	// finish one name
			i++;	// increase the name count
			if (line[j] == '\n')
				break;
			else {
				do j++; while (line[j] == ' ');
			}
		}
		return i;
	}
}

// ������ ������ �ϴܺθ� �о� ������ ����, store information by reading the lower part of the data file
void read_store_lower_data(FILE* fp) {
	char rname[30], address[100];
	float rgpa;
	nodeptr np;
	int read_num;

	do {
		read_num = fscanf(fp, "%s%f%s", rname, &rgpa, address);
		if (read_num != 3)
			break;
		else {
			// ���� �̸��� ���� ��带 Ʈ������ ã��, found nodes with read names in the tree
			np = search_node(root, rname);
			if (!np)
				printf("�̷� �̸��� ���� ��尡 �����ϴ�.\n");	// No node with this name exists
			else {
				// ���� �����͸� ����, save read data
				strcpy(np->name, rname);
				np->gpa = rgpa;
				strcpy(np->place, address);
			}
		}
	} while (1);
}

// ��� ����� ������ ���, output the contents of all nodes
void print_general_tree(nodeptr cur) {
	int i;
	if (!cur)
		return;
	printf("�̸�: %s\t����: %5.2f\t�ּ�: %s \n", cur->name, cur->gpa, cur->place);	// Name: %s\tGrade: %5.2f\tAddress: %s \n
	for (i = 0; cur->links[i]; i++)
		print_general_tree(cur->links[i]);
}

// parent�� loc ��ġ�� �ڽ� ��带 ����� �Ŵް� �̸��� tname�� �־���, create a child node in the loc location of the parents, hang it, and insert the name tname
void make_node_and_attach_to_parent(nodeptr parent, char* tname, int loc) {
	nodeptr np1;
	np1 = (nodeptr)malloc(sizeof(nodetype));
	strcpy(np1->name, tname);
	np1->links[0] = NULL;
	parent->links[loc] = np1;
}

void push_stack(nodeptr nptr) {
	top++;//0,1
	stack[top] = nptr;
}

// this pop des not return the element
void pop_stack() {
	top--;
}

// �̸����� search, search by name
// cur : Ʈ���� ��忡 ���� ������, pointer to nodes in the tree
// name : ã�� �̸�, name to look for
// ��ȯ�� : ã�� ����� ������ (�� ã�� ��� NULL), return value: pointer of found node (NULL if not found)
nodeptr search_node(nodeptr cur, char name[]) {
	int i;
	nodeptr rptr;

	if (!cur)
		return NULL;

	if (strcmp(cur->name, name) == 0)
		return cur;		// ����, success
	else {
		for (i = 0; cur->links[i] != NULL; i++) {
			rptr = search_node(cur->links[i], name);
			if (rptr) return rptr;
		}
		return NULL;	// �ڽĵ� ��ο����� �� ã�����Ƿ� ����, failed because none of the child found it
	}
}

// Find the height of the whole tree
void calc_height(nodeptr cur, int par_height, int* tree_height) {

	// Fill your code

	int i;
	int* k = tree_height;
	if (!cur)
		return;

	par_height++;
	
	*k = par_height;
	
	calc_height(cur->links[0], par_height,k);
	
	//if(strcmp(cur))
	

}

// Find the depth of a specific person
// return value : 1 if the name has been found and its depth was printed
//				  0 if the name was not found in the subtree with root of cur
int calc_depth(nodeptr cur, int par_height, char* sname) {

	// Fill your code

	if (search_node(root, sname) == 0)return 0;

	if (!cur)return; //������ �� ��� ������ �����϶�� ����

	if (strcmp(sname, "������") == 0) {

		if (top > -1) {
			while (top>0)
			{
				pop_stack();
			}

			printf("Height of the node of %s : %d\n", stack[top], par_height + 1);

			pop_stack();
			return 1;
		}
	}

	else {

		for (int i = 0; cur->links[i]; i++) {//ã�� �����ε� ã���� �������� �Ѿ �ʿ䰡 ����

			if (cur->links[i] == NULL)return;//��������

			else if (strcmp(cur->links[i]->name, sname) == 0) {

				push_stack(sname);

				sname = cur->name;//�θ� ��带 �־������ν� ���� �ڽ� ��带 ã�� ���� �ƴ� �θ� ��带 ã�ƾߵǰ� ������ݴϴ�.... 

				calc_depth(root, ++par_height, sname);
			}

		}
		for (int s = 0; cur->links[s]; s++)
		{
			calc_depth(cur->links[s], par_height,sname);
		}
	}
	

}

// Find all ancestors of a specific person
int find_ancestors(nodeptr cur, char* sname) {

	// Fill your code
	
	if (search_node(root, sname) == 0)return 0;

	if (!cur)return; //������ �� ��� ������ �����϶�� ����
	
	if (strcmp(sname, "������") == 0) {

		if (top > -1) {

			printf("this person's ancestor:");

			while (top != -1)
			{
				printf(" %s", stack[top]);

				pop_stack();
			}

			printf("\n");
			return 1;
		}
	}
	
	else {
		
		for (int i = 0; cur->links[i]; i++) {//ã�� �����ε� ã���� �������� �Ѿ �ʿ䰡 ����

			if (cur->links[i] == NULL)return;//��������

			else if (strcmp(cur->links[i]->name, sname) == 0) {
	
				push_stack(cur->name);

				sname = cur->name;//�θ� ��带 �־������ν� ���� �ڽ� ��带 ã�� ���� �ƴ� �θ� ��带 ã�ƾߵǰ� ������ݴϴ�.... 
			
				find_ancestors(root, sname);
			}

		}
		for (int s = 0; cur->links[s]; s++)
		{
			find_ancestors(cur->links[s], sname);
		}		
	}
}

// Find the number of descendants of a specific person
void calc_descendants(nodeptr cur, int* cnt) {
	

	int* k = cnt;
	
	if (!cur)
		return ;
	
	for (int i = 0; cur->links[i]; i++)
	{
		if (cur)(*k)++;

		calc_descendants(cur->links[i], k);

	}
	

}