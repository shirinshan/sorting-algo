#include <iostream>
using namespace std;

void MaxHeapify(int A[], int n, int i)
{
    int largest;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && A[l] > A[largest])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    if (r < n && A[r] > A[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(A[i], A[largest]);
        MaxHeapify(A, n, largest);
    }
}

void heapSort(int A[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        MaxHeapify(A, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        MaxHeapify(A, i, 0);
    }
}

int main()
{
    int A[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int n = sizeof(A) / sizeof(A[0]);

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << "\t";
    }

    heapSort(A, n);

    cout << "\nSorted array is \n";

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << "\t";
    }
}
