#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int a[100][100];
char s[100];
bool chk;
bool mark[100][100];

void Xuat(int v)
{
	chk = true;
	for (int i = 0 ; i < v ; i++)
	{
		cout << s[i];
	}
	cout << " ";
}

void DiChuyen(int x, int y, int k)
{
	mark[1][1] = 1;
	if (x == n && y == n)
	{
		Xuat(k);
	}
	
	if (x + 1 <= n && a[x+1][y] == 1 && mark[x+1][y] == 0)
	{
		mark[x][y] = 1;
		s[k] = 'D';
		DiChuyen(x+1, y, k+1);
		mark[x+1][y] = 0;
	}
	
	if (y - 1 >= 1 && a[x][y-1] == 1 && mark[x][y-1] == 0)
	{
		mark[x][y] = 1;
		s[k] = 'L';
		DiChuyen(x, y-1, k+1);
		mark[x][y-1] = 0;
	}
	
	if (y + 1 <= n && a[x][y+1] == 1 && mark[x][y+1] == 0)
	{
		mark[x][y] = 1;
		s[k] = 'R';
		DiChuyen(x, y+1, k+1);
		mark[x][y+1] = 0;
	}
	
	if (x - 1 >= 1 && a[x-1][y] == 1 && mark[x-1][y] == 0)
	{
		mark[x][y] = 1;
		s[k] = 'U';
		DiChuyen(x-1, y, k+1);
		mark[x-1][y] = 0;
	}
}

int main ()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1 ; i <= n ; i++)
		{
			for (int j = 1 ; j <= n ; j++)
			{
				cin >> a[i][j];
				mark[i][j] = 0;
			}
		}
		
		chk = false;
		
		if (a[1][1] == 0)
		{
			cout << "-1";
		}
		else
		{
			DiChuyen(1,1,0);
			if (chk == false) cout << "-1";
		}
		cout << endl;
	}
	return 0;
}
