#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k,i;
        cin>>k>>n;
        int arr[n];
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        priority_queue<int,vector<int>,greater<int>> stream;
        for(i=0;i<n;i++){
            pq.push(arr[i]);
            if(pq.size()<k){
                cout<<-1<<" ";
            }
            else if(pq.size()==k){
                cout<<pq.top()<<" ";
            }
            else{
                pq.pop();
                cout<<pq.
            }
        }
    }
}
