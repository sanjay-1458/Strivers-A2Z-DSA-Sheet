bool searchInARotatedSortedArrayII(vector<int>&A, int key) {
    // Write your code here.'
    int low=0,high=A.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(A[mid]==key){
            return true;
        }
        if(A[low]==A[mid] && A[mid] == A[high]){
            low++;high++;
            continue;
        }
        if(A[mid]<=A[high]){
            if(key>A[mid] && key<=A[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        else{
            if(key>=A[low] && key<A[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    }
    return false;
}
