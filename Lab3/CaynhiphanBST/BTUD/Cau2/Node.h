#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;
class Node
{
public:
    Node();
    Node(const string&);
    virtual ~Node();
    Node *Getleft() { return left; }
    void Setleft(Node* val) { left = val; }
    Node *Getright() { return right; }
    void Setright(Node* val) { right = val; }
    Node *Getparent() { return parent; }
    void Setparent(Node* val) { parent = val; }
    string Getkey() { return key; } 
    void Setkey(string val) { key = val; }

    int GetCount() const { return count; }
    void IncrementCount() { count++; }

protected:
private:
    Node *left;
    Node *right;
    Node *parent;
    string key;
    int count;
};

#endif // NODE_H