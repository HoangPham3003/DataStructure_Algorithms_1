#include <bits/stdc++.h>

using namespace std;

int t;
int n, p, s;
int a[500];
bool chksnt[500];
int vtri[500];
int x;
int dem;
int res[100][100];

void Sang()
{
	for (int i = 2 ; i <= sqrt(s) ; i++)
	{
		if (chksnt[i] == true)
		{
			for (int j = i*i ; j <= s ; j+=i)
			{
				chksnt[j] = false;
			}
		}
	}
}

void LocSnt()
{
	for (int i = p ; i <= s ; i++)
	{
		if (chksnt[i] == true)
		{
			a[x] = i;
			x++;
		}
	}
}

void Xuat()
{
	cout << dem << endl;
	
	for (int v = 1 ; v <= dem ; v++)
	{
		for (int o = 1 ; o <= n ; o++)
		{
			cout << res[v][o] << " ";
		}
		cout << endl;
	}
}

void kt()
{
	int sum = 0;
	for (int u = 1 ; u <= n ; u++)
	{
		sum = sum + a[vtri[u]];
	}
	
	if (sum == s)
	{
		dem++;
		for (int u = 1 ; u <= n ; u++)
		{
			res[dem][u] = a[vtri[u]];	
		}	
	}
}

void Try(int i)
{
	for (int j = vtri[i-1] + 1 ; j <= x-n+i ; j++)
	{
		vtri[i] = j;
		if (i == n) kt();
		else Try(i+1);
	}
}

int main ()
{
	cin >> t;
	while (t--)
	{
		dem = 0;
		cin >> n >> p >> s;
		for (int i = 2 ; i <= s ; i++)
		{
			chksnt[i] = true;
		}
		Sang();
		x = 1;
		LocSnt();
		x -= 1;
		
		vtri[0] = 0; 
		Try(1);
		Xuat();
	}
	return 0;
}
