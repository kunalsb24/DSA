#include <iostream>
using namespace std;

void towerofHanoi(int n, char A, char B, char C){
    if(n==1){
        cout << "Move 1 from " << A << " to " << C  << endl;
        return;
    }
    towerofHanoi(n-1, A, C, B);
    cout << "Move "<<n << " from " << A << " to " << C << endl;
    towerofHanoi(n-1, B, A, C);

}

int main(){
    int n = 3;
    towerofHanoi(n, 'A', 'B', 'C');
    return 0;
}