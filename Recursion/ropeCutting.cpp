#include <iostream>
#include <algorithm> // For max function
using namespace std;

int maxCuts(int n, int a, int b, int c) {
    // Base Case 1: Rope is successfully cut completely
    if(n == 0)
        return 0;
    
    // Base Case 2: Rope length became negative (Invalid cut)
    if(n < 0)
        return -1;

    // Recursive Step: Try all 3 cuts
    int resA = maxCuts(n-a, a, b, c);
    int resB = maxCuts(n-b, a, b, c);
    int resC = maxCuts(n-c, a, b, c);

    // Find the maximum of the valid results
    int res = max(resA, max(resB, resC));

    // If res is -1, it means no valid cut was possible from this point
    if(res == -1)
        return -1;

    // Add 1 to the valid maximum result
    return res + 1;
}

int main() {
    int n = 23, a = 12, b = 9, c = 11;
    cout << "Max pieces: " << maxCuts(n, a, b, c);
    return 0;
}