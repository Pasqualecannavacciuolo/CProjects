#ifndef COURSE_H
#define COURSE_H

#include <stdio.h>
#include "utils.h"
#include "student.h"

typedef struct Course Course;

Course *course_create(
    const char *id,
    const char *name,
    int credits);

void course_destroy(Course *c);

void course_set_id(Course *c, const char *id);
void course_set_name(Course *c, const char *name);
void course_set_credits(Course *c, int credits);

const char *course_get_id(const Course *c);
const char *course_get_name(const Course *c);
int course_get_credits(const Course *c);
int course_get_student_count(const Course *c);
// Student course_get_student(const Course *c, const char *student_id);

void course_add_student(Course *c, Student *s);
void course_remove_student(Course *c, Student *s);

#endif
