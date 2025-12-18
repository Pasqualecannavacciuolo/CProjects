#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "utils.h"

/*
 * Ownership rules:
 * - student_create: restituisce ownership completa allo user
 * - student_destroy: rilascia tutta la memoria
 * - getters: NON trasferiscono ownership
 * - setters: copiano internamente le stringhe
 */

/* Tipo opaco (incapsulamento) */
typedef struct Student Student;

/**
 * @brief Constructor
 *
 * @param name
 * @param lastname
 * @param age
 * @return Student*
 */
Student *student_create(
    const char *name,
    const char *lastname,
    int age);

/**
 * @brief Destructor
 *
 * @param s Pointer to the Student to destroy
 */
void student_destroy(Student *s);

/**
 * @brief Updates the student's name.
 *
 * This function replaces the name of the given Student object
 * with a copy of the provided string.
 *
 * @param s Pointer to a Student object to be modified. Must not be NULL.
 * @param name Pointer to a null-terminated string containing the
 *        new last name. The string is not modified by this function
 *        and ownership remains with the caller.
 *
 * @note If @p s or @p name is NULL, the function does nothing.
 *       The previous last name is freed and replaced by a copy of the new one.
 *       The caller must not free the returned string.
 */
void student_set_name(Student *s, const char *name);

/**
 * @brief Updates the student's last name.
 *
 * This function replaces the last name of the given Student object
 * with a copy of the provided string.
 *
 * @param s Pointer to a Student object to be modified. Must not be NULL.
 * @param lastname Pointer to a null-terminated string containing the
 *        new last name. The string is not modified by this function
 *        and ownership remains with the caller.
 *
 * @note If @p s or @p lastname is NULL, the function does nothing.
 *       The previous last name is freed and replaced by a copy of the new one.
 *       The caller must not free the returned string.
 */
void student_set_lastname(Student *s, const char *lastname);

/**
 * @brief Set Age
 *
 * @param s Pointer to the Student not declared as const because you can modify the Student
 * @param age
 */
void student_set_age(Student *s, int age);

/**
 * @brief Returns the student's name.
 *
 * This function provides read-only access to the name associated
 * with the given Student object.
 *
 * @param s Pointer to a Student object. The object is treated as
 *          read-only and will not be modified by this function.
 *
 * @return Pointer to a null-terminated string containing the student's
 *         name, or NULL if @p s is NULL.
 *
 * @note The returned pointer is owned by the Student object and must
 *       not be modified or freed by the caller.
 */
const char *student_get_name(const Student *s);

/**
 * @brief Returns the student's lastname.
 *
 * This function provides read-only access to the lastname associated
 * with the given Student object.
 *
 * @param s Pointer to a Student object. The object is treated as
 *          read-only and will not be modified by this function.
 *
 * @return Pointer to a null-terminated string containing the student's
 *         lastname, or NULL if @p s is NULL.
 *
 * @note The returned pointer is owned by the Student object and must
 *       not be modified or freed by the caller.
 */
const char *student_get_lastname(const Student *s);

/**
 * @brief Returns the student's age.
 *
 * This function provides read-only access to the age associated
 * with the given Student object.
 *
 * @param s Pointer to a Student object. The object is treated as
 *          read-only and will not be modified by this function.
 *
 * @return The student's age, or -1 if @p s is NULL.
 *
 * @note The returned integer is owned by the Student object and must
 *       not be modified by the caller.
 */
int student_get_age(const Student *s);

#endif
