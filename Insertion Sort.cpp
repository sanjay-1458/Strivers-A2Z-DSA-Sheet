#include<bits/stdc++.h>
void insertionSort(int arr[], int n)
{
    //write your code here
    for(int i=0;i<n-1;++i){
        int j=i+1;
        while(j-1>=0 && arr[j]<arr[j-1]){
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
}

void insertionSort(int arr[], int n)
{
    //write your code here
    for(int i=1;i<n;++i){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}


#include<bits/stdc++.h>
void insertionSort(int arr[], int n)
{
    for(int i=1;i<n;++i){
        int key=arr[i];
        int j=i;
        while(j>0 && arr[j]<arr[j-1]){
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
}
