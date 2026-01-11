class Solution {
public:
    int fn(vector<int>&h){

        stack<int>st;
        int ans = 0;
        for(int i = 0; i < h.size(); i++){

            int hgt = h[i];
            while(!st.empty() && h[st.top()] > hgt){
                int nse = i;
                int eleidx = st.top();
                st.pop();
                int pse = -1;
                if(!st.empty()){
                    pse = st.top();
                }
                ans = max(ans,h[eleidx]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = h.size();
            int pse = -1;
            int eleidx = st.top();
            st.pop();
            if(!st.empty()){
                pse = st.top();
            }
            ans = max(ans,h[eleidx]*(nse-pse-1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<vector<int>>presm;
        int r = matrix.size();
        int c = matrix[0].size();
        for(int i = 0; i< c; i++){
            vector<int>temp(r,0);
            for(int j = 0; j < r; j++){
                if(matrix[j][i] == '1'){
                    if(j == 0){
                        temp[j] = 1;
                    }
                    else{
                        temp[j] += temp[j-1]+1;
                    }
                }
                else temp[j] = 0;
            }
            presm.push_back(temp);
        }
        vector<vector<int>>h;
        for(int i = 0; i < r; i++){
            vector<int>temp;
            for(int j = 0; j < presm.size(); j++){
                temp.push_back(presm[j][i]);
            }
            h.push_back(temp);
        }
        int ans = 0;
        for(int i = 0; i < r; i++){
            int temp = fn(h[i]);
            ans = max(ans,temp);
        }
        return ans;
    }
};