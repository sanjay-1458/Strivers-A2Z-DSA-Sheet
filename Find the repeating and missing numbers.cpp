vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
    int sum1=0,sum2=0,n=a.size();
    for(int i=0;i<n;++i){
        sum1+=a[i];
        sum2+=a[i]*a[i];
    }
    int y_x=n*(n+1)/2-sum1;
    long long int y2_x2=n*(n+1);
    y2_x2*=(2*n+1);
    y2_x2/=6;
    y2_x2-=sum2;
    int y_p_x=(int)y2_x2;
    y_p_x/=y_x;
    int y=(y_p_x+y_x)/2;
    int x=y_p_x-y;
    vector<int> v={x,y};
    return v;
}



