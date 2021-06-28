//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3794/
public class Solution {
    public string RemoveDuplicates(string s) {
        Stack<char> st = new Stack<char>();
        foreach(char ch in s) {
            if(st.Count() != 0 && st.Peek() == ch) {
                st.Pop();
            } else {
                st.Push(ch);
            }
        }
        
        StringBuilder builder = new StringBuilder();
        while(st.Count() != 0 ) {
            builder.Append(st.Pop());
        }
        return new string(builder.ToString().Reverse().ToArray());
    }
}
