#include <bits/stdc++.h>

using namespace std;

int t;
int m, n;
int a[105][105];
int Count;

void DiChuyen(int x, int y)
{
	if (x == m && y == n)
	{
		Count++;
	}
	
	if (x + 1 <= m)
	{
		DiChuyen(x+1, y);
	}
	
	if (y + 1 <= n)
	{
		DiChuyen(x, y+1);
	}
}

int main ()
{
	cin >> t;
	while (t--)
	{
		cin >> m >> n;
		for (int i = 1 ; i <= m ; i++)
		{
			for (int j = 1 ; j <= n ; j++)
			{
				cin >> a[i][j];
			}
		}
		
		Count = 0;
		DiChuyen(1,1);
		cout << Count << endl;
	}
	return 0;
}
