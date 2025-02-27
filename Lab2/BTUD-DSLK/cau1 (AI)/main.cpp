#include <bits/stdc++.h>
#include "Polynomial.h"
#include "Polynomial.cpp"
#include "Node.h"
#include "Node.cpp"

using namespace std;

int main() {
    Polynomial poly1;
    Polynomial poly2;

    // Đa thức 1: 3x^4 + 2x^3 + x
    poly1.AddTerm(3, 4);
    poly1.AddTerm(2, 3);
    poly1.AddTerm(1, 1);

    // Đa thức 2: 5x^3 + 4x + 2
    poly2.AddTerm(5, 3);
    poly2.AddTerm(4, 1);
    poly2.AddTerm(2, 0);

    cout << "Da thuc 1: ";
    poly1.printPolynomial();

    cout << "Da thuc 2: ";
    poly2.printPolynomial();

    // Tính giá trị đa thức tại x = 2
    int x = 2;
    cout << "Gia tri Da thuc 1 tai x = " << x << ": " << poly1.EvaluatePolynomial(x) << endl;
    cout << "Gia tri Da thuc 2 tai x = " << x << ": " << poly2.EvaluatePolynomial(x) << endl;

    // Cộng hai đa thức
    Polynomial sum = poly1 + poly2;
    cout << "Tong: ";
    sum.printPolynomial();

    // Nhân hai đa thức
    Polynomial product = poly1 * poly2;
    cout << "Tich: ";
    product.printPolynomial();

    return 0;
}