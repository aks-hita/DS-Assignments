#include<iostream>
using namespace std;
void symmetricMatrix() {
    int n;
    cout << "\n(e) Symmetric Matrix\nEnter size of matrix: ";
    cin >> n;
    int size = n * (n + 1) / 2;
    int A[size];
    cout << "Enter lower triangular elements (including diagonal):\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            int index = i * (i - 1) / 2 + (j - 1);
            cout << "A[" << i << "," << j << "]: ";
            cin >> A[index];
        }
    }
    cout << "Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j)
                cout << A[i * (i - 1) / 2 + (j - 1)] << " ";
            else
                cout << A[j * (j - 1) / 2 + (i - 1)] << " ";
        }
        cout << endl;
    }
}
int main(){
    symmetricMatrix();
    return 0;
}
