#include <iostream>
using namespace std;
int partition(int a[] , int l , int r){
    int i = l;
    int j = r;
    int pivot = i;
    while(true){
        while(a[pivot] <= a[j] && pivot != j) j--;
        
        if(pivot == j) break;
        else{
            int temp = a[pivot];
            a[pivot] = a[j];
            a[j] = temp;
            pivot = j;
        }
        
        while(a[pivot] >= a[i] && pivot != i) i++;
        
        if(pivot == i) break;
        else{
            int temp = a[pivot];
            a[pivot] = a[i];
            a[i] = temp;
            pivot = i;
        }
    }
    return pivot;
}
void quickSort(int a[] , int l , int r){
    if(l < r){
        int curr  = partition(a,l,r);
        quickSort(a,l, curr - 1);
        quickSort(a,curr + 1 , r);
    }
}
int main() {
    int a[] = {2 , -1 , 4 , 7 , 0};
    int n = sizeof(a) / sizeof(a[0]);
    quickSort(a,0,n-1);
    for(int i = 0 ; i < n ; i++) cout << a[i] << " ";
    cout << endl;
}
