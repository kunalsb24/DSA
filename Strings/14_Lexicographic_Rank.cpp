#include <iostream>
#include <string>

#define CHAR 256 // Number of ASCII characters

using namespace std;

// Helper function to calculate factorial using long long to prevent overflow
long long fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

// Function to find the Lexicographic rank of a string (Assumes distinct characters)
long long lexRank(string &str) { 
    long long res = 1; 
    int n = str.length();
    long long mul = fact(n);
    int count[CHAR] = {0};
    
    // Populate the count array
    for (int i = 0; i < n; i++) {
        count[str[i]]++;
    }
        
    // Calculate cumulative sum
    for (int i = 1; i < CHAR; i++) {
        count[i] += count[i - 1];
    }
        
    for (int i = 0; i < n - 1; i++) {
        mul = mul / (n - i);
        
        // count[str[i]-1] gives the number of characters strictly smaller than str[i]
        res = res + count[str[i] - 1] * mul;
        
        // Reduce count of the current character and all characters greater than it
        for (int j = str[i]; j < CHAR; j++) {
            count[j]--;
        }
    }
    return res; 
}

int main() {
    string str = "STRING";
    cout << "The lexicographic rank of " << str << " is: " << lexRank(str) << endl;
    return 0;
}