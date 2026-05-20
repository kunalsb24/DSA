#include <bits/stdc++.h> 
using namespace std; 

// Naive Method
/*
bool isPalindrome(string &str){
    string rev = str;
    reverse(rev.begin(),rev.end());
    return (rev == str);
}
*/

bool isPalindrome(string &str){
    int begin = 0;
    int end = str.length() - 1;

    while(begin < end){
        if(str[begin] != str[end])
            return false;
        
        begin++;
        end--;
    }
    return true;

}

  int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    if (isPalindrome(str)) {
        cout << str << " is a palindrome." << endl;
    } else {
        cout << str << " is not a palindrome." << endl;
    }
    return 0;
}
