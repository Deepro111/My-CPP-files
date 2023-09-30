#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool CreditCardValidityCheck(string number){

    if(number.length() < 13 || number.length() > 16){
        return false;
    }

    vector<int> numberint;

    for(int i=0; i<number.length(); i++){
        numberint.push_back(number[i] - '0');
    }

    for(int i=number.length()-2; i>=0; i=i-2){
        int digit = numberint[i];

        digit = digit*2;

        if(digit > 9){
            digit = digit%10 + 1;
        }

        numberint[i] = digit;
    }

    int alldigitSum = 0;
    for(int i=0; i<numberint.size(); i++){
        alldigitSum+=numberint[i];
    }

    if(alldigitSum % 10 == 0){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    string number = "62";

    if(CreditCardValidityCheck(number)){
        cout << " Credit Card is VALID" <<endl;
    }
    else{
        cout << " INVALID Card Number" << endl;
    }
    return 0;
}