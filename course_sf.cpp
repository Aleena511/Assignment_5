#include "structures.h"

void add_course(Course*& list, const std::string& code, const std::string& name, int credits, int capacity) {
    Course* c = new Course;
    c->course_code = code;
    c->course_name = name;
    c->credits = credits;
    c->capacity = capacity;
    c->enrolled_count = 0;
    c->prerequisites = nullptr;
    c->prereq_count = 0;
    c->next = list;
    list = c;   // assigning pointers
}

Course* find_course(Course* list, const std::string& code) {
    while (list) {
        if (list->course_code == code) return list;
        list = list->next;
    }
    return nullptr;
}

void add_prerequisite(Course* course, const std::string& prereq) {
    std::string* arr = new std::string[course->prereq_count + 1];
    for (int i = 0; i < course->prereq_count; i++) arr[i] = course->prerequisites[i];
    arr[course->prereq_count] = prereq;
    delete[] course->prerequisites;
    course->prerequisites = arr;
    course->prereq_count++;
}

bool remove_course(Course*& list, Enrollment* enrollments, const std::string& code) {
    Enrollment* e = enrollments;
    while (e) {
        if (e->course_code == code) return false;
        e = e->next;
    }

    if (list && list->course_code == code) {  // logicsl and not ampersand 
        Course* temp = list;
        list = list->next;
        delete[] temp->prerequisites;
        delete temp;
        return true;
    }

    Course* c = list;
    while (c && c->next) {
        if (c->next->course_code == code) {
            Course* temp = c->next;
            c->next = temp->next;
            delete[] temp->prerequisites;
            delete temp;
            return true;
        }
        c = c->next;
    }
    return false; //course not removed 
}