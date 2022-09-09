/* • Can a data race occur in the following code sample, when func1 and 
func2 are run as concurrent threads? Explain your answer
const int x{5};
int func1() {
return 2*x;
}
int func2() {
return 3*x;
}
*/

#include<iostream>
#include<thread>

const int x{5};

using namespace std;

int fun1(){
    cout<<"Fun1 Called by thread 1 2*x="<<2*x<<endl;
    return 2*x;
}
int fun2(){
    cout<<"Fun2 Called by thread 2 3*x="<<3*x<<endl;
    return 3*x;
}
int main(){
     thread t1{fun1};
     thread t2{fun2};

     t1.join();
     t2.join();
     return 0;
}
/* O/P:
Fun2 Called by thread 2 3*x=15
Fun1 Called by thread 1 2*x=10
*/

/*
• x is const, so no thread can modify it
• There is no possibility of conflicting accesses to x (unless a thread dangerously 
casts away const)
• The code shown is data-race free
*/
