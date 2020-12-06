#pragma once

#include "LinkedList.h"
#include "Sequence.h"

template<class T>
class LinkedListSequence : public Sequence<T> {
protected:
    LinkedList<T> *linked_list;

public:

    LinkedListSequence() : Sequence<T>() {
        linked_list = new LinkedList<T>();
    }

    LinkedListSequence(T *item, int size) : Sequence<T>() {
        linked_list = new LinkedList<T>(item, size);
    }

    virtual ~LinkedListSequence() = default;

    T GetFirst() const override {
        if (linked_list->GetLength() == 0) throw out_of_range(IndexOutOfRange);

        return linked_list->GetFirst();
    }

    T GetLast() const override {
        if (linked_list->GetLength() == 0) throw out_of_range(IndexOutOfRange);

        return linked_list->GetLast();
    }

    virtual int GetLength() const {
        return linked_list->GetLength();
    }

    T Get(int index) const override {
        if (index < 0 || index >= linked_list->GetLength()) throw out_of_range(IndexOutOfRange);

        return linked_list->Get(index);
    }

    virtual T &operator[](int index) const {
        return linked_list->operator[](index);
    }

    Sequence<T> *GetSubSequence(int startIndex, int endIndex) const override {
        if (startIndex < 0 || endIndex < 0 || startIndex >= linked_list->GetLength() ||
            endIndex >= linked_list->GetLength())
            throw out_of_range(IndexOutOfRange);

        LinkedList<T> *subList = linked_list->GetSubList(startIndex, endIndex);
        Sequence<T> *subSequence = new LinkedListSequence<T>();

        for (int i = 0; i < subList->GetLength(); i++)
            subSequence->Prepend(subList->Get(i));

        return subSequence;
    }

    LinkedListSequence<T> *Concat(Sequence<T> *linked_list2) const override {
        auto *ConcatSequence = new LinkedListSequence<T>();

        for (int i = 0; i < linked_list->GetLength(); i++)
            ConcatSequence->Prepend(linked_list->Get(i));

        for (int i = 0; i < linked_list2->GetLength(); i++)
            ConcatSequence->Prepend(linked_list2->Get(i));

        return ConcatSequence;
    }

    void Delete(int index) override {
        this->linked_list->Delete(index);
    }

    void Set(int index, T item) override {
        this->linked_list->Delete(index);
        this->linked_list->InsertAt(item, index);
    }

    void Append(T item) override {
        return linked_list->Append(item);
    }

    void Prepend(T item) override {
        return linked_list->Prepend(item);
    }

    virtual void InsertAt(T item, int index) {
        if (index < 0 || index >= linked_list->GetLength()) throw out_of_range(IndexOutOfRange);

        return linked_list->InsertAt(item, index);
    }

    void Print() override {
        return linked_list->Print();
    }

    void Enter() override {
        return linked_list->EnterList();
    }

};
