#include <bits/stdc++.h>

using namespace std;

int t;
int n, k;
int a[1005];
int b[1005];
int Count;


int kttong()
{
	int sum = 0;
	for (int u = 1 ; u <= n ; u++)
	{
		sum += (a[u]*b[u]);
	}
	if (sum == k) return 1;
	return 0;
}

void Xuat()
{
		int dem = 0;
		for (int u = 1 ; u <= n ; u++)
		{
			if (b[u] == 1)
			{
				dem++;
			}
		}
		
		int dem2 = 0;
		
		cout << "[";
		for (int u = 1 ; u <= n ; u++)
		{
			if (b[u] == 1)
			{
				dem2++;
				cout << a[u];
				if (dem2 != dem) cout << " ";
			}
		}
		cout << "]";
		cout << " ";
}

void Try(int i)
{
	for (int j = 1 ; j >= 0 ; j--)
	{
		b[i] = j;
		if (i == n)
		{
			if (kttong() == 1)
			{
				Count++;
				Xuat();
			}
		}
		else Try(i+1);
	}
}


int main ()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1 ; i <= n ; i++)
		{
			cin >> a[i];
		}
		
		sort(a+1, a+n+1);
		Count = 0;
		Try(1);
		if (Count == 0) cout << "-1";
		cout << endl;
	}
	return 0;
}
