#include <iostream>
#include<vector>
using namespace std;
void merge(int l,int mid,int r,vector<int> &arr){
    vector<int> temp;
    int left=l,right=mid+1;
    while(left<=mid && right<=r){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=r){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=l;i<=r;i++){
        arr[i]=temp[i-l];
    }
    
}
void mergeSort(int l,int r,vector<int> &arr){
    if(l==r){
        return ;
    }
    int mid=l+(r-l)/2;
    mergeSort(l,mid,arr);
    mergeSort(mid+1,r,arr);
    merge(l,mid,r,arr);
}


int main()
{
    vector<int> arr={7,4,5,6,3,1,23,1,2,4,5,9,5,3};
    mergeSort(0,arr.size()-1,arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
