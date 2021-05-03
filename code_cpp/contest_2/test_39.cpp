#include <bits/stdc++.h>

using namespace std;

int n;
int C[20][20];
int vtri[20];
bool chkVtri[20];
int Cmin;
int can;
int chiphi;

void KhoiTao()
{ 
	can = 0;
	chiphi = 10000;
	for (int i = 1 ; i <= n ; i++)
	{
		chkVtri[i] = 1;
	}
}

void FindCmin()
{
	Cmin = 10000;
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= n ; j++)
		{
			if (i != j && C[i][j] < Cmin)
			{
				Cmin = C[i][j];
			}
		}
	}
}

void UpdateChiphi()
{
	int sum = 0;
	sum = can + C[vtri[n]][vtri[1]];
	if (sum < chiphi)
	{
		chiphi = sum;
	}
}

void Try(int i)
{
	for (int j = 2 ; j <= n ; j++)
	{
		if (chkVtri[j] == 1)
		{
			vtri[i] = j;
			chkVtri[j] = 0;
			can = can + C[vtri[i-1]][vtri[i]];
			if (i == n) UpdateChiphi();
			else if (can + (n-i+1)*Cmin < chiphi)
			{
				Try(i+1);
			}
			chkVtri[j] = 1;
			can = can - C[vtri[i-1]][vtri[i]];
		}
	}
}

int main ()
{
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= n ; j++)
		{
			cin >> C[i][j];
		}
	}
	
	KhoiTao();
	FindCmin();
	vtri[1] = 1;
	Try(2);
	cout << chiphi;
	return 0;
}
