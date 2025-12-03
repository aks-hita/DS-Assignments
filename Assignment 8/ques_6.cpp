#include<iostream>
#include<vector>
using namespace std;
class MinPriorityQueue {
    vector<int> heap;
    void heapifyUp(int i) {
        int parent = (i - 1) / 2;
        if (i > 0 && heap[i] < heap[parent]) {
            swap(heap[i], heap[parent]);
            heapifyUp(parent);
        }
    }
    void heapifyDown(int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int n = heap.size();

        if (left < n && heap[left] < heap[smallest])
            smallest = left;

        if (right < n && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }
public:
    void insert(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }
    int getTop() {
        if (heap.empty()) {
            cout << "priority Queue  empty";
            return -1;
        }
        return heap[0];
    }
    void extractTop() {
        if (heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
    void increaseKey(int i, int newValue) {
    if (newValue < heap[i]) {
        cout << " New value is smaller than current.\n";
        return;
    }
    heap[i] = newValue;
    heapifyUp(i); 
}
};
class MaxPriorityQueue {
    vector<int> heap;
    void heapifyUp(int i) {
        int parent = (i - 1) / 2;
        if (i > 0 && heap[i] > heap[parent]) {   // > for MAX HEAP
            swap(heap[i], heap[parent]);
            heapifyUp(parent);
        }
    }
    void heapifyDown(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int n = heap.size();
        if (left < n && heap[left] > heap[largest])
            largest = left;

        if (right < n && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }
public:
    void insert(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }
    int getTop() {
        if (heap.empty()) {
            cout << "Priority Queue empty\n";
            return -1;
        }
        return heap[0];  // largest
    }
    void extractTop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
    void increaseKey(int i, int newValue) {
        if (newValue < heap[i]) {   // can't decrease key in max heap
            cout << "New value is smaller than current.\n";
            return;
        }
        heap[i] = newValue;
        heapifyUp(i);
    }
};
int main(){
    return 0;
}