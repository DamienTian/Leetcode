/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 * 
 * Category: Design, Linked List
 */

// @lc code=start

struct Node
{
    Node() {}
    Node(int v) : val(v) {}
    Node(int v, Node *n, Node *p) : val(v), next(n), prev(p) {}

    int val = -1;
    Node *next = nullptr;
    Node *prev = nullptr;
};

// This is a Double Linked List
//  https://zxi.mytechroad.com/blog/list/leetcode-707-design-linked-list/ (Single Linked List)
class MyLinkedList
{
public:
    MyLinkedList() : head(nullptr), tail(nullptr) {}

    ~MyLinkedList()
    {
        Node* node = head;
        while (node)
        {
            Node* current = node;
            node = node->next;
            delete current;
        }
        head = nullptr;
        tail = nullptr;
    }

    int get(int index)
    {
        if(index < 0 || index >= size){
            return -1;
        }
        Node *t = head;
        while (t->next && index > 0)
        {
            t = t->next;
            --index;
        }
        cout << t->val << endl;
        return t->val;
    }

    void addAtHead(int val)
    {
        if (!head)
        {
            head = new Node(val, tail, nullptr);
            ++size;
            return;
        }
        head->prev = new Node(val, head, nullptr);
        head = head->prev;
        ++size;
    }

    void addAtTail(int val)
    {
        if (!head)
        {
            addAtHead(val);
        }
        else if (!tail)
        {
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = new Node(val, nullptr, temp);
            tail = temp->next;
            ++size;
        }
        else
        {
            tail->next = new Node(val, nullptr, tail);
            tail = tail->next;
            ++size;
        }
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
        {
            return;
        }
        if (index == 0)
        {
            addAtHead(val);
        }
        else if (index == size)
        {
            addAtTail(val);
        }
        else
        {
            Node *t = head;
            while (t->next && index > 0)
            {
                t = t->next;
                --index;
            }
            // Insert val at t's position
            Node *insert = new Node(val, t, t->prev);
            t->prev->next = insert;
            t->prev = insert;
            ++size;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            return;
        }

        Node *nodeToDelete = head;
        while (nodeToDelete->next && index > 0)
        {
            nodeToDelete = nodeToDelete->next;
            --index;
        }
        // After the while loop, found the node to delete
        Node *prevNode = nodeToDelete->prev;
        Node *nextNode = nodeToDelete->next;
        prevNode ? prevNode->next = nextNode : head = nodeToDelete->next;
        nextNode ? nextNode->prev = prevNode : tail = nodeToDelete->prev;
        delete nodeToDelete;
        --size;
    }

private:
    Node *head, *tail;
    int size = 0;
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
