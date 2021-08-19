#include <iostream>
#include <string>
class BankAccount
{
 public:
    BankAccount(int number, std::string owner, double funds) : number_(number), owner_(owner), funds_(funds) {}
    int number()
    {
        return number_;
    }
    std::string owner()
    {
        return owner_;
    }
    double funds()
    {
        return funds_;
    }
    void number(int number)
    {
        number_ = number;
        }
    void owner(std::string owner)
    {
        owner_ = owner;
    }
    void funds(double funds)
    {
        funds_ = funds;
    }

 private:
 int number_;
 std::string owner_;
 double funds_;
};
int main(){
 // TODO: instantiate and output a bank account
 BankAccount account(123456789, "David Silver", 1000000.01);

 std::cout << "Account Information\n";
 std::cout << "-------------------\n";
 std::cout << "ID: " << account.number() << "\n";
 std::cout << "Owner: " << account.owner() << "\n";
 std::cout << "Funds: $" << account.funds() << "\n";

 account.number(987654321);
 account.owner("Peter");
 account.funds(1000000.06);

 std::cout << "Account Information\n";
 std::cout << "-------------------\n";
 std::cout << "ID: " << account.number() << "\n";
 std::cout << "Owner: " << account.owner() << "\n";
 std::cout << "Funds: $" << account.funds() << "\n";
}