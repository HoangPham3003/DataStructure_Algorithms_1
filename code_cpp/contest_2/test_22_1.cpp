#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int a[100][100];
int arr[105];
int Count;

void Xuat()
{
	bool chk = true;
	
	int h = 1; 
	int c = 1;
	
	for (int u = 1 ; u <= 2*n-2 ; u++)
	{
		if(arr[u] == 0) h+=1;
		else if (arr[u] == 1) c+=1;
		
		if (a[h][c] == 0 || h > n || c > n)
		{
			chk = false;
			break;
		}
	}
	
	if (chk == true)
	{
		Count++;
		for (int u = 1 ; u <= 2*n-2 ; u++)
		{
			if (arr[u] == 0) cout << "D";
			else if (arr[u] == 1) cout << "R";
		}
		cout << " ";
	}
}

void Try(int i)
{
	for (int j = 0 ; j <= 1 ; j++)
	{
		arr[i] = j;
		if (i == 2*n-2) Xuat();
		else Try(i+1);
	}
}

int main ()
{
	cin >> t;
	while (t--)
	{
		Count = 0;
		cin >> n;
		for (int i = 1 ; i <= n ; i++)
		{
			for (int j = 1 ; j <= n ; j++)
			{
				cin >> a[i][j];
			}
		}
		
		if (a[1][1] == 0)
		{
			cout << "-1";
		}
		else
		{
			Try(1);
			if (Count == 0) cout << "-1";
		}
		cout << endl;
	}
	return 0;
}
