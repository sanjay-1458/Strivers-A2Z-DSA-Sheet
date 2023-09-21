vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(),arr.end());
    int i=0,j=1,k=n-1;
    vector<vector<int>> v;
    while(i<n-2){
        j=i+1;k=n-1;
        int val1=arr[i];
        while(j<k){
            if(arr[i]+arr[j]+arr[k]<0){
                int val2=arr[j];
                while(val2==arr[j]){
                    j++;
                }
            }
            else if(arr[i]+arr[j]+arr[k]==0){
                v.push_back({arr[i],arr[j],arr[k]});
                int val2=arr[j];
                while(val2==arr[j]){
                    j++;
                }
            }
            else{
                int val2=arr[k];
                while(val2==arr[k]){
                    k--;
                }
            }
        }
        while(val1==arr[i]){
            i++;
        }
    }
    return v;
}
