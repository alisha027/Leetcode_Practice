class NumArray {
private:
    vector<int> st;
    vector<int> nums;
    int n;

    int buildTree(int low, int high, int index) {
        if (low == high) {
            st[index] = nums[low];
            return st[index];
        }
        int mid = (low + high) / 2;
        st[index] = buildTree(low, mid, 2 * index + 1) + buildTree(mid + 1, high, 2 * index + 2);
        return st[index];
    }

    int calSum(int low, int high, int l, int r, int index) {
        if (high < l || low > r) return 0;  
        if (low >= l && high <= r) return st[index]; 

        int mid = (low + high) / 2;
        return calSum(low, mid, l, r, 2 * index + 1) + calSum(mid + 1, high, l, r, 2 * index + 2);
    }

    void updateValue(int low, int high, int pos, int val, int index) {
        if (low == high) {
            st[index] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (pos <= mid)
            updateValue(low, mid, pos, val, 2 * index + 1);
        else
            updateValue(mid + 1, high, pos, val, 2 * index + 2);
        st[index] = st[2 * index + 1] + st[2 * index + 2];
    }

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        st.resize(4 * n, 0);
        buildTree(0, n - 1, 0);
    }

    void update(int index, int val) {
        nums[index] = val;
        updateValue(0, n - 1, index, val, 0);
    }

    int sumRange(int left, int right) {
        return calSum(0, n - 1, left, right, 0);
    }
};
