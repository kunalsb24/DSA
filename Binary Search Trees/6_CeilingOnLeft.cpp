#include <iostream>
#include <set>
using namespace std;

void printCeiling(int arr[], int n) {

    set<int> s;

    cout << -1 << " ";

    s.insert(arr[0]);

    for (int i = 1; i < n; i++) {

        auto it = s.lower_bound(arr[i]);

        if (it == s.end())
            cout << -1 << " ";
        else
            cout << *it << " ";

        s.insert(arr[i]);
    }
}

int main() {

    int arr[] = {2,8,30,15,25,12};

    printCeiling(arr,6);
}