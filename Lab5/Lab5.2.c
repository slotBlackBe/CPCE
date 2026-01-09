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

void ShowAll(struct studentNode **walk) {
    struct studentNode *p = *walk;
    printf("List: ");
    while (p != NULL) {
        printf("[%s %d %c %.2f] -> ", p->name, p->age, p->sex, p->gpa);
        p = p->next;
    }
    printf("NULL\n");
}

void InsNode(struct studentNode **now, char name[], int age, char sex, float gpa) {
    struct studentNode *newNode = (struct studentNode*) malloc(sizeof(struct studentNode));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;

    newNode->next = *now;
    *now = newNode;
}

void GoNext(struct studentNode ***now) {
    if ((**now) != NULL) {
        *now = &((**now)->next);
    }
}

void DelNode(struct studentNode **now) {
    if (*now != NULL) {
        struct studentNode *tmp = *now;
        *now = (*now)->next;
        free(tmp);
    }
}

int main() {
    struct studentNode *start = NULL;
    struct studentNode **now = &start;

    InsNode(now, "one", 6, 'M', 3.11);
    ShowAll(&start);

    InsNode(now, "two", 8, 'F', 3.22);
    ShowAll(&start);

    GoNext(&now);
    InsNode(now, "three", 10, 'M', 3.33);
    ShowAll(&start);

    InsNode(now, "four", 12, 'F', 3.44);
    ShowAll(&start);

    GoNext(&now);
    DelNode(now);
    ShowAll(&start);

    return 0;
}
