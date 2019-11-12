#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>
#include <string.h>

/*
 学生信息
 */
typedef struct student {
	int id;		// id 内部使用，外部不用知道
	char no[20];	// 学号
    char name[20];	// 姓名
	int gender;	// 性别 1男 2女
    float englishScore; // 英语成绩
} Stu;

/*
 链表节点
 */
typedef struct node {
	Stu *info;	// 节点信息
	struct node *next;	// 下一个节点
} Node;

Stu *inputStuInfo();
void printStuInfo(Stu *info);
void printMenu();
Node *addStuInfo(Stu *info, Node *list);

/*
 初始化链表
 */
Node *createList() {
	Node *head = (Node *)malloc(sizeof(Node));
	head->info = NULL;
	head->next = NULL;
	return head;
}

/***
 输入学生信息
 */
Stu *inputStuInfo() {
    Stu *info = (Stu *)malloc(sizeof(Stu));

    printf("姓名：");
    char name[20];
    scanf("%s", name);
    strcpy(info->name, name);

    printf("学号：");
    char no[20];
    scanf("%s", no);
    strcpy(info->no, no);
    
    printf("性别（0女，1男）：");
    int gender;
    scanf("%d", &gender);
    info->gender = gender;
    
    printf("英语成绩：");
    float score;
    scanf("%f", &score);
    info->englishScore = score;
    
    return info;
}

Node *addStuInfo(Stu *info, Node *list) {
    if (list->info == NULL) {
        list->info = info;
        return list;
    }
    Node *tmp = list;
    while (tmp->next) {
        tmp = tmp->next;
    }
    
    Node *node = (Node *)malloc(sizeof(Node));
    node->info = info;
    node->next = NULL;
    
    tmp->next = node;
    return list;
}

/**
 打印指定学生信息
 */
void printStuInfo(Stu *info) {
    if (info) {
        printf("No:%s Name:%s Score:%.2f\n", info->no, info->name, info->englishScore);
    } else {
        printf("空\n");
    }
}

/**
 打印list中的学生信息
 */
void printList(Node *head) {
    Node *tmp = head;
    while (tmp) {
        printStuInfo(tmp->info);
        tmp = tmp->next;
    }
    printf("\n");
}

/**
 打印menu
 */
void printMenu() {
    printf("\n************************************\n\n");
    printf("请输入数字\n 1. 打印成绩\n 2. 输入成绩\n 0. 退出程序\n");
}

/**
 获取用户输入的命令
 */
void getCommand() {
    Node *list = createList();
    int qId = 1;
    while(1) {
        scanf("%d", &qId);
        switch(qId) {
            case 1:
                printf("\n打印学生成绩：\n\n");
                printList(list);
                break;
            case 2:
                printf("\n请输入学生信息：\n\n");
                Stu *newStuInfo = inputStuInfo();
                list = addStuInfo(newStuInfo, list);
                break;
            case 0:
                printf("\n退出程序\n");
                break;
        }
        if(qId <= 0) {
            break;
        } else {
            getchar();
        }
        printMenu();
    }
}

int main() {
	system("stty -icanon");
    printMenu();
    getCommand();
	return 0;
}
