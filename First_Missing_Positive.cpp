/*
Problem Statement:
Given an unsorted integer array
return the smallest missing positive integer.

Sample input:
4, [3,4,-1,1]

Sample Output:
2

*/
//contributors: Udit Singla

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int first_missing_positive(vector<int>& nums) {
        int i=0, n= nums.size();
        while(i<n){
            if(nums[i]>=1 && nums[i]<=n && nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }else i++;
        }
        for(int i=0; i<n; i++){
            if(nums[i] != i+1)return i+1;
        }
        return n+1;
    }


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<first_missing_positive(arr) << endl;
    return 0;
}
