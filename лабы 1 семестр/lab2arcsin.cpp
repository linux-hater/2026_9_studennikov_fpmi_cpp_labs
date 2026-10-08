#include <iostream>
#include <cmath>
using namespace std;
    int main() {
        cout << "input -1<x<1" << std::endl;
        long double eps=1e-10, result=0, x, k_n, sum;
        cin >>x;
        sum=x;
        k_n=x;
        int k=0;
        //BAZOVIY SLUCH к=0
        result = k_n;



        while(eps<fabs(k_n)){

           result=k_n*(x*x)*(2*k+1)*(2*k+1)/(2.0*(k+1)*(2*k+3));
            sum += result;
            k_n=result;
            k++;

        }
        cout<<"result="<<sum<<endl;






    }