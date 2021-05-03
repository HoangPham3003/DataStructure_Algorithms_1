#include <bits/stdc++.h>

using namespace std;

int t;
int n, k;
int a[20];
int stop = 1;

int ktbit()
{
	int dem = 0;
	for (int i = 0 ; i < n ; i++)
	{
		if (a[i] == 1) dem++;
	}
	if (dem == k) return 1;
	return 0;
}

void KhoiTao()
{
	for (int i = 0 ; i < n ; i++)
	{
		a[i] = 0;
	}
}

void Xuat()
{
	for (int i = 0 ; i < n ; i++)
	{
		cout << a[i];
	}
	cout << endl;
}

void Sinh()
{
	int idx = n-1;
	while (a[idx] == 1 && idx >= 0)
	{
		a[idx] = 0;
		idx--;
	}
	
	if (idx == -1) stop = 0;
	else
	{
		a[idx] = 1;
	}
}

void Ctrinh()
{
	stop = 1;
	while (stop != 0)
	{
		if (ktbit() == 1)
		{
			Xuat();
		}
		Sinh();
	}
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		KhoiTao();
		Ctrinh();
	}
	return 0;
}
