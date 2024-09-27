#include<iostream>
using namespace std;

int sum(int arr[],int size){
    int ans=0;
    //base case
    if(size==0){
        ans=arr[0];
    }
    else
        ans=arr[size]+sum(arr,size-1);
        return ans ;
}

int main(){
    int arr[5]={3,2,5,1,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    int ans = sum(arr,size-1);
    cout<<ans;
    
    }
