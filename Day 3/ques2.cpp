#include <iostream>
#include <vector>

using namespace std;

class ATM
{
private:
    // To store the denomination and number of notes
    vector<pair<int, int>> denominations;
    int balance = 0;

public:
    ATM()
    {
        denominations = {{2000, 0}, {500, 0}, {200, 0}, {100, 0}};
        balance = 0;
    }

    // Method to add number of notes
    void addDenominations(int amount, int twoThousand, int fiveHundred, int twoHundred, int hundred)
    {
        if (amount % 100 != 0)
        {
            cout << "This amount cannot be added. Amount should be in the multiples of 100." << endl;
            return;
        }

        denominations[0].second += twoThousand;
        denominations[1].second += fiveHundred;
        denominations[2].second += twoHundred;
        denominations[3].second += hundred;

        balance += amount;

        cout << "Amount added!" << endl;
    }

    // Method to withdraw the amount
    void withdraw(int amountToBeWithdrawed)
    {
        int amount = amountToBeWithdrawed;
        if (amount % 100 != 0)
        {
            cout << "This amount cannot be withdrawed. Amount should be in the multiples of 100." << endl;
            return;
        }

        if (amount > this->balance)
        {
            cout << "Insufficient balance." << endl;
            return;
        }

        vector<int> denom(this->denominations.size(), 0);

        for (int i = 0; i < denominations.size(); i++)
        {
            int numOfNotes = amount / denominations[i].first;
            if (numOfNotes > denominations[i].second)
            {
                numOfNotes = denominations[i].second;
            }

            amount -= (numOfNotes * denominations[i].first);
            denom[i] -= numOfNotes;

            if (amount == 0)
            {
                break;
            }
        }

        if (amount == 0)
        {
            cout << "Amount withdrawed." << endl;
            for (int i = 0; i < denominations.size(); i++)
            {
                denominations[i].second += denom[i];
            }

            this->balance -= amountToBeWithdrawed;
            availableBalance();
        }

        else
        {
            cout << "Unavailable denominations." << endl;
        }
    }

    // Method to display available balance
    void availableBalance()
    {
        cout << "Available Balance is : " << this->balance << endl;
        for (auto &denomination : denominations)
        {
            cout << denomination.first << "*" << denomination.second << endl;
        }
        cout << endl;
    }
};

int main()
{
    ATM myATM;

    // int amount;
    // cout << "Enter the amoutn to add: ";
    // cin >> amount;

    myATM.addDenominations(41000, 20, 2, 0, 0);

    myATM.availableBalance();

    myATM.withdraw(25000);
    myATM.withdraw(15000);

    return 0;
}