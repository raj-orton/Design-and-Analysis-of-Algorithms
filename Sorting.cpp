/*
Bubble sort
Insertion sort
Selection sort
Merge sort
Quick sort
*/

#include<bits/stdc++.h>
using namespace std;

int tc;
FILE *fp;
time_t start, end;

void print_array(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void copy_array(int src[], int tar[], int n)
{
    for(int i = 0; i < n; i++)
        tar[i] = src[i];
}

void fill_array(int a[], int n)
{
    for(int i = 0; i < n; i++)
        a[i] = (rand() % 100000) + 1;
}

void bubble_sort(int a[], int n)
{
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - 1 - i; j++)
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
}

void insertion_sort(int a[], int n)
{
   int j, key;
   for (int i = 1; i < n; i++)
   {
       key = a[i];
       j = i - 1;
       while(j >= 0 && a[j] > key) {
           a[j+1] = a[j];
           j = j - 1;
       }
       a[j+1] = key;
   }
}

void insertion_sort(int a[], int l, int r )
{
    for(int p = l + 1; p <= r; p++) {
        int tmp = a[p];
        int j;
        for(j = p; j > l && tmp < a[j-1]; j--)
            a[j] = a[j-1];
        a[j] = tmp;
    }
}


void selection_sort(int a[], int n)
{
    int min_idx, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
          if (a[j] < a[min_idx])
            min_idx = j;
        swap(a[i], a[min_idx]);
    }
}

void merge(int a[], int t[], int l, int r, int re)
{
    int le = r - 1;
    int cur = l;
    int len = re - l + 1;

    while(l <= le && r <= re) {
        if(a[l] < a[r])
            t[cur++] = a[l++];
        else
            t[cur++] = a[r++];
    }

    while(l <= le)
        t[cur++] = a[l++];

    while(r <= re)
        t[cur++] = a[r++];

    for(int i = 0; i < len; i++, re--)
        a[re] = t[re];
}

void merge_sort(int a[], int t[], int l, int r)
{
    if(l < r) {
        int mid = (l + r) / 2;
        merge_sort(a, t, 0, mid);
        merge_sort(a, t, mid + 1, r);
        merge(a, t, l, mid + 1, r);
    }
}

void merge_sort(int a[], int n)
{
    int t[n];
    merge_sort(a, t, 0, n - 1);
}

int median3(int a[], int l, int r)
{
    int mid = (l + r) / 2;
    if(a[mid] < a[l])
        swap(a[l], a[mid]);
    if(a[r] < a[l])
        swap(a[l], a[r]);
    if(a[r] < a[mid])
        swap(a[mid], a[r]);

    swap(a[mid], a[r-1]);
    return a[r-1];
}

const int CUTOFF = 30;
void quick_sort(int a[], int l, int r)
    {
        if(l + CUTOFF <= r)
        {
            int pivot = median3(a, l, r);

            int i = l, j = r - 1;

            for( ; ; )
            {
                while(a[++i] < pivot) { }
                while(a[--j] > pivot) { }
                if(i < j)
                    swap(a[i], a[j]);
                else
                    break;
            }

            swap(a[i], a[r-1]);

            quick_sort(a, l, i - 1);
            quick_sort(a, i + 1, r);
        }
        else
            insertion_sort(a, l, r);
    }


void quick_sort(int a[], int n)
{
    quick_sort(a, 0, n - 1);
}

void run(int n)
{
    int arr[n];
    fill_array(arr, n);

    fprintf(fp, "n = %d\t\t\t\t", n);

    int a[n];
    copy_array(arr, a, n);
    start = clock();
    bubble_sort(a, n);
    end = clock();
    tc = difftime(end, start);
    fprintf(fp, "%dms\t\t", tc);
    //print_array(a, n);

    int b[n];
    copy_array(arr, b, n);
    start = clock();
    insertion_sort(b, n);
    end = clock();
    tc = difftime(end, start);
    fprintf(fp, " %dms\t\t", tc);
    //print_array(b, n);

    int c[n];
    copy_array(arr, c, n);
    start = clock();
    selection_sort(c, n);
    end = clock();
    tc = difftime(end, start);
    fprintf(fp, " %dms\t\t", tc);
    //print_array(c, n);

    int d[n];
    copy_array(arr, d, n);
    start = clock();
    merge_sort(d, n);
    end = clock();
    tc = difftime(end, start);
    fprintf(fp, " %dms\t\t", tc);
    //print_array(d, n);

    int e[n];
    copy_array(arr, e, n);
    start = clock();
    quick_sort(e, n);
    end = clock();
    tc = difftime(end, start);
    fprintf(fp, " %dms\n", tc);
    //print_array(e, n);
}

int main()
{
    fp = fopen("Output.txt", "w");
    if(fp == NULL) {
        printf("Error");
        exit(0);
    }

    fprintf(fp, "Size of the input\t\tBubble Sort\t Insertion Sort\t Selection Sort\t Merge Sort\t Quick Sort\n");

    run(10);
    run(20);
    run(30);

    fclose(fp);

    return 0;

}
