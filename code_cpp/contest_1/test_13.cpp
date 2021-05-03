#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[100];
int stop = 1;
int res = 0;

int chk()
{
	int dem1 = 0;
	int dem2 = 0;
	
	for (int i = 1 ; i <= n ; i++)
	{
		if (a[i] == 0)
		{
			dem1 = 0;
			while (a[i] == 0)
			{
				dem1++;
				i++;
				if (dem1 > k) return 0;
			}
			if (dem1 == k) dem2++;
		}

		dem1 = 0;
	}
	
	if (dem2 == 1) return 1;
	return 0;
}


void KhoiTao()
{
	a[n+1] = 1;
	for (int i = 1 ; i <= n ; i++)
	{
		a[i] = 0;
	}
}

void Xuat()
{
	for (int i = 1 ; i <= n ; i++)
	{
		if (a[i] == 0) cout << "A";
		else if (a[i] == 1) cout << "B";
	}
	cout << endl;
}

void Sinh()
{
	int idx = n;
	while (a[idx] == 1 && idx >= 1)
	{
		a[idx] = 0;
		idx--;
	}
	
	if (idx == 0) stop = 0;
	else 
	{
		a[idx] = 1;
	}
}

int demSlg()
{
	stop = 1;
	int dem = 0;
	
	while (stop != 0)
	{
		if (chk() == 1) 
		{
			dem++;
		}
		Sinh();
	}
	return dem;
}

void Ctrinh()
{
	res = demSlg();
	cout << res << endl;
	KhoiTao();
	stop = 1;
	
	while (stop != 0)
	{
		if (chk() ==1) 
		{
			Xuat();
		}
		Sinh();
	}
}

int main ()
{
	cin >> n >> k;
	KhoiTao();
	Ctrinh();
	return 0;
}
