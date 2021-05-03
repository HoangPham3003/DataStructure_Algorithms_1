#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int cs;
int a[100];
int stop = 1;
int stop2 = 1;


long long arrayToNum(int x)
{
	long long num = 0;
	for (int i = 1 ; i <= x ; i++)
	{
		num = num*10 + a[i];
	}
	return num;
}

void KhoiTao(int x)
{
	for (int i = 1 ; i <= x ; i++)
	{
		a[i] = 0;
	}
}

void Sinh(int x)
{
	int idx = x;
	while (a[idx] == 1 && idx >= 1)
	{
		a[idx] = 0;
		idx--;
	}
	
	if (idx == 0) stop = 0;
	else
	{
		a[idx] = 1;
	}
}

int main ()
{
	cin >> t;
	while (t--)
	{
		stop2 = 1;
		cin >> n;
		cs = 1;
		while (stop2 != 0)
		{
			KhoiTao(cs);
			stop = 1;
			while (stop != 0)
			{
				long long res = arrayToNum(cs);
				res *= 9;
				if (res != 0 && res%n==0) 
				{
					cout << res << endl;
					stop2 = 0;
					break;
				}
				Sinh(cs);
			}
			cs++;
		}
	}
	return 0;
}
