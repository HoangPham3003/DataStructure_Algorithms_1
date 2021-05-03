#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int a[20];

void Input()
{
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
}

void Output()
{
	cout << "[";
	for (int i = 1 ; i <= n ; i++)
	{
		cout << a[i];
		if (i != n) cout << " ";
	}
	cout << "]";
	cout << endl;
}

void Solve()
{
	while (n > 1)
	{
		for (int i = 1 ; i <= n ; i++)
		{
			a[i] = a[i] + a[i+1];
		}
		n--;
		Output();
	}
}

int main ()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		Input();
		Output();
		Solve();
	}
	return 0;
}
