vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols) {
    vector<int> ans;
    for(int col = 0; col < mCols; col++) {
        if(col & 1) { // if column index is odd
            for(int row = nRows - 1; row >= 0; row--) { // fixed loop condition
                ans.push_back(arr[row][col]);
            }
        } else { // if column index is even
            for(int row = 0; row < nRows; row++) {
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}
