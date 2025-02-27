//DSLK đơn và cấu trúc tự trỏ
#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *next; // or struct node *next;
};

typedef struct node node; // đây là cách đặt tên cho kiểu dữ liệu struct node

//Thao tác tạo node mới
node* makeNode(int x)
{
    // Trong C, node *newNode = (node *)malloc(sizeof(node));
    node *newNode = new node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
// Mỗi node trong DSLK là một con trỏ kiểu nod

//->head = 3
//    1|8 -> 2|7 -> 5|4 -> 3|N -> NULL
//ĐC:  3      8      7      4      
//Mỗi node này là một con trỏ và nó sẽ quản lý một cái node khác, khi quản lý mấy cái node này thì ta sẽ sử dụng địa chỉ của nó bằng cái mũi tên ->. 