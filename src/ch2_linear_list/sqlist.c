/**
 * @file sqlist.c
 * @brief Sequential list implementation.
 */
#include "sqlist.h"
#include <stdio.h>

/**
 * @brief Initialize a sequential list.
 *
 * @param L Pointer to the sequential list to initialize.
 */
void InitList(SqList *L)
{
    for (int i = 0; i < MaxSize; ++i)
    {
        L->data[i] = 0;
    }
    L->length = 0;
}

/**
 * @brief Get the current length of a sequential list.
 *
 * @param L Sequential list.
 * @return Current number of valid elements.
 */
int Length(SqList L)
{
    return L.length;
}

/**
 * @brief Locate an element in a sequential list.
 *
 * @param L Sequential list.
 * @param e Target element.
 * @return Zero-based index of the first matching element, or -1 if not found.
 */
int LocateElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; ++i)
    {
        if (L.data[i] == e)
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Retrieve an element by index.
 *
 * @param L Sequential list.
 * @param i Zero-based index of the element to retrieve.
 * @return The stored element, or 0 if the index is out of range.
 */
ElemType GetElem(SqList L, int i)
{
    if (i >= 0 && i < L.length)
        return L.data[i];

    return 0;
}

/**
 * @brief Insert an element into a sequential list.
 *
 * @param L Pointer to the sequential list.
 * @param i Insertion position in the range [0, length].
 * @param e Element to insert.
 * @return @ref OK on success, @ref ERROR when the list is full or the position
 *         is invalid.
 */
Status ListInsert(SqList *L, int i, ElemType e)
{
    if (L->length == MaxSize || i < 0 || i > L->length)
    {
        return ERROR;
    }

    for (int j = L->length; j > i; --j)
    {
        L->data[j] = L->data[j - 1];
    }
    L->data[i] = e;

    ++L->length;
    return OK;
}

/**
 * @brief Delete an element from a sequential list.
 *
 * @param L Pointer to the sequential list.
 * @param i Zero-based index of the element to delete.
 * @param e Output parameter that receives the deleted element.
 * @return @ref OK on success, @ref ERROR when the index is invalid.
 */
Status ListDelete(SqList *L, int i, ElemType *e)
{
    if (i < 0 || i > L->length - 1)
    {
        return ERROR;
    }

    *e = L->data[i];

    for (int j = i; j < L->length - 1; ++j)
    {
        L->data[j] = L->data[j + 1];
    }
    --L->length;
    return OK;
}

/**
 * @brief Print all elements in a sequential list.
 *
 * @param L Sequential list to print.
 */
void PrintList(SqList L)
{
    for (int i = 0; i < L.length; ++i)
    {
        printf("%d ", L.data[i]);
    }

    printf("\n");
}

/**
 * @brief Check whether a sequential list is empty.
 *
 * @param L Sequential list.
 * @return true when the list contains no elements, otherwise false.
 */
bool Empty(SqList L)
{
    return L.length == 0;
}

/**
 * @brief Reset a sequential list to the empty state.
 *
 * @param L Pointer to the sequential list.
 * @return @ref OK when the list is reset successfully, @ref ERROR when the
 *         pointer is NULL.
 */
Status DestroyList(SqList *L)
{
    if (L == NULL)
    {
        return ERROR;
    }

    L->length = 0;
    return OK;
}
