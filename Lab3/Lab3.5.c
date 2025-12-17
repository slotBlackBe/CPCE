#include <stdio.h>

struct student {
    char name[20];
    int age;
    char sex;
    float gpa;
};

struct student (*GetStudent(int *room))[10] {

    static struct student children[20][10];
    int i, j;

    printf("Enter number of rooms: ");
    scanf("%d", room);

    for (i = 0; i < *room; i++) {
        printf("\nRoom %d\n", i + 1);

        for (j = 0; j < 10; j++) {
            printf("Student %d\n", j + 1);

            printf("Name: ");
            scanf("%s", children[i][j].name);

            printf("Age: ");
            scanf("%d", &children[i][j].age);

            printf("Sex: ");
            scanf(" %c", &children[i][j].sex);

            printf("GPA: ");
            scanf("%f", &children[i][j].gpa);
        }
    }

    return children;
}

int main() {

    struct student (*children)[10];
    int group;
    int i, j;

    children = GetStudent(&group);

    for (i = 0; i < group; i++) {
        printf("\nRoom %d student list\n", i + 1);

        for (j = 0; j < 10; j++) {
            printf("%s %d %c %.2f\n",
                   children[i][j].name,
                   children[i][j].age,
                   children[i][j].sex,
                   children[i][j].gpa);
        }
    }

    return 0;
}
