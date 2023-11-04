#include <bits/stdc++.h>

bool isAnagram(string str1, string str2)
{
    unordered_map<char,int> mp;
    if(str1.size()!=str2.size()){
        return false;
    }
    for(int i=0;i<str1.size();++i){
        mp[str1[i]]++;
    }
    for(int i=0;i<str2.size();++i){
        if(mp.find(str2[i])!=mp.end()){
            mp[str2[i]]--;
            if(mp[str2[i]]==0){
                mp.erase(str2[i]);
            }
        }
        else{
            return false;
        }
    }
    if(mp.size()>0){
        return false;
    }
    return true;
}
