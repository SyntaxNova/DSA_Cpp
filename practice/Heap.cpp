#include<iostream>
using namespace std;

void maxheapify(int arr[] , int n , int i){
    int largest = i ;
    int left = i*2 + 1 ;
    int right = i*2 + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if( largest != i){
        swap(arr[i], arr[largest]);
        maxheapify(arr , i , n);
    }
}

void buildheap(int arr[] , int n){
    for(int i = n/2 - 1 ; i >=0 ; i--){
        maxheapify(arr , n , 0);
    }
}

void heapsort(int arr[] , int n){
    buildheap(arr , n);
    for (int i = n-1 ; i > 0 ; i--){
        swap(arr[0] , arr[i]);
        maxheapify(arr , i , 0);
    }
}

int main(){
    int n ;

    cout<<"Enter Size of Array : ";
    cin>> n ;

    int arr[n];

    for(int i = 0 ; i < n ; i++){
        cout<<"Enter Int : ";
        cin>>arr[i];
        
    }
    
    cout<<"Original array : ";
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapsort(arr , n);

    cout<<"Sorted Array : ";
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
}












































































