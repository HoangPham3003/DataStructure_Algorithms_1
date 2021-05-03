#include <bits/stdc++.h>

using namespace std;

int t;
int tt;
string s;
int a[1005];
int x = 1;
int stop = 1;

void Swap(int &u, int &v)
{
	int tmp = u;
	u = v;
	v = tmp;
}

void stringToArr()
{
	for (int i = 0 ; i < s.length() ; i++)
	{
		int tmp = s[i] - '0';
		a[x] = tmp;
		x++;
	}
}

void Xuat()
{
	cout << tt << " ";
	for (int i = 1 ; i <= x-1 ; i++)
	{
		cout << a[i];
	}
	cout << endl;
}

void Sinh()
{
	int idx = x-1;
	a[0] = 100;
	while (a[idx] <= a[idx-1] && idx >= 1)
	{
		idx--;
	}
	
	if (idx == 0) 
	{
		stop = 0;
		cout << tt << " " << "BIGGEST" << endl;
	}
	else
	{
		int rem = x-1;
		idx-=1;
		
		while (a[rem] <= a[idx])
		{
			rem--;
		}
		
		Swap(a[rem], a[idx]);
		
		int limitDown = idx + 1;
		int limitUp = x-1;
		
		while (limitDown <= limitUp)
		{
			Swap(a[limitDown], a[limitUp]);
			limitDown++;
			limitUp--;
		}
	}
}

void Ctrinh()
{
	stop = 1;
	stringToArr();
	Sinh();
	if (stop == 1) Xuat();
}

int main ()
{
	cin >> t;
	while (t--)
	{
		x = 1;
		cin >> tt;
		cin.ignore();
		cin >> s;
		cin.ignore();
		Ctrinh();
	}
	return 0;
}
