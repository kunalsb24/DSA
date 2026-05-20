#include <iostream>
#include <unordered_map>
using namespace std;

//naive
/*
void printFreq(int arr[], int n){
    for(int i=0; i<n; i++){ // for every element

        // check if element is already processed
        bool flag = false;         
        for(int j=0; j<i; j++){  
            if(arr[i] == arr[j])   
            {
                flag = true;
                break;
            }
        }

        if(flag == true)
            continue;
        
        int freq = 1;
        for(int j = i+1; j<n; j++){
            if(arr[i]==arr[j])
                freq++;
        }

        cout << arr[i] << " " << freq << endl;
    }
    return 0;
}
*/

//hashing

void printFreq(int arr[], int n){
    unordered_map<int, int> h;
    for(int i=0; i<n; i++)
        h[arr[i]]++;
    
    for(auto e:h)
        cout << e.first << " " << e.second << endl;
}


int main(){
    int arr[] = {10,20,20,30,10}, n = 5;
    printFreq(arr,n);
    return 0;
}