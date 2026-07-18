#include <bits/stdc++.h> 
using namespace std; 

// Method 1 - Sorting

// int main() 
// { 
//     int n=5;
//     int cost[n]={1,12,5,111,200};
//     int sum=10;
    
//     int res=0;
//     sort(cost,cost+n);
//     for(int i=0;i<n;i++){
//         if(cost[i]<=sum){
//             sum-=cost[i];
//             res++;
//         }else{
//             break;
//         }
//     }
//     cout<<res;
//     return 0;
// } 

//------------------------------------------------------------------

// Method 2 - Heap

int main() 
{ 
    int n=5;
    int cost[n]={1,12,5,111,200};
    int sum=10;
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    int res=0;
    for(int i=0;i<n;i++)
        pq.push(cost[i]);
    
    for(int i=0;i<n;i++){
        if(pq.top()<=sum){
            sum-=pq.top();
            pq.pop();
            res++;
        }else{
            break;
        }
    }
    cout<<res;
    return 0;
} 
