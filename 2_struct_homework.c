#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char sub[100]; // 과목명 
	char pro[100]; // 담당교수명 
	char score[20]; // 학점 
}sub_info;

sub_info* allocMem(int n) {

	sub_info* p;

	p = (sub_info*)malloc(sizeof(sub_info) * n);

	if (p == NULL) {
		printf("오류 발생\n"); exit(1);
	}

	return p;
}

void get_info(sub_info* p, int n) {

	for (int i = 0; i < n; i++) {
		printf("과목명 : "); getchar(); gets(p[i].sub);
		printf("담당 교수명 : "); scanf("%s", p[i].pro);
		printf("학점 : "); scanf("%s", p[i].score);
	}
}

int main() {

	int sub_num; // 과목의 개수 
	sub_info* p; // 구조체 sub_info를 가리키는 구조체 포인터 p 

	printf("수강신청한 과목의 개수를 입력하세요 : ");
	scanf("%d", &sub_num);

	p = allocMem(sub_num); // p는 시작주소를 가진다. p는 배열처럼 사용 가능하다

	get_info(p, sub_num); // 수강신청 정보 작성 

	printf("------------- 수강신청 과목 ---------------\n");

	for (int i = 0; i < sub_num; i++) {
		printf("과목명 : %s\n", p[i].sub);
		printf("담당 교수명 : %s\n", p[i].pro);
		printf("학점 : %s\n\n", p[i].score);
	}

	free(p);

	return 0;
}

