#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    char name[128];
    char email[128];
    char phone[20];
    int MSSV;
};

int Hash1(const char* name, int M) {
    int hashValue = 0;
    for(int i = 0; name[i] != '\0'; i++) {

        hashValue += (int)name[i];
    }
    if (M == 0)
        return 0;
    return (hashValue % M);
}

int Hash2(const char* name, int M) {
    int hashValue = 0;

    for(int i = 0; name[i] != '\0'; i++) {
        hashValue += (int)name[i] * (i + 1);
    }
    return (1 + (hashValue % (M - 1)));

}

void InitHash(Student *U, int M, int N) {
    for(int i = 0; i < M; i++) {
        U[i].MSSV = 0;
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

        int h1 = Hash1(s.name, M);
        int h2 = Hash2(s.name, M);
        int pos = h1;
        int attempt = 0;

        while(U[pos].MSSV != 0 && strcmp(U[pos].name, s.name) != 0) {
            attempt++;
            pos = (h1 + attempt * h2) % M;
            if(pos == h1) {

                printf("Bang bam da day, khong the them sinh vien %d\n", i+1);
                break;
            }
        }

        if(U[pos].MSSV == 0 || strcmp(U[pos].name, s.name) == 0) {
            strcpy(U[pos].name, s.name);
            strcpy(U[pos].email, s.email);

            strcpy(U[pos].phone, s.phone);
            U[pos].MSSV = s.MSSV;
        }
    }
}

bool FindStudent(Student *U, int M, const char* searchName, Student& result) {
    int h1 = Hash1(searchName, M);
    int h2 = Hash2(searchName, M);

    int pos = h1;
    int attempt = 0;

    while(U[pos].MSSV != 0) {
        if(strcmp(U[pos].name, searchName) == 0) {
            result = U[pos];
            return true;
        }
        attempt++;
        pos = (h1 + attempt * h2) % M;
        if(pos == h1) {
            break;
        }

    }

    return false;
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

    Student foundStudent;
    bool found = FindStudent(U, M, searchName, foundStudent);

    if(found) {
        printf("Thong tin sinh vien:\n");
        printf("Ten: %s\n", foundStudent.name);
        printf("Email: %s\n", foundStudent.email);
        printf("So dien thoai: %s\n", foundStudent.phone);
        printf("MSSV: %d\n", foundStudent.MSSV);
    }
    else {
        printf("Khong tim thay sinh vien voi ten \"%s\" trong bang bam\n", searchName);
    }

    delete[] U;
    return 0;

}