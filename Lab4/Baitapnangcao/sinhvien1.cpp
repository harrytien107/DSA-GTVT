#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    char name[128];
    char email[128];
    char phone[20];
    int MSSV;
};

// Cấu trúc Node cho danh sách liên kết trong mỗi bucket của bảng băm
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

void InitHash(Student *&U, int M, int N) {
    for(int i = 0; i < M; i++) {
        U[i].MSSV = 0;
    }

    for(int i = 0; i < N; i++) {
        printf("Nhap thong tin cho sinh vien %d:\n", i+1);

        printf("Nhap ten: ");
        scanf(" %127[^\n]", U[i].name);

        printf("Nhap email: ");
        scanf(" %127[^\n]", U[i].email);

        printf("Nhap so dien thoai: ");
        scanf(" %19[^\n]", U[i].phone);

        printf("Nhap MSSV: ");
        scanf("%d", &U[i].MSSV);

        int pos = Hash(U[i].name, M);
        int originalPos = pos;
        int attempt = 0;

        while(U[pos].MSSV != 0 && strcmp(U[pos].name, U[i].name) != 0) {
            attempt++;
            pos = (Hash(U[i].name, M) + attempt) % M;
            if(pos == originalPos) {
                printf("Bang bam da day, khong the them sinh vien %d\n", i+1);
                break;
            }
        }

        if(U[pos].MSSV == 0 || strcmp(U[pos].name, U[i].name) == 0) {
            strcpy(U[pos].name, U[i].name);
            strcpy(U[pos].email, U[i].email);
            strcpy(U[pos].phone, U[i].phone);
            U[pos].MSSV = U[i].MSSV;
        }
    }
}

int main(int argc, char *argv[]) {
    int M = 10; 
    Student *U = new Student[M];

    int N;
    printf("Nhap so luong sinh vien can them vao bang bam: ");
    scanf("%d", &N);

    InitHash(U, M, N);

    char searchName[128];
    printf("Nhap ten sinh vien can tim kiem: ");
    scanf(" %127[^\n]", searchName);

    int pos = Hash(searchName, M);
    int originalPos = pos;
    int attempt = 0;
    bool found = false;

    while(U[pos].MSSV != 0) {
        if(strcmp(U[pos].name, searchName) == 0) {
            found = true;
            break;
        }
        attempt++;
        pos = (Hash(searchName, M) + attempt) % M;
        if(pos == originalPos) {
            break;
        }
    }

    if(found) {
        printf("Thong tin sinh vien:\n");
        printf("Ten: %s\n", U[pos].name);
        printf("Email: %s\n", U[pos].email);
        printf("So dien thoai: %s\n", U[pos].phone);
        printf("MSSV: %d\n", U[pos].MSSV);
    }
    else {
        printf("Khong tim thay sinh vien voi ten \"%s\" trong bang bam\n", searchName);
    }

    delete[] U;
    return 0;

}