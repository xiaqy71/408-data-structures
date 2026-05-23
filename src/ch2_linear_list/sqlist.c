#include "common.h"
#include <stdio.h>
#define MaxSize 50

/// @brief
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;

// Initliaze a SqList
void InitList(SqList *L)
{
    for (int i = 0; i < MaxSize; ++i)
    {
        L->data[i] = 0;
    }
    L->length = 0;
}

/// @brief Get the current length of the linear list
/// @param L Lineart List
/// @return Current length of the list
int Length(SqList L)
{
    return L.length;
}

/**
 * @brief Locate an element in the linear list.
 *
 * @param L Linear list.
 * @param e Target element.
 * @return Index of the target element if found; otherwise, -1.
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

ElemType GetElem(SqList L, int i)
{
    if (i >= 0 && i < L.length)
        return L.data[i];

    return 0;
}

Status ListInsert(SqList *L, int i, ElemType e)
{
    // check if full or i over the Length
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

void PrintList(SqList L)
{
    for (int i = 0; i < L.length; ++i)
    {
        printf("%d ", L.data[i]);
    }

    printf("\n");
}

bool Empty(SqList L)
{
    return L.length == 0;
}

Status DestroyList(SqList *L)
{
    if (L == NULL)
    {
        return ERROR;
    }

    L->length = 0;
    return OK;
}

int main(int argc, char const *argv[])
{
    /* code */
    SqList l1;
    InitList(&l1);

    for (int i = 0; i < 10; ++i)
    {
        ListInsert(&l1, 0, i + 1);
    }

    PrintList(l1);
    return 0;
}
