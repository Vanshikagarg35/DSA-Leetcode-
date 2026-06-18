class Solution {
public:
    double angleClock(int hour, int minutes) {
        double totalmin = (hour % 12) * 60 + minutes;
        
        double hour_angle = 0.5 * totalmin;
        double minute_angle = minutes * 6.0;
        
        double diff = abs(hour_angle - minute_angle);
        
        return min(diff, 360.0 - diff);
    }
};