#ifndef STRUCTURES_H
#define STRUCTURES_H // so that the compiler doesnt compile all this more than once.

#include <string>
#include <iostream>

struct Student {
    int student_id;
    std::string name;
    std::string major;
    int total_credits;
    double gpa;
    Student* next;
};

struct Course {
    std::string course_code;
    std::string course_name;
    int credits;
    int capacity;
    int enrolled_count;
    std::string* prerequisites;
    int prereq_count;
    Course* next;
};

struct Enrollment {
    int student_id;
    std::string course_code;
    char grade;
    std::string semester;
    Enrollment* next;
};

std::ostream& operator<<(std::ostream& out, const Student& s);


void update_gpa(Student* students, Enrollment* enrollments, int student_id); // rogue function 


// Student functions
void add_student(Student*& list, int id, const std::string& name, const std::string& major);
Student* find_student(Student* list, int id);
bool update_major(Student* list, int id, const std::string& new_major);
void remove_student(Student*& students, Enrollment*& enrollments, int id);

// Course functions
void add_course(Course*& list, const std::string& code, const std::string& name, int credits, int capacity);
Course* find_course(Course* list, const std::string& code);
void add_prerequisite(Course* course, const std::string& prereq);
bool remove_course(Course*& list, Enrollment* enrollments, const std::string& code);

// Enrollment functions
bool already_enrolled(Enrollment* list, int id, const std::string& code);
bool check_prerequisites(Enrollment* enrollments, Course* course, int id);
bool check_credit_limit(Enrollment* enrollments, Course* courses, int id, const std::string& sem, int newc);
bool enroll_student(Student* students, Course* courses, Enrollment*& enrollments, int id, const std::string& code, const std::string& sem);
bool drop_course(Enrollment*& list, Course* courses, int id, const std::string& code);
bool assign_grade(Enrollment* list, int id, const std::string& code, char g);

// added declerations so that all the other files can see these functions and know where to find them.


#endif //end of conditional block 

