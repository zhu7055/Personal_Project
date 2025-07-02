Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

* **0 <= i, j, k, l < n**
  
* **nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0**
 

* **Example 1:**

<strong>Input:</strong> nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]

<strong>Output: </strong>2
* **Explanation:**
  
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
* **Example 2:**

<strong>Input:</strong> nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]

<strong>Output: 1</strong>
 

<strong>Constraints:</strong>

* **n == nums1.length**
  
* **n == nums2.length**

* **n == nums3.length**

* **n == nums4.length**
  
* **1 <= n <= 200**
  

* **$-2^{28} <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2^{28}$**
  
