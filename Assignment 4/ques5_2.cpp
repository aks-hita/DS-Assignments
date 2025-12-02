#include <iostream>
#include<queue>
using namespace std;
class StackOneQueue {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int n = q.size();   
        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (q.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }
    int top() {
        if (q.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return q.front();
    }  
};
int main() {
    StackOneQueue s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.top() << endl;  
    s.pop();                                     
    cout << "Top element after pop: " << s.top() << endl; 
    return 0;
}
