#include "element.h"

element::element(int value)
{
    this->data = value;
    this->pointer = nullptr;
}

element::~element()
{
    //dtor
} 