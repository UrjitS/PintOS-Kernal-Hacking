#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

#include <stdint.h>

#define FIXED_POINT_FACTOR 16384

#define convert_int_to_fixed_point(n) (n * FIXED_POINT_FACTOR)
#define convert_fixed_point_to_int_round_towards_zero(x) (x / FIXED_POINT_FACTOR)
#define convert_fixed_point_to_int_round_to_nearest(x) (x >= 0 ? (x + FIXED_POINT_FACTOR / 2) / FIXED_POINT_FACTOR : (x - FIXED_POINT_FACTOR / 2) / FIXED_POINT_FACTOR)

/* Add two fixed-point numbers */
extern inline int32_t
add_fixed_point_numbers (int32_t fixed_point_number1, int32_t fixed_point_number2)
{
    return fixed_point_number1 + fixed_point_number2;
}

/* Subtract two fixed-point numbers */
extern inline int32_t
subtract_fixed_point_numbers (int32_t fixed_point_number1, int32_t fixed_point_number2)
{
    return fixed_point_number1 - fixed_point_number2;
}

/* Add integer n to fixed-point number x */
extern inline int32_t
add_int_to_fixed_point_number (int32_t fixed_point_number, int n)
{
    return fixed_point_number + convert_int_to_fixed_point(n);
}

/* Subtract integer n from fixed-point number x */
extern inline int32_t
subtract_int_from_fixed_point_number (int32_t fixed_point_number, int n)
{
    return fixed_point_number - convert_int_to_fixed_point(n);
}

/* Multiply two fixed-point numbers */
extern inline int32_t
multiply_fixed_point_numbers (int32_t fixed_point_number1, int32_t fixed_point_number2)
{
    return (int32_t) (((int64_t)fixed_point_number1) * fixed_point_number2 / FIXED_POINT_FACTOR);
}

/* Divide two fixed-point numbers */
extern inline int32_t
divide_fixed_point_numbers (int32_t fixed_point_number1, int32_t fixed_point_number2)
{
    return (int32_t) (((int64_t)fixed_point_number1) * FIXED_POINT_FACTOR / fixed_point_number2);
}

/* Multiply fixed-point number x by integer n */
extern inline int32_t
multiply_fixed_point_number_by_int (int32_t fixed_point_number, int n)
{
    return fixed_point_number * n;
}

/* Divide fixed-point number x by integer n */
extern inline int32_t
divide_fixed_point_number_by_int (int32_t fixed_point_number, int n)
{
    return fixed_point_number / n;
}

#endif