public class Solution {
    public string SimplifyPath(string path) 
    {
        Stack<string> st = new Stack<string>();
        
        string result = new string("");
        
        for(int i = 0; i < path.Length; ++i) 
        {
            if(path[i] == '/')
            {
                continue;
            }
            
            string temp = new string("");
            while( i < path.Length && path[i] != '/') 
            {
                temp += path[i];
                ++i;
            }
            if(temp == ".")
            {
                continue;
            }
            else if(temp == "..")
            {
                if(st.Count != 0)
                {
                    st.Pop();
                }
            }
            else 
            {
                st.Push(temp);
            }
        }
        
        
        while(st.Count != 0)
        {
            result = "/" + st.Peek() + result;
            st.Pop();
        }
        
        if(result.Length == 0)
            result = "/";
        
        return result;
    }
}
