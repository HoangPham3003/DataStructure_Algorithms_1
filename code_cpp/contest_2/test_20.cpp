#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int a[100];
int limitDown;
int limitUp;

void Output(int x)
{
	cout << "[";
	for (int i = x ; i <= n ; i++)
	{
		cout << a[i];
		if (i != n) cout << " ";
	}
	cout << "]";
	cout << " ";
}

void NextGroup()
{ 	
	for (int i = limitDown ; i < limitUp ; i++)
	{
		n++;
		a[n] = a[i] + a[i+1];
	}
}

void Solve()
{
	int value = n;
	int count = 1; 
	int x = n;
	
	
	while (count <= value)
	{
		NextGroup();
		limitDown += x;
		limitUp = n;
		x -= 1;
		count++;
	}
	

	int idx = n;
	int tmp = 1;
	
	while (n >= 1)
	{
		Output(idx);
		n -= tmp;
		idx = n - tmp;
		tmp++;
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
			cin >> a[i];
		}
		
		limitDown = 1;
		limitUp = n;
		
		Solve();
		cout << endl;
	}
	return 0;
}
