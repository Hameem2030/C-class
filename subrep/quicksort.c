#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>
using namespace std;

 int partition(int arr[],int left,int right){
    int randomIndex = left + rand() % (right - left + 1);
    swap(arr[randomIndex], arr[left]);
    int pivot=arr[left];
    int i=left;
    int j=right;
    while(i<j){
        while(arr[i]<=pivot&&i<=right){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j],pivot);
    return j;

 }
 void quicksort(int arr,int left,int right){
    if(left<right){
        int pivot=partition(arr[],left,right);
        quicksort(arr[],left,pivot-1);
        quicksort(arr[],pivot-1,right);
    }
 }
 void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        cout<<endl;
    }
 }
 int main()
 {
     srand(time(0));
     int arr[]={10,5,6,7,1,2,4,5,6,3,4,2,54,6,55};
     int n=sizeof(arr);
     cout<<original array<< " ";
     print(arr,n);

     quicksort(arr,0,n-1);
     cout << "Sorted array:\n";
    printArray(arr, n);

    return 0;
 }
