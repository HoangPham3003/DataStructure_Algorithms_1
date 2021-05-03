#include <bits/stdc++.h>

using namespace std;

int t;
int n, k;
int a[1005];
int stop = 1;

void Nhap()
{
	for (int i = 1 ; i <= k ; i++)
	{
		cin >> a[i];
	}
}

void Sinh()
{
	int indx = k;
	
	while (a[indx] == n-k+indx && indx > 0)
	{
		indx--;
	}
	
	if (indx == 0)
	{
		for (int i = 1 ; i <= k ; i++)
		{
			cout << i << " ";
		}
		cout << endl;
		stop = 0;
	}
	else
	{
		a[indx] += 1;
		
		for (int i = indx+1 ; i <= k ; i++)
		{
			a[i] = a[i-1] + 1;
		}
	}
}

void Xuat()
{
	for (int i = 1 ; i <= k ; i++)
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
		cin >> n >> k;
		Nhap();
		Sinh();
		if (stop == 1) Xuat();
	}
	return 0;
}
