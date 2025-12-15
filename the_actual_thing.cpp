#include "structures.h"

int main() {
    Student* students = nullptr;
    Course* courses = nullptr;
    Enrollment* enrollments = nullptr; // best practice to initialize pointers to nullptr

    add_student(students, 1, "Aleena", "CS");
    add_course(courses, "CS101", "Intro", 3, 30); // bad decison 

    enroll_student(students, courses, enrollments, 1, "CS101", "Fall 2025"); //
    assign_grade(enrollments, 1, "CS101", 'A');
    update_gpa(students, enrollments, 1); 

    std::cout << *students << std::endl;
    return 0;
}