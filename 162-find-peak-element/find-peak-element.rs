impl Solution {
    pub fn find_peak_element(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if(n==1){
            return 0 as i32;
        } 
        if(nums[0]>nums[1]){
            return 0 as i32;
        } 
        if(nums[n-1]>nums[n-2]){
            return (n-1) as i32;
        } 
        let mut low = 1;
        let mut high = n-2;
        while(low<=high){
            let mid = (low + high)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                return mid as i32;
            }
            else if(nums[mid]<nums[mid+1]){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return 0;
    }
}