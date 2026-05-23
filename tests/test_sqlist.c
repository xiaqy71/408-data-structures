#include "sqlist.h"
#include <assert.h>
#include <stdio.h>

static void test_init_and_insert(void)
{
    SqList list;
    InitList(&list);

    assert(Empty(list) == true);
    assert(Length(list) == 0);

    assert(ListInsert(&list, 0, 10) == OK);
    assert(ListInsert(&list, 1, 20) == OK);
    assert(ListInsert(&list, 2, 30) == OK);

    assert(Length(list) == 3);
    assert(GetElem(list, 0) == 10);
    assert(GetElem(list, 1) == 20);
    assert(GetElem(list, 2) == 30);
    assert(LocateElem(list, 20) == 1);
    assert(LocateElem(list, 99) == -1);
}

static void test_delete_and_destroy(void)
{
    SqList list;
    ElemType removed = 0;

    InitList(&list);
    assert(ListInsert(&list, 0, 1) == OK);
    assert(ListInsert(&list, 1, 2) == OK);
    assert(ListInsert(&list, 2, 3) == OK);

    assert(ListDelete(&list, 1, &removed) == OK);
    assert(removed == 2);
    assert(Length(list) == 2);
    assert(GetElem(list, 0) == 1);
    assert(GetElem(list, 1) == 3);

    assert(DestroyList(&list) == OK);
    assert(Length(list) == 0);
    assert(Empty(list) == true);
}

int main(void)
{
    test_init_and_insert();
    test_delete_and_destroy();

    puts("sqlist tests passed");
    return 0;
}
