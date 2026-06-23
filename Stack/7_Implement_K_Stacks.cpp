#include <iostream>
using namespace std;

class KStacks {
    int *arr;      // stores actual elements
    int *top;      // top index of each stack
    int *next;     // next free or next stack element

    int n, k;
    int freeTop;

public:
    KStacks(int K, int N) {
        k = K;
        n = N;

        arr = new int[n];
        top = new int[k];
        next = new int[n];

        // initialize all stacks as empty
        for (int i = 0; i < k; i++)
            top[i] = -1;

        // create free list
        for (int i = 0; i < n - 1; i++)
            next[i] = i + 1;

        next[n - 1] = -1;

        freeTop = 0;
    }

    bool isFull() {
        return (freeTop == -1);
    }

    bool isEmpty(int sn) {
        return (top[sn] == -1);
    }

    void push(int x, int sn) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }

        int i = freeTop;

        freeTop = next[i];

        arr[i] = x;

        next[i] = top[sn];

        top[sn] = i;
    }

    int pop(int sn) {
        if (isEmpty(sn)) {
            cout << "Stack Underflow\n";
            return -1;
        }

        int i = top[sn];

        top[sn] = next[i];

        next[i] = freeTop;

        freeTop = i;

        return arr[i];
    }

    ~KStacks() {
        delete[] arr;
        delete[] top;
        delete[] next;
    }
};

int main() {
    KStacks ks(3, 10);

    ks.push(10, 0);
    ks.push(20, 0);

    ks.push(50, 1);
    ks.push(60, 1);

    ks.push(100, 2);

    cout << ks.pop(0) << endl; // 20
    cout << ks.pop(1) << endl; // 60
    cout << ks.pop(2) << endl; // 100

    return 0;
}