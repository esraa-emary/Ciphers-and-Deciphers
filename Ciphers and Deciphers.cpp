// Purpose: Ciphers and Deciphers.
// Description: This program is for encryption your important information like password to be hard for strangers to get it.
// Author: Esraa Emary Abd Elsalam.
// version: 4.
//========================================================== 100 Game =====================================================// 

#include <bits/stdc++.h>

#define ll long long
using namespace std;


//check if the input has any character except alphabet
void validity(string &text) {
    while (true) {
        int count = 0;
        while (text.size() == 0) {
            cout << "Invalid Input." << endl;
            cout << "Please enter the message to encrypt that only contains letters of alphabet: ";
            getline(cin, text);
        }

        for (int i = 0; i < int(text.size()); i++) {
            if (isalpha(text[i]))
                count++;
            else {
                cout << "Invalid Input." << endl;
                cout << "Please enter the message to encrypt that only contains letters of alphabet: ";
                getline(cin, text);
            }
        }
        if (count == int(text.size())) {
            break;
        }
    }
}

// Check if the input has any character except A, B, a or b.
string validity1(string &text) {
    while (true) {
        int count = 0;
        for (int i = 0; i < int(text.size()); i++) {
            if (text[i] != 'A' && text[i] != 'B' && text[i] != 'a' && text[i] != 'b' && !isspace(text[i])) {
                cout << "Invalid input." << endl;
                cout << "Please enter the message to decrypt that only contain A, B, a or b.: ";
                cin >> text;
                break;
            } else
                count++;
        }
        if (count == int(text.size())) {
            break;
        }
    }
    return text;
}

//check if the input has any character except alphabet and it is 5 digits
void validity2(string &text) {
    while (true) {
        int count = 0;
        while (text.size() != 5) {
            cout << "Invalid Input." << endl;
            cout << "Please enter the keyword that only contains 5 letters of alphabet: ";
            getline(cin, text);
        }

        for (int i = 0; i < int(text.size()); i++) {
            if (isalpha(text[i]))
                count++;
            else {
                cout << "Invalid Input." << endl;
                cout << "Please enter the keyword that only contains 5 letters of alphabet: ";
                getline(cin, text);
            }
        }
        if (count == int(text.size())) {
            break;
        }
    }
}

//===================================================== Simple Substitution Cipher =====================================================

//encrypt messages 
string Simple_Substitution_encrypt(string &text, string keyword) {
    string result = "";
    string text2 = "";
    string keyword2 = "";
    deque<char> alphabet;
    deque<char> key;
    deque<char> new_alphabet;
    //convert the message and keyword into uppercase
    for (int i = 0; i < int(text.size()); i++) {
        text2 += toupper(text[i]);
    }
    for (int i = 0; i < int(keyword.size()); i++) {
        keyword2 += toupper(keyword[i]);
    }
    //make a list for alphabetic letters and add keyword and rest of alphabetic letters to it
    for (int i = static_cast<int>('A'); i <= static_cast<int>('Z'); i++) {
        alphabet.push_back(static_cast<char>(i));
    }
    for (int i = 0; i < int(keyword2.size()); i++) {
        key.push_back(keyword2[i]);
        new_alphabet.push_back(keyword2[i]);
    }
    for (int i = 0; i < int(alphabet.size()); i++) {
        if (find(key.begin(), key.end(), alphabet[i]) == key.end())
            new_alphabet.push_back(alphabet[i]);
    }
    for (int i = 0; i < int(text2.size()); i++) {
        if (isalpha(text2[i]))
            result += new_alphabet[static_cast<int>(text2[i]) - 65];
    }
    return result;
}

//decryption messages
string Simple_Substitution_decrypt(string &text, string keyword) {
    string result = "";
    string text2 = "";
    string keyword2 = "";
    deque<char> alphabet;
    deque<char> key;
    deque<char> new_alphabet;
    //convert the message and keyword into uppercase
    for (int i = 0; i < int(text.size()); i++) {
        text2 += toupper(text[i]);
    }
    for (int i = 0; i < int(keyword.size()); i++) {
        keyword2 += toupper(keyword[i]);
    }
    //make a list for alphabetic letters and add keyword and rest of alphabetic letters to it
    for (int i = static_cast<int>('A'); i <= static_cast<int>('Z'); i++) {
        alphabet.push_back(static_cast<char>(i));
    }
    for (int i = 0; i < int(keyword2.size()); i++) {
        key.push_back(keyword2[i]);
        new_alphabet.push_back(keyword2[i]);
    }
    for (int i = 0; i < int(alphabet.size()); i++) {
        if (find(key.begin(), key.end(), alphabet[i]) == key.end())
            new_alphabet.push_back(alphabet[i]);
    }
    for (int i = 0; i < int(text2.size()); i++) {
        for (int j = 0; j < int(new_alphabet.size()); j++) {
            if (text2[i] == new_alphabet[j])
                result += alphabet[j];
        }
    }
    return result;
}

//===================================================== Atbash Cipher =====================================================//

// Encryption the process of Atbash Cipher.
string Atbash_encrypt(string &text, int choice) {
    string result = "";
    validity(text);
    for (int i = 0; i < int(text.size()); i++) {

        // Encrypt a message on tne whole letters of alphabet
        if (choice == 1) {
            // Check if the letter is uppercase to encrypt
            if (isupper(text[i])) {
                result += static_cast<char>(25 + 130 -
                                            static_cast<int>(text[i]));  //130 = 2 * 65        cipher = (25 + 65) - 'i' + 65
                // 90 - 1
            }

                // Check if the letter is lowercase to encrypt
            else if (islower(text[i])) {
                result += static_cast<char>(25 + 194 - static_cast<int>(text[i])); // 194 = 2 *  97
            }
        }

            // Encrypt a message on half-letters of the alphabet
        else if (choice == 2) {
            // Check if the letter is uppercase to encrypt
            int digit = static_cast<int>(text[i]);
            if (isupper(text[i])) {
                if (digit <= 77) {
                    result += static_cast<char>(12 + 130 - static_cast<int>(text[i]));
                } else if (digit > 77) {
                    result += static_cast<char>(12 + 156 - static_cast<int>(text[i]));
                }
            }

                // Check if the letter is lowercase to encrypt
            else if (islower(text[i])) {
                if (digit <= 109) {
                    result += static_cast<char>(12 + 194 - static_cast<int>(text[i]));
                } else if (digit > 109) {
                    result += static_cast<char>(12 + 220 - static_cast<int>(text[i]));
                }
            }
        }
    }
    return result;
}

// Decryption the process of Atbash Cipher.
string Atbash_decrypt(string &text, int choice) {
    string result = "";
    validity(text);
    for (int i = 0; i < int(text.size()); i++) {
        // Decrypt a message on tne whole letters of alphabet
        if (choice == 1) {
            // Check if the letter is uppercase to decrypt
            if (isupper(text[i])) {
                result += static_cast<char>(25 + 130 - static_cast<int>(text[i]));
            }

                // Check if the letter is lowercase to decrypt
            else if (islower(text[i])) {
                result += static_cast<char>(25 + 194 - static_cast<int>(text[i]));
            }
        }

            // Decrypt a message on half-letters of the alphabet
        else if (choice == 2) {
            // Check if the letter is uppercase to decrypt
            int digit = static_cast<int>(text[i]);
            if (isupper(text[i])) {
                if (digit <= 77) {
                    result += static_cast<char>(12 + 130 - static_cast<int>(text[i]));
                } else if (digit > 77) {
                    result += static_cast<char>(12 + 156 - static_cast<int>(text[i]));
                }
            }

                // Check if the letter is lowercase to decrypt
            else if (islower(text[i])) {
                if (digit <= 109) {
                    result += static_cast<char>(12 + 194 - static_cast<int>(text[i]));
                } else if (digit > 109) {
                    result += static_cast<char>(12 + 220 - static_cast<int>(text[i]));
                }
            }
        }
    }
    return result;
}

//===================================================== Baconian Cipher =====================================================//

// Encryption the process of Baconian Cipher.
string Baconian_encrypt(string text) {
    deque<string> elements;
    string old_result = "";
    string result = "";

    // Make a deque that contain binary conversion to elements from A to Z
    for (int i = static_cast<int>('A'); i <= static_cast<int>('Z'); i++) {
        int digit = 0;
        string digit2 = "";
        digit = i - 65;
        bitset<5> binary(digit);
        digit2 = binary.to_string();
        elements.push_back(digit2);
    }

    // Convert all characters into uppercase and add the opposite index to each character in elements deque from A to Z to old_result
    for (int i = 0; i < int(text.size()); i++) {
        int digit = 0;
        char index;
        index = toupper(text[i]);
        digit = static_cast<int>(index) - 65;
        old_result += elements[digit];
    }

    // Convert every '1' to b and every '0' to a then add it to result
    for (int i = 0; i < int(old_result.size()); i++) {
        if (old_result[i] == '1')
            result += 'b';
        else if (old_result[i] == '0')
            result += 'a';
    }
    return result;
}

// Decryption the process of Baconian Cipher.
string Baconian_decrypt(string text) {
    string result = "";
    string text2 = "";

    // Convert every (A or a) into 0 and every (B or b) into 1 and add this to text2
    for (int i = 0; i < int(text.size()); i++) {
        if (text[i] == 'A' || text[i] == 'a')
            text2 += '0';
        else if (text[i] == 'B' || text[i] == 'b')
            text2 += '1';
    }

    // Check about the existence of these unknown strings and ignore it
    deque<int> numbers;
    for (int i = 0; i < int(text2.size()); i++) {
        if ((text2[i] == '1' && text2[i + 1] == '1' && text2[i + 2] == '1' && text2[i + 3] == '1' &&
             text2[i + 4] == '1') ||
            (text2[i] == '1' && text2[i + 1] == '1' && text2[i + 2] == '1' && text2[i + 3] == '1' &&
             text2[i + 4] == '0') ||
            (text2[i] == '1' && text2[i + 1] == '1' && text2[i + 2] == '1' && text2[i + 3] == '0' &&
             text2[i + 4] == '1') ||
            (text2[i] == '1' && text2[i + 1] == '1' && text2[i + 2] == '1' && text2[i + 3] == '0' &&
             text2[i + 4] == '0') ||
            (text2[i] == '1' && text2[i + 1] == '1' && text2[i + 2] == '0' && text2[i + 3] == '1' &&
             text2[i + 4] == '0') ||
            (text2[i] == '1' && text2[i + 1] == '1' && text2[i + 2] == '0' && text2[i + 3] == '1' &&
             text2[i + 4] == '1')) {
            continue;
        }

            // Take every 5 characters in an index of a deque to evaluate it
        else if (((text2[i] == '1' || text2[i] == '0') && (text2[i + 1] == '1' || text2[i + 1] == '0') &&
                  (text2[i + 2] == '1' || text2[i + 2] == '0') && (text2[i + 3] == '1' || text2[i + 3] == '0') &&
                  (text2[i + 4] == '1' || text2[i + 4] == '0'))) {
            int digit = 0;
            bitset<5> decimal(text2.substr(i, 5));
            digit = decimal.to_ulong();
            numbers.push_back(digit);
            i += 4;
        } else
            continue;
    }

    // Check if every index in the deque has a value and add it to the result
    for (int j = 0; j < int(numbers.size()); j++) {
        for (int i = static_cast<int>('A'); i <= static_cast<int>('Z'); i++) {
            if (numbers[j] == (i - 65)) {
                result += static_cast<char>(i);
            }
        }
    }
    return result;
}

//===================================================== Main =====================================================//

int main(){
    // A description for user to simplify the program.
    cout << "# The Description For User To Simplify The Program:" << endl;
    cout<< "--> This program is for encryption your important information like password to be hard for strangers to get it."<< endl;
    cout << "--> Also it can decryption if your password is already encrypt with one of this ciphers." << endl;
    cout<< "// ================================================================================================================== //";
    cout << "\n# ===== Welcome To Encryption and Decryption Program ===== #" << endl;

    while (true) {
        cout<< "Which type of Cipher do you want?\n[1] Atbash Cipher.\n[2] Baconian Cipher.\n[3] Simple Substitution Cipher.\n[4] Exit Program.\nEnter Your Choice : ";
        string choice1;
        cin >> choice1;
        while (choice1 != "1" && choice1 != "2" && choice1 != "3" && choice1 != "4") {
            cout << "Invalid input." << endl;
            cout << "Please enter a valid choice: ";
            cin >> choice1;
        }

        if (choice1 == "1") {
            cout<<"===== Welcome to Atbash Cipher ====="<<endl;
            while(true){
                //print the menue and check the validity of choice
                cout << "What do you want to do?\n[1]Encrypt a message.\n[2]Decrypt a message.\n[3]Exit.\nChoice: ";
                int choice;
                cin>>choice;
                while ((cin.fail())||(choice!= 1 && choice!= 2 && choice!=3)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<< "Invalid input."<<endl;
                    cout<< "Please enter a valid choice: ";
                    cin>>choice;
                }  
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                //get the message and encrypt messages
                if(choice == 1){
                    cout<<"What do you want to do?\n [1] Encrypt a message on the whole alphabet.\n [2] Encrypt a message on half alphabet.\n [3] Back.\nEnter Your Choice: ";
                    int choice4;
                    cin>>choice4;
                    while ((cin.fail())||(choice4!= 1 && choice4!= 2 && choice4!=3)){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout<< "Invalid input."<<endl;
                        cout<< "Please enter a valid choice: ";
                        cin>>choice4;
                    }  
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    string text;
                    cout<<"Please enter the message you want to encrypt: ";
                    getline(cin, text);
                    validity(text);
                    cout << "The encrypted message is: "<<Atbash_encrypt(text, choice4)<<endl;
                }
                
                //get the message and decrypt messages
                else if(choice == 2){
                    cout<<"What do you want to do?\n [1] Decrypt a message on the whole alphabet.\n [2] Decrypt a message on half alphabet.\n [3] Back.\nEnter Your Choice: ";
                    int choice4;
                    cin>>choice4;
                    while ((cin.fail())||(choice4!= 1 && choice4!= 2 && choice4!=3)){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout<< "Invalid input."<<endl;
                        cout<< "Please enter a valid choice: ";
                        cin>>choice4;
                    }  
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    string text;
                    cout<<"Please enter the message you want to decrypt: ";
                    getline(cin, text);
                    validity(text);
                    cout << "The decrypted message is: "<<Atbash_decrypt(text, choice4)<<endl;
                }
                //exit the cipher
                else if(choice == 3){
                    break;
                }
                else{
                    cout <<  "Invalid choice.\n";
                    continue;
                }
                // To see if user want to encrype with the same type of cipher or no
                int choice1;
                while (true){
                    cout<<"Do you want to continue with same type of cipher?\n[1] Yes\n[2] No\nYour choice: ";
                    cin>>choice1;
                    while ((cin.fail())|| (choice1 != 1 && choice1 != 2 )){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input.\n";
                        cout << "Please select a valid choice from the previous menu: ";
                        cin >> choice1;
                    }
                    if (choice1 == 1 || choice1 == 2)
                        break;
                    
                    else
                        cout << "Please enter a valid choice: ";
                }
                if (choice1 == 2)
                    break ;
            }
        }

        else if (choice1 == "2") {
            cout<<"===== Welcome to Baconian Cipher ====="<<endl;
            while(true){
                //print the menue and check the validity of choice
                cout << "What do you want to do?\n[1]Encrypt a message.\n[2]Decrypt a message.\n[3]Exit.\nChoice: ";
                int choice;
                cin>>choice;
                while ((cin.fail())||(choice!= 1 && choice!= 2 && choice!=3)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<< "Invalid input."<<endl;
                    cout<< "Please enter a valid choice: ";
                    cin>>choice;
                }  
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                //get the message and encrypt messages
                if(choice == 1){
                    string text;
                    cout << "Please enter the message to encrypt that only contains letters of alphabet: ";
                    getline(cin, text);
                    cin.ignore(0,'\n');

                    // Check if the input has any character except alphabet
                    while (true)
                    {
                        bool flag = false;
                        for (int i = 0; i < int(text.size()); i++)
                        {
                            if(!isalpha(text[i]) && !isspace(text[i])){
                                flag = true;
                                break;
                            }
                        }
                        if(flag == true)
                        {
                            cout << "Invalid Input." << endl;
                            cout << "Please enter the message to encrypt that only contains letters of alphabet: ";
                            getline(cin, text);
                        }
                        else{
                            break;
                        }
                    }

                    // Print the encrypted message
                    cout << "\nThe Encrypted Message is: " << Baconian_encrypt(text) << endl << endl;
                }
                
                //get the message and decrypt messages
                else if(choice == 2){
                    string text;
                    cout << "Please enter the message to decrypt that only contains A, B, a or b.: ";
                    getline(cin, text);
                    validity1(text);

                    // Print the decrypted message
                    cout << "\nThe Decrypted Message is: " << Baconian_decrypt(text) << endl << endl;
                }
                //exit the cipher
                else if(choice == 3){
                    break;
                }
                else{
                    cout <<  "Invalid choice.\n";
                    continue;
                }
                // To see if user want to encrype with the same type of cipher or no
                int choice1;
                while (true){
                    cout<<"Do you want to continue with same type of cipher?\n[1] Yes\n[2] No\nYour choice: ";
                    cin>>choice1;
                    while ((cin.fail())|| (choice1 != 1 && choice1 != 2 )){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input.\n";
                        cout << "Please select a valid choice from the previous menu: ";
                        cin >> choice1;
                    }
                    if (choice1 == 1 || choice1 == 2)
                        break;
                    
                    else
                        cout << "Please enter a valid choice: ";
                }
                if (choice1 == 2)
                    break ;
            }
        }

        else if (choice1 == "3") {
            cout<<"===== Welcome to Simple Substitution Cipher ====="<<endl;
            while(true){
                //print the menue and check the validity of choice
                cout << "What do you want to do?\n[1]Encrypt a message.\n[2]Decrypt a message.\n[3]Exit.\nChoice: ";
                int choice;
                cin>>choice;
                while ((cin.fail())||(choice!= 1 && choice!= 2 && choice!=3)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<< "Invalid input."<<endl;
                    cout<< "Please enter a valid choice: ";
                    cin>>choice;
                }  
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                //get the message and encrypt messages
                if(choice == 1){
                    string text, keyword;
                    cout<<"Please enter the message you want to encrypt: ";
                    getline(cin, text);
                    validity(text);
                    cout<<"Please enter the keyword: ";
                    getline(cin, keyword);
                    validity2(keyword);
                    cout << "The encrypted message is: "<<Simple_Substitution_encrypt(text, keyword)<<endl;
                }
                
                //get the message and decrypt messages
                else if(choice == 2){
                    string text, keyword;
                    cout<<"Please enter the message you want to decrypt: ";
                    getline(cin, text);
                    validity(text);
                    cout<<"Please enter the keyword: ";
                    getline(cin, keyword);
                    validity2(keyword);
                    cout << "The decrypted message is: "<<Simple_Substitution_decrypt(text, keyword)<<endl;
                }
                //exit the cipher
                else if(choice == 3){
                    break;
                }
                else{
                    cout <<  "Invalid choice.\n";
                    continue;
                }
                // To see if user want to encrype with the same type of cipher or no
                int choice1;
                while (true){
                    cout<<"Do you want to continue with same type of cipher?\n[1] Yes\n[2] No\nYour choice: ";
                    cin>>choice1;
                    while ((cin.fail())|| (choice1 != 1 && choice1 != 2 )){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input.\n";
                        cout << "Please select a valid choice from the previous menu: ";
                        cin >> choice1;
                    }
                    if (choice1 == 1 || choice1 == 2)
                        break;
                    
                    else
                        cout << "Please enter a valid choice: ";
                }
                if (choice1 == 2)
                    break ;
            }
        }
        else if (choice1 == "4") {
            break;
        }
    }
    cout << "Thanks for using my program...";
}
