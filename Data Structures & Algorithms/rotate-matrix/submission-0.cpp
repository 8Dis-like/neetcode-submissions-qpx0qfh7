class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size(); int n=matrix[0].size();
        for(int i=0;i<m/2;i++){
            for(int j=0;j<n;j++){
                int tmp=matrix[i][j];
                matrix[i][j]=matrix[m-i-1][j];
                matrix[m-i-1][j]=tmp;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};
