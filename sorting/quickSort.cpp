#include <iostream>
#include <vector>
using namespace std;
int fun(int l,int r,vector<int> &arr){
    int pivot=arr[l];
    int i=l,j=r;
    while(i<j){
        while(arr[i]<=pivot&&i<r) i++;
        while(arr[j]>pivot&&j>l) j--;
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[l],arr[j]);
    return j;
}
void qs(int l,int r,vector<int> &arr){
    if(l==r) return ;
    if(l<r){
        int p=fun(l,r,arr);
        qs(l,p-1,arr);
        qs(p+1,r,arr);
    }
}

int main()
{
    vector<int> arr={6,2,8,3,5,2,1};
    qs(0,arr.size()-1,arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
