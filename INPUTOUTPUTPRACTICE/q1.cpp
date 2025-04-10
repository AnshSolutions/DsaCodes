// You are given an array A of N integers. Your task is to sort the array based on the frequency of elements 
//in descending order. If two elements have the same frequency, the smaller number should come first.

// Input:

// The first line contains an integer T (number of test cases).
// Each test case contains an integer N (size of array).
// The next line contains N integers.
// Output:

// Print the sorted array for each test case.
#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>&a,pair<int,int>&b){
    if(a.second==b.second){
        return a.first<b.first;
    }
   return  a.second>b.second;
}
void solve(){
    int n;
    cin>>n;
    unordered_map<int,int>mp;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    vector<pair<int,int>>vec(mp.begin(),mp.end());
    sort(vec.begin(),vec.end(),compare);
    for(auto a:vec){
        cout<<a.first<<" ";
    }

    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
