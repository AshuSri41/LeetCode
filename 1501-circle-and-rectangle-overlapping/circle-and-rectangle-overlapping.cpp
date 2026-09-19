class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        for(int x = x1; x <= x2; x++) {
            for(int y = y1; y <= y2; y++) {
                int dx = x - xc;
                int dy = y - yc;

                if(dx * dx + dy * dy <= r * r)
                    return true;
            }
        }

        return false;
    }
};