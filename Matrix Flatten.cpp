#include <bits/stdc++.h>
#define Go ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
#define file ifstream cin ("input.txt");ofstream cout("output.txt")
#define vi vector<int>
#define endl "\n"
#define ret(x) {cout << x;return 0;}
using namespace std;
typedef long long ll;
typedef vector<vector<vi>> matrix;

//converts index i, j, k of 3D matrix of size n * m * p to 1D index
//n can be removed from parameters as it is not used in the equation but kept for assertion
int convertIndex(int i, int j, int k,int n,int m,int p)
{
	assert(i>=0 && i < n && j>=0 && j < m && k>=0 && k < p);
	return i * m * p + j * p + k;
}

//creates a 3D matrix of size n * m * p and tests convertIndex function
void testConvertIndex(int n,int m,int p)
{
	assert(n > 0 && m > 0 && p > 0);
	cout << "\nTesting convertIndex function\n";
	int start = -1;
	matrix a(n, vector<vi>(m, vi(p)));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < p; k++)
			{
				int temp = convertIndex(i, j, k, n, m, p);
				assert(++start == temp);
				cout << temp << endl;
			}
		}
	}
}

//converts 3D matrix of size n * m * p to 1D array of size q
vi convertMatrix(matrix& mat)
{
	int n = mat.size();
	int m = mat[0].size();
	int p = mat[0][0].size();
	vi arr(n * m * p);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < p; k++)
			{
				arr[convertIndex(i, j, k, n, m, p)] = mat[i][j][k];
			}
		}
	}
	return arr;
}

//creates a 3D matrix of size n * m * p and tests convertMatrix function
void testConvertMatrix(int n, int m, int p)
{
	assert(n > 0 && m > 0 && p > 0);
	cout << "\nTesting convertMatrix\n";
	matrix a(n, vector<vi>(m, vi(p)));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < p; k++)
			{
				a[i][j][k] = convertIndex(i, j, k, n, m, p);
			}
		}
	}
	vi arr = convertMatrix(a);
	int q = arr.size();
	for (int i = 0; i < q; i++)
	{
		assert(arr[i] == i);
		cout << arr[i] << endl;
	}
}

int main()
{
	testConvertIndex(1,2, 5);
	testConvertMatrix(3, 4, 5);
}