#include<iostream>

int FactorialR(int n){
  if(n == 1 || n == 0)
    return 1;
  return n * FactorialR(n-1);
}

int FactorialI(int n){
  int x{1}, fact{1};
  while(x <= n){
    fact *= x;
    x++;
  }
  return fact;
}
int main(){
  int i;
  std::cin >> i;
  std::cout << FactorialR(i) << std::endl;
  std::cout << FactorialI(i);
  return 0;
}
