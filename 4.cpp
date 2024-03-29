class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), low = 0, high = m;
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        while (low <= high) {
            int i = (low + high) / 2, j = (m + n + 1) / 2 - i;
            if (i && nums1[i - 1] > nums2[j]) {
                high = i - 1;
            } else if (i < m && nums2[j - 1] > nums1[i]) {
                low = i + 1;
            } else {
                int lmax = !i ? nums2[j - 1] : (!j ? nums1[i - 1] : max(nums1[i - 1], nums2[j - 1]));
                if ((m + n) % 2) {
                    return lmax;
                }
                int rmin = i == m ? nums2[j] : (j == n ? nums1[i] : min(nums1[i], nums2[j]));
                return 0.5 * (lmax + rmin);
            }
        }
        return 0.0;
    }
};