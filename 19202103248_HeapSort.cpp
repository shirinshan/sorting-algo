#include <iostream>
using namespace std;

//                                       Swap function so we can use it later on

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    //                                  Here it will find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    //                                         Here it will swap and heapifying if root is not largest
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

//                                          It is used to print the function

void show(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout<<arr[i]<<" ";
        cout<<"\n";
}

//                                                      HeapSort Main Funtion

void heapSort(int arr[], int n)
{
    // Generate max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        show(arr, n);

        // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
}

//                                                  Main funtion, Compiler will start compiling from here

int main()
{
    int arr[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\nUnsorted array is \n";

    // Printing Unsorted Array
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << "  ";
    }
    cout<<endl;
    //Calling the HeapSort Funtion
    heapSort(arr, n);

    cout << "\nSorted array is \n";
    //Calling the Print Funtion
    show(arr, n);
}