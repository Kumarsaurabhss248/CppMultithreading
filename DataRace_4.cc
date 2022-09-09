/*
• Can a data race occur in the following code sample, when func1 and func2 
are run as concurrent threads? Explain your answer
int x{0}, y{0};
void func1() {
x = 1;
int r1 = y;
}
void func2() {
y = 1;
int r2 = x;
}
*/
#include<iostream>
#include<thread>

using namespace std;

int x{0},y{0};

void fun1(){
    x=1;
    cout<<"thread1 x="<<x<<" y="<<y<<endl;
    int r1=y;
}
void fun2(){
    y=1;
    cout<<"thread2 x="<<x<<" y="<<y<<endl;
    int r2=x;
}
int main(){
    thread t1{fun1};
    thread t2{fun2};

    t1.join();
    t2.join();

    return 0;
}
/* O/P:
thread1 x=1 y=1
thread2 x=1 y=1
*/
/*
• It is possible for func1 to read y while func2 is modifying it, and vice versa for x.
• The accesses are not atomic and are not ordered, so we have a data race
*/
