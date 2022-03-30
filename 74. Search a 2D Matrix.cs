public class Solution {
    public bool SearchMatrix(int[][] matrix, int target) {
        
        if(matrix.Length == 0 || matrix[0].Length == 0)
            return false;
        
        //first find the row where the element is belong , basically first element wll be Floor Value
        int s = 0, e = matrix.Length - 1;
        int rowToSearch = s;
        while( s < e) {  // final window size of 2
            
            int mid = s + (e-s)/2; // mid is biased towards s, since its " s + "
            
            if(matrix[mid][0] <= target && matrix[mid+1][0] > target) {
                rowToSearch = mid;
                break;
            }
            
            if(target < matrix[mid][0]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
            rowToSearch = s;
        }
        
        s = 0;
        e = matrix[rowToSearch].Length - 1;
        while( s < e) { // final window size is still 2, will be terminating when s == e
            int mid = s + (e-s)/2;
            if(matrix[rowToSearch][mid] == target) {
                return true;
            }
            if(target < matrix[rowToSearch][mid]) {
                e = mid - 1;  // this has to be there to terminate mid not tocuhing
            } else {
                s = mid + 1;  // terminate , mid not toching
            }
        }
        
        return matrix[rowToSearch][s] == target;
    }
}
