public class Solution {
    public int CountMatches(IList<IList<string>> items, string ruleKey, string ruleValue) {
        
        int indexToLookFor = GetIndexOfKey(ruleKey);        
        int result = 0;
        foreach(var item in items) {
            if(item[indexToLookFor] == ruleValue) {
                result++;
            }            
        }        
        return result;    
    }
    
    private int GetIndexOfKey(string ruleKey){
        switch(ruleKey) {
            case "type":
                return 0;
            case "color":
                return 1;
            case "name":
                return 2;                
        }
        return -1;
    }
}
