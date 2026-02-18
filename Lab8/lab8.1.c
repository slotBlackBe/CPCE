#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode* next;
};

struct LinkedList {
    struct studentNode* start;
    struct studentNode* now;
};


void initList(struct LinkedList* list) {
    list->start = NULL;
    list->now = NULL;
}

void InsNode(struct LinkedList* list, char n[], int a, char s, float g) {
    struct studentNode* newNode =
        (struct studentNode*)malloc(sizeof(struct studentNode));

    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;

    if (list->start == NULL) {
        list->start = newNode;
        list->now = newNode;
    } else {
        struct studentNode* temp = list->start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void GoNext(struct LinkedList* list) {
    if (list->now != NULL)
        list->now = list->now->next;
}

void DelNode(struct LinkedList* list) {
    if (list->start == NULL || list->now == NULL)
        return;

    if (list->now == list->start) {
        struct studentNode* temp = list->start;
        list->start = list->start->next;
        list->now = list->start;
        free(temp);
    } else {
        struct studentNode* temp = list->start;
        while (temp->next != list->now)
            temp = temp->next;

        temp->next = list->now->next;
        free(list->now);
        list->now = temp->next;
    }
}

void ShowNode(struct LinkedList* list) {
    if (list->now != NULL) {
        printf("Name: %s Age: %d Sex: %c GPA: %.2f\n",
               list->now->name,
               list->now->age,
               list->now->sex,
               list->now->gpa);
    } else {
        printf("No current node\n");
    }
}

void freeList(struct LinkedList* list) {
    struct studentNode* temp;
    while (list->start != NULL) {
        temp = list->start;
        list->start = list->start->next;
        free(temp);
    }
}


int main() {

    struct LinkedList listA;
    struct LinkedList listB;
    struct LinkedList* listC;

    initList(&listA);
    initList(&listB);

    InsNode(&listA, "one", 1, 'A', 1.1);
    InsNode(&listA, "two", 2, 'B', 2.2);
    InsNode(&listA, "three", 3, 'C', 3.3);

    GoNext(&listA);
    ShowNode(&listA);

    InsNode(&listB, "four", 4, 'D', 4.4);
    InsNode(&listB, "five", 5, 'E', 5.5);
    InsNode(&listB, "six", 6, 'F', 6.6);

    GoNext(&listB);
    DelNode(&listB);
    ShowNode(&listB);

    listC = &listA;
    GoNext(listC);
    ShowNode(listC);

    listC = &listB;
    ShowNode(listC);

    freeList(&listA);
    freeList(&listB);

    return 0;
}
