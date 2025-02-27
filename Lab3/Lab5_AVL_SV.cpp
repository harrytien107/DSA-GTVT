#include <iostream>
#include <algorithm>
// #include "AVL_tree.h"
// #include "AVL_tree.cpp"
using namespace std;

class Student
{
private:
    int studentID;
    string name;
    string dateOfBirth;
    float gpa;

public:
    // Constructors
    Student() : studentID(0), name(""), dateOfBirth(""), gpa(0.0) {}
    Student(int id, const string& n, const string& d, float g) :
        studentID(id), name(n), dateOfBirth(d), gpa(g) {}

    // Getters and setters
    int getStudentID() const { return studentID; }
    void setStudentID(int id) { studentID = id; }
    const string& getName() const { return name; }
    void setName(const string& n) { name = n; }
    const string& getdateOfBirth() const { return dateOfBirth; }
    void setdateOfBirth(const string& d) { dateOfBirth = d; }
    float getGPA() const { return gpa; }
    void setGPA(float g) { gpa = g; }
};

// Node structure for AVL tree
class Node
{
private:
    Student student;
    Node* left;
    Node* right;
    int height;

public:
    // Constructors
    Node() : left(nullptr), right(nullptr), height(1) {}
    Node(const Student& s) : student(s), left(nullptr), right(nullptr), height(1) {}

    // Getters and setters
    const Student& getStudent() const { return student; }
    void setStudent(const Student& s) { student = s; }
    Node* getLeft() const { return left; }
    void setLeft(Node* n) { left = n; }
    Node* getRight() const { return right; }
    void setRight(Node* n) { right = n; }
    int getHeight() const { return height; }
    void setHeight(int h) { height = h; }
};

// AVL Tree class
class AVL_tree
{
private:
    Node* root;

    int getHeight(Node* p)
    {
        if (p == nullptr) return 0;
        return p->getHeight();
    }

    int checkBalance(Node* p)
    {
        if (p == nullptr) return 0;
        return getHeight(p->getLeft()) - getHeight(p->getRight());
    }

    void rotateLeft(Node*& x)
    {
        Node* y = x->getRight();
        Node* T2 = y->getLeft();

        y->setLeft(x);
        x->setRight(T2);

        x->setHeight(1 + max(getHeight(x->getLeft()), getHeight(x->getRight())));
        y->setHeight(1 + max(getHeight(y->getLeft()), getHeight(y->getRight())));

        x = y;
    }

    void rotateRight(Node*& y)
    {
        Node* x = y->getLeft();
        Node* T2 = x->getRight();

        x->setRight(y);
        y->setLeft(T2);

        y->setHeight(1 + max(getHeight(y->getLeft()), getHeight(y->getRight())));
        x->setHeight(1 + max(getHeight(x->getLeft()), getHeight(x->getRight())));

        y = x;
    }

    Node* deleteNode(Node* root, int key)
    {
        if (root == nullptr)
            return root;

        if (key < root->getStudent().getStudentID())
            root->setLeft(deleteNode(root->getLeft(), key));
        else if (key > root->getStudent().getStudentID())
            root->setRight(deleteNode(root->getRight(), key));
        else 
		{
            if ((root->getLeft() == nullptr) || (root->getRight() == nullptr)) 
			{
                Node* temp = root->getLeft() ? root->getLeft() : root->getRight();

                if (temp == nullptr) 
                {
                    temp = root;
                    root = nullptr;
                }
                else 
                {
                    *root = *temp;
                }

                delete temp;
            }
            else 
            {
                Node* temp = root->getRight();
                while (temp->getLeft() != nullptr)
                    temp = temp->getLeft();

                root->setStudent(temp->getStudent());
                root->setRight(deleteNode(root->getRight(), temp->getStudent().getStudentID()));
            }
        }

        if (root == nullptr)
            return root;

        root->setHeight(1 + max(getHeight(root->getLeft()), getHeight(root->getRight())));
        int balance = checkBalance(root);

        if (balance > 1 && checkBalance(root->getLeft()) >= 0)
            rotateRight(root);

        if (balance > 1 && checkBalance(root->getLeft()) < 0) 
        {
            Node* nLeft = root->getLeft();
            rotateLeft(nLeft);
            rotateRight(root);
        }

        if (balance < -1 && checkBalance(root->getRight()) <= 0)
            rotateLeft(root);

        if (balance < -1 && checkBalance(root->getRight()) > 0) 
        {
            Node* nRight = root->getRight();
            rotateRight(nRight);
            rotateLeft(root);
        }

        return root;
    }

    Node* insert(Node* node, const Student& student)
    {
        if (node == nullptr)
            return new Node(student);

        if (student.getStudentID() < node->getStudent().getStudentID())
            node->setLeft(insert(node->getLeft(), student));
        else if (student.getStudentID() > node->getStudent().getStudentID())
            node->setRight(insert(node->getRight(), student));
        else
            return node;

        node->setHeight(1 + max(getHeight(node->getLeft()), getHeight(node->getRight())));

        int balance = checkBalance(node);

        if (balance > 1 && student.getStudentID() < node->getLeft()->getStudent().getStudentID())
            rotateRight(node);

        if (balance < -1 && student.getStudentID() > node->getRight()->getStudent().getStudentID())
            rotateLeft(node);

        if (balance > 1 && student.getStudentID() > node->getLeft()->getStudent().getStudentID()) 
        {
            Node* nLeft = node->getLeft();
            rotateLeft(nLeft);
            rotateRight(node);
        }

        if (balance < -1 && student.getStudentID() < node->getRight()->getStudent().getStudentID()) 
        {
            Node* nRight = node->getRight();
            rotateRight(nRight);
            rotateLeft(node);
        }

        return node;
    }

    bool search(Node* root, int key) {
        if (root == nullptr)
            return false;

        if (key == root->getStudent().getStudentID())
            return true;
        else if (key < root->getStudent().getStudentID())
            return search(root->getLeft(), key);
        else
            return search(root->getRight(), key);
    }

public:
    AVL_tree() : root(nullptr) {}

    void insert(const Student& student) 
    {
        root = insert(root, student);
    }

    void deleteNode(int key) 
    {
        root = deleteNode(root, key);
    }

    bool search(int key) 
    {
        return search(root, key);
    }

    void LNR(Node* root) 
    {
        if (root != nullptr) 
        {
            LNR(root->getLeft());
            cout << "Student ID: " << root->getStudent().getStudentID() << ", Name: " << root->getStudent().getName()
                << ", dateOfBirth: " << root->getStudent().getdateOfBirth() << ", GPA: " << root->getStudent().getGPA() << endl;
            LNR(root->getRight());
        }
    }

    void TravelLNR() 
    {
        LNR(root);
    }

    void NLR(Node* root)
    {
        if (root != nullptr)
        {
            cout << "Student ID: " << root->getStudent().getStudentID() << ", Name: " << root->getStudent().getName()
                << ", dateOfBirth: " << root->getStudent().getdateOfBirth() << ", GPA: " << root->getStudent().getGPA() << endl;
            LNR(root->getLeft());
            LNR(root->getRight());
        }
    }

    void TravelNLR()
    {
        NLR(root);
    }
};

int main()
{
    AVL_tree tree;

    // Inserting some students
    tree.insert(Student(101, "An", "2002-05-15", 3.0));
    tree.insert(Student(102, "Bo", "2003-02-28", 3.6));
    tree.insert(Student(103, "Ca", "2004-10-10", 3.7));
    tree.insert(Student(104, "De", "2005-06-20", 2.9));

    tree.TravelLNR();
    cout << "-------------\n";
    tree.TravelNLR();

    int search_id = 102;
    bool found = tree.search(search_id);
    if (found)
    {
        cout << "Student with ID " << search_id << " found in the AVL tree." << endl;
    }
    else
    {
        cout << "Student with ID " << search_id << " not found in the AVL tree." << endl;
    }


    return 0;
}
