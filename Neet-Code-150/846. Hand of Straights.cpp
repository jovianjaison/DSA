//Greedy
//O(nlogn + n) Time
//O(n) Space
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> m;

        for(int card:hand){
            m[card]++;
        }

        for(auto card:m){
            int cardVal=card.first;
            int cardCount=card.second;

            while(m[cardVal]>0){
                m[cardVal]--;
                for(int i=1;i<groupSize;i++){
                    if(m[cardVal+i]>0){
                        m[cardVal+i]--;
                    }else{
                        return false;
                    }
                }
            }
        }

        return true;
    }
};