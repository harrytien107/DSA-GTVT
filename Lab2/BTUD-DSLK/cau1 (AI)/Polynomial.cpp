#include "Polynomial.h"
#include <iostream>
#include <cmath>
using namespace std;

Polynomial::Polynomial() : head(nullptr), tail(nullptr) {}

Polynomial::~Polynomial() {
    while (head != nullptr) {
        DeleteFirst();
    }
}

void Polynomial::InsertFirst(Node* node) {
    if (head == nullptr) {
        head = tail = node;
    } else {
        node->SetPointer(head);
        head = node;
    }
}

void Polynomial::InsertTail(Node* node) {
    if (head == nullptr) {
        head = tail = node;
    }
    else {
        tail->SetPointer(node);
        tail = node;
    }
}

bool Polynomial::DeleteFirst() {
    if (head == nullptr) return false;
    Node* temp = head;
    head = head->GetPointer();
    delete temp;
    if (head == nullptr) tail = nullptr;
    return true;
}

void Polynomial::printPolynomial() {
    Node* p = head;
    while (p != nullptr) {
        cout << p->GetCoefficient();
        if (p->GetExponent() > 1) {
            cout << "x^" << p->GetExponent();
        }  
        else if (p->GetExponent() == 1) {
            cout << "x";
        }
        p = p->GetPointer();
        if (p != nullptr) cout << " + ";
    }
    cout << endl;
}

int Polynomial::EvaluatePolynomial(int x) {
    int result = 0;
    Node* p = head;
    while (p != nullptr) {
        result += p->GetCoefficient() * static_cast<int>(pow(x, p->GetExponent()));
        p = p->GetPointer();
    }
    return result;
}

// Cộng hai đa thức
Polynomial Polynomial::operator+(const Polynomial& other) const {
    Polynomial result;
    Node* p1 = this->head;
    Node* p2 = other.head;
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->GetExponent() > p2->GetExponent()) {
            result.InsertTail(new Node(p1->GetCoefficient(), p1->GetExponent()));
            p1 = p1->GetPointer();
        }
        else if (p1->GetExponent() < p2->GetExponent()) {
            result.InsertTail(new Node(p2->GetCoefficient(), p2->GetExponent()));
            p2 = p2->GetPointer();
        }
        else {
            int sumCoef = p1->GetCoefficient() + p2->GetCoefficient();
            if (sumCoef != 0) {
                result.InsertTail(new Node(sumCoef, p1->GetExponent()));
            }
            p1 = p1->GetPointer();
            p2 = p2->GetPointer();
        }
    }
    while (p1 != nullptr) {
        result.InsertTail(new Node(p1->GetCoefficient(), p1->GetExponent()));
        p1 = p1->GetPointer();
    }
    while (p2 != nullptr) {
        result.InsertTail(new Node(p2->GetCoefficient(), p2->GetExponent()));
        p2 = p2->GetPointer();
    }
    return result;
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    Polynomial result;
    for (Node* p1 = this->head; p1 != nullptr; p1 = p1->GetPointer()) {
        Polynomial temp;
        for (Node* p2 = other.head; p2 != nullptr; p2 = p2->GetPointer()) {
            temp.InsertTail(new Node(p1->GetCoefficient() * p2->GetCoefficient(),
        p1->GetExponent() + p2->GetExponent()));
        }
        result = result + temp;
    }
    return result;
}

void Polynomial::AddTerm(int coef, int exp) {
    if (coef == 0) return;
    Node* newNode = new Node(coef, exp);
    if (head == nullptr || exp > head->GetExponent()) {
        InsertFirst(newNode);
    }
    else {
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr && current->GetExponent() > exp) {
            previous = current;
            current = current->GetPointer();
        }
        if (current != nullptr && current->GetExponent() == exp) {
            current->SetCoefficient(current->GetCoefficient() + coef);
            delete newNode;
            if (current->GetCoefficient() == 0) {
                if (previous != nullptr) {
                    previous->SetPointer(current->GetPointer());
                    if (current == tail) tail = previous;
                } else {
                    head = current->GetPointer();
                    if (head == nullptr) tail = nullptr;
                }
                delete current;
            }
        }
        else {
            newNode->SetPointer(current);
            if (previous != nullptr) {
                previous->SetPointer(newNode);
            }
            if (current == nullptr) {
                tail = newNode;
            }
        }
    }
}