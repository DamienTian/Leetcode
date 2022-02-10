/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start

struct Node
{
    Node() {}
    Node(int v) : val(v) {}
    Node(int v, Node *n, Node *p) : val(v), next(n), prev(p) {}
    // ~Node()
    // {
    //     delete next;
    //     delete prev;
    // }

    int val = -1;
    Node *next = nullptr;
    Node *prev = nullptr;
};

class MyLinkedList
{
public:
    MyLinkedList()
    {
        head = new Node();
        tail = head;
    }

    ~MyLinkedList()
    {
        current = head;
        while (current)
        {
            delete current;
            current = head->next;
        }
    }

    int get(int index)
    {
        Node *t = head;
        while (t && index >= 0)
        {
            t = t->next;
            --index;
        }

        return !t ? -1 : t->val;
    }

    void addAtHead(int val)
    {
        if (head == tail)
        {
            head->val = val;
            tail = new Node();
            head->next = tail;
            return;
        }
        current = new Node(val, head, nullptr);
        head = current;
    }

    void addAtTail(int val)
    {
        if (head == tail)
        {
            addAtHead(val);
        }
        current = new Node(val, nullptr, tail);
        tail = current;
    }

    void addAtIndex(int index, int val)
    {
        Node *t = head;
        while (t && index >= 0)
        {
            t = t->next;
            --index;
        }
        if (!t)
        { // add to tail
            addAtTail(val);
        }
        else if (index == 0)
        {
            current = new Node(val, t, t->prev);
        }
    }

    void deleteAtIndex(int index)
    {
        Node *t = head;
        while (t && index >= 0)
        {
            t = t->next;
            --index;
        }
        if (!t)
            return;
        else if(index == 0)
            t->prev = t->next;
            current = t;
            delete current;
    }

private:
    Node *head, *tail, *current;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
