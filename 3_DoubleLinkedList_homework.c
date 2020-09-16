#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char title[100];
	char artist[50];
}element;

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

void print_PlayList(DListNode* head, DListNode* cur) {
	DListNode* p;

	printf("---------------------------\n");

	for (p = head->rlink; p != head; p = p->rlink) {
		if (p == cur) { printf("%-20s", p->data.title); printf("%-35s", p->data.artist); printf("<-- 재생중\n"); }
		else { printf("%-20s", p->data.title); printf("%-35s", p->data.artist); printf("\n"); }		
	}
	printf("---------------------------\n");

	printf("\n현재 %s가 플레이 중입니다.\n", cur->data.title);
}


void play(DListNode* head) {
	char ch;
	DListNode* cur = head->rlink;

	do {
		getchar();
		print_PlayList(head, cur);
		printf("\n\n이전으로 가려면 '<', 다음으로 가려면 '>', 종료하려면 'q'\n");
		printf("명령어를 입력하세요 : "); ch = getchar();

		switch (ch) {
		   case '<':
			   cur = cur->llink;
			   if (cur == head) cur = cur->llink;
			   break;
		   case '>':
			   cur = cur->rlink;
			   if (cur == head) cur = cur->rlink;
			   break;
		}

	} while (ch != 'q');
}


int main(void) {
	DListNode head;
	element item;

	init(&head);

	strcpy(item.title, "Yesterday"); strcpy(item.artist, "Beatles"); dInsert_first(&head, item);
	strcpy(item.title, "Hotel California"); strcpy(item.artist, "Eagles"); dInsert_first(&head, item);
	strcpy(item.title, "The boxer"); strcpy(item.artist, "Simon & Garfunkle"); dInsert_first(&head, item);
	strcpy(item.title, "Let It Be"); strcpy(item.artist, "Beatles"); dInsert_first(&head, item);
	strcpy(item.title, "연습곡"); strcpy(item.artist, "김보성"); dInsert_first(&head, item);

	play(&head);

	return 0;
}

