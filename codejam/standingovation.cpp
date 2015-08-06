#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1001
using namespace std;

int main() {
    int t;
    int max, shyness, friends, sum;
    cin >> t;
    for (int i = 0; i < t; i++) {
        friends = sum = 0;
        cin >> max;
        cin >> shyness;
        int digits[MAX];
        for(int j = max; j >= 0; j--) {
            digits[j] = shyness % 10;
            shyness /= 10;
        }
        sum = digits[0];
        for (int k = 1; k <= max; k++) {
            if (sum < k && digits[k] > 0) {
                friends += k - sum;
                sum += k - sum;
            }
            sum += digits[k];
        }
        cout << "Case #" << i+1 << ": " << friends << endl;
    }
    return 0;
}
