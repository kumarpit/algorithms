#include<vector>
#include<iostream>

using namespace std;

void csort(vector<int> &arr) {
    int size = arr.size() + 1;
    vector<int> seen(size);

    for (int k=0; k < arr.size(); k++) {
        if (arr[k] > size - 1) {
            seen.resize(arr[k] + 1, 0);
        }
        seen[arr[k]]++;
    }

    int i = 0;
    int j = 0;
    while (j < seen.size()) {
        if (seen[j] == 0) {
            j++;
        } else {
            arr[i++] = j;
            seen[j]--;
        }
    }
}

int main() {
    vector<int> arr = {14,8,7,6,5,4,3,2,1};

    csort(arr);

    for (int i=0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }
}