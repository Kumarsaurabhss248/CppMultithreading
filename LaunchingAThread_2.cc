/*Thread calling function with argument */
/* • Write a program with a thread that receives one int, prints their values
• Use
• A regular function
• A functor
• A lambda expression
*/
#include<iostream>
#include<functional>
#include<thread> 
using namespace std;

//Member function 
void fun(){
    std::cout<<"Hello thread functon\n";
} 
//Functors 
class fun_obj{
    public:
     void operator()(int x){
        cout<<"Hello Fun Object X="<<x <<endl;
     }
};

int main(){
 
    thread t1{fun};
    thread t2{fun_obj(),5};
    //Lambda expression
    auto f=[] (int x)
    {
        std::cout<<"Hello thread Called in Lambda Expression X="<<x<<endl;
    };
    thread t3{f,3};
    t1.join();
    t2.join();
    t3.join();
    return 0;
}
O/P:
Hello thread functon
Hello thread Called in Lambda Expression X=3
Hello Fun Object X=5
