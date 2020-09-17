#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[100];
}element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

typedef struct {
	ListNode* head;
	int size;
}ListType;

void init_list(ListType* L) {
	L->head = NULL;
	L->size = 0;
}

int is_empty(ListType* L) {
	return (L->head == NULL);
}

void print_list(ListType* L) {
	ListNode* p;

	if (L->head == NULL) {
		printf("No data exists..\n"); return;
	}

	for (p = L->head->link; p != L->head; p = p->link)
		printf("%d->", p->data);

	printf("%d.. End of List\n", p->data);
}

void insert_first(ListType* L, element item) {
	ListNode* new_node;

	new_node = (ListNode*)malloc(sizeof(ListNode));
	new_node->data = item;

	if(L->head == NULL) {
		new_node->link = new_node;
		L->head = new_node;
	}

	else {
		new_node->link = L->head->link;
		L->head->link = new_node;
	}

	L->size++;
}

void insert_last(ListType* L, element item) {
	ListNode* new_node;

	new_node = (ListNode*)malloc(sizeof(ListNode));
	new_node->data = item;

	if (is_empty(L)) {
		new_node->link = new_node;
		L->head = new_node;
	}

	else {
		new_node->link = L->head->link;
		L->head->link = new_node;
		L->head = new_node;
	}

	L->size++;
}

element delete_first(ListType* L) {

	element item;
	ListNode* removed = NULL;

	if (is_empty(L)) { printf("List Error\n\n"); exit(1); }

	removed = L->head->link;
	item = removed->data;

	if (removed != L->head) // 원소가 한 개가 아닐 때 
		L->head->link = removed->link;
	else // 원소가 한 개 일 때 
		L->head = NULL;

	free(removed);
	L->size--;

	return item;
}

int main() {
	ListType List;
	ListNode* p;
	element item;
	int i;

	init_list(&List);

	strcpy(item.name, "Kim"); insert_last(&List, item);
	strcpy(item.name, "Lee"); insert_last(&List, item);
	strcpy(item.name, "Park"); insert_last(&List, item);

	printf("Start game...\n\n");

	for (i = 0, p = List.head->link; i < 10; i++, p = p->link) { // p를 초기화 시킨다, 10번 반복
		printf("현재 차례 : %s\n", p->data.name);
	}

	return 0;
}