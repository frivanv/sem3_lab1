#pragma once

#include "LinkedListSequence.h"
#include "ArraySequence.h"
#include "Sorts.h"

void Test_Linked_List_Sequence() {
    cout << "Tests for LinkedListSequence" << endl;

    int *a{new int[6]{1, 4, 5, 7, 4, 17}};
    LinkedListSequence<int> list1{a, 6};

    int *b{new int[5]{5, 11, 8, 9, 2}};
    LinkedListSequence<int> list2{b, 5};

    if (list1.GetFirst() == 1) cout << "GetFirst succeed" << endl;
    else cout << "GetFirst failed" << endl;

    if (list1.GetLast() == 17) cout << "GetLast succeed" << endl;
    else cout << "GetLast failed" << endl;

    if (list1[2] == 5 && list1[5] == 17) cout << "Operator [] succeed" << endl;
    else cout << "Operator [] failed" << endl;

    if (list1.GetLength() == 6) cout << "GetLength succeed" << endl;
    else cout << "GetLength failed" << endl;

    if (list1.Get(3) == 7) cout << "Get succeed" << endl;
    else cout << "Get failed" << endl;

    list1.Append(5);
    if (list1.Get(0) == 5) cout << "Append succeed" << endl;
    else cout << "Append failed" << endl;

    list2.Prepend(9);
    if (list2.Get(5) == 9) cout << "Prepend succeed" << endl;
    else cout << "Prepend failed" << endl;

    list2.InsertAt(3, 2);
    if (list2.Get(2) == 3) cout << "InsertAt succeed" << endl;
    else cout << "InsertAt failed" << endl;

    delete[] a;
    delete[] b;

    cout << endl;

}

void Test_Array_Sequence() {
    cout << "Tests for ArraySequence" << endl;

    int *pr{new int[5]{11, 12, 13, 14, 15}};
    ArraySequence<int> arr1(pr, 5);

    if (arr1[1] == 12 && arr1[4] == 15) cout << "Operator [] succeed" << endl;
    else cout << "Operator [] failed" << endl;

    cout << arr1.GetFirst();

    if (arr1.GetFirst() == 11) cout << "GetFirst succeed" << endl;
    else cout << "GetFirst failed" << endl;

    cout << arr1.GetLast();

    if (arr1.GetLast() == 15) cout << "GetLast succeed" << endl;
    else cout << "GetLast failed" << endl;

    if (arr1.GetLength() == 5) cout << "GetLength succeed" << endl;
    else cout << "GetLength failed" << endl;

    if (arr1.Get(3) == 14) cout << "Get succeed" << endl;
    else cout << "Get failed" << endl;

    arr1.Append(76);
    if (arr1.GetFirst() == 76) cout << "Append succeed" << endl;
    else cout << "Append failed" << endl;

    arr1.Prepend(8);
    if (arr1.GetLast() == 8) cout << "Prepend succeed" << endl;
    else cout << "Prepend failed" << endl;

    int data = 44;

    arr1.InsertAt(data, 4);
    if (arr1[4] == 44) cout << "InsertAt succeed" << endl;
    else cout << "InsertAt failed" << endl;

    delete[] pr;

    cout << endl;
}

void Test_Bubble_Sort() {
    Sequence<int> *mas1;
    mas1 = new ArraySequence<int>(5);
    mas1->Set(0, 16);
    mas1->Set(1, 5);
    mas1->Set(2, 29);
    mas1->Set(3, 14);
    mas1->Set(4, 19);

    bubbleSort(mas1);

    if ((mas1->Get(0) == 5) && (mas1->Get(1) == 14) && (mas1->Get(2) == 16)
        && (mas1->Get(3) == 19) && (mas1->Get(4) == 29))
        cout << "Bubble sort succeed" << endl;
    else cout << "Bubble sort failed" << endl;

    cout << endl;
}

void Test_Merge_Sort() {
    Sequence<int> *mas3;
    mas3 = new ArraySequence<int>(5);
    mas3->Set(0, 16);
    mas3->Set(1, 5);
    mas3->Set(2, 29);
    mas3->Set(3, 14);
    mas3->Set(4, 19);

    mergeSort(mas3, 0, 4);

    if ((mas3->Get(0) == 5) && (mas3->Get(1) == 14) && (mas3->Get(2) == 16)
        && (mas3->Get(3) == 19) && (mas3->Get(4) == 29))
        cout << "Merge sort succeed" << endl;
    else cout << "Merge sort failed" << endl;

    cout << endl;
}

void Test_Quick_Sort() {
    Sequence<int> *mas2;
    mas2 = new ArraySequence<int>(5);
    mas2->Set(0, 16);
    mas2->Set(1, 5);
    mas2->Set(2, 29);
    mas2->Set(3, 14);
    mas2->Set(4, 19);

    quickSort(mas2, 0, 4);

    if ((mas2->Get(0) == 5) && (mas2->Get(1) == 14) && (mas2->Get(2) == 16)
        && (mas2->Get(3) == 19) && (mas2->Get(4) == 29))
        cout << "Quick sort succeed" << endl;
    else cout << "Quick sort failed" << endl;

    cout << endl;
}