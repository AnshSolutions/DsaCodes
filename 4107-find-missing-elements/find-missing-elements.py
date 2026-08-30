# class Solution(object):
#     def findMissingElements(self, nums):
#        n=len(nums)
#        nums.sort()
#        st=set()
#        for i in range(len(nums)):
#             st.add(nums[i])

#        smallest=nums[0]
#        largest=nums[-1]
#        ans = []
#        for i in range (smallest,largest+1):
#           if i  not in st:
#             ans.append(i)

#         return ans
class Solution(object):
    def findMissingElements(self, nums):
        n = len(nums)
        nums.sort()
        st = set()
        for i in range(len(nums)):
            st.add(nums[i])

        smallest = nums[0]
        largest = nums[-1]
        ans = []
        for i in range(smallest, largest + 1):
            if i not in st:
                ans.append(i)

        return ans

            
       
        
        