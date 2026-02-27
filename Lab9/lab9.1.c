#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[50];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

struct studentNode *start = NULL;

void InsNode(char name[], int age, char sex, float gpa) {
    struct studentNode *newNode, *temp;

    newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = NULL;

    if (start == NULL) {
        start = newNode;
    } else {
        temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void ShowAll() {
    struct studentNode *temp = start;

    if (temp == NULL) {
        printf("No data\n");
        return;
    }

    while (temp != NULL) {
        printf("Name: %s Age: %d Sex: %c GPA: %.2f\n",
               temp->name, temp->age, temp->sex, temp->gpa);
        temp = temp->next;
    }
}

struct studentNode* FindNode(char name[]) {
    struct studentNode *temp = start;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void DelNode(char name[]) {
    struct studentNode *temp = start, *prev = NULL;

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Not found\n");
        return;
    }

    if (prev == NULL)
        start = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Deleted successfully\n");
}

void EditNode(char name[]) {
    struct studentNode *node = FindNode(name);

    if (node == NULL) {
        printf("Not found\n");
        return;
    }

    printf("New Age: ");
    scanf("%d", &node->age);
    printf("New Sex: ");
    scanf(" %c", &node->sex);
    printf("New GPA: ");
    scanf("%f", &node->gpa);

    printf("Updated successfully\n");
}

void writeFile() {
    FILE *fp;
    struct studentNode *temp;

    fp = fopen("student.dat", "wb");
    if (fp == NULL) return;

    temp = start;
    while (temp != NULL) {
        fwrite(temp, sizeof(struct studentNode) - sizeof(struct studentNode*), 1, fp);
        temp = temp->next;
    }

    fclose(fp);
}

void readFile() {
    FILE *fp;
    struct studentNode temp;

    fp = fopen("student.dat", "rb");
    if (fp == NULL) return;

    while (fread(&temp, sizeof(struct studentNode) - sizeof(struct studentNode*), 1, fp)) {
        InsNode(temp.name, temp.age, temp.sex, temp.gpa);
    }

    fclose(fp);
}

int main() {
    int menu;
    char name[50];
    int age;
    char sex;
    float gpa;

    readFile();

    do {
        printf("\nMenu\n");
        printf("1. Add\n");
        printf("2. Edit\n");
        printf("3. Delete\n");
        printf("4. Find\n");
        printf("5. Show All\n");
        printf("0. Exit\n");
        printf("Select: ");
        scanf("%d", &menu);

        switch (menu) {

        case 1:
            printf("Name: ");
            scanf("%s", name);
            printf("Age: ");
            scanf("%d", &age);
            printf("Sex (M/F): ");
            scanf(" %c", &sex);
            printf("GPA: ");
            scanf("%f", &gpa);
            InsNode(name, age, sex, gpa);
            break;

        case 2:
            printf("Enter name to edit: ");
            scanf("%s", name);
            EditNode(name);
            break;

        case 3:
            printf("Enter name to delete: ");
            scanf("%s", name);
            DelNode(name);
            break;

        case 4:
            printf("Enter name to find: ");
            scanf("%s", name);
            struct studentNode *node = FindNode(name);
            if (node != NULL) {
                printf("Found -> Name: %s Age: %d Sex: %c GPA: %.2f\n",
                       node->name, node->age, node->sex, node->gpa);
            } else {
                printf("Not found\n");
            }
            break;

        case 5:
            ShowAll();
            break;
        }

    } while (menu != 0);

    writeFile();
    return 0;
}