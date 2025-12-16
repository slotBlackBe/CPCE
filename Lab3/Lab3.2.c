#include <stdio.h>

struct student {
    char name[20];
    int age;
    char sex;
    float gpa;
};

void upgrade(struct student *child);

int main() {
    struct student aboy;
    aboy.sex = 'M';
    aboy.gpa = 3.00;

    printf("GPA ก่อนเรียกฟังก์ชัน: %.2f\n", aboy.gpa);

    upgrade(&aboy);

    printf("GPA หลังเรียกฟังก์ชัน: %.2f\n", aboy.gpa);

    return 0;
}

void upgrade(struct student *child) {
    if (child->sex == 'M') {
        child->gpa *= 1.10;
        printf("  > เป็นผู้ชาย (M): GPA เพิ่มขึ้น 10%% (ใหม่: %.2f)\n", child->gpa);
    } else if (child->sex == 'F') {
        child->gpa *= 1.20;
        printf("  > เป็นผู้หญิง (F): GPA เพิ่มขึ้น 20%% (ใหม่: %.2f)\n", child->gpa);
    } else {
        printf("  > ไม่สามารถระบุเพศได้: ไม่มีการเปลี่ยนแปลง GPA\n");
    }
}