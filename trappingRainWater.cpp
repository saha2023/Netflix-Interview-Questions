class Solution {
public:
    int trap(vector<int>& height) {
        int max_h = distance(height.begin(), max_element(height.begin(), height.end()));
        int n = height.size();
        int sum = 0, left = height.front(), right = height.back();
        // for(int i=1;i<=max_h;i++){
        //     if(left<height[i]){
        //         left = height[i];
        //     }
        //     else sum += left - height[i];
        // }

        // int right = height.back();
        // for(int i=height.size()-2;i>=max_h;i--){
        //     if(right<height[i]){
        //         right = height[i];
        //     }
        //     else sum += right - height[i];
        // }

        int i = 0, j = n-1;

        while(i<=max_h or j>=max_h){
            if(i<=max_h){
                if(left<height[i]){
                    left = height[i++];
                }
                else sum += left - height[i++];
            }
            if(j>=max_h){
                if(right<height[j]){
                    right = height[j--];
                }
                else sum += right - height[j--];
            }
        }

        return sum;
    }
};