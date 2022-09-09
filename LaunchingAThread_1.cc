/* Thread Function without argument */
/* • Rewrite the "Hello thread" program so that the thread entry point is
• A functor (a class with an overloaded () operator)
• A lambda expression
• A member function of a class */

#include<iostream>
#include<thread>

using namespace std;

//Callable object- thread entry point
void hello(){
    std::cout<<"Hello Thread Function\n";
}

//Functor class with Overloaded Operator
class hellothread{
      public:
      void operator() () { std::cout<<"Hello Thread Functor!\n"; }
};

int main(){

    thread t1{hello};
    thread t2{hellothread()};
    auto f=[] () { cout<<"Lambda Expression\n"; };
    //std::thread t { [] () { std::cout << "Hello, Thread!\n";}};    
    thread t3(f);

    t1.join();
    t2.join();
    t3.join();
 
}
