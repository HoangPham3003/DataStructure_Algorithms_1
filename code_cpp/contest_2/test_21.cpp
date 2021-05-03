#include <bits/stdc++.h>

using namespace std;

int t;
string s;
int res[20];
int chk[20];
int len;

void Xuat()
{
	for (int u = 1 ; u <= len ; u++)
	{
		cout << s[res[u]-1];
	}
	cout << " ";
}

void Try(int i)
{
	for (int j = 1 ; j <= len ; j++)
	{
		if (chk[j] == 0)
		{
			res[i] = j;
			chk[j] = 1;
			if (i == len) Xuat();
			else Try(i+1);
			chk[j] = 0;
		}
	}
}

int main()
{
	cin >> t;
	cin.ignore();
	while (t--)
	{
		cin >> s;
		
		len = s.length();
		for (int u = 0 ; u <= len ; u++)
		{
			chk[u] = 0;
		}
		Try(1);
		cout << endl;
	}
	return 0;
}
