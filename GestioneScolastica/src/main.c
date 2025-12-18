#include <stdio.h>
#include "student.h"

int main(void)
{
    Student *s = student_create("Pasquale", "Cannavacciuolo", 28);
    if (!s)
    {
        fprintf(stderr, "student_create failed\n");
        return 1;
    }

    student_set_name(s, "Xasquale");

    printf("%s %s (%d)\n",
           student_get_name(s),
           student_get_lastname(s),
           student_get_age(s));

    return 0;
}
