//not effecient; a better solution is to create hashtable for all alphabets and count the diff;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1_map; 
        for (auto& i: s1){
            s1_map[i] ++;
        }
    
        for(int i = 0; i < (s2.size()-s1.size()); i++){
            unordered_map<char, int> s2_map; 
            for (int j = i; j < (i+s1.size()); j++){
                s2_map[s2[j]]++;
            }
            bool flag = true;
            for (auto m: s1_map){
                flag &= (m.second == s2_map[m.first]);
            }
            if (flag == true) return true;
        }
        return false;
    }

};