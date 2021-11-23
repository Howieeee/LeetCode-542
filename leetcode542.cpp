class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size() , col = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        
        vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        int times = 0;
        while(!q.empty()){
            int size = q.size();
            //cout << size << endl;
            for(int i=0;i<size;i++){
                
                pair<int,int> node = q.front();
                q.pop();
                
                for(int k=0;k<4;k++){
                    int r = node.first + dir[k][0];
                    int c = node.second + dir[k][1];
                    if(r < 0 || r > row-1 || c <0 || c > col-1){ //超過邊界
                        //cout << node.first << " " << node.second << " " << r << " " << c  << "  is out of bound\n";
                        continue;
                    }
                    if(mat[r][c] == 1 && !visited[r][c]){ //=1 且沒走過
                        q.push({r,c});
                        mat[r][c] += times; //走過幾步
                        visited[r][c] = 1;
                    }
                }
            }
            times++;
        }
        
        return mat;
    }
};
