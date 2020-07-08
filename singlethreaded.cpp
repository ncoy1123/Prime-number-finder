#include <iostream>
using namespace std;

int main() {
   int n=46000000, i;
   bool isPrime = true;

   
  while(n<50000000){

   for (i = 2; i <= n / 2; ++i) {
      if (n % i == 0) {
         isPrime = false;
         break;
      }
   }
   if (isPrime){
      cout << n <<endl;}
   else{
   isPrime = true;}
     
n++;
}

   return 0;
}

