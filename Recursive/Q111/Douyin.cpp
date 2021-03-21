//
// Created by yann on 2021/3/21.
//

#include "vector"
#include "iostream"

using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...

    int banana[200];
    string c;
    int i=0;
    int n;


    int num;




    while(cin>>num){
        if (cin.get() == '\n')break;
        banana[i] = num;
        i++;
    }


    int sum=banana[i-1];

    for(n=i-2;n>=0;n--){
        if(banana[n]>sum) sum = 2*banana[n];
        else sum+=banana[n]*2;
    }

    cout << sum;
    return 0;
}


