# Assignment_5

So to make this system, what I did was make separate supporting files (SFs) for different parts of the program:

- student_sf.cpp: This file has all the functions related to students, like adding a student, finding a student by ID, updating their major, removing a student, and updating their GPA.

- course_sf.cpp: This file handles courses, including adding courses, finding a course by code, adding prerequisites, and removing courses safely.

- enrollment_sf.cpp: This file manages enrollments, like enrolling a student in a course, dropping a course, assigning grades, and checking prerequisites and credit limits.

- gpa_sf.cpp: This file contains the logic to calculate a student’s GPA based on their completed courses and grades.

- structures.h: This header file contains all the struct definitions for Student, Course, and Enrollment, as well as the declarations of all the functions from the supporting files. It also has the operator<< to print a student’s information.

The way the program works is:

1.It first creates the linked lists for students, courses, and enrollments, starting them empty (nullptr).

2.Then it adds students and courses using the add functions, which create new nodes and attach them to the lists.

3.After that, students can enroll in courses, but the program first checks if the student exists, the course exists, the student hasn’t already enrolled, the prerequisites are met, the credit limit isn’t exceeded, and the course has available capacity.

4.When a student is enrolled, a new enrollment node is created and added to the enrollments list, and the course’s enrolled count is increased.

5.Grades are assigned to the student’s enrollment using the assign_grade function.

6.The program then calculates the GPA by looking at all of the student’s completed courses, converting letter grades to points, multiplying by course credits, summing them, and dividing by total credits.

6.Finally, the program can print student information, showing ID, name, major, total credits, and GPA.
