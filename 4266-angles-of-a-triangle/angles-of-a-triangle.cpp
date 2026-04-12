class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<int>copy = sides;
        sort(sides.begin() , sides.end());

        if(sides[0] + sides[1] <= sides[2]) return {};
        double a = sides[0] , b = sides[1] , c = sides[2];
        double A = acos((b*b + c*c - a*a)/(2 * b * c));
        double B = acos((a*a + c*c - b*b)/(2 * a * c));
        double C = acos((b*b + a*a - c*c)/(2 * b * a));

        double x = A*(180 / M_PI);
        double y = B*(180 / M_PI);
        double z = C*(180 / M_PI);


        vector<double>ans ={x , y ,z};
        sort(ans.begin() , ans.end());
        return ans;
    }
};