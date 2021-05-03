#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int a[20];
int b[20];
int stop = 1;

void KhoiTao()
{
	for (int i = 1 ; i <= n ; i++)
	{
		a[i] = 0;
		b[i] = 0;
	}
}

void Xuat()
{
	for (int i = 1 ; i <= n ; i++)
	{
		cout << a[i];
	}
	cout << " ";
}

void Sinh()
{
	int idx = n;
	while (b[idx] == 1 && idx >= 1)
	{
		b[idx] = 0;
		idx--;
	}
	
	if (idx == 0) stop = 0;
	else
	{
		if (a[idx] == 0) a[idx] = 1;
		else if (a[idx] == 1) a[idx] = 0;
		b[idx] = 1;
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
		cin >> n;
		KhoiTao();
		Ctrinh();
		cout << endl;
	}
	return 0;
}
