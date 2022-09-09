/* • Can a data race occur in the following code sample, when func1 and func2 are 
run as concurrent threads? Explain your answer
int x{0}, y{0};
void func1() {
if (x)
y = 1;
}
void func2() {
if (y)
x = 1;
}
• Write a program to exercise this code */

#include<iostream>
#include<thread>

using namespace std;

int x{0},y{0};

void fun1(){
    if(x){
        y=1;
        cout<<"Set y to 1"<<endl;
    }
}
void fun2(){
    if(y){
        x=1;
        cout<<"Set x to 1"<<endl;
    }
}
int main(){
    thread t1{fun1};
    thread t2{fun2};

    t1.join();
    t2.join();
    
    return 0;
}
/*
• In func1, x is always 0, so y is never set to 1. In func2, y is always 0, so x is never set to 1
• There is no possible execution path in which more than one thread tries to modify x or y
• The code is data-race free
*/
