#include <iostream>
using namespace std;

 // Naive

 int maxAppear(int left[], int right[], int n){
    int freq[100] = {0};
    for(int i=0; i<n; i++)
        for(int j=left[i]; j<=right[i]; j++)
            freq[j]+=1;
    
    int res = 0;
    for(int i=1; i<100; i++)
        if(freq[i]>freq[res])
            res=i;
    
    return res;
 }


 // Efficient -- using prefix sum

 int maxAppear(int left[], int right[], int n){
    int freq[101]={0};
    for(int i=0; i<n; i++){
        freq[left[i]]++;
        freq[right[i]+1]--;
    }

    int res=0;
    for(int i=1; i<100; i++){
        freq[i] = freq[i-1] + freq[i];
        if(freq[i]>freq[res])
            res=i;
    }
    return res;
 }


 int main(){
    int n = 3;
    int left[] = {1,2,4}, right[] = {4,5,7};
    cout << "Max Appearing element is " << maxAppear(left, right, n);
    return 0;
 }
