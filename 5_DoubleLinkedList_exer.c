#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DlistNode {
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
}DListNode;

void init(DListNode* head) {
	head->llink = head;
	head->rlink = head;
}

void dInsert_first(DListNode* before, element item) {

	DListNode* new_node;

	new_node = (DListNode*)malloc(sizeof(DListNode));
	new_node->data = item;

	new_node->llink = before;
	new_node->rlink = before->rlink;
	before->rlink->llink = new_node;
	before->rlink = new_node;
}

void dRemove_node(DListNode* phead_node, DListNode* removed) {

	if (remove == phead_node) return;

	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;

	free(removed);
}

DListNode* get_dNode_at(DListNode* head, int pos) {

	DListNode* p = head->rlink;
	int i;

	for (i = 0; i < pos; i++) p = p->rlink;
	return p;
}

element dDelete(DListNode* head, int pos) {
	DListNode* p;
	element item;

	p = get_dNode_at(head, pos);
	item = p->data;
	dRemove_node(head, p);
	return item;
}


void print_dlist(DListNode* phead) {

	DListNode* p;

	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-|%d|->", p->data);
	}

	printf("\n");
}


int main() {

	DListNode list;

	init(&list);

	dInsert_first(&list, 10);
	dInsert_first(&list, 20);
	dInsert_first(&list, 30);
	dInsert_first(&list, 40);
	dInsert_first(&list, 50);

	print_dlist(&list);

	dDelete(&list, 2);

	print_dlist(&list);

}