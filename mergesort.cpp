#include<iostream>
using namespace std;

void merge(int *arr, int l, int r, int mid) {
    int pA1 = 0, pA2 = 0, cnt = l;
    int L[mid - l + 1], R[r - mid];

    for(int i = 0; i < mid - l + 1; i++) L[i] = arr[l + i];
    for(int j = 0; j < r - mid; j++) R[j] = arr[mid + 1 + j];

    while(pA1 < mid - l + 1 && pA2 < r - mid) {
        if(L[pA1] <= R[pA2]) {
            arr[cnt] = L[pA1];
            ++pA1;
        } else {
            arr[cnt] = R[pA2];
            ++pA2;
        }
        cnt++;
    }

    while(pA1 < mid - l + 1) arr[cnt++] = L[pA1++];
    while(pA2 < r - mid) arr[cnt++] = R[pA2++];
}

void printarr(int* arr, int start, int end) {
    cout << start << "  - " << end << endl;
    cout << "[ ";
    for(int i = start; i <= end; i++) cout << arr[i] << "  ,";
    cout << "]" << endl;
}

void mergesort(int arr[], int l, int r, int level) {
    if(l < r) {
        int mid = (l + r) / 2;

        cout << "action in L\n";
        printarr(arr, l, mid);
        mergesort(arr, l, mid, level + 1);

        cout << "action in R\n";
        printarr(arr, mid + 1, r);
        mergesort(arr, mid + 1, r, level + 1);

        merge(arr, l, r, mid);
    } else {
        cout << "return" << endl;
    }
}

int main() {
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << "bef sort = ";
    printarr(arr, 0, 9);
    mergesort(arr, 0, 9, 1);
    cout << "aft sort = ";
    printarr(arr, 0, 9);
    return 0;
}