#include <bits/stdc++.h>

using namespace std;

int t;
int n, k;
int stop = 1;
int a[20];

void KhoiTao()
{
	for (int i = 1 ; i <= k ; i++)
	{
		a[i] = i;
	}
}

void Xuat()
{
	for (int i = 1 ; i <= k ; i++)
	{
		cout << a[i];
	}
	cout << " ";
}

void Sinh()
{
	int idx = k;
	while (a[idx] == n-k+idx && idx > 0)
	{
		idx--;
	}
	
	if (idx == 0) stop = 0;
	else
	{
		a[idx] += 1;
		
		for (int i = idx+1 ; i <= k ; i++)
		{
			a[i] = a[i-1] + 1;
		}
	}
}

void Ctrinh()
{
	stop = 1;
	while (stop != 0)
	{
		Xuat();
		Sinh();
	}
}

int main ()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		KhoiTao();
		Ctrinh();
		cout << endl;
	}
	return 0;
}
