#include <bits/stdc++.h>

using namespace std;

int t;
int a[10];
int vtriPtu[10]; // co 5 vtri
int vtriDau[10]; // co 4 ctri 
int chkPtu[10]; // co 5 vtri
bool acc;

void KhoiTao()
{
	acc = false;
	for (int i = 1 ; i <= 5 ; i++)
	{
		chkPtu[i] = 0;
	}
}

void TinhToan()
{
	int kq = a[vtriPtu[1]];
	int idx = 2;
	for (int l = 1 ; l <= 4 ; l++)
	{
		if (vtriDau[l] == 1)
		{
			kq = kq + a[vtriPtu[idx]];
		}
		else if (vtriDau[l] == 2)
		{
			kq = kq - a[vtriPtu[idx]];
		}
		else if (vtriDau[l] == 3)
		{
			kq = kq * a[vtriPtu[idx]];
		}
		idx++;
	}
	
	if (kq == 23) 
	{
		acc = true;
	}
}

void Try1(int v)
{
	for (int u = 1 ; u <= 3 ; u++)
	{
		vtriDau[v] = u;
		if (v == 4) 
		{
			TinhToan();
		}
		else Try1(v+1);
	}
}

void Try2(int i)
{
	for (int j = 1 ; j <= 5 ; j++)
	{
		if (chkPtu[j] == 0)
		{
			vtriPtu[i] = j;
			chkPtu[j] = 1;
			if (i == 5) 
			{
				Try1(1);
			}
			else Try2(i+1);
			chkPtu[j] = 0;
		}
	}
}

int main ()
{
	cin >> t;
	while (t--)
	{
		KhoiTao();
		for (int i = 1 ; i <= 5 ; i++)
		{
			cin >> a[i];
		}
		
		Try2(1);
		if (acc == true) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
