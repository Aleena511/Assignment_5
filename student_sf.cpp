#include "structures.h"

void add_student(Student*& list, int id, const std::string& name, const std::string& major) { // list is a reference to a pointer to a Student so that only copy isnt changed 
    Student* s = new Student;
    s->student_id = id;
    s->name = name;
    s->major = major;
    s->total_credits = 0;
    s->gpa = 0.0;
    s->next = list; 
    list = s;   // assigning pointers 
}

Student* find_student(Student* list, int id) {
    while (list) {
        if (list->student_id == id) return list;
        list = list->next;
    }
    return nullptr;  // no dangling pointer 
}         

bool update_major(Student* list, int id, const std::string& new_major) {
    Student* s = find_student(list, id);
    if (!s) return false;
    s->major = new_major;
    return true;
}

void remove_student(Student*& students, Enrollment*& enrollments, int id) {
    // remove enrollments to clear memory 
    while (enrollments && enrollments->student_id == id) {
        Enrollment* temp = enrollments;
        enrollments = enrollments->next;
        delete temp;
    }

    Enrollment* e = enrollments;
    while (e && e->next) {
        if (e->next->student_id == id) {
            Enrollment* temp = e->next;
            e->next = temp->next;
            delete temp;
        } else e = e->next;
    }

    // remove student
    if (students && students->student_id == id) {
        Student* temp = students;
        students = students->next;
        delete temp;
        return;
    }

    Student* s = students;
    while (s && s->next) {
        if (s->next->student_id == id) {
            Student* temp = s->next;
            s->next = temp->next;
            delete temp;
            return;
        }
        s = s->next;
    }
}

std::ostream& operator<<(std::ostream& out, const Student& s) {
    out << "ID: " << s.student_id << "Name: " << s.name  // core logic 
        << "Major: " << s.major << "Credits: "
        << s.total_credits << "GPA: " << s.gpa;
    return out;}   // clear multiple insertions 