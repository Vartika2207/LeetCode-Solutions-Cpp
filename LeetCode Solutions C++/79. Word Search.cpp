class Solution {
  //time:   , space: 
    int dxdy[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    bool isValid(int n, int m, int x, int y){
    return ((x>=0 && x<n) && (y>=0 && y<m));
   }
    
    bool findWordInGrid(vector<vector<char>>& board, string word, int idx, int x, int y){
        if(idx == word.size())
            return true;
        char temp = board[x][y];
        board[x][y] = '*';
        bool found = false;
        for(int i=0; i<4; i++){
            int dx = x + dxdy[i][0];
            int dy = y + dxdy[i][1];
            if(isValid(board.size(), board[0].size(), dx, dy) and board[dx][dy] == word[idx])
                found = found | findWordInGrid(board, word, idx+1, dx, dy);
        }
        board[x][y] = temp;
        return found;
    }
    
    bool exist_(vector<vector<char>>& board, string word){
        
        bool found = false;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    found = findWordInGrid(board, word, 1, i, j);
                    if(found)
                        break;
                }
            }
            if(found)
                break;
        }
        return found;
    }
    
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        return exist_(board, word);
    }
};
