#pragma once

class Node
{
    private:
        int coefficient;
        int exponent;
        Node* pointer;
    public:
        Node();
        Node(int, int);
        virtual ~Node();
        
        int GetCoefficient()
        {
            return coefficient;
        }
        
        void SetCoefficient(int val)
        {
            coefficient = val;
        }
        
        int GetExponent() const;
        void SetExponent(int val);
        Node* GetPointer() const;
        void SetPointer(Node* ptr);
};
