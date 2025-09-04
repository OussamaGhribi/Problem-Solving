class Solution {
public:
    int findClosest(int x, int y, int z) {
        int diff1 = 0,diff2 = 0;
        diff1 = abs(z - x);
        diff2 = abs(z - y);

        if(diff1 > diff2) return 2;
        if(diff1 < diff2) return 1;
        return 0;
    }
};
