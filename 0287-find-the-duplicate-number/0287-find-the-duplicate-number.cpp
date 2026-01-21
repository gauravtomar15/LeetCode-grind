class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];  // ye slow pointer ye one step chalega
        int fast = nums[0];  // ye faster fointer jo slow pointer k twice chalega
        slow = nums[slow];
        fast = nums[nums[fast]];

        // Detect  cycle technique name (hare & tortoise) ye floyd algorithm follow krta hai
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow= nums[0];
        
        // ab hume pata chal gya ha ki cycle kha ban rhi ha than ab hum apne
        // slow ko start pr target krenge or fast ko whi rehne denge or jaha slow || fast milenge whi deuplicate hoga 
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
        
    }
};