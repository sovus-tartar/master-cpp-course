#include "List.hpp"
#include <cassert>

List::~List()
{
    Node* current = head;
    while (current)
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

bool List::empty() const
{
    return head == nullptr;
}

void List::show() const
{
    Node* current = head;
    std::cout << "[";
    while (current)
    {
        std::cout << current->value;
        if (current->next) std::cout << ", ";
        current = current->next;
    }
    std::cout << "]\n";
}

void List::push_front(int val)
{
    Node* node = new Node(val);
    node->next = head;
    head = node;
    if (tail == nullptr) tail = node;
}

void List::push_back(int val)
{
    Node* node = new Node(val);
    if (tail)
    {
        tail->next = node;
        tail = node;
    }
    else
    {
        head = tail = node;
    }
}

void List::pop_front()
{
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (!head) tail = nullptr;
    delete temp;
}

void List::pop_back()
{
    if (!head) return;
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
        return;
    }

    Node* current = head;
    while (current->next != tail)
    {
        current = current->next;
    }
    delete tail;
    tail = current;
    tail->next = nullptr;
}

int List::get() const
{
    if (!head) throw std::runtime_error("List is empty");

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->value;
}
