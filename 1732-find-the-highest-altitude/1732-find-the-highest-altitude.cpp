class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        // Initialize the maximum altitude and current altitude
        int maxAltitude = 0;  // The highest altitude reached (starts at 0)
        int currentAltitude = 0;  // Current altitude at each point
      
        // Iterate through each altitude gain value
        for (int altitudeGain : gain) {
            // Update current altitude by adding the gain
            currentAltitude += altitudeGain;
          
            // Update maximum altitude if current altitude is higher
            maxAltitude = max(maxAltitude, currentAltitude);
        }
      
        // Return the highest altitude reached
        return maxAltitude;
    }
};
