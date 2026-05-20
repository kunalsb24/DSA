#include <bits/stdc++.h> 
#include <iostream>
#include <string>
#include <algorithm> // For std::reverse

using namespace std;

// Efficient Solution: O(n) Time, O(1) space

// Pass the string by reference (&) so we modify the original
void reverseWords(string &s) {
    int n = s.length();
    int start = 0;
    
    for (int end = 0; end < n; end++) {
        // When we hit a space, reverse the word we just passed
        if (s[end] == ' ') {
            // std::reverse takes iterators (start, end)
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
    }
    
    // Reverse the very last word (since it isn't followed by a space)
    reverse(s.begin() + start, s.end());
    
    // Reverse the entire string
    reverse(s.begin(), s.end());
}

int main() { 
    string s = "Welcome to Gfg";
    
    cout << "Original string: " << s << endl;
    
    // Modify the string directly in place
    reverseWords(s);
    
    cout << "After reversing: " << s << endl;
    
    return 0; 
}