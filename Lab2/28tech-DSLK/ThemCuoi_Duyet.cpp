#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next; // or struct node *next;
};

typedef struct node node; //C

node *makeNode(int x){ 
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
// Thêm node vào cuoi DSLK
void pushBack(node **head, int x)
{
    node *temp = *head;
    node *newNode = makeNode(x);
    if(*head == NULL){
        *head = newNode; return;}
    while(temp->next != NULL){
        temp = temp->next;
    }
    //cho phan next cua node head -> newNode
    temp->next = newNode;
}
// Cách 2 tham chiếu
void pushBack2(node *&head, int x)
{
    node *temp = head;
    node *newNode = makeNode(x);
    if(head == NULL){
        head = newNode; return;}
    while(temp->next != NULL){
        temp = temp->next;
    }
    //cho phan next cua node head -> newNode
    temp->next = newNode;
}
int main(){
    node *head = NULL;
    for (int i = 0; i <= 10 ; i++)
    {
        pushBack2(head, i);
    }
    duyet(head);
    return 0;
}