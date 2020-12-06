#pragma once

#include <iostream>
#include <stdexcept>
#include <exception>

using namespace std;

constexpr const auto IndexOutOfRange = "Index out of range";

template<class T>
class LinkedList {

private:
    struct Node {
        T item;
        Node *next;
    };

    Node *head = nullptr;
    int size = 0;

public:
    LinkedList() : size(0), head(nullptr) {};

    LinkedList(const T *item, const int size) : LinkedList() {
        if (size < 0) throw length_error("Index is negative");
        if (size == 0) throw length_error("Node is empty");

        Node *tail = new Node{*item, nullptr};
        head = tail;

        for (size_t i = 1; i < size; i++) {
            Node *body = new Node{*(item + i), nullptr};
            tail->next = body;
            tail = body;
        }

        this->size = size;
    }

    LinkedList(LinkedList<T> const &list) {
        Node *body{head};
        Node *List{body};

        for (size_t i = 1; i < size; i++, body = body->next) {
            List = new Node{body->item, List};
        }

        this->size = size;
    }

    ~LinkedList() {
        while (this->head != nullptr) {
            Node *body{head->next};
            delete[] head;
            this->head = body;
        }

        delete[] this->head;
    }

    T GetFirst() {
        if (size == 0) throw length_error(IndexOutOfRange);

        return head->item;
    }

    T GetLast() {
        if (size == 0) throw length_error(IndexOutOfRange);
        Node *body{head};

        for (size_t i = 0; i < size - 1; i++) body = body->next;

        return body->item;
    }

    T Get(int index) {
        if (index < 0 || index >= size) throw length_error(IndexOutOfRange);
        Node *body{head};

        for (size_t i = 0; i < index; i++) body = body->next;
        return body->item;
    }

    T &operator[](int index) {
        if (index < 0 || index >= size) throw length_error(IndexOutOfRange);
        Node *body{head};

        for (size_t i = 0; i < index; i++) body = body->next;

        return body->item;
    }

    LinkedList<T> *GetSubList(int startIndex, int endIndex) {
        if (startIndex < 0 || endIndex < 0 || startIndex >= size || endIndex >= size || startIndex > endIndex)
            throw length_error(IndexOutOfRange);
        Node *body{head};

        for (size_t i = 0; i < startIndex; i++) body = body->next;

        auto *newNode = new LinkedList<T>;

        for (auto i = static_cast<size_t>(startIndex); i < endIndex + 1; i++) {
            newNode->Prepend(body->item);
            body = body->next;
        }

        newNode->size = endIndex - startIndex + 1;

        return newNode;
    }

    int GetLength() {
        return size;
    }

    void Delete(int index) {
        if (this->size <= 0) throw out_of_range(IndexOutOfRange);

        if (index == 0) {
            Node *tmp;
            tmp = this->head;
            this->head = this->head->next;
            delete tmp;
        } else if (index == this->size - 1) {
            Node *tmp;
            tmp = this->head;
            for (int i = 0; i < this->size - 1; i++) {
                tmp = tmp->next;
            }
            delete tmp;
        } else {
            Node *tmp;
            tmp = this->head;
            for (int i = 0; i < index - 1; i++) {
                tmp = tmp->next;
            }
            Node *cur;
            cur = tmp;
            tmp = tmp->next;
            cur->next = tmp->next;
            delete tmp;
        }
        this->size--;
    }

    void Append(T data) {
        head = new Node{data, head};

        ++size;
    }

    void Prepend(T data) {
        if (head == nullptr) head = new Node{data, head};
        else {
            Node *body{head};
            for (size_t i = 1; i < size; i++) body = body->next;
            body->next = new Node{data, nullptr};
        }

        ++size;
    }

    void InsertAt(T data, int index) {
        if (index < 0 || index >= size) throw length_error(IndexOutOfRange);
        Node *body{head};

        for (size_t i = 0; i < index - 1; i++) body = body->next;

        Node *newNode = new Node{data, body->next};
        body->next = newNode;

        this->size += 1;
    }

    void Print() {
        for (int i = 0; i < size; i++) {
            cout << Get(i) << " ";
        }
        cout << endl;
    }

    void EnterList() {
        cout << "Please, type List size: ";
        int count;
        cin >> count;

        for (int i = 0; i < count; i++) {
            T data;
            cout << "Element " << i << " - ";
            cin >> data;
            Prepend(data);
        }

    }
};