/*
• Can a data race occur in the following code sample, when func1 and func2 are 
run as concurrent threads? Explain your answer
int x{0};
bool done;
void func1() {
std::this_thread::sleep_for(50ms);
x = 42;
done = true;
}
void func2() {
std::this_thread::sleep_for(50ms);
while (!done) {}
std::cout << x << std::endl;
}
*/
#include<iostream>
#include<thread>
#include<chrono>

using namespace std;
using namespace std::literals;

int x{0};
volatile bool done{false};

void fun1(){
    std::this_thread::sleep_for(50ms);
    x=42;
    done=true;
}
void fun2(){
    std::this_thread::sleep_for(50ms);
    while(!done){ }
    cout<<x<<endl;
}
int main(){
    thread t1{fun1};
    thread t2{fun2};

    t1.join();
    t2.join();

    return 0;
}
//O/P:42

/* 
• There are two data races, on x and done
• The compiler optimizes the loop in func2, because it does not know 
that done can be modified by func1
• It assumes done is a constant. This allows it to generate more efficient 
code, but causes the loop to run for ever
• We can declare done as "volatile" to prevent this optimization
• In Java and C#, the volatile keyword means that modifying done will be 
performed as an atomic operation. This removes the data race on done
• However, in C++ we use a different keyword for atomic operations. The data 
race on done will still exist if it is declared volatile, even though the loop will 
now run correctly
*/
