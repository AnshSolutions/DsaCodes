#include <bits/stdc++.h>
using namespace std;
class NumArray {
    public:
        int n;
        vector<int> segmentTree;
    
        void buildsegmentTree(int l, int r, int i, vector<int>& arr) {
            if (l == r) {
                segmentTree[i] = arr[l];
                return;
            }
            int mid = l + (r - l) / 2;
            buildsegmentTree(l, mid, 2 * i + 1, arr);
            buildsegmentTree(mid + 1, r, 2 * i + 2, arr);
            segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
        }
    
        void updateQuery(int idx, int val, int l, int r, int i) {
            if (l == r) {
                segmentTree[i] = val;
                return;
            }
            int mid = l + (r - l) / 2;
            if (idx <= mid) {
                updateQuery(idx, val, l, mid, 2 * i + 1);
            } else {
                updateQuery(idx, val, mid + 1, r, 2 * i + 2);
            }
            segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
        }
    
        int rangeSumQuery(int ql, int qr, int l, int r, int i) {
            if (ql > r || qr < l) return 0;
            if (ql <= l && r <= qr) return segmentTree[i];
            int mid = l + (r - l) / 2;
            return rangeSumQuery(ql, qr, l, mid, 2 * i + 1) + rangeSumQuery(ql, qr, mid + 1, r, 2 * i + 2);
        }
    
        NumArray(vector<int>& nums) {
            n = nums.size();
            segmentTree.resize(4 * n);
            buildsegmentTree(0, n - 1, 0, nums);
        }
    
        void update(int index, int val) {
            updateQuery(index, val, 0, n - 1, 0);
        }
    
        int sumRange(int left, int right) {
            return rangeSumQuery(left, right, 0, n - 1, 0);
        }
    };
    
    
    /**
     * Your NumArray object will be instantiated and called as such:
     * NumArray* obj = new NumArray(nums);
     * obj->update(index,val);
     * int param_2 = obj->sumRange(left,right);
     */