class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (searchWord(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }

private:
    bool searchWord(vector<vector<char>>& board, string word, int r, int c, int index) {
        if (index == word.length()) {
            return true;
        }
        
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) {
            return false;
        }
        
        if (board[r][c] != word[index]) {
            return false;
        }
        
        char originalChar = board[r][c];
        board[r][c] = '#'; 
        
        
        if (searchWord(board, word, r + 1, c, index + 1)) return true;
        
        if (searchWord(board, word, r - 1, c, index + 1)) return true;
        
        if (searchWord(board, word, r, c + 1, index + 1)) return true;
        
        if (searchWord(board, word, r, c - 1, index + 1)) return true;
        
        board[r][c] = originalChar;
        
        return false;
    }
};
