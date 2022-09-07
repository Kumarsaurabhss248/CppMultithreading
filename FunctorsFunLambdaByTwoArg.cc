#include<iostream>
#include<functional>
#include<thread> 
using namespace std;

//Member function 
void fun(int x,int y){
    cout<<"Member Function Call X+Y="<<x+y<<endl;
} 
//Functors 
class fun_obj{
    public:
     void operator()(int x,int y){
        cout<<"Functors Sum of x="<<x<<" and y=" <<y<<" is ="<<x+y<<endl;
     }
};

int main(){
 
    thread t1{fun,4,5};
    thread t2{fun_obj(),5,10};
    //Lambda expression
    auto f=[] (int x,int y)
    {
        std::cout<<"Lambda Expression Sum of x="<<x<<" and y="<<y<<" is ="<<x+y<<endl;
    };
    thread t3{f,3,4};
    t1.join();
    t2.join();
    t3.join();
    return 0;
}
O/P:
Lambda Expression Sum of x=3 and y=4 is =7
Member Function Call X+Y=9
Functors Sum of x=5 and y=10 is =15  
