#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long LL;
typedef vector<LL> vec;
typedef vector<vec> mat;

const LL MOD = 1000000007;

mat mul(mat &A, mat &B)
{
	mat C(A.size(), vec(B[0].size()));
	for (int i = 0; i < A.size(); i++)
	{
		for (int k = 0; k < B.size(); k++)
		{
			if (A[i][k] != 0)
			{
				for (int j = 0; j < B[0].size(); j++)
				{
					C[i][j] = ((C[i][j] % MOD) + (A[i][k] * B[k][j]) % MOD) % MOD;
				}
			}
		}
	}
	return C;
}

mat pow(mat A, LL n)
{
	mat B(A.size(), vec(A[0].size()));
	for (int i = 0; i < A.size(); i++)
		B[i][i] = 1;
	while (n > 0)
	{
		if (n & 1)
			B = mul(B, A);
		A = mul(A, A);
		n >>= 1;
	}
	return B;
}

int main(int argc, char const *argv[])
{
	LL arr[4][3] = {{0, 1, 0}, {1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
	vector<LL> temp(3);
	mat A, B;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			temp[j] = arr[i][j];
		A.push_back(temp);
	}

	for (int i = 0; i < 3; i++)
	{
		vector<LL> temp2;
		temp2.push_back(arr[3][i]);
		B.push_back(temp2);
	}

	map<int, LL> mp;
	int m, u, v;
	scanf("%d", &m);
	mp[-1] = 0;
	mp[0] = 0;
	mp[1] = 1;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &u, &v);
		if (mp.count(u - 1) == 0)
		{
			mat powAns1 = pow(A, u - 2);
			mp[u - 1] = mul(powAns1, B)[2][0];
		}
		if (mp.count(v) == 0)
		{
			mat powAns2 = pow(A, v - 1);
			mp[v] = mul(powAns2, B)[2][0];
		}

		if (mp[v] > mp[u - 1])
			cout << (mp[v] - mp[u - 1]) % MOD << endl;
		else
			cout << (mp[v] + MOD - mp[u - 1]) << endl;
	}

	return 0;
}
