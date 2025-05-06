#include <iostream>
using namespace std;

typedef long long ll;

// ----------------------------
// Function to calculate GCD
// ----------------------------
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

// ----------------------------
// Function to calculate LCM using GCD
// ----------------------------
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

// ------------------------------------------------------
// Function to build the segment tree for LCM
// arr  : original input array
// st   : segment tree array
// si   : current index in segment tree
// ss   : segment start index
// se   : segment end index
// ------------------------------------------------------
void buildTree(int *arr, ll *st, int si, int ss, int se) {
    if (ss == se) {
        st[si] = arr[ss]; // Leaf node
        return;
    }

    int mid = (ss + se) / 2;

    // Recursively build left and right subtrees
    buildTree(arr, st, 2 * si + 1, ss, mid);
    buildTree(arr, st, 2 * si + 2, mid + 1, se);

    // Internal node stores LCM of left and right children
    st[si] = lcm(st[2 * si + 1], st[2 * si + 2]);
}

// -------------------------------------------------------------------------------------------
// Function to get LCM from index qs to qe in the array
// st  : segment tree array
// arr : original input array
// n   : size of original array
// qs  : query start index
// qe  : query end index
// si  : current index in segment tree (starts from 0)
// ss  : segment start index (defaults to 0)
// se  : segment end index (defaults to n-1)
// -------------------------------------------------------------------------------------------
ll getLCM(ll *st, int *arr, int n, int qs, int qe, int si = 0, int ss = 0, int se = -1) {
    if (se == -1) se = n - 1; // Initialize on first call

    // No overlap
    if (qs > se || qe < ss)
        return 1;

    // Complete overlap
    if (qs <= ss && qe >= se)
        return st[si];

    // Partial overlap: check left and right children
    int mid = (ss + se) / 2;
    ll left = getLCM(st, arr, n, qs, qe, 2 * si + 1, ss, mid);
    ll right = getLCM(st, arr, n, qs, qe, 2 * si + 2, mid + 1, se);

    return lcm(left, right);
}

// -------------------------------------------------------------------------------------------------
// Internal helper function to update value at a given index in segment tree
// si       : current index in segment tree
// ss, se   : segment range
// index    : index in the original array to be updated
// new_val  : new value to set
// -------------------------------------------------------------------------------------------------
void updateValueUtil(int *arr, ll *st, int si, int ss, int se, int index, int new_val) {
    if (index < ss || index > se)
        return;

    if (ss == se) {
        arr[index] = new_val;
        st[si] = new_val;
        return;
    }

    int mid = (ss + se) / 2;

    // Recur for the correct child
    updateValueUtil(arr, st, 2 * si + 1, ss, mid, index, new_val);
    updateValueUtil(arr, st, 2 * si + 2, mid + 1, se, index, new_val);

    // Update current node after child updates
    st[si] = lcm(st[2 * si + 1], st[2 * si + 2]);
}

// -------------------------------------------------------------------------
// Wrapper function to update the segment tree
// index    : index in the original array
// new_val  : new value to be updated
// -------------------------------------------------------------------------
void updateValue(int *arr, ll *st, int n, int index, int new_val) {
    updateValueUtil(arr, st, 0, 0, n - 1, index, new_val);
}

// -----------------------
// Main function
// -----------------------
int main() {
    int arr[] = {2, 7, 3, 9, 4}; // Original array
    int n = sizeof(arr) / sizeof(arr[0]);

    ll *st = new ll[4 * n];  // Segment tree array (size ~4n)

    buildTree(arr, st, 0, 0, n - 1); // Build the segment tree

    // Query LCM from index 1 to 3
    cout << "LCM(1, 3): " << getLCM(st, arr, n, 1, 3) << endl; // Expected: 63

    // Update index 2 to value 6
    updateValue(arr, st, n, 2, 6);

    // Query again after update
    cout << "LCM(1, 3) after update: " << getLCM(st, arr, n, 1, 3) << endl; // Expected: 126

    delete[] st;
    return 0;
}
