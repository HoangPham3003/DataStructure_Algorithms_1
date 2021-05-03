#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int x;
int a[100];
int vtri[100];
bool chk;
int tong;

void Xuat(int v)
{
	chk = true;
	cout << "[";
	for (int u = 1 ; u <= v ; u++)
	{
		cout << a[vtri[u]];
		if (u != v) cout << " ";
	}
	cout << "]";
	cout << " ";
}

void Try(int i, int k)
{
	for (int j = vtri[i-1] ; j <= n ; j++)
	{
		if (a[j] <= x)
		{
			vtri[i] = j;
			tong = tong + a[vtri[i]];
			if (tong == x) Xuat(k);
			else if (tong + a[vtri[i]] <= x)
			{
				Try(i+1, k+1);
			}
			tong = tong - a[vtri[i]];
		}
	}
}

int main ()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> x;
		for (int i = 1 ; i <= n ; i++)
		{
			cin >> a[i];
		}
		sort(a+1, a+n+1);
		vtri[0] = 1;
		chk = false;
		Try(1, 1);
		if (chk == false) cout << "-1";
		cout << endl;
	}
	return 0;
}
