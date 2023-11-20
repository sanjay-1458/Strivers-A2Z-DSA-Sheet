//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
	public:
    int gcd1(int A, int B) 
	{ 
	    int num=min(A,B);
	    while(num>0){
	        if(A%num==0 && B%num==0){
	            return num;
	        }
	        else{
	            num--;
	        }
	    }
	    return 1;
	      
	} 
	int fun2(int a,int b){
	    if(a==b){
	        return a;
	    }
	    if(a>b){
	        return fun2(a-b,b);
	    }
	    else{
	        return fun2(a,b-a);
	    }
	}
	int gcd2(int a,int b){
	    return fun2(a,b);
	}
	int fun3(int a,int b){
	    if(b==0){
	        return a;
	    }
	    return fun3(b,a%b);
	}
	int gcd3(int a,int b){
	    return fun3(a,b);
	}
	int gcd(int a,int b){
	   while(a>0 && b>0){
	       if(a>b){
	           a=a%b;
	       }
	       else{
	           b=b%a;
	       }
	   }
	   if(a==0){
	       return b;
	   }
	   else{
	       return a;
	   }
	}
};

//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        Solution ob;
       	cout <<  ob.gcd(A, B) << "\n";
    }
    return 0;
}
// } Driver Code Ends
