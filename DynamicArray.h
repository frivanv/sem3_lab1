#pragma once

#include <iostream>
#include <stdexcept>
#include <exception>

using namespace std;

constexpr auto IndexOutOfRange1 = "Index out of range";

template<class T>
class DynamicArray {
private:
    T *item = nullptr;
    int size = 0;
public:
    DynamicArray() {
        this->size = 0;
        this->item = nullptr;
    }

    DynamicArray(T *item, int size) {
        this->item = new T[size];
        this->size = size;
        for (int i = 0; i < this->size; i++) {
            this->item[i] = item[i];
        }
    }

    explicit DynamicArray(int size) {
        this->item = new T[size];
        this->size = size;
    }

    DynamicArray(const DynamicArray<T> &new_arr) {
        this->size = new_arr.size;
        this->item = new T[this->size];
        for (int i = 0; i < new_arr.size; i++) {
            this->item[i] = new_arr.item[i];
        }
    }

    T &operator[](int index) {
        if (index < 0 || index >= this->size) throw out_of_range(IndexOutOfRange1);

        return item[index];
    }

    ~DynamicArray() {
        this->size = 0;
        delete[] this->item;
    }

    T Get(int index) {
        if (index < 0 || index >= this->size) throw length_error(IndexOutOfRange1);
        return item[index];
    }

    int GetSize() {
        return this->size;
    }

    void Set(int index, T value) {
        if (index < 0 || index >= this->size) throw length_error(IndexOutOfRange1);
        item[index] = value;
    }

    void Resize(int new_size) {
        T *temp = new T[new_size];
        if (new_size > this->size) {
            for (int i = 0; i < this->size; i++) {
                temp[i] = this->item[i];
            }
            this->size = new_size;
        } else {
            for (int i = 0; i < new_size; i++) {
                temp[i] = this->item[i];
            }
            this->size = new_size;
        }
        delete[] this->item;
        this->item = temp;
    }

    void Delete(int index) {
        if (index < 0 || index >= this->size) throw length_error(IndexOutOfRange1);
        const int new_size = this->size - 1;
        T *temp = new T[new_size];
        for (int i = 0; i < new_size; i++) {
            if (i < index) {
                temp[i] = this->item[i];
            } else {
                temp[i] = this->item[i + 1];
            }
        }
        this->size--;
        delete[] this->item;
        this->item = temp;
    }

    void Print() {
        for (int i = 0; i < this->size; i++) {
            cout << this->item[i] << "  ";
        }
        cout << endl;
    }

    void EnterMas() {
        cout << "Please, type Array size:";
        int count;
        cin >> count;
        Resize(count);
        for (int i = 0; i < count; i++) {
            int data;
            cout << "Element " << i << " -";
            cin >> data;
            Set(i, data);
        }
    }
};