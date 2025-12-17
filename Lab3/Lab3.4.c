#include <stdio.h>

struct student {
    char name[20];
    int age;
    char sex;
    float gpa;
};

void GetStudent(struct student child[][10], int *room) {
    int i, j;

    printf("Enter number of rooms: ");
    scanf("%d", room);

    for (i = 0; i < *room; i++) {
        printf("Room %d\n", i + 1);

        for (j = 0; j < 10; j++) {
            printf("Student %d\n", j + 1);

            printf("Name: ");
            scanf("%s", child[i][j].name);

            printf("Age: ");
            scanf("%d", &child[i][j].age);

            printf("Sex: ");
            scanf(" %c", &child[i][j].sex);

            printf("GPA: ");
            scanf("%f", &child[i][j].gpa);
        }
    }
}

int main() {

    struct student children[20][10];
    int group;

    GetStudent(children, &group);

    return 0;
}
