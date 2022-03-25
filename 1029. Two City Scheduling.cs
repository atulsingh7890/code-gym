public class Solution {
    public int TwoCitySchedCost(int[][] costs) {
        int size = costs.Length;
        int[,] dpMatrix = new int[size/2 + 1, size/2 + 1];
        return TwoCitySchedulerCost(costs, dpMatrix, size/2, size/2, size - 1);
    }
    private int TwoCitySchedulerCost(int[][] costs, int[,] dpMatrix, int cityACount, int cityBCount, int currentPerson) {
        // we will go backwards from full list to last remaining person
        if(cityACount == 0 && cityBCount == 0) {
            return dpMatrix[cityACount,cityBCount];
        }
        
        if(cityACount < 0 || cityBCount < 0) {
            return Int32.MaxValue;
        }
        
        if(dpMatrix[cityACount,cityBCount] != 0) {
            return dpMatrix[cityACount,cityBCount];
        }
        
        int minCostIncludingCurrentPersonInCityA = TwoCitySchedulerCost(costs, dpMatrix, cityACount - 1, cityBCount, currentPerson - 1);
        if(minCostIncludingCurrentPersonInCityA != Int32.MaxValue) {
            minCostIncludingCurrentPersonInCityA += costs[currentPerson][0];
        }
        
        int minCostIncludingCurrentPersonInCityB = TwoCitySchedulerCost(costs, dpMatrix, cityACount, cityBCount - 1, currentPerson - 1);
        if(minCostIncludingCurrentPersonInCityB != Int32.MaxValue) {
            minCostIncludingCurrentPersonInCityB += costs[currentPerson][1];
        }
        
        dpMatrix[cityACount,cityBCount] = Math.Min(minCostIncludingCurrentPersonInCityA, minCostIncludingCurrentPersonInCityB);
        return dpMatrix[cityACount,cityBCount];
    }
}
