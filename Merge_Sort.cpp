//https://practice.geeksforgeeks.org/problems/merge-sort/1


#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
public:
    void merge(int arr[], int L, int mid, int R)
    {
        // Your code here

        int n1, n2;
        n1 = mid - L + 1;
        n2 = R - mid;
        int l[n1], r[n2];
        for (int i = 0; i < n1; i++)
            l[i] = arr[L + i];
        for (int i = 0; i < n2; i++)
            r[i] = arr[mid + i + 1];
        int i = 0, j = 0; int k = L;
        while (i < n1 && j < n2)
        {
            if (l[i] <= r[j])
                arr[k++] = l[i++];
            else
                arr[k++] = r[j++];
        }

        while (i < n1)
        {
            arr[k++] = l[i++];
        }
        while (j < n2)
        {
            arr[k++] = r[j++];
        }

    }
public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if (l >= r)
            return;
        {
            int mid = l + (r - l) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }
};

// { Driver Code Starts.


int main()
{
    int n, T, i;

    scanf("%d", &T);

    while (T--) {

        scanf("%d", &n);
        int arr[n + 1];
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        Solution ob;
        ob.mergeSort(arr, 0, n - 1);
        printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends
