#include <bits/stdc++.h>

using namespace std;

int t;
int k;
string s;
int a[100];
int x;
int stop;
int idxMax;

void stringToArr()
{
	for (int i = 0 ; i < s.length() ; i++)
	{
		int tmp = s[i] - '0';
		a[x] = tmp;
		x++;	
	}	
}

void Swap(int &u, int &v)
{
	int tmp = u;
	u = v;
	v = tmp;
}

void Xuat()
{
	for (int p = 0 ; p < x ; p++)
	{
		cout << a[p];
	}
	cout << endl;
}

void DeQuy(int i, int j, int l)
{
	if (l == k) Xuat();
	else
	{
		if (j == x-1) 
		{
			Swap(a[idxMax], a[i]);
			idxMax = i + 1;
			DeQuy(i++, i+2, l++);
		}
		else if (a[i] >= a[j] && j < x-1) DeQuy(i, j++, l);
		else if (a[i] < a[j] && j < x-1) 
		{
			idxMax = j;
			DeQuy(i, j++, l);
		}
	}
}


int main ()
{
	cin >> t;
	while (t--)
	{
		cin >> k;
		cin.ignore();
		cin >> s;
		
		x = 0;
		stop = 1;
		idxMax = 0;
		stringToArr();
		DeQuy(0,1,0);
	}
	return 0;
}
