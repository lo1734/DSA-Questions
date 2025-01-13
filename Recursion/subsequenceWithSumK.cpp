
#include <iostream>
#include<vector>
using namespace std;

void fun(int idx,int sum,int t,vector<int> arr,vector<int> temp){
    if(sum==t){
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<" ";
        }
        cout<< endl;
        return;
    }
    temp.push_back(arr[idx]);
    sum+=arr[idx];
    fun(idx+1,sum,t,arr,temp);
    temp.pop_back();
    sum-=arr[idx];
    fun(idx+1,sum,t,arr,temp);
}

int main()
{
    std::cout<<"Hello World"<<endl;
    int n=10;
    int k=24;
    vector<int> arr={20,4,1,3,6,4,22,13,2,11};
    vector<int> temp;
    fun(0,0,k,arr,temp);
    return 0;
}
