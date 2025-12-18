#include "student.h"

struct Student
{
    char *name;
    char *lastname;
    int age;
};

Student *student_create(const char *name, const char *lastname, int age)
{
    Student *s = malloc(sizeof(Student));
    if (!s)
    {
        return NULL;
    }

    s->name = dup_string(name);
    s->lastname = dup_string(lastname);
    s->age = age;

    if (!s->name || !s->lastname)
    {
        student_destroy(s);
        return NULL;
    }

    return s;
}

void student_destroy(Student *s)
{
    if (!s)
        return;
    free(s->name);
    free(s->lastname);
    free(s);
}

void student_set_name(Student *s, const char *name)
{
    if (!s || !name)
    {
        return;
    }

    char *tmp = dup_string(name);
    if (!tmp)
    {
        return;
    }

    // Mi libero della vecchia stringa
    free(s->name);
    // Inserisco il nuovo valore
    s->name = tmp;
}

void student_set_lastname(Student *s, const char *lastname)
{
    if (!s || !lastname)
    {
        return;
    }

    char *tmp = dup_string(lastname);
    if (!tmp)
    {
        return;
    }

    free(s->lastname);
    s->lastname = tmp;
}

void student_set_age(Student *s, int age)
{
    if (!s)
    {
        return;
    }
    s->age = age;
}

const char *student_get_name(const Student *s)
{
    return s ? s->name : NULL;
}

const char *student_get_lastname(const Student *s)
{
    return s ? s->lastname : NULL;
}

int student_get_age(const Student *s)
{
    return s ? s->age : -1;
}
