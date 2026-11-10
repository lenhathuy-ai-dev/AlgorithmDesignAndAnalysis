#include <iostream>

using namespace std;

bool isSorted(int a[], int n);
void showArr(int a[], int n);


void selectionSort(int a[], int n)
{
    for (int i = 0; i < n-1; ++i)
    {
        int min_index = i;
        for (int j = i+1; j < n; ++j)
            if (a[j] < a[min_index])
                min_index = j;
        swap(a[i], a[min_index]);
    }
}

int main()
{
    int a[] = {1, 2, 3, -2, 3, 6};
    int n = sizeof(a)/sizeof(a[0]);
    int b[] = {-99, 22, 33, 44, 11, 22};
    int m = sizeof(b)/sizeof(b[0]);

    cout << "Before: \n";

    cout << "Array A: ";
    showArr(a, n);
    if (isSorted(a, n))
        cout << "Array A is sorted!\n";
    else
        cout << "Array A is unsorted!\n";

    cout << "Array B: ";
    showArr(b, m);
    if (isSorted(b, m))
        cout << "Array B is sorted!\n";
    else
        cout << "Array B is unsorted!\n";

    selectionSort(a, n);
    selectionSort(b, m);

    cout << "\nAfter: \n";

    cout << "Array A: ";
    showArr(a, n);
    if (isSorted(a, n))
        cout << "Array A is sorted!\n";
    else
        cout << "Array A is unsorted!\n";

    cout << "Array B: ";
    showArr(b, m);
    if (isSorted(b, m))
        cout << "Array B is sorted!\n";
    else
        cout << "Array B is unsorted!\n";

    return 0;
}

bool isSorted(int a[], int n)
{
    for (int i = 0; i < n-1; ++i)
        if (a[i] > a[i+1])
            return false;
    return true;
}

void showArr(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << '\n';
}
