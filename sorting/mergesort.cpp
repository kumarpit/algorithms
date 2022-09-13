#include<vector>
#include<iostream>

using namespace std;

// don't forget your elses!
void merge(vector<int> &arr, int lo, int mid, int high) {
    vector<int> res;

    int p1 = lo;
    int p2 = mid + 1;

    while (p1 <= mid || p2 <= high) {
        if (p1 >= mid + 1) {
            res.push_back(arr[p2]);
            p2++;
        } else if (p2 >= high + 1) {
            res.push_back(arr[p1]);
            p1++;
        } else if (arr[p1] > arr[p2]) {
            res.push_back(arr[p2]);
            p2++;
        } else {
            res.push_back(arr[p1]);
            p1++;
        }
    }

    for (int i=0; i < res.size(); i++) {
        arr[lo + i] = res[i];
    }
}

void mergesort(vector<int> &arr, int lo, int high) {
    if (lo == high) {
        return;
    }
    int mid = (lo + high) / 2;
    
    mergesort(arr, lo, mid);
    mergesort(arr, mid + 1, high);

    merge(arr, lo, mid, high);
}

int main() {
    vector<int> arr = {8,5,3,1};
    mergesort(arr, 0, arr.size()-1);
    
    for (int i=0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }
}