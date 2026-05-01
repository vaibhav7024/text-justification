class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int max) {
         vector<string> res,curr;
         int currlen =0;
         for(string & word:words){
            if(currlen + curr.size() + word.size()>max){
                for(int i=0;i<max-currlen;i++){
                    curr[i%(curr.size()-1?curr.size()-1:1)]+=' ';
                }
                res.push_back("");
                for(string& c:curr){
                    res.back()+=c;
                }
                curr.clear();
                currlen=0;
            }
            curr.push_back(word);
            currlen+=word.size();
         }
         string last = "";
         for(string& s:curr) last+=s+' ';
         last=last.substr(0,last.size()-1);
         while(last.size()<max) last+=' ';
         res.push_back(last);
         return res;
    }
};
