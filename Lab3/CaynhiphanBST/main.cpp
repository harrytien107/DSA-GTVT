#include <iostream>
#include "BST.h"
#include "BST.cpp"
#include "Node.h"
#include "Node.cpp"

using namespace std;

int main()
{
    BST* tree = new BST();
    Node* n;
    n = new Node(10);
    tree->InsertNode(n);
    n = new Node(19);
    tree->InsertNode(n);
    n = new Node(9);
    tree->InsertNode(n);
    n = new Node(3);
    tree->InsertNode(n);
    n = new Node(19);
    tree->InsertNode(n);
    n = new Node(8);
    tree->InsertNode(n);
    n = new Node(4);
    tree->InsertNode(n);
    n = new Node(1);
    tree->InsertNode(n);
    n = new Node(15);
    tree->InsertNode(n);

    tree->TravelNLR();

    cout << "Sum of tree: " << tree->SumTree() << endl;
    cout << "Min of tree: " << tree->FindMin()->Getkey() << endl;
    cout << "Max of tree: " << tree->FindMax()->Getkey() << endl;
    cout << "Total number of nodes: " << tree->CountAllNode() << endl;
    cout << "Total number of leaf nodes: " << tree->CountLeafNodes() << endl;

    // Problem 5a: Count the number of distinct values
    cout << "Problem 5a: Number of distinct values: " << tree->CountDistinctValues() << endl;

    // Problem 5b: Display each distinct value with its frequency
    cout << "Problem 5b: Frequency of each distinct value:" << endl;
    tree->PrintFrequencies();

    // New functionality: Search for a user-input key
    int x;
    cout << "Enter a key to search in the BST: ";
    cin >> x;
    Node* result = tree->search_x(tree->Getroot(), x);
    if (result != nullptr)
    {
        cout << "Key " << x << " is present in the BST with frequency " << result->GetCount() << "." << endl;
    }
    else
    {
        cout << "Key " << x << " is NOT present in the BST." << endl;
    }

    // Clean up
    delete tree;
    return 0;
}