#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    int n;
    vector<int> segmentTreeSum;
    vector<int> segmentTreeMin;
    vector<int> segmentTreeMax;

    // Build all segment trees: sum, min, and max
    void buildSegmentTrees(int l, int r, int i, vector<int>& arr) {
        if (l == r) {
            segmentTreeSum[i] = segmentTreeMin[i] = segmentTreeMax[i] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegmentTrees(l, mid, 2 * i + 1, arr);
        buildSegmentTrees(mid + 1, r, 2 * i + 2, arr);

        segmentTreeSum[i] = segmentTreeSum[2 * i + 1] + segmentTreeSum[2 * i + 2];
        segmentTreeMin[i] = min(segmentTreeMin[2 * i + 1], segmentTreeMin[2 * i + 2]);
        segmentTreeMax[i] = max(segmentTreeMax[2 * i + 1], segmentTreeMax[2 * i + 2]);
    }

    // Update all segment trees
    void updateQuery(int idx, int val, int l, int r, int i) {
        if (l == r) {
            segmentTreeSum[i] = segmentTreeMin[i] = segmentTreeMax[i] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid)
            updateQuery(idx, val, l, mid, 2 * i + 1);
        else
            updateQuery(idx, val, mid + 1, r, 2 * i + 2);

        segmentTreeSum[i] = segmentTreeSum[2 * i + 1] + segmentTreeSum[2 * i + 2];
        segmentTreeMin[i] = min(segmentTreeMin[2 * i + 1], segmentTreeMin[2 * i + 2]);
        segmentTreeMax[i] = max(segmentTreeMax[2 * i + 1], segmentTreeMax[2 * i + 2]);
    }

    // Range sum query
    int rangeSumQuery(int ql, int qr, int l, int r, int i) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return segmentTreeSum[i];
        int mid = l + (r - l) / 2;
        return rangeSumQuery(ql, qr, l, mid, 2 * i + 1) +
               rangeSumQuery(ql, qr, mid + 1, r, 2 * i + 2);
    }

    // Range min query
    int rangeMinQuery(int ql, int qr, int l, int r, int i) {
        if (ql > r || qr < l) return INT_MAX;
        if (ql <= l && r <= qr) return segmentTreeMin[i];
        int mid = l + (r - l) / 2;
        return min(rangeMinQuery(ql, qr, l, mid, 2 * i + 1),
                   rangeMinQuery(ql, qr, mid + 1, r, 2 * i + 2));
    }

    // Range max query
    int rangeMaxQuery(int ql, int qr, int l, int r, int i) {
        if (ql > r || qr < l) return INT_MIN;
        if (ql <= l && r <= qr) return segmentTreeMax[i];
        int mid = l + (r - l) / 2;
        return max(rangeMaxQuery(ql, qr, l, mid, 2 * i + 1),
                   rangeMaxQuery(ql, qr, mid + 1, r, 2 * i + 2));
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTreeSum.resize(4 * n);
        segmentTreeMin.resize(4 * n);
        segmentTreeMax.resize(4 * n);
        buildSegmentTrees(0, n - 1, 0, nums);
    }

    void update(int index, int val) {
        updateQuery(index, val, 0, n - 1, 0);
    }

    int sumRange(int left, int right) {
        return rangeSumQuery(left, right, 0, n - 1, 0);
    }

    // Added: Get minimum value in range [left, right]
    int minRange(int left, int right) {
        return rangeMinQuery(left, right, 0, n - 1, 0);
    }

    // Added: Get maximum value in range [left, right]
    int maxRange(int left, int right) {
        return rangeMaxQuery(left, right, 0, n - 1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index, val);
 * int sum = obj->sumRange(left, right);
 * int minimum = obj->minRange(left, right); // new
 * int maximum = obj->maxRange(left, right); // new
 */
