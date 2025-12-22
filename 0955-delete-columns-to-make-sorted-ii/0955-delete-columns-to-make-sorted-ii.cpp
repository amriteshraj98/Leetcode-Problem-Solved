class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();
        int deletion = 0;
        int row = 0 , col = 0;
        vector<bool>alreadysorted(rows,false);
        for( col = 0 ; col < cols ; col++){
            bool isdeleted = false;
            for( row = 0 ; row < rows-1 ; row++){
                if(!alreadysorted[row] && strs[row][col] > strs[row+1][col]){
                    isdeleted = true;
                    deletion++;
                    break;
                }
            }
            if(isdeleted) { // agar hamne delete kar diya tha toh continue kar jao
                continue; 
            }
            // agar delete nhi kiya toh ye pura ka pura col safe hai 
            for(int i = 0 ; i < rows-1 ; i++){
                alreadysorted[i] = alreadysorted[i] | (strs[i][col] < strs[i+1][col] );
            }

        }
        return deletion;
    }
};