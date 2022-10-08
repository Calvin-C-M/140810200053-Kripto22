/*

JUDUL PROGRAM   : Vigenere Cipher
NAMA            : Calvin Calfi Montolalu
NPM             : 140810200053
KELAS           : A
DESKRIPSI       : Program kriptografi menggunakan vigenere cipher

*/

#include <iostream>
#include <vector>

namespace Viginere {
    const int ASCII_CODE_UC=65;
    const int ASCII_CODE_LC=97;

    bool inRangeOfAscii(char character,int kode) {
        return (
            (character-kode) >= 0
            &&
            (character-kode) <= 25
        );
    }

    std::string makeNewKey(std::string text, std::string oldKey) {
        std::string key="";
        for(int i=0; i<text.size(); i++) {
            if(i > oldKey.size()-1) {
                key.push_back(oldKey[i-oldKey.size()]);
            } else {
                key.push_back(oldKey[i]);
            }
        }
        return key;
    }

    std::string encrypt(std::string plaintext, std::string key) {
        std::string ans="";
        std::string newKey=makeNewKey(plaintext,key);

        for(int i=0; i<plaintext.size(); i++) {
            char temp='a';
            if(inRangeOfAscii(plaintext.at(i),ASCII_CODE_LC)) {
                temp=(((plaintext.at(i)-ASCII_CODE_LC)+(newKey.at(i)-ASCII_CODE_LC))%26)+ASCII_CODE_LC;            
            } else if(inRangeOfAscii(plaintext.at(i),ASCII_CODE_UC)) {
                temp=(((plaintext.at(i)-ASCII_CODE_UC)+(newKey.at(i)-ASCII_CODE_UC))%26)+ASCII_CODE_UC;            
            }
            ans.push_back(temp);
        }
        
        return ans;
    }

    std::string decrypt(std::string crypttext, std::string key) {
        std::string ans="";
        std::string newKey=makeNewKey(crypttext,key);

        for(int i=0; i<crypttext.size(); i++) {
            char temp='a';

            if(inRangeOfAscii(crypttext.at(i),ASCII_CODE_LC)) {
                temp=(crypttext.at(i)-ASCII_CODE_LC)-(newKey.at(i)-ASCII_CODE_LC);
                temp = (temp < 0) ? temp+26 : temp;
                temp = (temp%26)+ASCII_CODE_LC;
            } else if(inRangeOfAscii(crypttext.at(i),ASCII_CODE_UC)) {
                temp=(crypttext.at(i)-ASCII_CODE_UC)-(newKey.at(i)-ASCII_CODE_UC);
                temp = (temp < 0) ? temp+26 : temp;
                temp = (temp%26)+ASCII_CODE_UC;
            }
            ans.push_back(temp);
        }   
        return ans;
    }
};

std::vector<std::string> split(std::string text, char del) {
    std::vector<std::string> arr={};
    std::string temp="";

    for(int i=0; i<text.size(); i++) {
        if(text.at(i) != del) {
            temp.push_back(text.at(i));
        } else {
            arr.push_back(temp);
            temp = "";
        }
    }
    arr.push_back(temp);

    return arr;
}

int main() {
    system("cls");
    bool running=true;

    while(running) {
        std::string command="";

        std::cout << "\n> "; std::getline(std::cin,command);

        std::vector<std::string>comms=split(command, ' ');

        if(comms[0] == "exit") running=false;

        if(comms[0] == "encrypt") {
            std::string plaintext=comms[1];
            std::string key=comms[2];

            std::cout << "Encryption = " << Viginere::encrypt(plaintext,key);
        }

        if(comms[0] == "decrypt") {
            std::string plaintext=comms[1];
            std::string key=comms[2];

            std::cout << "Decryption = " << Viginere::decrypt(plaintext,key);
        }
    }
}