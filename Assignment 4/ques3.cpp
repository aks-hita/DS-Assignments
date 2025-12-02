#include <iostream>
#include<queue>
using namespace std;
void interleaveQueue(queue<int> & q) {
    int n = q.size();
    queue<int> firstHalf;
    queue<int> secondHalf;
    for (int i = 0; i < n/2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }
    while (q.empty()==false) {
        secondHalf.push(q.front());
        q.pop();
    }
    while (firstHalf.empty()==false && secondHalf.empty()==false) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(secondHalf.front());
        secondHalf.pop();
    }
    while(secondHalf.empty()==false) {
        q.push(secondHalf.front());
        secondHalf.pop();
    }
}
int main() {
    queue<int> q;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    //OG QUEUE 4 7 11 20 5 
    interleaveQueue(q);
    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}