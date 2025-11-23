#pragma once
#include <iostream>

class List
{
private:
    struct Node
    {
        int value;
        Node* next;
        Node(int val) : value(val), next(nullptr) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;

public:
    ~List();

    bool empty() const;
    void show() const;

    void push_front(int val);
    void push_back(int val);

    void pop_front();
    void pop_back();

    int get() const; // возвращает значение "среднего" узла
};
