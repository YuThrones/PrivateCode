class Solution {
public:
    double radius;
    double x_center;
    double y_center;
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    vector<double> randPoint() {
        random_device rd;
        mt19937 gen(rd());
        std::uniform_real_distribution<> dis1(0, 1);
        double r = sqrt(dis1(gen)) * radius; // 这里必须平方，因为在区域内分布是跟半径平方成正比的，必须补偿，否则圆心会太密集
        double theta = dis1(gen) * 2 * M_PI;
        double x = r * cos(theta);
        double y = r * sin(theta);
        
        return {x + x_center, y + y_center};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */