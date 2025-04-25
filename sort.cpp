#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>

using namespace std;

int partition(vector<int> &arr,int low,int high){
    int i=low,j=high;
    int pivot=arr[low];
    while(j>i){
        while(arr[i]<=pivot) i++;
        while(arr[j]>pivot) j--;
        if(j>i) swap(arr[i],arr[j]);
        
    }
    swap(arr[low],arr[j]);
    return j;
}
void quicksort(vector<int> &arr,int low,int high) {
    if(high>low){
        int j=partition(arr,low,high);
        quicksort(arr,low,j-1);
        quicksort(arr,j+1,high);
    }
}

void bubble_sort(vector<int> &arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}

vector <int> merge(vector <int> left , vector <int> right){
    vector <int> merged_array;
    for(int i=0,j=0;(i<left.size() or j<right.size());){
            if((left[i]<right[j] or j==right.size()) and i<left.size()){
                merged_array.push_back(left[i]);
                i++;
            }else {
                merged_array.push_back(right[j]);
                j++;
            }   
    }
    return merged_array;
}
vector <int> merge_sort(vector<int> arr){
    int n=arr.size();
    if(n==1) return arr;
    int mid=(n-1)/2;
    vector <int> left(arr.begin(),arr.begin()+mid+1);
    vector <int> right(arr.begin()+mid+1,arr.end());
    vector <int> sorted_right=merge_sort(right);
    vector <int> sorted_left=merge_sort(left);
    vector <int> sorted_array = merge(sorted_left,sorted_right);
    return sorted_array;

}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) arr[i]=rand()%1000;

    clock_t start,end;
    double time;
    start=clock();
    quicksort(arr, 0,n-1);
    end=clock();
    time=(double)(end-start);
    cout<<"time taken for quick sort: "<<time/CLOCKS_PER_SEC<<" second";
    start=clock();
    bubble_sort(arr,n);
    end=clock();
    time=(double)(end-start);
    cout<<"\ntime taken for bubble sort: "<<time/CLOCKS_PER_SEC<<" second";
    start=clock();
    arr=merge_sort(arr);
    end=clock();
    time=(double)(end-start);
    cout<<"\ntime taken for merge sort: "<<time/CLOCKS_PER_SEC<<" second";

    // cout << "Sorted array: ";
    // for (int i = 0; i < n; ++i)
    //     cout << arr[i] << " ";
    // cout << endl;
    return 0;
}
