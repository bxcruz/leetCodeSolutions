
/*  default direction in the diagonally down. reverse list for up traversals
*   each diagonal traversal alternates from up to down.
*/
void downDiagonal(vector<vector<int>>& mat, vector<int>& diag, int row, int col){
    while(col >= 0 && row < mat.size()){
    diag.push_back(mat[row][col]);
        col--;
        row++;
    }
}

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int columnSize = mat[0].size();
        int rowSize = mat.size();
        int rowCounter = 0;
        int colCounter = 0;
        vector<int> diagonal; //buffer for diagonal passes. reverses on upstrokes
        vector<int> sol;      //contains solution of diagonal traversal
        std::vector<int>::iterator iter;
        bool direction = true; //true for up, false for down
        
        //cout << rowSize << "x" << columnSize << " matrix" << endl; // get row x col dim
        
        //go horizontally via columns
        while(colCounter < columnSize){        
                downDiagonal(mat,diagonal, rowCounter, colCounter);
                colCounter++;
                if(direction){
                    reverse(diagonal.begin(), diagonal.end());
                }
                for (iter = diagonal.begin(); iter != diagonal.end(); iter++){
                    sol.push_back(*iter);
                }
                direction = !direction; //this negation sets up next up/down stroke
                diagonal.clear();
        }
        
        colCounter = columnSize - 1;
        
        //go vertically via rows
        while(rowCounter < rowSize){
                rowCounter++;
                downDiagonal(mat,diagonal, rowCounter, colCounter);
                if(direction){
                    reverse(diagonal.begin(), diagonal.end());
                }
                for (iter = diagonal.begin(); iter != diagonal.end(); iter++){
                    sol.push_back(*iter);
                }
                direction = !direction;
                diagonal.clear();            
        }      
        return sol;
    }
};