class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int top=0,bottom=matrix.size();
        int left=0,right=matrix[0].size();
        while(left<right&&top<bottom){
            for(int i=left;i<right;i++)res.push_back(matrix[top][i]);
            top++;
            for(int j=top;j<bottom;j++)res.push_back(matrix[j][right-1]);
            right--;
            if (!(left < right && top < bottom)) {
                break;
            }
            for(int i=right-1;i>=left;i--)res.push_back(matrix[bottom-1][i]);
            bottom--;
            for(int j=bottom-1;j>=top;j--)res.push_back(matrix[j][left]);
            left++;
        }return res;
    }
};
