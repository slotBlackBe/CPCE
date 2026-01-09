#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

struct studentNode* AddNode(struct studentNode **start, char n[], int a, char s, float g);
struct studentNode* InsNode(struct studentNode *now, char n[], int a, char s, float g);
void DelNode(struct studentNode *now);
void ShowAll(struct studentNode *walk);

int main() {
    struct studentNode *start, *now;
    start = NULL;

    now = AddNode(&start, "one", 6, 'M', 3.11);  ShowAll(start);
    now = AddNode(&start, "two", 8, 'F', 3.22);  ShowAll(start);
    now = InsNode(now, "three", 10, 'M', 3.33);  ShowAll(start);
    now = InsNode(now, "four", 12, 'F', 3.44);   ShowAll(start);
    DelNode(now);                                ShowAll(start);

    return 0;
}

struct studentNode* AddNode(struct studentNode **start, char n[], int a, char s, float g) {
    struct studentNode *node = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(node->name, n);
    node->age = a;
    node->sex = s;
    node->gpa = g;
    node->next = NULL;

    if (*start == NULL) {
        *start = node;
        return node;
    }

    struct studentNode *walk = *start;
    while (walk->next != NULL)
        walk = walk->next;

    walk->next = node;
    return node;
}

struct studentNode* InsNode(struct studentNode *now, char n[], int a, char s, float g) {
    if (now == NULL) return NULL;

    struct studentNode *node = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(node->name, n);
    node->age = a;
    node->sex = s;
    node->gpa = g;

    node->next = now->next;
    now->next = node;

    return node;
}

void DelNode(struct studentNode *now) {
    if (now == NULL || now->next == NULL) return;

    struct studentNode *tmp = now->next;
    now->next = tmp->next;
    free(tmp);
}

void ShowAll(struct studentNode *walk) {
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}
