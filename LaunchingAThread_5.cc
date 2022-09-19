/*Using Move to a pass a rvalue to function */
#include<iostream>
#include<thread>
#include<string>
using namespace std;

/* By using move we can move the whole string to the caller argument and the ownership goes to the caller function from the main */
void func(string && s){ //Rvalue Reference

  cout<<"Ownership "<<s<<" transfered to thread "<<endl;
}
int main(){
      string s="abc";
      thread t{func, std::move(s)}; // Passing a value by move 

      t.join(); //Tells the main fucnction to stop til this thread runs

      cout<<"String is now "<<s<<endl; // If we try to access string it shows nothing as ownership not lies to main func

      return 0;
}

O/P:
Ownership abc transfered to thread 
String is now
