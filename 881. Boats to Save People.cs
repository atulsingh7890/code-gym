public class Solution {
    public int NumRescueBoats(int[] people, int limit) {
        
        Array.Sort(people);
        
        int start = 0, end = people.Length - 1;
        int boats = 0;
        while( start <= end)
        {
            boats++;
            if(people[start] + people[end] <= limit)
            {
                start++;
            }
            end--;
        }
        return boats;
    }
}
