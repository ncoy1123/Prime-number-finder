// g++ -std=c++11 -pthread

#include <iostream>
#include <thread>
#include <atomic> 
using namespace std;

void prime(atomic_int& n){
 int i, z = 1, t;
 bool isprime = true;
 n.fetch_add(1000);
 t=n;
 while(z<1000){
   for (i = 2; i <= t / 2; ++i) {
     if ( t % i == 0) {
      isprime = false;
      break;}}
   if (isprime){
     cout << t<<endl;}
   else{
    isprime=true;}
    t=t+1;
    n=t;}}
    
int main() {
atomic_int n(1);
 int i,z = 1;
 bool isPrime = true;
  
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
