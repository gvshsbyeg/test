#include "../inc/calc_funcs.h"

// 计算阶乘 x!
long long factorial(int x)
{
	long long res = 1;
	for (int i = 1; i <= x; i++)
	{
		res *= i;
	}
	return res;
}

// 计算组合数 C(n, i)
long long binomial_coefficient(int n, int i) 
{
	return factorial(n) / (factorial(i) * factorial(n - i));
}

// 计算 mask 二进制形式中 1 的个数
int popcnt_func1(int mask)
{
	int ans = 0;
	while (mask)
	{
		ans += (mask & 1);
		mask = mask >> 1;
	}
	return ans;
}

int popcnt_func2(int mask)
{
	return __builtin_popcount((unsigned int)mask);
}

int popcnt_func3(int mask)
{
	// Brian Kernighan 算法
	int ans = 0;
	while (mask)
	{
		mask &= (mask - 1);	// 消除最低位的1
		ans++;
	}
	return ans;
}

// 计算整数 num 二进制形式的位数
int count_bits_func1(int num)
{
	int res = 0;
	while (num)
	{
		res++;
		num >>= 1;
	}
	return res;
}

int count_bits_func2(int num)
{
	if (num == 0)
	{
		return 1;
	}
	return 32 - __builtin_clz(num);
} 






