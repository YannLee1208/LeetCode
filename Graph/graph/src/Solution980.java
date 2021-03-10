public class Solution980 {
    private int[][] grid;
    private int R, C;
    private int start, end;
    private boolean[][] visited;
    private int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    public int uniquePathsIII(int[][] grid) {
        this.grid = grid;
        this.R = grid.length;
        this.C = grid[0].length;
        visited = new boolean[R][C];
        int left = R * C;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 1) {
                    start = i * C + j;
                    grid[i][j] = 0;
                }
                else if (grid[i][j] == 2){
                    end = i * C + j;
                    grid[i][j] = 0;
                }
                else if (grid[i][j] == -1)
                    left--;
            }
        }

        return dfs(start, left);
    }

    private int dfs(int v, int left){
        int x = v / C;
        int y = v % C;
        visited[x][y] = true;
        left --;
        if (left == 0 && v == end){
            // 回溯不要忘记
            visited[x][y] =false;
            return 1;
        }

        int res = 0;
        for (int i = 0; i < 4; i++) {
            int nextx = x + dirs[i][0];
            int nexty = y + dirs[i][1];
            if (inArea(nextx, nexty) && !visited[nextx][nexty] && grid[nextx][nexty] == 0){
                res += dfs(nextx * C + nexty, left);
            }
        }

        visited[x][y] = false;
        return res;


    }

    private boolean inArea(int x, int y){
        return x >= 0 && x < R && y >= 0 && y < C;
    }
}
