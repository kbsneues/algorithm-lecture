#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

// 반복적인 탐색 함수
TreeNode* search(TreeNode* node, int key) {
	while (node != NULL) {
		if (key == node->key)
			return node;
		else if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	return NULL; // 탐색에 실패한 경우 NULL 반환 
}

// 재귀적인 탐색 함수 
TreeNode* search(TreeNode* node, int key) {
	if (node == NULL) return NULL;
	
	if (key == node->key) return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}

TreeNode* new_node(element item) {
	TreeNode* p;
	p = (TreeNode*)malloc(sizeof(TreeNode));
	p->key = item;
	p->left = p->right = NULL;
	return p;
}

// 이진탐색트리에서의 삽입연선 - 반복문 이용 
TreeNode* insert_node(TreeNode* root, element key) {
	TreeNode* p, * t; // p는 부모 노드, t는 현재노드
	TreeNode* node; // node는 새로운 노드

	t = root; p = NULL;

	while (t != NULL) { 
		if (key == t->key) return root;
		p = t; // t를 부모노드로 바꾼다
		if (key < t->key) t = t->left;
		else t = t->right;
	}

	// node를 하나 만들어 key를 추가
	node = new_node(key);

	if (p == NULL)
		root = node;
	else {
		if (key < p->key) p->left = node;
		else p->right = node;
	}

	return root;

}

// 이진 탐색트리에서의 삽입 연산 - 재귀 사용
TreeNode* insert_node(TreeNode* node, int key) {
	// 트리가 공백이면 새로운 노드를 반환한다. 

	if (node == NULL) return new_node(key);

	// 그렇지 않으면 순환적으로 트리를 내려간다. 

	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	// 변경된 루트 포인터를 반환한다.
	return node;
}