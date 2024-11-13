class Solution {
public:
    int height(vector<int>v)
{
    int n=v.size();
    stack<int>st;
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        while(!st.empty()&&v[st.top()]>v[i])
        {
            int f=st.top();
            st.pop();
            if(!st.empty())
                ans=max(ans,v[f]*(i-st.top()-1));
            else
                ans=max(ans,v[f]*(i));
        }
        st.push(i);
    }
    while(!st.empty())
    {
        int f=st.top();
        st.pop();
        if(!st.empty())
        {
            ans=max(ans,v[f]*(n-st.top()-1));
        }
        else
            ans=max(ans,v[f]*n);
    }
    return ans;
}



    int maximalRectangle(vector<vector<char>>&v) {
          int row =v.size();
    int c=v[0].size();
    int maxi=INT_MIN;
    vector<int>arr(c);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(v[i][j]=='1')
            arr[j]=arr[j]+1;
            if(v[i][j]=='0')
            arr[j]=0;
        }
        maxi=max(maxi,height(arr));
        
    }
    return maxi;
    }
};