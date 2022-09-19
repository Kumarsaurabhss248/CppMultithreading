/* A group of children sit in a circle, counting numbers out loud.
The first child says "one", the second child says "two", and so on.
However, if the number is divisible by 3, they say "fizz" instead of the number. If the number is divisible by 5, they say "buzz", and if the number is divisible 
by 3 and by 5, they say "fizzbuzz".
Write a function which produces the output from a game of Fizzbuzz
Abdul says 1
Bart says 2
Claudia says fizz!
Divya says 4
Abdul says buzz!
Bart says fizz!
Claudia says 7
Divya says 8
and so on... */

#include<iostream>
#include<thread>
#include<string> 
using namespace std;

void fun(string s[],int n,const int max_num){

    for(int i=0;i<max_num;i++){
        if((i+1)%3==0 && (i+1)%5==0){
          cout<<s[i%n]<<" says fizzbuz!"<<" ";
        }else if((i+1)%3==0){
            cout<<s[i%n]<<" says fizz!"<<" ";
        }else if((i+1)%5==0){
            cout<<s[i%n]<<" says buzz!"<<" ";
        }else{
            cout<<s[i%n]<<" says "<<i+1<<" ";
        }
    
    }
} 

int main()
{
    string s[]={"Abdul","Bart", "Claudia", "Divya"};
    const int max_num=20;
    int n=4;
    thread t1{fun,s,n,max_num};
    t1.join();
    return 0;
}

O/P:-
Abdul says 1 Bart says 2 Claudia says fizz! Divya says 4 Abdul says buzz! Bart says fizz! Claudia says 7 Divya says 8 Abdul says fizz! Bart says buzz! 
Claudia says 11 Divya says fizz! Abdul says 13 Bart says 14 Claudia says fizzbuz! Divya says 16 Abdul says 17 Bart says fizz! Claudia says 19 Divya says buzz! 
