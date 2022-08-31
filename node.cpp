#include "node.h"

Node::Node(int x)
{
    this->val = x;
    this->next = nullptr;
}

void Node::setVal(int &x)
{
    this->val = x;
}

int Node::getVal()
{
    return this->val;
}
