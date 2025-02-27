#include "Polynomial.h"
#include <iostream>
#include <cmath>
using namespace std;
Polynomial::Polynomial()
{
    //ctor
    this->head = nullptr;
    this->tail = nullptr;
    this->nNum = 0;
}

Polynomial::~Polynomial()
{
}
void Polynomial::InsertFirst(Node* e) 
{
    if (this->head == nullptr)
        this->head = this->tail = e;
    else 
    {
        e->Setpointer(this->head);
        this->head = e;
    }
    this->nNum++;
}
void Polynomial::InsertTail(Node* e) 
{
    if (this->head == nullptr)
        this->head = this->tail = e;
    else 
    {
        this->tail->Setpointer(e);
        this->tail = e;
    }
    this->nNum++;
}
void Polynomial::InsertPoly(int coefficient, int exponent) {
    Node* newNode = new Node(coefficient, exponent);
    if (!head || head->GetExponent() < exponent) 
    {
        newNode->Setpointer(this->head);
        this->head = newNode;
    }
    else 
    {
        Node* currNode = this->head;
        while (currNode->Getpointer()!=nullptr && currNode->Getpointer()->GetExponent() > exponent) 
        {
            currNode = currNode->Getpointer();
        }
        if (currNode->GetExponent() == exponent) 
        {
            currNode->SetCoefficient(currNode->GetCoefficient() + coefficient);
        }
        else 
        {
            newNode->Setpointer(currNode->Getpointer());
            currNode->Setpointer(newNode);
        }
    }
}
void Polynomial::printPolynomial()
{
    Node* p = this->head;
    while (p != nullptr) 
    {
        cout << p->GetCoefficient();
        if (p->GetExponent() > 1)
        {
            cout<< "x^" << p->GetExponent();
        }
        else if (p->GetExponent() == 1)
        {
            cout << "x";
        }        
        p = p->Getpointer();
        if (p != nullptr) cout << " + ";
    }
}

int Polynomial::EvaluatePolynomial(int x)
{
    int resultOfEvaPoly = 0;
    Node* p = this->head;
    while (p != nullptr)
    {
        resultOfEvaPoly += p->GetCoefficient() * pow(x, p->GetExponent());
        p = p->Getpointer();
    }
    return resultOfEvaPoly;
}
Polynomial Polynomial::add2Polynomial(const Polynomial& other)
{
    Polynomial resultAdd;
    Node* p1 = this->head;
    Node* p2 = other.head;
    while (p1 != nullptr && p2 != nullptr) 
    {
        if (p1->GetExponent() > p2->GetExponent()) 
        {
            Node* p3 = new Node(p1->GetCoefficient(), p1->GetExponent());
            resultAdd.InsertTail(p3);
            p1 = p1->Getpointer();
        }
        else if (p1->GetExponent() < p2->GetExponent())
        {
            Node* p3 = new Node(p2->GetCoefficient(), p2->GetExponent());
            resultAdd.InsertTail(p3);
            p2 = p2->Getpointer();
        }
        else
        {
            Node* p3 = new Node(p1->GetCoefficient() + p2->GetCoefficient(), p1->GetExponent());
            resultAdd.InsertTail(p3);
            p1 = p1->Getpointer();
            p2 = p2->Getpointer();
        }
    }
    while (p1 != nullptr)
    {
        Node* p3 = new Node(p1->GetCoefficient(), p1->GetExponent());
        resultAdd.InsertTail(p3);
        p1 = p1->Getpointer();
    }
    while (p2 != nullptr)
    {
        Node* p3 = new Node(p2->GetCoefficient(), p2->GetExponent());
        resultAdd.InsertTail(p3);
        p2 = p2->Getpointer();
    }
    return resultAdd;
}
Polynomial Polynomial::operator+(const Polynomial& other) const
{
    Polynomial resultAdd;
    Node* p1 = this->head;
    Node* p2 = other.head;
    while (p1 != nullptr && p2 != nullptr)
    {
        if (p1->GetExponent() > p2->GetExponent())
        {
            Node* p3 = new Node(p1->GetCoefficient(), p1->GetExponent());
            resultAdd.InsertTail(p3);
            p1 = p1->Getpointer();
        }
        else if (p1->GetExponent() < p2->GetExponent())
        {
            Node* p3 = new Node(p2->GetCoefficient(), p2->GetExponent());
            resultAdd.InsertTail(p3);
            p2 = p2->Getpointer();
        }
        else
        {
            Node* p3 = new Node(p1->GetCoefficient() + p2->GetCoefficient(), p1->GetExponent());
            resultAdd.InsertTail(p3);
            p1 = p1->Getpointer();
            p2 = p2->Getpointer();
        }
    }
    while (p1 != nullptr)
    {
        Node* p3 = new Node(p1->GetCoefficient(), p1->GetExponent());
        resultAdd.InsertTail(p3);
        p1 = p1->Getpointer();
    }
    while (p2 != nullptr)
    {
        Node* p3 = new Node(p2->GetCoefficient(), p2->GetExponent());
        resultAdd.InsertTail(p3);
        p2 = p2->Getpointer();
    }
    return resultAdd;
}
Polynomial Polynomial::multiply2Poly(const Polynomial& other)
{
    Polynomial result;
    Node* p1 = this->head;
    if (p1 == nullptr)
    {
        result = other;
    }
    while (p1!=nullptr) 
    {
        Node* p2 = other.head;
        Polynomial tempPoly;

        while (p2!=nullptr) 
        {
            Node* p3 = new Node(p1->GetCoefficient() * p2->GetCoefficient(), p1->GetExponent() + p2->GetExponent());
            tempPoly.InsertTail(p3);
            p2 = p2->Getpointer();
        }

        result = result.add2Polynomial(tempPoly);
        p1 = p1->Getpointer();
    }

    return result;
}
Polynomial Polynomial::operator*(const Polynomial& other) const
{
    Polynomial result;
    Node* p1 = this->head;
    if (p1 == nullptr)
    {
        result = other;
    }
    while (p1 != nullptr)
    {
        Node* p2 = other.head;
        Polynomial tempPoly;

        while (p2 != nullptr)
        {
            Node* p3 = new Node(p1->GetCoefficient() * p2->GetCoefficient(), p1->GetExponent() + p2->GetExponent());
            tempPoly.InsertTail(p3);
            p2 = p2->Getpointer();
        }

        result = result.add2Polynomial(tempPoly);
        p1 = p1->Getpointer();
    }

    return result;
}


Polynomial Polynomial::multiply(const Polynomial& other)
{
    Polynomial result;
    for (Node* p1 = this->head; p1; p1 = p1->Getpointer())
    {
        Polynomial temp;
        for (Node* p2 = other.head; p2; p2 = p2->Getpointer()) {
            temp.InsertPoly(p1->GetCoefficient() * p2->GetCoefficient(), p1->GetExponent() + p2->GetExponent());
        }
        result = result.add2Polynomial(temp);
    }
    return result;
}

