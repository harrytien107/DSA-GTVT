#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next; // or struct node *next;
};

node* makeNode(int x)
{
    node *newNode = new node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void duyet(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}    

// head = 3         head = head->next // head->next : Địa chỉ của node kế tiếp
// head -> next
//   ↱￣￣￣↴
// 1|7 -> 2|8 -> 3|4 -> 4|2 -> 5|N -> NULL
// 3      7      8      4      2
// head->data = 1
// head = head->next = 7 
//vòng lặp tiếp tục cho đến khi head = NULL , // 1 2 3 4 5 

//Biến đếm bao nhiêu node head trong DSLK
int count(node *head)
{
    int dem = 0;
    while (head != NULL)
    {
        dem++;
        head = head->next;
    }
    return dem;
}
// Thêm node vào đầu DSLK
void pushFront(node **head, int x)
{
    node *newNode = makeNode(x);
    //Buoc 1: phan next cua newNode => head
    newNode->next = *head; // *head : địa chỉ của node head trong DSLK
    //Buoc 2: Cap nhat node head => newNode
    *head = newNode;
}
// Cách 2 tham chiếu
void pushFront2(node *&head, int x)
{
    node *newNode = makeNode(x);
    newNode->next = head;
    head = newNode;
}

int main()
{
    node *head =NULL;
    // Thêm node vào đầu DSLK
    for (int i = 1; i <= 5; i++)
    {
        pushFront(&head, i);
    }
    // duyet(head);
    // cout << count(head);
    for(int i = 10; i <= 20; i++)
    {
        pushFront2(head, i);
    }
    duyet(head);
    return 0;   
}


