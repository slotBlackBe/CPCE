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

void SaveNode(struct studentNode *child,
              char n[], int a, char s, float g) {
    strcpy(child->name, n);
    child->age = a;
    child->sex = s;
    child->gpa = g;
    child->next = NULL;
}

void GoNext1(struct studentNode **walk) {
    if ((*walk)->next != NULL) {
        *walk = (*walk)->next;  
        printf("GoNext1 -> %s %d %c %.2f\n",
               (*walk)->name,
               (*walk)->age,
               (*walk)->sex,
               (*walk)->gpa);
    } else {
        printf("No next node\n");
    }
}

int main() {
    struct studentNode *start, *now1;
    struct studentNode **now2;

    start = (struct studentNode *)malloc(sizeof(struct studentNode));
    SaveNode(start, "one", 6, 'M', 3.11);

    start->next = (struct studentNode *)malloc(sizeof(struct studentNode));
    SaveNode(start->next, "two", 8, 'F', 3.22);

    start->next->next = (struct studentNode *)malloc(sizeof(struct studentNode));
    SaveNode(start->next->next, "three", 10, 'M', 3.33);

    start->next->next->next = (struct studentNode *)malloc(sizeof(struct studentNode));
    SaveNode(start->next->next->next, "four", 12, 'F', 3.44);

    now1 = start;
    now2 = &start;   

    GoNext1(&now1); 

    printf("After GoNext1, now1 = %s\n", now1->name);

    return 0;
}
