class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        string num = "";

        string tempN = to_string(n);
        for(int i = 0 ; i < tempN.size(); i++){
            if(tempN[i] != '0') num+= tempN[i];
        }
        long long x = stoi(num);
        long long temp = x;
        
        long long sum = 0;
        while(x != 0){
            sum += (x%10);
            x = x/10;
        }

        return temp*sum;
    }
};