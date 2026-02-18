class Solution {
public:
    bool hasAlternatingBits(int n) {

        // approach 1

        // bitset<32> b(n);
        // int bits = log2(n);
        // for(int i =0; i<bits; i++){
        //     if(b[i] == b[i+1]){
        //         return false;
        //     }
        // }
        // return true;  

        // approach 2

        //   int current = n%2;
        // n = n/2;
        // while(n>0){
        //     if(current == n%2 ){
        //         return false;
        //     }
        //     current = n%2;
        //     n = n/2;
        // }
        // return true;

        // approach 3

        unsigned int result = n ^ (n>>1); // result ki value int se bahar ja rhi ha islye
                                        // unsigned use kiya ha
        return (result & (result+1))==0;
    }
};