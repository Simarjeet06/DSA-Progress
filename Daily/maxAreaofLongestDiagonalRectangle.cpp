#include <vector>
using namespace std;
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonal=0;
        int maxArea=0;
        for(int i=0;i<dimensions.size();i++){
            int h=dimensions[i][0];
            int w=dimensions[i][1];
            int diag=(h*h)+(w*w);
            int area=h*w;
            if(diag>maxDiagonal || ((diag==maxDiagonal)&&(area>maxArea))){
                maxDiagonal=diag;
                maxArea=area;
            }
        }
        return maxArea;
    }
};