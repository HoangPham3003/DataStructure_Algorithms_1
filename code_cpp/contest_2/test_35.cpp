#include <bits/stdc++.h>

using namespace std;

int n;
int k;
int s;
int a[100];
int Count;

void Kt()
{
	int sum = 0;
	for (int u = 1 ; u <= k ; u++)
	{
		sum += a[u];
	}
	if (sum == s) Count++;
}

void Try(int i)
{
	for (int j = a[i-1] + 1 ; j <= n-k+i ; j++)
	{
		a[i] = j;
		if (i == k) Kt();
		else Try(i+1);
	}
}

int main ()
{
	do 
	{
		cin >> n >> k >> s;
		if (n == 0 && k == 0 && s == 0) return 0;
		a[0] = 0;
		Count = 0;
		
		Try(1);
		cout << Count << endl;
	}
	while (n != 0 && k != 0 && s != 0);
	return 0;
}
