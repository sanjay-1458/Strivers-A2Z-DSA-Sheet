bool fun(int i,string &str){
    if(i>=str.size()/2) return true;
    if(str[i]==str[str.size()-i-1]){
        return fun(i+1,str);
    }
    else{
        return false;
    }
}

bool isPalindrome(string& str) {
    return fun(0,str);
}
