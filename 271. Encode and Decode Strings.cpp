//Length Header
//O(n) Time 
//O(1) Space
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string og;
        for(string str:strs){
            og+=to_string(str.length());
            og+="@";
            og+=str;
        }
        return og;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        while(s.length()){
            int pos=s.find("@");
            int len;
            if(pos==1)
                len=s[0]-'0';
            else
                len=stoi(s.substr(0,pos));
            string curr=s.substr(pos+1,len);
            s=s.substr(pos+len+1);
            res.push_back(curr);
        }
        return res;
    }
};