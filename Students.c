#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>

typedef struct student {
	int id;
	char *no;
	char *name;
	int gender;
} stu;

struct student *createList () {
	stu *student = (stu *)malloc(sizeof(stu));
	student->id = 1;
	student->no = "sss";
	student->name = "zhang";
	student->gender = 2;
	return student;
}

int main() {
	system("stty -icanon");
	printf("请输入命令号\n 1. 打印\n 2. 输入\n 0. 退出程序\n");

	int qId = 1;
	while(0) {
		printf("请输入：");
		scanf("%d", &qId);
		switch(qId) {
			case 1:
				printf("打印\n");
				break;
			case 2:
				printf("输入\n");
				break;
			case 0:
				printf("退出程序\n");
				break;
		}
		if(qId <= 0) {
			break;
		} else {
			getchar();
		}
	}
	stu *s = createList();

	printf("输入的是%d %s %s\n", s->id, s->no, s->name);

	return 0;
}
