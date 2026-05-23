/**
 * @file sqlist.h
 * @brief Public interface for the sequential list implementation.
 */
#ifndef SQLIST_H
#define SQLIST_H

#include "common.h"

/**
 * @brief Maximum capacity of a sequential list.
 */
#define MaxSize 50

/**
 * @brief Sequential storage representation of a linear list.
 */
typedef struct
{
    ElemType data[MaxSize]; /**< Storage for the list elements. */
    int length;             /**< Current number of valid elements. */
} SqList;

void InitList(SqList *L);
int Length(SqList L);
int LocateElem(SqList L, ElemType e);
ElemType GetElem(SqList L, int i);
Status ListInsert(SqList *L, int i, ElemType e);
Status ListDelete(SqList *L, int i, ElemType *e);
void PrintList(SqList L);
bool Empty(SqList L);
Status DestroyList(SqList *L);

#endif
