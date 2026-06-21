class Solution {
public:
    int compress(vector<char>& chars) {
        int size = chars.size();
        if(size < 2){
            return size;
        }
        char ch = chars[0];
        int count = 1;
        int k = 0;
        int i = 1;
        while(i < size){
            while(i<size && ch==chars[i]){
                i++;
                count++;
            }
            if(count == 1){
                chars[k++] = ch;
            }else{
                string s = to_string(count);
                chars[k++] = ch;
                for(auto j:s){
                    chars[k++] = j;
                }
            }
            if(i == size){
                return k;
            }
            ch = chars[i];
            count = 1;
            i++;
        }
        chars[k++] = ch;
        return k;
    }
};