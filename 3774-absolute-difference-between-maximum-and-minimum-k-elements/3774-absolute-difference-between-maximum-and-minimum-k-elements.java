class Solution {
    public int absDifference(int[] nums, int k) {
        Scanner sc= new Scanner(System.in);
        int n=nums.length, s1=0, s2=0;
        Arrays.sort(nums);
        for(int i=0; i<k; i++)
        {
            s1+=nums[i];
        }
        for(int i=n-k; i<n; i++)
        {
            s2+=nums[i];
        }
        return Math.abs(s1-s2);        
    }
}