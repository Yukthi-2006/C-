#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private: 
  string owner;
  double balance;
public:
  void open(const string &name, double initail){
    owner = name;
    balance = (initail > 0)? initail : 0;
   }
   void deposit(double amt){ if (amt>0) balance += amt;}
   bool withdraw (double  amt){ if (amt >0 && amt <= balance){balance -= amt; return true;}
   return false;
}
   double getbalance() const { return balance;}
   string getowner() const {return owner;}
};
int main(){
    BankAccount a;
    a.open("Asha",1000);
    a.deposit(500);
    if(! a.withdraw(200)) cout << "withdraw denied ( insufficient)\n";
    a.withdraw(300);
    cout << a.getowner() << "balance = " << a.getbalance() << endl;
    return 0;
}
