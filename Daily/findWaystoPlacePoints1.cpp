#include<vector>
using namespace std;
class Solution {
public:
 
    int numberOfPairs(vector<vector<int>>& points) {
       int n=points.size();
    //     for(int i=0;i<n;i++){
    //       points[i][1]=-points[i][1];
    //     }
    //     int ymax=INT_MIN;
    //     int ans=0;
    //     sort(begin(points),end(points));
    //     for(int i=0;i<n;i++){
    //         int x=points[i][0];
    //         int y=-points[i][1];
    //         int ymax=INT_MIN;
    //         for(int j=i+1;j<n;j++){
    //             int x1=points[j][0];
    //             int y1=-points[j][1];
    //             if(y1>ymax && y1<=y){
    //                 ans++;
    //                 ymax=max(ymax,y1);
    //             }
    //         }
    //     }
    //     return ans;
    //approach-1: brute force; o(n^3)
    // int res=0;
    // for(int i=0;i<n;i++){
    //     //point A
    //    int x1=points[i][0];
    //    int y1=points[i][1];
    //     for(int j=0;j<n;j++){
    //         if(i==j) continue;
    //      //point B
    //      int x2=points[j][0];
    //      int y2=points[j][1];
    //      if(x2>=x1 && y1>=y2){
    //           bool insideRectangle=false;
    //         //a and b are valid and hence need to check if it forms a rectangle consisting of some other point or not
    //         for(int k=0;k<n;k++){
    //             if(i==k || j==k) continue;
    //             int x3=points[k][0];
    //             int y3=points[k][1];
    //             if(x3>=x1 && x3<= x2 && y3>=y2 && y3<=y1){
    //                 insideRectangle=true;
    //                break;
    //             }
    //         }
    //         if(!insideRectangle) res++;
    //      }
    //     }
    // }
    // return res;

    //Approach-2: o(n^2)
 auto lambda=[](vector<int>& point1,vector<int>& point2){
    if(point1[0]==point2[0]){
        return point1[1]>point2[1];
    }
     return point1[0]<point2[0];
  };
    int res=0;
    sort(begin(points),end(points),lambda);
    for(int i=0;i<n;i++){
        int x1=points[i][0];
        int y1=points[i][1];
        int ymax=INT_MIN;
        for(int j=i+1;j<n;j++){
            int x2=points[j][0];
            int y2=points[j][1];
            //since this point is on right but not lower hence this is not valid.
            if(y2>y1) continue;
            if(y2>ymax){
                //no point lies in between
                res++;
                ymax=y2;
            }
        }
    }
return res;
    }
};