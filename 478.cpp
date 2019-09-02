// A = PI * R * R * rand[0,1];
// nR = R * sqrt(rand[0,1]);

class Solution {
public:
    double x, y, r;
    Solution(double radius, double x_center, double y_center) {
        x = x_center;
        y = y_center;
        r = radius;
    }
    
    vector<double> randPoint() {
        double rr = r * sqrt(rand() / double(RAND_MAX));
        double ra = 2 * M_PI * (rand() / double(RAND_MAX));
        double nx = x + rr * cos(ra);
        double ny = y + rr * sin(ra);
        return {nx, ny};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
