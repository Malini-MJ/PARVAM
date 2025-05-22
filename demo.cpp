#include<iostream>
using namespace std;
class Calci{
    public:
    int add(int a, int b);
    int subtract(int a , int b);
    int multiply(int a, int b);
    int divide(int a , int b);
    int mod(int a , int b);

    };
    int Calci::add(int a, int b){
        return a+b;
    }
    int Calci::subtract(int a, int b){
        return a-b;
    }
    int Calci::multiply(int a, int b){
        return a*b;
    }
    int Calci::divide(int a, int b){
        return a/b;
    }
     int Calci::mod(int a, int b){
        return a%b;
    }
int main(){
    Calci cal;
    cout<<"add"<<" "<<cal.add(10,5)<<endl;
    cout<<"subtract"<<" "<<cal.subtract(10,5)<<endl;
    cout<<"multiply"<<" "<<cal.multiply(10,5)<<endl;
    cout<<"divide"<<" "<<cal.divide(15,5)<<endl;
    cout<<"mod"<<" "<<cal.divide(68,4)<<endl;
    return 0;

}