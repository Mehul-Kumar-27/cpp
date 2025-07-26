#include <iostream>
#include "../node/node.hh"

using namespace std;

class LinkedList
{
public:
    Node *head;

    LinkedList() { head = nullptr; }

    // Inserts the node at the last of the linked list
    void insertNode(Node *next)
    {
        // Traverse to the end of the linked list
        Node *curr = head;
        while (head->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = next;
    };
};
