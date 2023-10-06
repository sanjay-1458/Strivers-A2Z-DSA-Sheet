double median(vector<int>& a, vector<int>& b) {
	double v1=0,v2=0;
	int cnt=0,n=a.size()+b.size();
	int i=0,j=0;
	while(i<a.size() && j<b.size()){
		if(a[i]<=b[j]){
			cnt++;
			if(cnt==n/2){
				v1=a[i];
			}
			if(cnt==n/2+1){
				v2=a[i];
			}
			i++;
		}
		else{
			cnt++;
			if(cnt==n/2){
				v1=b[j];
			}
			if(cnt==n/2+1){
				v2=b[j];
			}
			j++;
		}
	}
	while(i<a.size()){
		cnt++;
		if(cnt==n/2){
			v1=a[i];
		}
		if(cnt==n/2+1){
			v2=a[i];
		}
		i++;
	}
	while(j<b.size()){
		cnt++;
		if(cnt==n/2){
			v1=b[j];
		}
		if(cnt==n/2+1){
			v2=b[j];
		}
		j++;
	}
	if(n%2==0){
		return (v1+v2)/2;
	}
	else{
		return v2;
	}
}
