#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    vector<int> A = {4, 5, 2, 10, 8};
    int n = A.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= A[i]) {
            st.pop();
        }

        if (!st.empty()) {
            result[i] = st.top();
        }

        st.push(A[i]);
    }

    // Output result
    cout << "Nearest smaller to left:\n";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}