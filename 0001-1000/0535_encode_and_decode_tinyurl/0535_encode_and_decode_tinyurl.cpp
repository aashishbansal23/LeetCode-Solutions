class Solution {
    int count = 0;
    unordered_map<string, string> mp;
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string temp = "http://tinyurl.com/abcd" + to_string(count++);
        mp[temp] = longUrl;
        return temp;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if(mp.count(shortUrl) > 0){
            return mp[shortUrl];
        }else{
            return "";
        }
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));