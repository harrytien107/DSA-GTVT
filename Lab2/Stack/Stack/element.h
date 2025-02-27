#ifndef ELEMENT_H
#define ELEMENT_H

class element {
private:
    int data;
    element* pointer;

public:
    element(int value);
    virtual ~element();
    
    int Getdata() { return data; }
    void Setdata(int val) { data = val; }
    
    element* Getpointer() { return pointer; }
    void Setpointer(element* p) { pointer = p; }
};

#endif 