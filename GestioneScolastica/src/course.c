#include "course.h"

struct Course
{
    char *id;
    char *name;
    int credits;
    Student **students;
    size_t student_count;
    size_t student_capacity;
};

Course *course_create(const char *id, const char *name, int credits)
{
    Course *c = malloc(sizeof(Course));
    if (!c)
    {
        return NULL;
    }
    c->id = dup_string(id);
    c->name = dup_string(name);
    c->credits = credits;
    c->students = NULL;
    c->student_count = 0;
    c->student_capacity = 0;

    if (!c->id || !c->name)
    {
        course_destroy(c);
        return NULL;
    }

    return c;
}

void course_destroy(Course *c)
{
    if (!c)
    {
        return;
    }
    free(c->id);
    free(c->name);
    free(c->students);
    free(c);
}

void course_set_name(Course *c, const char *name)
{
    if (!c || !name)
    {
        return;
    }

    char *tmp = dup_string(c->name);
    if (!tmp)
    {
        return;
    }

    free(c->name);
    c->name = tmp;
}

void course_set_id(Course *c, const char *id)
{
    if (!c || !id)
    {
        return;
    }

    char *tmp = dup_string(id);
    if (!tmp)
    {
        return;
    }

    free(c->id);
    c->id = tmp;
}

void course_set_credits(Course *c, int credits)
{
    if (!c)
    {
        return;
    }

    c->credits = credits;
}

const char *course_get_name(const Course *c)
{
    return c ? c->name : NULL;
}

const char *course_get_id(const Course *c)
{
    return c ? c->id : NULL;
}

int course_get_credits(const Course *c)
{
    return c ? c->credits : -1;
}

int course_get_student_count(const Course *c)
{
    return c ? c->student_count : -1;
}

void course_add_student(Course *c, Student *s)
{
    if (!c || !s)
    {
        return;
    }

    if (c->student_count == c->student_capacity)
    {
        size_t new_capacity = (c->student_capacity == 0) ? 4 : c->student_capacity * 2;

        // We do not have to use sizeof(Student) because we are not allocating Student, but a pointer to Student.
        Student **tmp = realloc(c->students, new_capacity * sizeof(Student *));
        if (!tmp)
        {
            return;
        }

        c->students = tmp;
        c->student_capacity = new_capacity;
    }

    c->students[c->student_count] = s;
    c->student_count++;
}

void course_remove_student(Course *c, Student *s)
{
    if (!c || !s)
        return;

    for (size_t i = 0; i < c->student_count; i++)
    {
        // Student founded
        if (c->students[i] == s)
        {
            // Substitute with last Student
            c->students[i] = c->students[c->student_count - 1];

            c->student_count--;

            c->students[c->student_count] = NULL;

            return;
        }
    }
}

// Student course_get_student(const Course *c, const char *student_id)
// {
//     continue;
// }
