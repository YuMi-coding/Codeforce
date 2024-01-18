#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 100010;
int h[maxn];
int d1[maxn][20], d2[maxn][20];
void RMQ_init(int* A, int n)
{
	for (int i = 0; i < n; i++) d1[i][0] = d2[i][0] = A[i];
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 0; i + (1 << j) - 1 < n; i++)
		{
			d1[i][j] = min(d1[i][j - 1], d1[i + (1 << (j - 1))][j - 1]);
			d2[i][j] = max(d2[i][j - 1], d2[i + (1 << (j - 1))][j - 1]);
		}
}
int RMQ1(int L, int R)
{
	int k = 0;
	while ((1 << (k + 1)) <= R - L + 1) k++;
	return min(d1[L][k], d1[R - (1 << k) + 1][k]);
}
int RMQ2(int L, int R)
{
	int k = 0;
	while ((1 << (k + 1)) <= R - L + 1) k++;
	return max(d2[L][k], d2[R - (1 << k) + 1][k]);
}
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &h[i]);
	int f = 0, r = 0, maxl = 0;
	vector<pii> v;
	RMQ_init(h, n);
	while (r < n)
	{
		while (r < n)
		{
			int minh = RMQ1(f, r), maxh = RMQ2(f, r);
			if (maxh - minh > k) break;
			if (r - f + 1 > maxl)
			{
				maxl = r - f + 1;
				v.clear();
				v.push_back(make_pair(f, r));
			}
			else if (r - f + 1 == maxl)
				v.push_back(make_pair(f, r));
			r++;
		}
		while (f < r)
		{
			int minh = RMQ1(f, r), maxh = RMQ2(f, r);
			if (maxh - minh <= k) break;
			f++;
		}
	}
	printf("%d %d\n", maxl, (int)v.size());
	for (int i = 0; i < v.size(); i++) printf("%d %d\n", v[i].first + 1, v[i].second + 1);
	return 0;
}