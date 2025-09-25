class NumArray {
private:
    vector<int> seg;
    int n;

    void build(int node, int start, int end, vector<int>& nums) {
        if (start == end) {
            seg[node] = nums[start];
        } else {
            int mid = (start + end) / 2;
            build(2*node, start, mid, nums);
            build(2*node+1, mid+1, end, nums);
            seg[node] = seg[2*node] + seg[2*node+1];
        }
    }

    int query(int node, int start, int end, int L, int R) {
        if (end < L || start > R) return 0;            
        if (L <= start && end <= R) return seg[node];
        int mid = (start + end) / 2;
        int leftSum = query(2*node, start, mid, L, R);
        int rightSum = query(2*node+1, mid+1, end, L, R);
        return leftSum + rightSum;
    }

    void updateTree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            seg[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) updateTree(2*node, start, mid, idx, val);
            else updateTree(2*node+1, mid+1, end, idx, val);
            seg[node] = seg[2*node] + seg[2*node+1];
        }
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*n);
        build(1, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        updateTree(1, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(1, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
