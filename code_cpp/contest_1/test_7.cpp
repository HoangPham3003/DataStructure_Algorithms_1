#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int x = 1;
int stop = 1;
int a[100];

void KhoiTao()
{
	x = 1;
	a[1] = n;
}

void Xuat()
{
	cout << "(";
	for (int i = 1 ; i <= x ; i++)
	{
		cout << a[i];
		if (i != x) cout << " ";
	}
	cout << ")";
	cout << " ";
}

void Sinh()
{
	int D, R, S;
	int idx = x;
	
	while (a[idx] == 1 && idx >= 1)
	{
		idx--;
	}

	if (a[1] == 1) stop = 0;
	else
	{
		a[idx]-=1;
		D = x - idx + 1;
		R = D / a[idx];
		S = D % a[idx];
		x = idx;
		if (R > 0)
		{
			for (int j = idx + 1 ; j <= idx + R ; j++)
			{
				a[j] = a[idx];
			}
			x += R;
		}
		
		if (S > 0) 
		{
			x += 1;
			a[x] = S;
		}
	}
}

void Ctrinh()
{
	stop = 1;
	x = 1;
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
