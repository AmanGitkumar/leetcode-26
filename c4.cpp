class Solution {
public:

    double fn(double mid,vector<vector<int>>&squares){
        double sm = 0;
        int n = squares.size();
        for(int i = 0; i < n; i++){
            if(squares[i][1]+squares[i][2] <= mid){
                sm += (double)squares[i][2]*squares[i][2];
            }
            else if(squares[i][1] < mid){
                sm += (squares[i][2])*(mid-squares[i][1]);
            }
        }
        return sm;
    }
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        double low = 0.0;
        double high = 0.0;
        for(int i = 0; i < n; i++){
            high = max(high,(double)squares[i][1]+squares[i][2]);
        }
        double total = 0;
        for(int i = 0; i < n; i++){
            total += (double)squares[i][2]*squares[i][2];
        }
        for(int i = 0; i < 55; i++){
            double mid = low + (high-low)/2;
            double temp = fn(mid,squares);
            
            if(temp >= total/2.0){
                high = mid;
            }
            else low = mid;
        }

        return high;
    }
};