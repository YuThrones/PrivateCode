class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters)
    {
       sort(houses.begin(),houses.end());
       sort(heaters.begin(),heaters.end());
       int radius=-1;
       int j=0;
       for(int i=0;i<houses.size();i++)
       {
         while(j<heaters.size()-1 && abs(heaters[j+1]-houses[i])<=abs(heaters[j]-houses[i]))
        {
            j++;
            }
       int dist=abs(houses[i]-heaters[j]);
        radius=max(radius,dist);
       }
       return radius;
    }
};

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int result = 0;
        int i = 0;
        int j = 0;

        while(i < houses.size()) {
            // cout << houses[i] << " " << heaters[j] << " " <<result << endl;
            if (houses[i] + result < heaters[j]) {
                result = max(result, heaters[j] - houses[i]);
                ++i;
            }
            else if (houses[i] - result > heaters[j]) {
                while (j + 1 < heaters.size() && abs(houses[i] - heaters[j]) >= abs(houses[i] - heaters[j + 1])) {
                    ++j;
                }
                result = max(result, abs(houses[i] - heaters[j]));
            }
            else {
                ++i;
            }
        }
        return result;
    }
};