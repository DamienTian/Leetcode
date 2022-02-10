#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

// Author: Huahua
// Running time: 24 ms
class MyLinkedList
{
public:
    MyLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

    ~MyLinkedList()
    {
        Node *node = head_;
        while (node)
        {
            Node *cur = node;
            node = node->next;
            delete cur;
        }
        head_ = nullptr;
        tail_ = nullptr;
    }

    int get(int index)
    {
        if (index < 0 || index >= size_)
            return -1;
        auto node = head_;
        while (index--)
            node = node->next;
        return node->val;
    }

    void addAtHead(int val)
    {
        head_ = new Node(val, head_);
        if (size_++ == 0)
            tail_ = head_;
    }

    void addAtTail(int val)
    {
        auto node = new Node(val);
        if (size_++ == 0)
        {
            head_ = tail_ = node;
        }
        else
        {
            tail_->next = node;
            tail_ = tail_->next;
        }
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size_)
            return;
        if (index == 0)
            return addAtHead(val);
        if (index == size_)
            return addAtTail(val);
        Node dummy(0, head_);
        Node *prev = &dummy;
        while (index--)
            prev = prev->next;
        prev->next = new Node(val, prev->next);
        ++size_;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size_)
            return;
        Node dummy(0, head_);
        Node *prev = &dummy;
        for (int i = 0; i < index; ++i)
            prev = prev->next;
        Node *node_to_delete = prev->next;
        prev->next = prev->next->next;
        if (index == 0)
            head_ = prev->next;
        if (index == size_ - 1)
            tail_ = prev;
        delete node_to_delete;
        --size_;
    }

private:
    struct Node
    {
        int val;
        Node *next;
        Node(int _val) : Node(_val, nullptr) {}
        Node(int _val, Node *_next) : val(_val), next(_next) {}
    };
    Node *head_;
    Node *tail_;
    int size_;
};

// struct Node
// {
//     Node() {}
//     Node(int v) : val(v) {}
//     Node(int v, Node *n, Node *p) : val(v), next(n), prev(p) {}
//     // ~Node()
//     // {
//     //     delete next;
//     //     delete prev;
//     // }

//     int val = -1;
//     Node *next = nullptr;
//     Node *prev = nullptr;
// };

// class MyLinkedList
// {
// public:
//     MyLinkedList() : head(nullptr), tail(nullptr) {}

//     ~MyLinkedList()
//     {
//         current = head;
//         while (current)
//         {
//             delete current;
//             current = head->next;
//         }
//     }

//     int get(int index)
//     {
//         Node *t = head;
//         while (t && index >= 0)
//         {
//             t = t->next;
//             --index;
//         }

//         return !t ? -1 : t->val;
//     }

//     void addAtHead(int val)
//     {
//         if (head == nullptr)
//         {
//             head->val = val;
//             tail = new Node();
//             head->next = tail;
//             return;
//         }
//         current = new Node(val, head, nullptr);
//         head = current;
//     }

//     void addAtTail(int val)
//     {
//         if (head == nullptr)
//         {
//             addAtHead(val);
//         }
//         current = new Node(val, nullptr, tail);
//         tail = current;
//     }

//     void addAtIndex(int index, int val)
//     {
//         Node *t = head;
//         while (t && index >= 0)
//         {
//             t = t->next;
//             --index;
//         }
//         if (!t)
//         { // add to tail
//             addAtTail(val);
//         }
//         else if (index == 0)
//         {
//             current = new Node(val, t, t->prev);
//         }
//     }

//     void deleteAtIndex(int index)
//     {
//         Node *t = head;
//         while (t && index >= 0)
//         {
//             t = t->next;
//             --index;
//         }
//         if (!t)
//             return;
//         else if(index == 0){
//             t->prev = t->next;
//             current = t;
//             delete current;
//         }
//     }

// public:
//     Node *head, *tail, *current;
// };

#endif
