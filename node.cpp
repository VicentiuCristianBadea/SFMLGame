#include "node.h"

Node::Node(int x)
{
    val = x;
    next = nullptr;
}

void Node::setVal(int &x)
{
    val = x;
}

int Node::getVal()
{
    return val;
}
