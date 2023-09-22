void merge(int arr[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;++i){
        L[i]=arr[l+i];
    }
    for(int i=0;i<n2;++i){
        R[i]=arr[m+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    // Write Your Code Here
    if(l<r){
        int mid=l+(r-l)/2;
        mergeSort(arr,  l, mid);
        mergeSort(arr,  mid+1, r);
        merge(arr,l,mid,r);
    }
}
