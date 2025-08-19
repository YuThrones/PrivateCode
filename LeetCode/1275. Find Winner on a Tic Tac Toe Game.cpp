// 没什么难度，条件写对就行

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> map;
        for (int i = 0; i < 3; ++i) {
            map.push_back(vector<int>(3, 0));
        }
        for (int i = 0; i < moves.size(); ++i) {
            auto& move = moves[i];
            int x = move[0];
            int y = move[1];
            int check = (i % 2 == 0) ? 1 : 2;
            map[x][y] = check;
            bool bIsWin = false;


            if (map[x][0] == check && map[x][1] == check && map[x][2] == check) {
                bIsWin = true;
            }

            if (map[0][y] == check && map[1][y] == check && map[2][y] == check) {
                bIsWin = true;
            }

            if (x == y && map[0][0] == check && map[1][1] == check && map[2][2] == check)       {
                bIsWin = true;
            }

            if (x + y == 2 && map[0][2] == check && map[1][1] == check && map[2][0] == check) {
                bIsWin = true;
            }

            if (bIsWin) {
                return (check == 1) ? "A" : "B";
            }
        }

        return moves.size() == 9 ? "Draw" : "Pending";
    }
};