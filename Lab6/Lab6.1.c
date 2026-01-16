#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

struct studentNode* AddNode(struct studentNode **start, char name[], int age, char sex, float gpa) {
    struct studentNode *newNode = malloc(sizeof(struct studentNode));
    struct studentNode *walk = *start;

    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = NULL;
    newNode->back = NULL;

    if (*start == NULL) {
        *start = newNode;
        return newNode;
    }

    while (walk->next != NULL)
        walk = walk->next;

    walk->next = newNode;
    newNode->back = walk;

    return newNode;
}

void InsNode(struct studentNode **start, struct studentNode *now, char name[], int age, char sex, float gpa) {
    if (now == NULL) return;

    struct studentNode *newNode = malloc(sizeof(struct studentNode));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;

    newNode->next = now;
    newNode->back = now->back;

    if (now->back != NULL) {
        now->back->next = newNode;
    } else {
        *start = newNode;
    }

    now->back = newNode;
}

void GoBack(struct studentNode **now) {
    if (*now && (*now)->back)
        *now = (*now)->back;
}

void DelNode(struct studentNode **now, struct studentNode **start) {
    if (*now == NULL) return;

    struct studentNode *del = *now;

    if (del->back != NULL)
        del->back->next = del->next;
    else
        *start = del->next;

    if (del->next != NULL)
        del->next->back = del->back;

    if (del->next != NULL)
        *now = del->next;
    else
        *now = del->back;

    free(del);
}

void ShowAll(struct studentNode *walk) {
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}

int main() {
    struct studentNode *start = NULL;
    struct studentNode *now = NULL;

    now = AddNode(&start, "one", 6, 'M', 3.11);
    ShowAll(start);

    now = AddNode(&start, "two", 8, 'F', 3.22);
    ShowAll(start);

    InsNode(&start, now, "three", 10, 'M', 3.33);
    ShowAll(start);

    InsNode(&start, now, "four", 12, 'F', 3.44);
    ShowAll(start);

    GoBack(&now);
    DelNode(&now, &start);
    ShowAll(start);

    DelNode(&now, &start);
    ShowAll(start);

    DelNode(&now, &start);
    ShowAll(start);

    return 0;
}
