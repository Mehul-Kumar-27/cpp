#include <iostream>
#include "../node/node.hh"

using namespace std;

// This function would take in the head of a linked list and would reverse this list
Node *reverseLinkedList(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;

    while (curr != nullptr)
    {
        Node *next = curr->next;
        // Reverse this node
        curr->next = prev;
        // now move forward
        prev = curr;
        curr = next;
        next = curr->next;
    }

    head = prev;
    return head;
};

// This function would return the middle node of a linked list
Node *findMiddleElement(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
};

// This function would reverse the linked list in a group of k
Node *reverseInKGroups(Node *head, int group)
{

}
