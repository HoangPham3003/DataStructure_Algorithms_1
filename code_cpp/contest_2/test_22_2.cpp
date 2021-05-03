#include <bits/stdc++.h>

using namespace std;

int t;
char s[100];
int n;
int a[100][100];
bool Count;

void Xuat(int v)
{
	for (int i = 0 ; i < v ; i++)
	{
		cout << s[i];
	}
	Count = true;
	cout << " ";
}

void DiChuyen(int x, int y, int k)
{
	if (x == n && y == n)
	{
		Xuat(k);
		return;
	}
	
	if (x + 1 <= n && a[x+1][y] == 1)
	{
		s[k] = 'D';
		DiChuyen(x+1, y, k+1);
	}
	
	if (y + 1 <= n && a[x][y+1] == 1)
	{
		s[k] = 'R';
		DiChuyen(x, y+1, k+1);
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
			}
		}
		
		Count = false;
		
		if (a[1][1] == 0)
		{
			cout << "-1";
		}
		else
		{
			DiChuyen(1,1,0);
			if (Count == false) cout << "-1";
		}
		cout << endl;
	}	
	return 0;
}
