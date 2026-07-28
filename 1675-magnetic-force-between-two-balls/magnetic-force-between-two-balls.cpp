class Solution
{
public:
    bool canWePlaceBall(vector<int> &nums, int i, int m)
    {
        int n = nums.size();

        int ball = 1;
        int last = nums[0];

        for (int j = 1; j < n; j++)
        {
            if (nums[j] - last >= i)
            {
                ball++;
                last = nums[j];
            }
        }
        return (ball >= m);
    }

    int maxDistance(vector<int> &nums, int m)
    {
        int n = nums.size();

        int maxi = *max_element(nums.begin() , nums.end());
        int mini = *min_element(nums.begin() , nums.end());
        sort(nums.begin(), nums.end());

        // Bruteforce Solution

        // for(int i=1;i<=maxi-mini;i++){
        //     if(canWePlaceBall(nums , i , m) == false) return i-1;
        // }
        // return maxi - mini;

        // Optimal Solution

        int low = 1, high = maxi - mini;
        int ans = 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (canWePlaceBall(nums, mid, m) == true)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};