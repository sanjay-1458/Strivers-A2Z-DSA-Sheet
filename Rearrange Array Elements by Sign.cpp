vector<int> alternateNumbers(vector<int>&a) {
    // Write your code here.
    int n=a.size();
    for(int i=0;i<n;++i){
        if(i%2==0){
            if(a[i]<0){
                int ind=-1;
                for(int j=i+1;j<n;++j){
                    if(a[j]>0){
                        ind=j;
                        break;
                    }
                }
                if(ind==-1) continue;
                int val=a[ind];
                for(int k=ind;k>i;--k){
                    a[k]=a[k-1];
                }
                a[i]=val;
            }
            else{
                continue;
            }
        }
        else{
            if(a[i]>0){
                int ind=-1;
                for(int j=i+1;j<n;++j){
                    if(a[j]<0){
                        ind=j;
                        break;
                    }
                }
                if(ind==-1) continue;
                int val=a[ind];
                for(int k=ind;k>i;--k){
                    a[k]=a[k-1];
                }
                a[i]=val;
            }
            else{
                continue;
            }
        }
    }
    return a;
}
