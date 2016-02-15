class countAndSayClass{
public:
    static string countAndSay(int n) {
        // Write your code here
        string tmp = "1";
        for(int i = 0 ; i < n - 1; i ++){
            tmp = countStr(tmp);
        }
        return tmp;
    }

    static string countStr(string input){
        if(input.length() == 0) return "";
        char lastChr = input[0];
        string out = "";
        int counter = 1;
        for(int i = 1; i < input.length(); i ++){
            if(input[i] == lastChr){
                counter++;
            }else{
                out += to_string(counter) + lastChr;
                lastChr = input[i];
                counter = 1;
            }
        }
        out +=  to_string(counter) + lastChr ;
        return out;
    }

    static string countStrTogether(string s){
        if(s.length() == 0) return "";
        unordered_map<char, int> myMap;
        vector<char> order;
        for(int i = 0; i < s.length() ; i ++){
            if(myMap.find(s[i]) == myMap.end()){
                myMap.insert(make_pair(s[i],1));
                order.push_back(s[i]);
            }else{
                myMap[s[i]]++;
            }
        }
        string out = "";
        for(auto &i : order){
            out += i;
            out += to_string(myMap[i]);
        }
        return out;
    }
};

int main(){
    string case1 = "112232323132221ababjdiwjwiwoaaaddwp";
    cout << countAndSayClass::countStr(case1) << endl;
    cout << countAndSayClass::countStrTogether(case1) << endl;
    return 0;
}
