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

void selection_sort(int a[], int n)
{
    int min_idx, temp;
    for (int i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
          if (a[j] < a[min_idx])
            min_idx = j;
        swap(a[i], a[min_idx]);
    }
}

void run(int n)
{
    int arr[n];
    fill_array(arr, n);

    fprintf(fp, "n = %d\t\t", n);

    int a[n];
    copy_array(arr, a, n);
    start = clock();
    bubble_sort(a, n);
    end = clock();
    tc = difftime(end, start);
    fprintf(fp, " %dms\t\t", tc);
    print_array(a, n);

    int b[n];
    copy_array(arr, b, n);
    start = clock();
    insertion_sort(b, n);
    end = clock();
    tc = difftime(end, start);
    fprintf(fp, " %dms\t\t", tc);

    int c[n];
    copy_array(arr, c, n);
    start = clock();
    selection_sort(c, n);
    end = clock();
    tc = difftime(end, start);
    fprintf(fp, " %dms\n", tc);
}

int main()
{
    fp = fopen("Output.txt", "w");
    if(fp == NULL) {
        printf("Error");
        exit(0);
    }

    fprintf(fp, "Size of the input\tBubble Sort\t Insertion Sort\t Selection Sort\n");

    run(5);
    run(10);
    run(15);

    fclose(fp);

    return 0;

}
