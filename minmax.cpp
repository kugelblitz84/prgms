#include<iostream>
#include<utility>
using namespace std;

pair<int,int> MinMax(int arr[],int low,int high){
    pair<int,int> ans;
    if(low==high){
        ans.first=arr[low];
        ans.second=arr[low];
        return ans;
    }
    if(low == high-1){
        ans.first=min(arr[high],arr[low]);
        ans.second=max(arr[high],arr[low]);
        return ans;
    }
    pair<int,int> minmax1,minmax2;
    int mid=(high+low)/2;
    minmax1=MinMax(arr,low,mid);
    minmax2=MinMax(arr,mid+1,high);
    ans.first=min(minmax1.first,minmax2.first);
    ans.second=max(minmax1.second,minmax2.second);
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    int arr[n];
    cout<<"Enter the value of array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    pair<int,int> minmax;
    minmax=MinMax(arr,0,n-1);
    cout<<"Minimum value:"<<minmax.first<<"\nMaximum value:"<<minmax.second;
    return 0;
}