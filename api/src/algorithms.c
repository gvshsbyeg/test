#include <stdlib.h>
#include "../inc/algorithms.h"
#include "calc_funcs.h"

int** sub_sequence_func1(int* arr, int arr_length)
{
    int n = (1 << arr_length) - 1;
    int** ans = (int**)malloc(n * sizeof(int*));
    for (int mask = 1; mask <= n; mask++)
    {
        int m = mask / arr_length + 1;
        int* res = (int*)malloc(m * sizeof(int));
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i))
            {
                res[k++] = arr[i];
            }
        }
        ans[mask - 1] = res;
    }
    return ans;
}


// 把整数 num 转换成二进制字符串
void uint2bin(unsigned int num, char* ans, int bit_len)
{
    for (int i = bit_len - 1; i >= 0; i--)
    {
        ans[i] = (num & 1) ? '1' : '0';
        num >>= 1;
    }
    return;
}