#include "structures.h"

bool already_enrolled(Enrollment* list, int id, const std::string& code) {
    while (list) {
        if (list->student_id == id && list->course_code == code) return true;
        list = list->next;
    }
    return false;
}

bool check_prerequisites(Enrollment* enrollments, Course* course, int id) {
    for (int i = 0; i < course->prereq_count; i++) {
        bool passed = false;
        Enrollment* e = enrollments;
        while (e) {
            if (e->student_id == id && e->course_code == course->prerequisites[i]
                && (e->grade == 'A' || e->grade == 'B' || e->grade == 'C')) {
                passed = true;
                break;
            }
            e = e->next;
        }
        if (!passed) return false;
    }
    return true;
}

bool check_credit_limit(Enrollment* enrollments, Course* courses, int id, const std::string& sem, int newc) {
    int sum = 0;
    Enrollment* e = enrollments;
    while (e) {
        if (e->student_id == id && e->semester == sem) {
            Course* c = courses;
            while (c) {
                if (c->course_code == e->course_code) sum += c->credits;
                c = c->next;
            }
        }
        e = e->next;
    }
    return (sum + newc <= 18);
}

bool enroll_student(Student* students, Course* courses, Enrollment*& enrollments,
                    int id, const std::string& code, const std::string& sem) {
    Student* s = find_student(students, id);
    Course* c = find_course(courses, code);

    if (!s || !c) return false;
    if (already_enrolled(enrollments, id, code)) return false;
    if (!check_prerequisites(enrollments, c, id)) return false;
    if (!check_credit_limit(enrollments, courses, id, sem, c->credits)) return false;
    if (c->enrolled_count >= c->capacity) return false;

    Enrollment* e = new Enrollment;
    e->student_id = id;
    e->course_code = code;
    e->semester = sem;
    e->grade = 'P';
    e->next = enrollments;
    enrollments = e;

    c->enrolled_count++;
    return true;
}

bool drop_course(Enrollment*& list, Course* courses, int id, const std::string& code) {
    if (!list) return false;

    if (list->student_id == id && list->course_code == code) {
        Enrollment* temp = list;
        list = list->next;
        delete temp;
        return true;
    }

    Enrollment* e = list;
    while (e->next) {
        if (e->next->student_id == id && e->next->course_code == code) {
            Enrollment* temp = e->next;
            e->next = temp->next;
            delete temp;
            return true;
        }
        e = e->next;
    }
    return false;
}

bool assign_grade(Enrollment* list, int id, const std::string& code, char g) {
    while (list) {
        if (list->student_id == id && list->course_code == code) {
            list->grade = g;
            return true;
        }
        list = list->next;
    }
    return false;
}