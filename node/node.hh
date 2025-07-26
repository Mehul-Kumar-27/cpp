#include <iostream>

using namespace std;

class Node
{
public:
    int NodeData;
    Node *next;
    Node(int nodeData)
    {
        NodeData = nodeData;
        next = nullptr;
        cout << "Node created with the data" << nodeData << endl;
    }
};
