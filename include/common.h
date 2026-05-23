/**
 * @file common.h
 * @brief Shared type definitions and status codes for the data structure examples.
 */
#ifndef COMMON_H
#define COMMON_H

/**
 * @brief Success status code.
 */
#define OK 1

/**
 * @brief Failure status code.
 */
#define ERROR 0

/**
 * @brief Memory or resource overflow status code.
 */
#define OVERFLOW -1

/**
 * @brief Function return status type.
 */
typedef int Status;

/**
 * @brief Element type stored in the linear lists.
 */
typedef int ElemType;

/**
 * @brief Boolean type used by the examples.
 */
typedef enum
{
    false,
    true
} bool;

#endif