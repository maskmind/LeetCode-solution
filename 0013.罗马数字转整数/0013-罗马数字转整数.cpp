class Solution {
public:
    int romanToInt(string s) {
       
        map<char,int> chToNum;//³õÊ¼»¯¹þÏ£±í
        chToNum.insert(map<char,int>::value_type('I',1));
        chToNum.insert(map<char,int>::value_type('V',5));
        chToNum.insert(map<char,int>::value_type('X',10));
        chToNum.insert(map<char,int>::value_type('L',50));
        chToNum.insert(map<char,int>::value_type('C',100));
        chToNum.insert(map<char,int>::value_type('D',500));
        chToNum.insert(map<char,int>::value_type('M',1000));
        int num=0;
        for (int i = 0; i < s.length(); ++i)
        {
            if((i+1)<s.length()&&chToNum[s[i]]<chToNum[s[i+1]]){
                num=num - chToNum[s[i]];
            }else{
                num=num + chToNum[s[i]];
            }
        }
        return num;

        
    }
};