#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int a[1005];
int stop = 1;

void Swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

void Nhap()
{
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
}

void Sinh()
{
	int idx = n;
	a[0] = n+1;
	while (a[idx] < a[idx-1] && idx > 0)
	{
		idx--;
	}
	
	if (idx == 0)
	{
		for (int i = 1 ; i <= n ; i++)
		{
			cout << i << " ";
		}
		cout << endl;
		stop = 0;
	}
	else
	{
		int rem = n;
		idx -= 1;
		while (a[idx] > a[rem])
		{
			rem--;
		}
		
		Swap(a[idx], a[rem]);
		
		int limitDown = idx + 1;
		int limitUp = n;
		while (limitDown <= limitUp)
		{
			Swap(a[limitDown], a[limitUp]);
			limitDown++;
			limitUp--;
		}
	}
}

void Xuat()
{
	for (int i = 1 ; i <= n ; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main ()
{
	cin >> t;
	while (t--)
	{
		stop = 1;
		cin >> n;
		Nhap();
		Sinh();
		if (stop != 0) Xuat();
	}
	return 0;
}
