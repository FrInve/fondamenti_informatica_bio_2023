#include <stdio.h>

#define MAX_EXAMS 20
#define MAX_STUDENTS 100

typedef struct exam {
    float vote;
    int credits;
} Exam;

typedef struct student {
    int id;
    Exam exams[MAX_EXAMS];
    int num_exams;
} Student;

typedef struct registro {
    Student students[MAX_STUDENTS];
    int num_students;
} Register;

float weighted_average(Student s) {
    float sum_v_c = 0;
    int sum_c = 0;

    for (int i = 0; i < s.num_exams; i++) {
        sum_v_c += s.exams[i].vote * s.exams[i].credits;
        sum_c += s.exams[i].credits;
    }

    return sum_v_c / sum_c;
}

void print_weighted_averages(Register r) {
    for (int i = 0; i < r.num_students; i++) {
        printf("Student %d: %.2f\n", r.students[i].id, weighted_average(r.students[i]));
    }
}

void add_student(Register *r, int id, Exam *exams, int num_exams) {
    if (r->num_students < MAX_STUDENTS) {
        Student s = {id, {}, 0};
        for (int i = 0; i < num_exams && i < MAX_EXAMS; i++) {
            s.exams[i] = exams[i];
            s.num_exams++;
        }
        r->students[r->num_students++] = s;
    }
}

int main() {
    // create a register and add some students with exams
    Register r = {0};
    Exam exams1[] = {{24, 6}, {27, 9}};
    add_student(&r, 1, exams1, 2);
    Exam exams2[] = {{18, 6}, {30, 9}, {28, 9}};
    add_student(&r, 2, exams2, 3);
    Exam exams3[] = {{20, 6}};
    add_student(&r, 3, exams3, 1);

    // print the weighted averages of the students
    print_weighted_averages(r);

    return 0;
}
