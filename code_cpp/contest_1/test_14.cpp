#include <bits/stdc++.h>

using namespace std;

int t;
int n, k;
int a[50];
int b[50];
int c[50];
int dem = 0;
int stop = 1;

int demSlg()
{
	dem = 0;
	for (int i = 1 ; i <= k ; i++)
	{
		if (b[a[i]] == 1 && c[a[i]] == 1) dem++;
	}
	return dem;
}

void KhoiTao()
{
	for (int i = 1 ; i <= 50 ; i++)
	{
		b[i] = 0;
		c[i] = 0;
	}
}

void Nhap()
{
	for (int i = 1 ; i <= k ; i++)
	{
		cin >> a[i];
		b[a[i]] = 1;
	}
}

void Sinh()
{
	int idx = k;
	while (a[idx] == n-k+idx && idx >= 1)
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
	Sinh();
	for (int i = 1 ; i <= k ; i++)
	{
		c[a[i]] = 1;
	}
	int res = demSlg();
	if (stop == 0) cout << k << endl;
	else cout << k-res << endl;	
}

int main ()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		KhoiTao();
		Nhap();
		Ctrinh();
	}
	return 0;
}
