#include <stdio.h>
#include <stdlib.h>

int ent_integer(); // 사용자에게 몇 개의 정수를 처리할 것인지 물어보는 함수 
int* arr_alloc(int); // 배열을 동적으로 할당 받아 그 시작주소를 반환하는 함수 
void ent_array(int*, int); // 배열의 시작주소와 원소의 개수 n개의 정수를 키보드로부터 입력받아 배열에 저장하는 함수 
double retur_ave(int*, int); // 배열의 시작주소와 원소의 개수 n을 매개변수로 받아 그 평균을 반환하는 함수 

int ent_integer() {

	int kbs;
	printf("몇 개의 정수를 입력할까요? : ");
	scanf("%d", &kbs);

	return kbs;
}

int* arr_alloc(int n) {

	int* kbs;
	kbs = (int*)malloc(sizeof(int) * n);
	if (kbs == NULL) {
		printf("오류 발생"); exit(1);
	}

	return kbs;
}

void ent_array(int* p, int n) {

	for (int i = 0; i < n; i++) {
		printf("%d번째 정수 입력 : ", i + 1);
		scanf("%d", p + i);
	}

}

double retur_ave(int* p, int n) {

	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += *(p + i);

	return (double)sum / n;

}

int main() {

	int n, * kbs;

	n = ent_integer();

	kbs = arr_alloc(n);

	ent_array(kbs, n);

	printf("배열의 평균은 %.2f", retur_ave(kbs, n));

	free(kbs);

	return 0;
}

