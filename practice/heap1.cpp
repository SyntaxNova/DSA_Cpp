#include<iostream>
using namespace std;

void maxheapify(int arr[] , int n , int i){
    int largest = i ;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest]){
        largest = left ;
    }
    if (right < n && arr[right] > arr[largest]){
        largest = right ;
    }
    if (largest!= i){
        swap(arr[i] , arr[largest]);
        maxheapify(arr , i , n);
    }
}

void buildheap(int arr[] , int n ){
    for(int i = n/2 -1 ; i >= 0 ; i--){
        maxheapify(arr , n , 0);
    }
}

void heapsort(int arr[] , int n){
    buildheap(arr , n);
    for(int i = n-1 ; i > 0 ; i--){
        swap(arr[0] , arr[i]);
        maxheapify(arr , i , 0);
    }
}

int main(){
    int n;
    

    cout<<"Enter size of Array : ";
    cin >> n ;

    int arr[n];

    for (int i = 0 ; i < n ; i++){
        cout<<"Enter int : ";
        cin>>arr[i];
    }
    cout<<"Original Array : ";
    for (int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapsort(arr , n );

    cout<<"Sorted Array : ";
    for (int i ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0 ;
}
