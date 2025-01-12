class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //unsorted array
        //use collection
        //we are using stack
        if(heights.size()== 0)
        {
            return 0;
        }
        if(heights.size()==1)
        {
            return heights[0];
        }
        
        int maxv=0;
        
        std::stack<int> st;
        st.push(0);
        for(int i=1; i<heights.size(); i++)
        {
            if(heights[i]>heights[st.top()])
            {
                st.push(i);
            }
            else
            { 
                while(!st.empty()  && heights[i] < heights[st.top()])
                {
                   int temp=heights[st.top()];st.pop();
                    if(st.empty())
                    {
                     maxv=max(maxv, (i ) * temp);                 
                    }
                    else
                     maxv=max(maxv, temp* (i- ( st.top()+1)));           
                          
                }
                st.push(i);   
            }    
        
        }
        if(!st.empty())
        {
            int i=heights.size();
            while(!st.empty())
                {int temp=heights[st.top()];st.pop();
                    if(st.empty())
                    {
                     maxv=max(maxv, (i ) * temp);                 
                    }
                    else
                     maxv=max(maxv, temp* (i- ( st.top()+1)));       
                }
        }
        
        
        return maxv;
    }
};