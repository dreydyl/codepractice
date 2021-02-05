class Solution {
public:
    /*
    in vector int >= 0
    out int
    con O(n^2)
    edge 0 <= n <= 2, heights all the same
     */
    int trap(vector<int>& height) {
        //[0,1,-1,2,-1,-1,1,2,-1,-1,1,-1]
        if(height.size() <= 2 && height.size() >= 0) return 0;
        int tallest = 0;
        for(int i = 0;i < height.size();i++) {
            if(height.at(i) > height.at(tallest)) tallest = i;
        }
        int water = 0;
        for(int i = 1;i < tallest;i++) {
                if(height.at(i-1) > height.at(i)) {
                    water += height.at(i-1) - height.at(i);
                    height[i] = height[i-1];
                }
        }
        for(int i = height.size()-2;i >= tallest;i--) {
                if(height.at(i+1) > height.at(i)) {
                    water += height.at(i+1) - height.at(i);
                    height[i] = height[i+1];
                }
        }
        return water;
    }
};