#include <stdio.h>
#include <string.h>

struct Word
{
    int key;
    char value[128];
};

int Hash(int k, int M)
{
    if (M == 0)
        return 0;
    return (k % M);
}

void InitHash(Word *&U, int M, int N)
{
    Word *K = new Word[N];
    
    for(int i = 0; i < N; i++)

    {
        printf("Nhap MSSV cho sinh vien %d: ", i+1);
        scanf("%d", &K[i].key);
        printf("Nhap ten cho sinh vien %d: ", i+1);
        scanf(" %127[^\n]", K[i].value);

    }

    for(int i = 0; i < M; i++)
        U[i].key = 0;

    for(int i = 0; i < N; i++)

    {
        int pos = Hash(K[i].key, M);
        U[pos] = K[i];

    }
    
    delete[] K;

}

int main(int argc, char *argv[])
{
    int M = 10; // Kích thước bảng băm
    Word *U = new Word[M];
    
    int N;
    printf("Nhap so luong sinh vien can them vao bang bam: ");
    scanf("%d", &N);
    
    // Khởi tạo bảng băm với N sinh viên
    InitHash(U, M, N);

    int x;
    printf("Nhap MSSV tim kiem: ");
    scanf("%d", &x);
    
    int pos = Hash(x, M);
    if (U[pos].key == 0)
    {
        printf("Khong tim thay SV nao trong bang bam\n");
    }
    else
    {
        // Kiểm tra xem khóa có trùng với MSSV tìm kiếm hay không
        if (U[pos].key == x)
        {
            printf("Ten cua SV can tim kiem la: %s\n", U[pos].value);
        }
        else
        {
            // Nếu không trùng, thông báo không tìm thấy
            printf("Khong tim thay SV voi MSSV %d trong bang bam\n", x);
        }
    }
    
    // Giải phóng bộ nhớ đã cấp phát cho bảng băm
    delete[] U;
    return 0;
}