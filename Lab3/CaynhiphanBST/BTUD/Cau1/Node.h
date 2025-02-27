#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node();
    Node(char); // Thay đổi từ int thành char
    virtual ~Node();
    Node *Getleft() { return left; }
    void Setleft(Node* val) { left = val; }
    Node *Getright() { return right; }
    void Setright(Node* val) { right = val; }
    Node *Getparent() { return parent; }
    void Setparent(Node* val) { parent = val; }
    char Getkey() { return key; } 
    void Setkey(char val) { key = val; }

    int GetCount() const { return count; }
    void IncrementCount() { count++; }

protected:
private:
    Node *left;
    Node *right;
    Node *parent;
    char key; // Thay đổi từ int thành char
    int count;
};

#endif // NODE_H