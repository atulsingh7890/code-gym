public class Solution 
{
    public string GetSmallestString(int n, int k) 
    {
        char[] result = Enumerable.Repeat('a', n).ToArray();
        
        for(int i = result.Length - 1; i >= 0; --i) 
        {
            // check if even if place z here, there would still be room left
            if( k > (26 + i))
            {
                result[i] = 'z';
            } 
            else
            {
                result[i] = Convert.ToChar('a' + k - (i + 1));
                break;
            }
            k -= 26;
        }
        
        return new string(result);
    }
}
