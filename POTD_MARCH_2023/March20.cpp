class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        if(m == 1){
            if(flowerbed[0] == 0 && n <= 1) return true;
            if(flowerbed[0] == 1 && n == 0) return true;
            else return false;
        }
        int count = 0;
        for(int i=0; i<m-1; i++){
            if(i == 0){ //boundary case
                if(flowerbed[i] == 0 && flowerbed[i+1] == 0){
                    flowerbed[i] = 1;
                    count++;
                }
            }
            else if(i == m-2){ //boundary case
                if(flowerbed[m-2] == 0 && flowerbed[m-1] == 0){
                    flowerbed[m-1] = 1;
                    count++;
                }
            }
            else{   
                if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
                    flowerbed[i] = 1;
                    count++;
                }
            }
        }
        return n <= count;
    }
};
