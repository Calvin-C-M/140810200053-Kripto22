#include <iostream>

namespace ShiftCipher {
    const int ASCII_CODE_LC=97;
    const int ASCII_CODE_UC=65;

    /**
     * @brief 
     * Check if character is in range of A(0) to Z(25)
     *  
     * @param karakter Character being checked
     * @param code Ascii code used
     * 
     * @return true or false 
     */
    bool inRangeOfAscii(char karakter, int code) {
        return (
            (karakter-code) >= 0
            &&
            (karakter-code) <= 25
        );
    }

    /**
     * @brief 
     * Encrypting a text using the formula below:
     * Formula = (x + K) mod 26
     * 
     * @param text Plaintext for encryption
     * @param key Key used in formula
     * 
     * @return Encrypted text
     */
    std::string encrypt(std::string text="abc", int key=1) {
        std::string ans="";

        for(char ch: text) {
            if(inRangeOfAscii(ch,ASCII_CODE_LC)) { // Handling for lower case
                ch = (((ch-ASCII_CODE_LC)+key)%26)+ASCII_CODE_LC;
            } else if(inRangeOfAscii(ch,ASCII_CODE_UC)) { // Handling for upper case
                ch = (((ch-ASCII_CODE_UC)+key)%26)+ASCII_CODE_UC;
            }
            ans.push_back(ch);
        }

        return ans;
    }

    /**
     * @brief
     * Decrypting a text using the formula below:
     * Formula = (x - K) mod 26
     * 
     * @param text Encrypted Text for decryption
     * @param key Key used in formula
     * 
     * @return Decrypted text
     */
    std::string decrypt(std::string text="abc", int key=1) {
        std::string ans="";

        for(char ch: text) {
            if(inRangeOfAscii(ch,ASCII_CODE_LC)) { // Handling for lower case
                ch -= (ASCII_CODE_LC + key);
                ch = (ch < 0) ? ch+26 : ch; // If char is below 0, then it adds 26 to the char value
                ch = (ch%26)+ASCII_CODE_LC;
            } else if(inRangeOfAscii(ch,ASCII_CODE_UC)) { // Handling for upper case
                ch -= (ASCII_CODE_UC + key);
                ch = (ch < 0) ? ch+26 : ch; // If char is below 0, then it adds 26 to the char value
                ch = (ch%26)+ASCII_CODE_UC;
            }
            ans.push_back(ch);
        }

        return ans;        
    }
};
