#ifndef NODE_H
#define NODE_H

#include "Student.h"
class Node
{
public:
    Node() : left(nullptr), right(nullptr), height(1) {}
    Node(const Student& s) : student(s), left(nullptr), right(nullptr), height(1) {}

    Node(int k, Student s) : key(k), student(s), left(nullptr), right(nullptr), height(1) {}
    // Getters and setters
    const Student& GetStudent() const { return student; }
    void SetStudent(const Student& s) { student = s; }
    Node *Getleft() const { return left; }
    void Setleft(Node *val) { left = val; }
    Node *Getright() const { return right; }
    void Setright(Node *val) { right = val; }
    Node *Getparent() const { return parent; }
    void Setparent(Node *val) { parent = val; }
    int Getkey() const { return key; }
    void Setkey(int val) { key = val; }
    int getHeight() const { return height; }
    void Setheight(int val) { height = val; }

protected:
private:
    Node *left;
    Node *right;
    Node *parent;
    // int bal; // -1 0 1
    int key;
    int height;
    Student student;
};
#endif // NODE_H