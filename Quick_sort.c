#include <stdio.h>

void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main()
{
    int n;
    printf(" Enter no. of elements to sort : ");
    scanf("%d", &n);
    int arr[n];
    int i;
    printf("\n Enter the elements : ");
    for(i = 0; i < n; i++)
    scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);

    printf("\n Sorted array using QuickSort : ");
    for(i = 0; i < n; i++)
    printf("%d ", arr[i]);

    return 0;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partiton(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partiton(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
