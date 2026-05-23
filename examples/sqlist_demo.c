#include "sqlist.h"
#include <stdio.h>

int main(void)
{
    SqList list;
    InitList(&list);

    for (int i = 1; i <= 5; ++i)
    {
        if (ListInsert(&list, i - 1, i * 10) != OK)
        {
            fprintf(stderr, "failed to insert %d\n", i * 10);
            return 1;
        }
    }

    printf("Length: %d\n", Length(list));
    printf("Element at 2: %d\n", GetElem(list, 2));
    printf("Locate 40: %d\n", LocateElem(list, 40));
    PrintList(list);

    ElemType removed = 0;
    if (ListDelete(&list, 1, &removed) != OK)
    {
        fprintf(stderr, "failed to delete element at index 1\n");
        return 1;
    }

    printf("Deleted: %d\n", removed);
    PrintList(list);
    return 0;
}
