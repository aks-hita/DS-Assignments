#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) 
    cin >> arr[i];

    int distinctCount = 0;

    for (int i = 0; i < n; i++) {
        bool isDistinct = 1;
    
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = 0;
                break;
            }
        }
        if (isDistinct==1) 
        distinctCount++;
    }

    cout << "Total distinct elements: " << distinctCount << endl;
    return 0;
}
