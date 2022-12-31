class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        for element in nums2:
            index = nums1.index(0)  # find the index of the next placeholder element
            nums1[index] = element  # change value of that element to element of second list
        nums1.sort()                # sort first list after insertion
