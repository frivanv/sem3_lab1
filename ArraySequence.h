#pragma once

#include "DynamicArray.h"
#include "Sequence.h"

template<class T>
class ArraySequence : public Sequence<T> {
protected:
    DynamicArray<T> *arr = 0;
    int size = 0;
public:
    ArraySequence() : Sequence<T>() {
        arr = new DynamicArray<T>(0);
        this->size = 0;
    }

    explicit ArraySequence(int size) : Sequence<T>() {
        arr = new DynamicArray<T>(size);
        this->size = size;
    }

    ArraySequence(T *item, int size) : Sequence<T>() {
        arr = new DynamicArray<T>(item, size);
        this->size = size;
    }

    virtual T &operator[](int index) const {
        return arr->operator[](index);
    }

    virtual ~ArraySequence() = default;

    T GetFirst() const override {
        if (this->size == 0) throw out_of_range(IndexOutOfRange);
        return arr->Get(0);
    }

    T Get(int index) const override {
        if (index < 0 || index >= size) throw out_of_range(IndexOutOfRange);
        return arr->Get(index);
    }

    int GetLength() const override {
        return this->size;
    }

    T GetLast() const override {
        return arr->Get(this->size - 1);
    }

    void Delete(int index) override {
        this->arr->Delete(index);
    }

    void Set(int index, T item) override {
        this->arr->Set(index, item);
    }

    void Prepend(T item) override {
        arr->Resize(size + 1);
        size = size + 1;
        arr->Set(size - 1, item);
    }

    void Append(T item) override {
        arr->Resize(size + 1);
        T data1 = arr->Get(0);
        T data2 = 0;
        for (int i = 0; i < this->size; i++) {
            data2 = data1;
            data1 = arr->Get(i + 1);
            arr->Set(i + 1, data2);
        }
        arr->Set(0, item);
    }

    void InsertAt(T item, int index) override {
        if (index < 0 || index >= size) throw out_of_range(IndexOutOfRange);
        arr->Set(index, item);
    }

    Sequence<T> *GetSubSequence(int startIndex, int endIndex) const override {
        if (startIndex < 0 || startIndex >= size || endIndex < 0 || endIndex >= size)
            throw out_of_range(IndexOutOfRange);
        Sequence<T> *GetSubSequence = new ArraySequence();
        for (int i = 0; i < (endIndex - startIndex + 1); i++)
            GetSubSequence->Prepend(arr->Get(startIndex + i));
        return GetSubSequence;
    }

    ArraySequence<T> *Concat(Sequence<T> *arr2) const override {
        auto *new_arr = new ArraySequence();
        for (int i = 0; i < this->size; i++)
            new_arr->Prepend(arr->Get(i));
        for (int i = 0; i < arr2->GetLength(); i++)
            new_arr->Prepend(arr2->Get(i));
        return new_arr;
    }

    void Print() override {
        arr->Print();
    }

    void Enter() override {
        cout << "Please, type Array size:";
        int count;
        cin >> count;

        for (int i = 0; i < count; i++) {
            T data;
            cout << "Element " << i << " -";
            cin >> data;
            Prepend(data);
        }

    }

};