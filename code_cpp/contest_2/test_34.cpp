#include <bits/stdc++.h>

using namespace std;

int t;
int a[100][100];
int hv[100];
bool cot[100] = {0};
bool cheoChinh[100] = {0};
bool cheoPhu[100] = {0};
int maxx;

void CheckSum()
{
	int sum = 0;
	for (int i = 1 ; i <= 8 ; i++)
	{
		sum += a[i][hv[i]];
	}
	
	if (sum > maxx) maxx = sum;
}

void Try(int i)
{
	for (int j = 1 ; j <= 8 ; j++)
	{
		if (cot[j] == 0 && cheoChinh[8+i-j] == 0 && cheoPhu[i+j-1] == 0)
		{
			hv[i] = j;
			cot[j] = 1;
			cheoChinh[8+i-j] = 1;
			cheoPhu[i+j-1] = 1;
			if (i == 8) CheckSum();
			else Try(i+1);
			cot[j] = 0;
			cheoChinh[8+i-j] = 0;
			cheoPhu[i+j-1] = 0;
		}
	}
}

int main ()
{
	cin >> t;
	while (t--)
	{
		for (int i = 1 ; i <= 8 ; i++)
		{
			for (int j = 1 ; j <= 8 ; j++)
			{
				cin >> a[i][j];
			}
		}
		
		maxx = 0;
		Try(1);
		cout << maxx << endl;
	}
	return 0;
}
