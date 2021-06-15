#### [153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)

> - 执行用时：0 ms, 在所有 Java 提交中击败了100.00%的用户

```java
class Solution {
    public int findMin(int[] nums) {
        int left = 0, right = nums.length - 1;
        while(left < right){
            while(left < right && nums[left] == nums[left + 1]){
                left++;
            }
            while(left < right && nums[right] == nums[right - 1]){
                right--;
            }
            int mid = (left + right) >>> 1;
            if(nums[mid] > nums[right]){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return nums[left];
    }
}
```

