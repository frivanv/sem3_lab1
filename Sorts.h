#pragma once

#include "LinkedListSequence.h"
#include "ArraySequence.h"

template<class T>
void bubbleSort(Sequence<T> *cur) { //cur - sorted array
    T temp;
    for (int i = 0; i < cur->GetLength(); i++) {
        for (int j = 0; j < cur->GetLength() - 1; j++) {
            if ((cur->Get(j)) > (cur->Get(j + 1))) {
                temp = cur->Get(j);             //
                cur->Set(j, cur->Get(j + 1));   //change elements
                cur->Set(j + 1, temp);          //
            }
        }
    }
}

template<class T>
void mergeSort(Sequence<T> *cur, int lb, int rb) { //cur - sorted array; lb,rb - left and right borders
    if (lb < rb) {
        int split = (lb + rb - 1) / 2;
        mergeSort(cur, lb, split);      //sort of left half
        mergeSort(cur, split + 1, rb);  //sort of right half
        merge(cur, lb, split, rb);
    }
}

template<class T>
void merge(Sequence<T> *cur, int lb, int split, int rb) { //first subarray cur[lb, split], second - cur[split+1, rb]
    int n1 = split - lb + 1;
    int n2 = rb - split;

    //create temp arrays
    Sequence<T> *L = new ArraySequence<T>(n1);
    Sequence<T> *R = new ArraySequence<T>(n2);

    //copy data to temp arrays
    for (int i = 0; i < n1; i++) L->Set(i, cur->Get(lb + i));
    for (int j = 0; j < n2; j++) R->Set(j, cur->Get(split + 1 + j));

    //initial indexes for first, second and merged arrays
    int i = 0, j = 0, k = lb;

    //merge temp arrays back into cur[lb, rb]
    while (i < n1 && j < n2) {
        if (L->Get(i) <= R->Get(j)) {
            cur->Set(k, L->Get(i));
            i++;
        } else {
            cur->Set(k, R->Get(j));
            j++;
        }
        k++;
    }

    //copy remaining elements of L if there are any
    while (i < n1) {
        cur->Set(k, L->Get(i));
        i++;
        k++;
    }

    //copy remaining elements of R if there are any
    while (j < n2) {
        cur->Set(k, R->Get(j));
        j++;
        k++;
    }
}

template<class T>
void quickSort(Sequence<T> *cur, int low, int high) { //cur - sorted array, low and high - start and end indexes
    int i = low, j = high;
    T pivot = cur->Get((i + j) / 2);
    T temp;

    while (i <= j) {
        // find 'wrong' elements
        while (cur->Get(i) < pivot) i++;
        while (cur->Get(j) > pivot) j--;

        if (i <= j) {
            //swap elements
            temp = cur->Get(i);
            cur->Set(i, cur->Get(j));
            cur->Set(j, temp);
            i++;
            j--;
        }
    }

    if (j > low) quickSort(cur, low, j);    //sort left part
    if (i < high) quickSort(cur, i, high);  //sort right part
}