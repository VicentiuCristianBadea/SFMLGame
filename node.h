#ifndef NODE_H
#define NODE_H


class Node
{


    int val;

public:
    Node(int);
    void setVal(int&);
    int getVal();


    Node* next;
};

#endif // NODE_H
