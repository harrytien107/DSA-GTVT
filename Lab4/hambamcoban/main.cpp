#include <stdio.h>

int Hash(int k, int M) {
    if (M == 0) return 0;
    return (k % M);
}
// Giai thích: Hàm Hash(k, M) trả về vị trí của khóa k trong bảng băm có kích thước M. Chi tiết hơn, hàm này trả về phần dư của k khi chia cho M.

void InitHash(int *&U, int M) {
    int K[5] = {1,2,4,6,9};
    int i, pos;
    for(i = 0; i < M; i++)
        U[i] = 0;
    for(i = 0; i < 5; i++) {
        pos = Hash(K[i], M);
        U[pos] = K[i];
    }
}

int main() {
    int M = 10;
    int *U = new int[M];
    InitHash(U, M);
    
    int x;
    printf("Nhap khoa tim kiem: ");
    scanf("%d", &x);
    
    int pos = Hash(x, M);
    if (U[pos] == 0) {
        printf("Khong tim thay khoa trong bang bam\n");
    } else {
        printf("Gia tri phan tu can tim kiem: %d\n", U[pos]);
    }
    return 0;
}