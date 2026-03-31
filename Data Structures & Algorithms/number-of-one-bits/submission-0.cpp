class Solution {
public:
    int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        n &= (n - 1); // 清除最低位的1
        count++;
    }
    return count;
    }
};
