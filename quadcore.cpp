// g++ -std=c++11 -pthread
#include <iostream>
#include <thread>
#include <atomic> 
#include <fstream>

using namespace std;

void prime(atomic_int& n){
 int i, z = 1, t=n;
 bool isprime = true;
 
 n.fetch_add(1000);
 t=n;
 
 while(z<1000){
   for (i = 2; i <= t / 2; ++i) {
     if ( t % i == 0) {
      isprime = false;
      break;
      }}
      
  if (isprime){
    ofstream myfile("50mil.txt", std::ios_base::app);
    myfile<<t<<endl;
    myfile.close();
    }
  else{
    isprime=true;}
    t=t+1;
    n=t;
    }}
    
int main() {
 int g, i,z = 1;
 bool isPrime = true;
 
 cin>>g;//starting number
 g=g-1000;
 atomic_int n(g);
  
 thread first (prime, ref(n));
 thread second (prime, ref(n));
 thread third (prime,ref(n));
 thread fourth (prime, ref(n));
 first.join();              
 second.join();
 third.join();
 fourth.join();

 while(n<10000){
   thread first (prime, ref(n));
   thread second (prime, ref(n));
   thread third (prime, ref(n));
   thread fourth (prime, ref(n));
 }
 return 0;}
