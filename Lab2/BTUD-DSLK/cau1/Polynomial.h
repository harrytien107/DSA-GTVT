#pragma once

#include "Node.h"

class Polynomial {
private:
    Node* head;
    Node* tail;
    int nNum;

public:
    Polynomial();
    virtual ~Polynomial();
    Node* GetHead() { return head; }
    void SetHead(Node* val) { head = val; }
    Node* GetTail() { return tail; }
    void SetTail(Node* val) { tail = val; }
    void InsertFirst(Node* );
    void InsertTail(Node* );
    bool DeleteFirst();
    
    void InsertPoly(int coefficient, int exponent);      
    void printPolynomial();
    int EvaluatePolynomial(int x);
    Polynomial add2Polynomial(const Polynomial& other); 
    Polynomial multiply2Poly(const Polynomial& other);  
    Polynomial multiply(const Polynomial& other);        
    
    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;
    void AddTerm(int coef, int exp);
};