class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int, int>> q;

        int fresh = 0;

        // Find all rotten and fresh oranges
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {

                if (grid[row][col] == 2) {
                    q.push({row, col});
                }
                else if (grid[row][col] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        // BFS
        while (!q.empty() && fresh > 0) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                auto [row, col] = q.front();
                q.pop();

                // Up
                if (row - 1 >= 0 &&
                    grid[row - 1][col] == 1) {

                    grid[row - 1][col] = 2;
                    fresh--;
                    q.push({row - 1, col});
                }

                // Down
                if (row + 1 < grid.size() &&
                    grid[row + 1][col] == 1) {

                    grid[row + 1][col] = 2;
                    fresh--;
                    q.push({row + 1, col});
                }

                // Left
                if (col - 1 >= 0 &&
                    grid[row][col - 1] == 1) {

                    grid[row][col - 1] = 2;
                    fresh--;
                    q.push({row, col - 1});
                }

                // Right
                if (col + 1 < grid[0].size() &&
                    grid[row][col + 1] == 1) {

                    grid[row][col + 1] = 2;
                    fresh--;
                    q.push({row, col + 1});
                }
            }

            minutes++;
        }

        // If fresh oranges are still left, impossible
        if (fresh > 0)
            return -1;

        return minutes;
    }
};