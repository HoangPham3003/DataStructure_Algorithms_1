#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int a[20];
int stop = 1;

void Swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

void KhoiTao()
{
	for (int i = 1 ; i <= n ; i++)
	{
		a[i] = i;
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
	a[0] = n+1;
	while (a[idx] < a[idx-1] && idx > 0)
	{
		idx--;
	}
	
	if (idx == 0) stop = 0;
	else
	{
		int rem = n;
		idx-=1;
		while (a[rem] < a[idx])
		{
			rem--;
		}
		
		Swap(a[rem], a[idx]);
		
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
