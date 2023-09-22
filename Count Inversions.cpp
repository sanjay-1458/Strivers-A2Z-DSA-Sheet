int cnt=0;
void merge(vector<int>&arr,int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    vector<int> temp;
    int L[n1],R[n2];
    for(int i=0;i<n1;++i){
        L[i]=arr[i+l];
    }
    for(int j=0;j<n2;++j){
        R[j]=arr[m+1+j];
    }
    int i=0,j=0,k=l;
    int rem=0;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            cnt+=n1-i;
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k]=R[j];
        k++;
        j++;
    }
}

void mergesort(vector<int>&arr,int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr,l,m,r);
    }
}

int numberOfInversions(vector<int>&a, int n) {
    // Write your code here.
    mergesort(a,0,n-1);
    return cnt;
}
