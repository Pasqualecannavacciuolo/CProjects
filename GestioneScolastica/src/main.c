#include <stdio.h>
#include "student.h"
#include "course.h"

int main(void)
{
    Student *s1 = student_create("Pasquale", "Cannavacciuolo", 28);
    if (!s1)
    {
        fprintf(stderr, "student_create failed\n");
        return 1;
    }
    printf("%s %s (%d)\n",
           student_get_name(s1),
           student_get_lastname(s1),
           student_get_age(s1));

    Student *s2 = student_create("Davide", "Cannavacciuolo", 18);
    if (!s2)
    {
        fprintf(stderr, "student_create failed\n");
        return 1;
    }
    printf("%s %s (%d)\n",
           student_get_name(s2),
           student_get_lastname(s2),
           student_get_age(s2));

    Course *c = course_create("IT001", "Sistemi e Reti", 9);
    if (!c)
    {
        fprintf(stderr, "course_create failed\n");
        return 1;
    }

    course_add_student(c, s1);
    course_add_student(c, s2);

    printf("Course ID: %s\nCourse Name: %s\nCourse Credits: %d\nCourse Number of Students: %d\n",
           course_get_id(c),
           course_get_name(c),
           course_get_credits(c),
           course_get_student_count(c));
    course_remove_student(c, s2);
    printf("Course ID: %s\nCourse Name: %s\nCourse Credits: %d\nCourse Number of Students: %d\n",
           course_get_id(c),
           course_get_name(c),
           course_get_credits(c),
           course_get_student_count(c));
    return 0;
}
