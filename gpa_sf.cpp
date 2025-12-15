#include "structures.h"

void update_gpa(Student* students, Enrollment* enrollments, int id) {
    Student* s = find_student(students, id);
    if (!s) return;

    double points = 0;
    int attempted = 0;
    int completed = 0;

    Enrollment* e = enrollments;
    while (e) {
        if (e->student_id == id) {
            double gp = -1;
            if (e->grade == 'A') gp = 4;
            if (e->grade == 'B') gp = 3;
            if (e->grade == 'C') gp = 2;
            if (e->grade == 'D') gp = 1;
            if (e->grade == 'F') gp = 0;

            if (gp >= 0) {
                attempted += 3;
                points += gp * 3;
                if (gp >= 2) completed += 3;
            }
        }
        e = e->next;
    }

    s->total_credits = completed;
    s->gpa = attempted ? points / attempted : 0;
}