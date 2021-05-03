#include <bits/stdc++.h>

using namespace std;

int n;
int a[20][20];
int b[20];
int c[20][20];
long k;
int stop = 1;

void Swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

int chk()
{
	long sum = 0;
	int count1 = 0;
	for (int i = 1 ; i <= n ; i++)
	{
		sum += a[i][b[i]];
	}
	
	if (sum == k) return sum;
	return 0;
}

void Nhap()
{
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= n ; j++)
		{
			cin >> a[i][j];
		}
	}
}

void KhoiTao()
{
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= n ; j++)
		{
			c[i][j] = 0;
		}
	}
	for (int i = 1 ; i <= n ; i++)
	{
		b[i] = i;
	}
}

void Xuat()
{
	for (int i = 1 ; i <= n ; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
}

void Sinh()
{
	int idx = n;
	b[0] = n+1;
	while (b[idx] < b[idx-1] && idx >= 1)
	{
		idx--;
	}
	
	if (idx == 0) stop = 0;
	else
	{
		int rem = n;
		idx -= 1;
		while (b[rem] < b[idx])
		{
			rem--;
		}
		
		Swap(b[rem], b[idx]);
		
		int limitDown = idx+1;
		int limitUp = n;
		
		while (limitDown <= limitUp)
		{
			Swap(b[limitDown], b[limitUp]);
			limitDown++;
			limitUp--;
		}
	}
}

int demSlg()
{
	stop = 1;
	int dem = 0;	
	while (stop != 0)
	{
		int res = chk();
		if (res != 0) dem++;
		Sinh();
	}
	return dem;
}

void Ctrinh()
{
	int slg = demSlg();
	cout << slg << endl;
	KhoiTao();
	
	stop = 1;
	
	while (stop != 0)
	{
		int res = chk();
		if (res != 0) 
		{
			Xuat();
		}
		Sinh();
	}
}

int main ()
{
	cin >> n >> k;
	Nhap();
	KhoiTao();
	Ctrinh();
	return 0;
}
