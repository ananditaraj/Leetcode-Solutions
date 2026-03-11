class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        string s=bitset<32>(n).to_string();
        s.erase(0,s.find('1'));

        int ns=s.length();
        for(char &c:s) 
        c=(c=='1'?'0':'1');
        return stoi(s,nullptr,2);        
    }
};