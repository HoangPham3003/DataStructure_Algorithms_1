#include <bits/stdc++.h>

using namespace std;

int t;
string s;
int a[1005];
int b[1005];
int x = 0;

void stringToArr()
{
	x = 0;
	for (int i = 0 ; i < s.length() ; i++)
	{
		int tmp = s[i] - '0';
		a[x] = tmp;
		x++;
	}
}

void Xuat()
{
	for (int i = 0 ; i < x ; i++)
	{
		cout << b[i];
	}
	cout << endl;
}

void Sinh()
{
	b[0] = a[0];
	for (int i = 1 ; i < x ; i++)
	{
		b[i] = a[i-1] + a[i];
		if(b[i] == 2) b[i] = 0;	
	} 
}

void Ctrinh()
{
	x = 1;
	stringToArr();
	Sinh();
	Xuat();
}

int main ()
{
	cin >> t;
	cin.ignore();
	while (t--)
	{
		cin >> s;
		Ctrinh();
	}
	return 0;
}
