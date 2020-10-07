#include <stdio.h>
#include <stdlib.h>

// 이진탐색트리에서의 삭제연산 - 반복문 이용

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* delete_node(TreeNode* root, element key) {
	TreeNode* p, * t, * child, * succ, * succ_p;
	// key를 갖는 노드 t를 탐색, p는 t의 부모노드 
	p = NULL; t = root;
	// key를 갖는 노드 t를 탐색한다.
	while (t != NULL && t->key != key) { // 노드 t가 널이 이거나 원하는 값을 찾을 때 루프 탈출
		p = t;
		t = (key < t->key) ? t->left : t->right;
	}

	if(t == NULL) { // 탐색이 종료된 시점에 t가 NULL이면 트리 안에 key가 없음
		printf("key is not in the tree");
		return root;
	}

	// 2. 삭제할 노드 관련 링크를 조정한다.
	// case 1 : 단말노드인 경우 : 부모노드가 있는지 없는지에 따라 다르다 
	if ((t->left == NULL) && (t->right == NULL)) {
		if (p != NULL) { // 부모노드의 자식필드를 NULL로 만든다
			if (p->left == t)
				p->left = NULL;
			else p->right = NULL;
		}
		else // 만약 부모노드가 NULL이면?
			root = NULL; // 삭제되는 노드가 루트
	}
	// case 2 : 하나의 자식만 가지는 경우 
	else if ((t->left == NULL) || (t->right == NULL)) {
		// t의 자식 노드의 주소를 얻는다 
		child = (t->left != NULL) ? t->left : t->right;

		// 부모를 자식과 연결 
		if (p != NULL) {
			if (p->left == t) p->left = child;
			else p->right = child;
		}
		else // 만약 부모노드가 NULL이면 삭제되는 노드가 루트 
			root = child;
	}

	// case 3 : 두개의 자식을 가지는 경우 

	else { // 오른쪽 서브트리에서 후속자를 찾는다 
		succ_p = t; succ = t->right;
		// 후속자를 찾아서 계속 왼쪽으로 이동 
		while (succ->left != NULL) {
			succ_p = succ; succ = succ->left;
		}
		// 후속자의 부모와 자식을 연결 
		if (succ_p->left == succ)
			succ_p->left = succ->right;
		else
			succ_p->right = succ->right;

		// 후속자가 가진 키값을 현재 노드에 복사한 다음 
		t->key = succ->key;
		// 원래의 후속자 삭제를 위해 포인터 변경 
		t = succ;
	}
	free(t);
	return root; // 3. 삭제할 노드를 free 시키고, root를 반환한다
}


