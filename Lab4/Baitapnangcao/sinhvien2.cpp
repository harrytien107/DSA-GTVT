#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    char name[128];
    char email[128];
    char phone[20];
    int MSSV;
};

struct Node {
    Student data;
    Node* next;
};

int Hash(const char* name, int M) {
    int hashValue = 0;

    for(int i = 0; name[i] != '\0'; i++) {
        hashValue += (int)name[i];
    }
    if (M == 0)
        return 0;
    return (hashValue % M);
}

void InitHash(Node**& U, int M, int N) {
    for(int i = 0; i < M; i++) {
        U[i] = NULL;
    }

    for(int i = 0; i < N; i++) {
        Student s;
        printf("Nhap thong tin cho sinh vien %d:\n", i+1);


        printf("Nhap ten: ");
        scanf(" %127[^\n]", s.name);

        printf("Nhap email: ");
        scanf(" %127[^\n]", s.email);

        printf("Nhap so dien thoai: ");
        scanf(" %19[^\n]", s.phone);

        printf("Nhap MSSV: ");
        scanf("%d", &s.MSSV);

        int pos = Hash(s.name, M);

        Node* newNode = new Node;
        newNode->data = s;
        newNode->next = NULL;

        if(U[pos] == NULL) {
            U[pos] = newNode;
        } else {

            newNode->next = U[pos];
            U[pos] = newNode;
        }
    }
}

bool FindStudent(Node** U, int M, const char* searchName, Student& result) {
    int pos = Hash(searchName, M);


    Node* current = U[pos];
    while(current != NULL) {
        if(strcmp(current->data.name, searchName) == 0) {
            result = current->data;
            return true;
        }
        current = current->next;
    }

    return false;
}

void FreeHashTable(Node**& U, int M) {
    for(int i = 0; i < M; i++) {

        Node* current = U[i];
        while(current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        U[i] = NULL;
    }
    delete[] U;
}

int main(int argc, char *argv[]) {
    int M = 10; 
    Node** U = new Node*[M];

    int N;
    printf("Nhap so luong sinh vien can them vao bang bam: ");
    scanf("%d", &N);

    InitHash(U, M, N);

    char searchName[128];
    printf("Nhap ten sinh vien can tim kiem: ");
    scanf(" %127[^\n]", searchName);

    Student foundStudent;
    bool found = FindStudent(U, M, searchName, foundStudent);

    if(found) {
        printf("Thong tin sinh vien\n");
        printf("Ten: %s\n", foundStudent.name);
        printf("Email: %s\n", foundStudent.email);
        printf("So dien thoai: %s\n", foundStudent.phone);
        printf("MSSV: %d\n", foundStudent.MSSV);
    }
    else {
        printf("Khong tim thay sinh vien voi ten \"%s\" trong bang bam\n", searchName);
    }

    FreeHashTable(U, M);
    return 0;
}