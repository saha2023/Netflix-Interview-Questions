class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box[0].size();
        int m = box.size();

        vector<vector<char>> res(n, vector<char>(m,'.'));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[i][j] = box[m-j-1][i];
            }
        }

        for(int j = 0; j < m; j++){
            int cur = n - 1;
            for(int i = n - 1; i >= 0; i--){
                if(res[i][j] == '*'){
                    cur = i - 1;
                }
                else if(res[i][j] == '#'){
                    res[i][j] = '.';
                    res[cur--][j] = '#';
                }
            }
        }
    }
};