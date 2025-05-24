#include <stdio.h>
#include <string.h> // strcat
#include <stdlib.h>
#include <time.h>
// 任意の形状の行列の積を計算する関数
// A: m×n行列, B: n×p行列, C: m×p行列（結果を格納）
// m: Aの行数, n: Aの列数/Bの行数, p: Bの列数
void matmul(const double *A, const double *B, double *C, int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            double sum = 0;
            for (int k = 0; k < n; k++) {
                sum += A[i * n + k] * B[k * p + j];
            }
            C[i * p + j] = sum;
        }
    }
}

int com(int x, int y, int z,const double *brain0, int p, double *brain1){
    double temp[p];
    double input[3] = {(double)x,(double)y,(double)z};
    double output[21];
    matmul(input,brain0,temp,1,3,p);
    matmul(temp,brain1,output,1,p,21);
    int max_index = 0;
    for (int i = 0; i < 21; i++)
    {
        if (output[i] > output[max_index])
        {
            max_index = i;
        }
    }
    return max_index;
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    // brain生成
    int numofbrain = 10;
    double brainA[numofbrain][3*10];
    for(int i = 0; i < numofbrain; i++)
    {
        for (int j = 0; j < 3*10; j++)
        {
            brainA[i][j] = (double)rand() / RAND_MAX;
        }
    }
    double brainB[numofbrain][10*27];
    for(int i = 0; i < numofbrain; i++)
    {
        for (int j = 0; j < 10*27; j++)
        {
            brainB[i][j] = (double)rand() / RAND_MAX;
        }
    }
    
    int comhand = com(1,2,3,brainA,10,brainB);
    if (1 <= comhand && comhand <= 5){
        printf("左を%d減らす\n", comhand);
    }else if (6 <= comhand && comhand <= 12){
        printf("中央を%d減らす\n", comhand-5);
    }else if (13 <= comhand && comhand <= 21){
        printf("右を%d減らす\n", comhand-12);
    }else{
        printf("エラー\n");
    }

    return 0;
}