Bank Statement Reader
This program reads a customer's checking account transactions from a .dat file and prepares a statement at the end of each month. It displays the account number, opening balance, each transaction, service fees, interest, and closing balance.

Features
Reads account data from a .dat file in the specified format.
Calculates the closing balance by applying transactions and updating the balance.
Applies service fees of R25 if the balance goes below R1000 during the month.
Tracks and displays interest earned by the account.
Prints the account statement with transaction details and the closing balance.
Input Format
The program expects the input file to have the following format:

python
Copy code
AccountNumber OpeningBalance
TransactionCode1 TransactionAmount1
TransactionCode2 TransactionAmount2
...
The first line contains the account number and the opening balance.
Each subsequent line contains a transaction code and the corresponding transaction amount.
The transaction codes are as follows:

W: Withdrawal
D: Deposit
I: Interest
Usage
Ensure that the input file "Transactions.dat" is in the same directory as the program.
Compile and run the program.
The program will read the account data from the input file and display the account statement on the console.
Example Output
yaml
Copy code
Account number: 46780976

Opening balance: 3750.40

Transaction      Amount       Balance          Bank costs
Withdrawal       250.00       3500.40
Deposit          1200.00      4700.40
Withdrawal       75.00        4625.40
Withdrawal       375.00       4250.40
Deposit          1200.00      5450.40
Interest         5.50         5455.90
Withdrawal       400.00       5055.90
Withdrawal       600.00       4455.90          25.00
Deposit          450.50       4905.40

Closing balance: R4905.40
Note: The "Bank costs" column displays the service fees deducted when the balance goes below R1000.

Dependencies
The program requires a C++ compiler and standard libraries.
