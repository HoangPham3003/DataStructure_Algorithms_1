#include <bits/stdc++.h>

using namespace std;

int n;
int hv[100];
bool cot[100] = {0};
bool cheoChinh[100] = {0};
bool cheoPhu[100] = {0};
int res;

void Try(int i)
{
	for (int j = 1 ; j <= n ; j++)
	{
		if (cot[j] == 0 && cheoChinh[n+i-j] == 0 && cheoPhu[i+j-1] == 0)
		{
			hv[i] = j;
			cot[j] = 1;
			cheoChinh[n+i-j] = 1;
			cheoPhu[i+j-1] = 1;
			if (i == n) res++;
			else Try(i+1);
			cot[j] = 0;
			cheoChinh[n+i-j] = 0;
			cheoPhu[i+j-1] = 0;
		}
	}
}

int main ()
{
	cin >> n;
	res = 0;
	Try(1);
	cout << res;
	return 0;
}
