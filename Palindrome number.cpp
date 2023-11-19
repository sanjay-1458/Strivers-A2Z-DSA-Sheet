#include <iostream>
#include <cmath>
bool palindrome(int n)
{
    int num=n;
    while(num>9){
        int rem=num%10;
        int p=log10(num);
        int np=p-1;
        int r=pow(10,p);
        int front=(num-num%r)/pow(10,p);
        // cout<<front<<" "<<rem;
        // cout<<num<<" ";
        if(front!=rem){
            return false;
        }
        num=num%r;
        num=num/10;
    }
    return true;
}
