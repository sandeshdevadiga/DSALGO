class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        bool ret=false;
        int temp=std::gcd(x,y);
        std::cout<<"value " <<temp<<std::endl;
        if(target % temp ==0 && target <= (x+y))
        {
            ret=true;
        }
        return ret;
    }
};  