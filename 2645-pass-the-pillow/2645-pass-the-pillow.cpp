class Solution {
public:
    int passThePillow(int n, int time) {
        int position = 1;
        bool forward = true;

        while(time>0){
            if(forward){
                position++;
                if(position==n){
                    forward = false;
                }
            }
            else{
                position--;
                if(position==1){
                    forward = true;
                }
            }
            time--;
        }
        return position;
    }
};