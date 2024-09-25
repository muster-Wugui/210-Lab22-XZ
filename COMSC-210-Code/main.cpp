//
//  main.cpp
//  COMSC-210-Code
//
//  Created by Xiao Zhang on 9/25/24.
//

#include<iostream>
using namespace std;
int main(){
    char x;
    cout<<"do you want to run this program?(y/n)"<<endl;
    cin>>x;
    if(x == 'y' || x == 'Y'){
        cout<<"Hello world"<<endl;
        cout<<"Finally!!!"<<endl;
    }
    else{
        cout<<"Okay"<<endl;
    }
    return 0;
}
