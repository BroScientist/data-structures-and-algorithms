class Solution:
    def intersection(self, nums1, nums2):
        hashtable = {}
        result = []
        for num in set(nums1):
            hashtable[num] = 1
        for num in set(nums2):
            if num not in hashtable:
                continue
            hashtable[num] += 1
        for item in hashtable:
            if hashtable[item] == 2:
                result.append(item)
        return result
