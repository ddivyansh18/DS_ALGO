#include <stdlib.h>
#include <stdio.h>

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

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

    mergeSort(arr, 0, n - 1);

    printf("\n Sorted array using MergeSort : ");
    for(i = 0; i < n; i++)
    printf("%d ", arr[i]);

    return 0;
}

//Merges subarrays arr[l..m],arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++ )
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + j + 1];

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
