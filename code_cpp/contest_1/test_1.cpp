#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int a[1005];
string s;

void reverseToArr()
{
	n = s.length()-1;
	for (int i = s.length()-1 ; i >= 0 ; i--)
	{
		int tmp = s[i] - '0';
		a[n] = tmp;
		n--;
	}
}

void Xuat(int x)
{
	for (int i = 0 ; i < x ; i++)
	{
		cout << a[i];
	}
	cout << endl;
}

void Sinh(int x)
{
	int indx = x-1;
	
	while (a[indx] == 1 && indx >= 0)
	{
		a[indx] = 0;
		indx--;
	}
	
	a[indx] = 1;
}

int main ()
{
	cin >> t;
	cin.ignore();
	while (t--)
	{
		cin >> s;
		reverseToArr();
		int sz = s.length(); // do dai day nhi phan
		Sinh(sz);
		Xuat(sz);
		
	}
	return 0;
}
