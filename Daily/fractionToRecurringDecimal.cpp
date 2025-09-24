class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        long long num=llabs((long long)numerator);
        long long den=llabs((long long)denominator);
        string result;
        if((numerator<0)^(denominator<0)){
            result+="-";
        }
        long long quotient=num/den;
        long long rem=num%den;
        result+=to_string(quotient);
        if(rem==0) return result;
        result+=".";
        unordered_map<long long,int> mpp;
        while(rem){
           if(mpp.count(rem)){
            int pos=mpp[rem];
            result.insert(pos,"(");
            result+=")";
            return result;
           }
           mpp[rem]=result.size();
           num=rem*10;
           quotient=num/den;
           rem=num%den;
           result+=to_string(quotient);
        }
        return result;
    }
};