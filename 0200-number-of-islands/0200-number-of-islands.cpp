class Solution {
public:
 
void dfs(vector<vector<char>>& grid, int row, int col) {

if (row < 0 || row >= grid.size() ||
    col < 0 || col >= grid[0].size())
    return;




if (grid[row][col] == '0')
    return;
 grid[row][col] = '0';

 dfs(grid, row - 1, col); // up
dfs(grid, row + 1, col); // down
dfs(grid, row, col - 1); // left
dfs(grid, row, col + 1); // right
}




 int numIslands(vector<vector<char>>& grid) {

        int island = 0;

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {

                if (grid[row][col] == '1') {
                    island++;
                    dfs(grid, row, col);
                }
            }
        }

        return island;


    }
};