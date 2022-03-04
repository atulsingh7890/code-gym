class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        std::vector<std::vector<double>> glasses(102, std::vector<double>(102, 0.0));
        //fill the first glasss with all the liquid
        glasses[0][0] = poured;
        for(int r = 0; r <= query_row; ++r) {
            for(int c = 0; c <= r; ++c) {
                //now see how much extra is there in glass r,c
                double extraLiquid = glasses[r][c] - 1.0;
                // divide this extra into two havles in bottom two glasses
                if(extraLiquid > 0) {
                    glasses[r+1][c] += extraLiquid/2;
                    glasses[r+1][c+1] += extraLiquid/2;
                }
            }
        }
        
        return std::min(1.0, glasses[query_row][query_glass]);
    }
    double champagneTower1(int poured, int query_row, int query_glass) {
        
        if(poured <= 0)
            return 0;
        
        std::vector<std::vector<long>> pascalTriangle;
        std::vector<std::vector<double>> glassCapacity;
        
        pascalTriangle.push_back({1});
        glassCapacity.push_back({1.0});
        
        int capcityTillNow = 1;
        int liquidAvailable = poured - 1;
        
        //printVec(pascalTriangle[0]);
        // we need to find the fibonacci number
        for(int r = 1; r <= query_row; ++r) {
            
            int requiredLiquidAtThisLevel = r + 1;
            long proporitionalFillValue = 0;
            std::vector<long> currenPascalTriangleRow;                        
            
            for(int c = 0; c <= r; ++c) {
                
                long top_left = c > 0  ? pascalTriangle[r-1][c-1] : 0;
                long top_right = c < r  ? pascalTriangle[r-1][c] : 0;
                
                currenPascalTriangleRow.push_back(top_left + top_right);
                proporitionalFillValue += top_left + top_right;
            }
            //printVec(currenPascalTriangleRow);
            pascalTriangle.push_back(currenPascalTriangleRow);
            
            if(proporitionalFillValue <= liquidAvailable) {
                liquidAvailable -= requiredLiquidAtThisLevel;
                glassCapacity.push_back(std::vector<double>(r+1, 1.0));
            } else {
                //now divide the liquid in the proporitions
                std::vector<double> currentGlassLevels;
                for(auto pascalValue : currenPascalTriangleRow) {
                    double glassLiquidFilled = 1.0/proporitionalFillValue * pascalValue * liquidAvailable;
                    glassLiquidFilled = std::min(1.0, glassLiquidFilled);
                    currentGlassLevels.push_back(glassLiquidFilled);
                }
                liquidAvailable -= proporitionalFillValue;
                glassCapacity.push_back(currentGlassLevels);
            }
        }        
        return glassCapacity[query_row][query_glass];
    }
    private:
    void printVec(std::vector<int> & a) {
        for(auto n : a) {
            std::cout << n << " ";
        }
        std::cout << "\n";
    }
};
