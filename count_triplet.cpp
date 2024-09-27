// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to count triplets with the
// given conditions
int CountTriplets(int arr[], int n)
{
	int cnt = 0;

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)

				// If it satisfy the
				// given conditions
				if (arr[k] < arr[i]
					&& arr[i] < arr[j]) {

					cnt += 1;
				}

	// Return the final count
	return cnt;
}

// Driver Code
int main()
{
	// Given array arr[]
	int arr[] = { 2, 5, 1, 3, 0 };

	int n = sizeof(arr) / sizeof(arr[0]);

	// Function Call
	cout << CountTriplets(arr, n)
		<< endl;
	return 0;
}
