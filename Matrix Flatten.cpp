#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
template <class type>
using matrix = vector<vector<vector<type>>>;

//converts index i, j, k of 3D matrix of size n * m * p to 1D index
//n can be removed from parameters as it is not used in the equation but kept for assertion
int convertIndex(int i, int j, int k,int n,int m,int p)
{
	assert(i>=0 && i < n && j>=0 && j < m && k>=0 && k < p);
	return i * m * p + j * p + k;
}

//creates a 3D matrix of size n * m * p and tests convertIndex function
template <typename T>
void testConvertIndex(int n,int m,int p)
{
	assert(n > 0 && m > 0 && p > 0);
	cout << "\nTesting convertIndex function\n";
	int start = -1;
    matrix<T> a(n, vector<vector<T>>(m, vector<T>(p)));
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
template <typename T>
vector<T> convertMatrix(matrix<T>& mat)
{
	int n = mat.size();
	int m = mat[0].size();
	int p = mat[0][0].size();
	vector<T> arr(n * m * p);
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
template <typename T>
void testConvertMatrix(int n, int m, int p)
{
	assert(n > 0 && m > 0 && p > 0);
	cout << "\nTesting convertMatrix\n";
	matrix<T> a(n, vector<vector<T>>(m, vector<T>(p)));
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
	vector<T> arr = convertMatrix<T>(a);
	int q = arr.size();
	for (int i = 0; i < q; i++)
	{
		assert(arr[i] == i);
		cout << arr[i] << endl;
	}
}
int main()
{
    testConvertIndex<int>(1,2, 5);
    testConvertIndex<char>(1,2, 5);
    testConvertIndex<double>(1,2, 5);
    testConvertMatrix<int>(3, 4, 5);
    testConvertMatrix<char>(3, 4, 5);
    testConvertMatrix<double>(3, 4, 5);
}