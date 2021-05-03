#include <bits/stdc++.h>

using namespace std;

int n;
long s;
long a[50];
int b[50];
int cs;
int stop = 1;
int resMinSlg = 0;

long long tongTien(int x)
{
	long long sum = 0;
	for (int i = 1 ; i <= x ; i++)
	{
		sum += a[b[i]];
	}
	
	return sum;
}

void Nhap()
{
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
}

void KhoiTao(int u)
{
	for (int i = 1 ; i <= u ; i++)
	{
		b[i] = i;	
	}
}

void Xuat(int u)
{
	for (int i = 1 ; i <= u ; i++)
	{
		cout << b[i];
	}
	cout << endl;
}

void Sinh(int u)
{
	int idx = u;
	
	while (b[idx] == n-u+idx && idx >= 1)
	{
		idx--;
	}
	
	if (idx == 0) stop = 0;
	else
	{
		b[idx] += 1;
		for (int j = idx+1 ; j <= u ; j++)
		{
			b[j] = b[j-1] + 1;
		}
	}
}


int main ()
{
	cin >> n >> s;
	Nhap();

	int stop2 = 1;
	int cs = 1;
	while (stop2 != 0)
	{
		KhoiTao(cs);
		resMinSlg = cs;
		stop = 1;
		while (stop != 0)
		{
			long long tt = tongTien(cs);
			if (tt == s && cs <= resMinSlg)
			{
				resMinSlg = cs;
				stop2 = 0;
				break;
			}
			Sinh(cs);
		}
		cs++;
	}
	
	cout << resMinSlg;
	return 0;
}
