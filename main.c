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
    for (int i = 0; i < p; i++)
    {
        if(temp[i] < 0){
            temp[i] = 0;
        }
    }
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
    int brainscore = 0;
    double brainA[3*3];
    for (int i = 0; i < 3*3; i++)
    {
        brainA[i] = (double)rand() / RAND_MAX;
    }
    double brainB[3*27];
    for (int i = 0; i < 3*27; i++)
    {
        brainB[i] = (double)rand() / RAND_MAX;
    }
    int comhand = com(1,2,3,brainA,10,brainB);
    int x = 5;
    int y = 7;
    int z = 9;
    printf("%d %d %d\n", x, y, z);

    if (1 <= comhand && comhand <= 5){
        printf("COM>左を%d減らす\n", comhand);
        if( 1 <= comhand && comhand <= x){
            printf("有効な値\n");
            x -= comhand;
            brainscore ++;
        }else{
            printf("無効な値\n");
            brainscore --;
        }
    }else if (6 <= comhand && comhand <= 12){
        printf("COM>中央を%d減らす\n", comhand-5);
        if(1 <= comhand-5 && comhand-5 <= y){
            printf("有効な値\n");
            y -= (comhand-5);
            brainscore ++;
        }else{
            printf("無効な値\n");
            brainscore --;
        }
    }else if (13 <= comhand && comhand <= 21){
        printf("COM>右を%d減らす\n", comhand-12);
        if(1 <= comhand-12 && comhand-12 <= z){
            printf("有効な値\n");
            z -= (comhand-12);
            brainscore ++;
        }else{
            printf("無効な値\n");
            brainscore --;
        }
    }else{
        printf("エラー0\n");
    }
    if (x == 0 && y == 0 && z == 0){
        printf("COMの勝ち\n");
        brainscore += 10;
    }
    printf("COMのスコア:%d\n", brainscore);

    return 0;
}