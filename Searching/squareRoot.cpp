#include<iostream>
using namespace std;

// Naive
// int squareRoot(int x){
//     int i = 1;
//     while(i*i<x)
//         i++;
//     return (i-1);
// }

//Efficient

int squareRoot(int x){
    int low = 0, high = x, ans = -1;
    while(low<=high){
        int mid = (low + high)/2;
        int mid_Sq = mid * mid;

        if(mid_Sq == x)
            return mid;
        
        else if(mid_Sq > x)
            high = mid - 1;
        
        else{
            low = mid + 1;
            ans = mid;
        }               
    }
        return ans;
}

int main(){
    
    int x = 9;
    cout << squareRoot(x);
    return 0;
}