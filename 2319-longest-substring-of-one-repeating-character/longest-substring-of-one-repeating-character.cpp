class Solution {
public:
    struct Node {
        int pre;
        int suf;
        int maxLen;
        char leftChar;
        char rightChar;

        Node() {
            pre = 0;
            suf = 0;
            maxLen = 0;
            leftChar = '#';
            rightChar = '#';
        }

        Node(int p, int s, int m, char l, char r) {
            pre = p;
            suf = s;
            maxLen = m;
            leftChar = l;
            rightChar = r;
        }
    };

    int n;
    vector<Node> segTree;

    void buildSegTree(int i, int l, int r, string& s) {
        // Leaf node
        if (l == r) {
            segTree[i] = Node(1, 1, 1, s[l], s[l]);
            return;
        }

        int mid = l + (r - l) / 2;

        buildSegTree(2 * i + 1, l, mid, s);
        buildSegTree(2 * i + 2, mid + 1, r, s);

        segTree[i] = merge(
            segTree[2 * i + 1],
            segTree[2 * i + 2],
            mid - l + 1,
            r - mid
        );
    }

    Node merge(const Node& L, const Node& R,
               int leftLen, int rightLen) {

        Node res;

        // First and last character of combined segment
        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;

        // Prefix
        res.pre = L.pre;

        if (L.pre == leftLen && L.rightChar == R.leftChar) {
            res.pre = L.pre + R.pre;
        }

        // Suffix
        res.suf = R.suf;

        if (R.suf == rightLen && L.rightChar == R.leftChar) {
            res.suf = R.suf + L.suf;
        }

        // Maximum repeating substring inside either child
        res.maxLen = max(L.maxLen, R.maxLen);

        // Repeating substring crossing the boundary
        if (L.rightChar == R.leftChar) {
            res.maxLen = max(res.maxLen, L.suf + R.pre);
        }

        return res;
    }

    void update(int i, int l, int r, int pos, char ch) {
        // Leaf node
        if (l == r) {
            segTree[i] = Node(1, 1, 1, ch, ch);
            return;
        }

        int mid = l + (r - l) / 2;

        if (pos <= mid) {
            update(2 * i + 1, l, mid, pos, ch);
        } else {
            update(2 * i + 2, mid + 1, r, pos, ch);
        }

        // Recalculate current node
        segTree[i] = merge(
            segTree[2 * i + 1],
            segTree[2 * i + 2],
            mid - l + 1,
            r - mid
        );
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        n = s.size();

        segTree.assign(4 * n, Node());

        buildSegTree(0, 0, n - 1, s);

        int k = queryIndices.size();
        vector<int> result(k);

        for (int i = 0; i < k; i++) {
            int pos = queryIndices[i];
            char ch = queryCharacters[i];

            // Update the character
            update(0, 0, n - 1, pos, ch);

            // Root contains the answer for the entire string
            result[i] = segTree[0].maxLen;
        }

        return result;
    }
};