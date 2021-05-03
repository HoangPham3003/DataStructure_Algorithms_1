#include <bits/stdc++.h>

using namespace std;

string s;
long long n;
vector <char> v;

void Xuat()
{
//	for (int i = 0 ; i < v.size() ; i++)
//	{
//		cout << v[i];
//	}
cout << v[n-1];
}

void stringToVector()
{
	for (int i = 0 ; i < s.length() ; i++)
	{
		v.push_back(s[i]);
	}
}

void NextString()
{
	v.push_back(v.back());
		
	long long len = v.size();
		
	for (int i = 0 ; i < len-2 ; i++)
	{
		v.push_back(v[i]);
	}
		
	if (v.size() < n) NextString();		
}

int main ()
{
	cin >> s;
	cin.ignore();
	cin >> n;
	
	stringToVector();
	NextString();
	Xuat();
	return 0;
}
