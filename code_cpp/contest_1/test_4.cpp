#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int a[20];
int stop = 1;

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
		if (a[i] == 0) cout << 'A';
		else cout << 'B';
	}
	cout << " ";
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
