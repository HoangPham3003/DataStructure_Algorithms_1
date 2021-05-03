#include <bits/stdc++.h>

using namespace std;

int t;
int n, m;
int a[100][100]; // ma tran ke
bool chk[100][100];
int u, v;
int vtri[100]; // duong di 
int len;

void KhoiTao()
{
	len = 0;
	for (int i = 0 ; i < 20 ; i++)
	{
		for (int j = 0 ; j < 20 ; j++)
		{
			a[i][j] = 0;
			chk[i][j] = 0;	
		}
	}
}

void Try(int i, int k)
{
	for (int j = 1 ; j <= n-1 ; i++)
	{
		if (a[vtri[i-1]][j] == 1 && chk[vtri[i-1]][j] == 0)
		{
			vtri[i] = j;
			chk[vtri[i-1]][j] = 1;
			chk[j][vtri[i-1]] = 1;
			if (k + 1 > len) len = k+1;
			else if (k + 1 <= m)Try(i+1, k+1);
			chk[vtri[i-1]][j] = 0;
			chk[j][vtri[i-1]] = 0;
		}
	}
}

int main ()
{
	cin >> t;
	while (t--)
	{
		KhoiTao();
		cin >> n >> m;
		while (m--)
		{
			cin >> u >> v;
			a[u][v] = 1;
			a[v][u] = 1;
		}
		
//		for (int i = 0 ; i < n ; i++)
//		{
//			for (int j = 0 ; j < n ; j++)
//			{
//				cout << a[i][j] << " ";
//			}
//			cout << endl;
//		}
		
		vtri[0] = 0;
		Try(1, 0);
		cout << len << endl;
	}
	return 0;
}
