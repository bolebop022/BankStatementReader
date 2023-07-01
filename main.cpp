#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

struct Transaction {
    char code;
    double amount;
};
struct Account {
    vector<Transaction> transactions;
    double balance;
    int accNumber;
};


Account readFile(string fileName);
void displayTransactions(Account& transactionData);

int main()
{
    Account transactionData = readFile("Transactions.dat");

    displayTransactions(transactionData);

    return 0;
}

Account readFile(string fileName){
    ifstream inputFile(fileName); // Open the .dat file
    vector<Transaction> transactionData;
    Account userAccount;

    if (inputFile.is_open()) { // Check if the file is successfully opened

        string accNumber, balance;

        getline(inputFile, accNumber, ' '); // Read and discard the first line
        getline(inputFile, balance);

        userAccount.accNumber = stoi(accNumber);
        userAccount.balance = stod(balance);

        char code;
        double amount;


        while (inputFile >> code >> amount) { // Read key-value pairs from the file
            Transaction trans;
            trans.code = code; // Store the key-value pair in the map
            trans.amount = amount;
            userAccount.transactions.push_back(trans);
        }


        inputFile.close(); // Close the file after reading
    } else {
        cout << "Failed to open the file." << endl;
    }
    return userAccount;
}

void displayTransactions(Account& accountData){
    double balance = accountData.balance;
    vector<Transaction> transactionData = accountData.transactions;

    cout << "Account number: "<< accountData.accNumber << endl << endl;
    cout << "Opening balance: " << accountData.balance << endl << endl;

    // Display the transaction table header
     // Display the transaction table header
    cout << left << setw(15) << "Transaction" << right << setw(10) << "Amount" << right << setw(16) << "Balance" << setw(20) << "Bank costs" << endl;

    // Display each transaction row
    for (int i = 0; i < transactionData.size(); ++i) {
        switch (transactionData[i].code){
            case 'W':
                balance = balance - transactionData[i].amount;
                cout << left << setw(15) << "Withdrawal" << right << setw(10)
                << transactionData[i].amount << right << setw(16) << balance << endl;
                break;
            case 'D':
                balance = balance + transactionData[i].amount;
                cout << left << setw(15) << "Deposit" << right << setw(10) << transactionData[i].amount << right << setw(16) << balance << endl;
                break;
            case 'I':
                balance = balance + transactionData[i].amount;
                cout << left << setw(15) << "Interest" << right << setw(10) <<  transactionData[i].amount << right << setw(16) << balance << endl;
                break;
        }
    }

    cout << endl;
    cout << "Closing balance: R" << balance << endl;
}
