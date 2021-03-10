import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

public class Solution773 {
    private int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    public int slidingPuzzle(int[][] board) {

        Queue<String> queue = new LinkedList<>();
        HashMap<String, Integer> visited = new HashMap<>();

        String init = boardToString(board);
        if (init.equals("123450"))
            return 0;

        queue.add(init);
        visited.put(init, 0);
        while (!queue.isEmpty()){
            String cur = queue.remove();
            ArrayList<String> nexts = getNext(cur);

            for (String next : nexts){
                if (!visited.containsKey(next)){
                    queue.add(next);
                    visited.put(next, visited.get(cur) + 1);

                    if (next.equals("123450"))
                        return visited.get(next);
                }
            }
        }

        return -1;
    }

    private ArrayList<String> getNext(String s){
        ArrayList<String> res = new ArrayList<>();
        int[][] cur = stringToBoard(s);
        int zero_pos;
        for (zero_pos = 0; zero_pos < 6; zero_pos ++ ){
            if (cur[zero_pos / 3][zero_pos % 3] == 0)
                break;
        }

        int zx = zero_pos / 3;
        int zy = zero_pos % 3;
        for (int i = 0; i < 4; i++) {
            int nextx = zx + dirs[i][0];
            int nexty = zy + dirs[i][1];
            if (inArea(nextx, nexty)){
                swap(cur, zx, zy, nextx, nexty);
                res.add(boardToString(cur));
                swap(cur, zx, zy, nextx, nexty);
            }
        }

        return res;
    }

    private void swap(int[][] board, int x1, int y1, int x2, int y2){
        int t = board[x1][y1];
        board[x1][y1] = board[x2][y2];
        board[x2][y2] = t;
    }

    private boolean inArea(int x, int y){
        return x >= 0 && x  < 2 && y >= 0 && y < 3;
    }

    private int[][] stringToBoard(String s){
        int[][] board = new int[2][3];
        for (int i = 0; i < 6; i++){
            board[i /3][i % 3] = s.charAt(i) - '0';
        }

        return board;
    }

    private String boardToString(int[][] board){
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                sb.append(board[i][j]);
            }
        }

        return sb.toString();
    }


}
