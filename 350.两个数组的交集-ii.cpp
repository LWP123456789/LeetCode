/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect(nums2,nums1);
        }
        unordered_map <int,int> m;
        for (int num : nums1){
            ++m[num];
        }
        vector<int> intersection;
        for (int num : nums2){
            if (m.count(num)){
                intersection.push_back(num);
                --m[num];
                if (m[num] == 0)
                {
                    m.erase(num);
                }
            }
        }
        return intersection;
    }
};
// @lc code=end

/*
    1、unordered_map 关联容器，内部采用的是hash表结构，拥有快速检索的功能
    2、for (int num : nums1) {
            ++m[num];
        }
        C++新特性，遍历数组中的每个值给num
    3、count函数用以统计key值在unordered_map中出现的次数。实际上，c++ unordered_map不允许有重复的key。
        因此，如果key存在，则count返回1，如果不存在，则count返回0.
*/