#include "Shift.cpp"

int main() {
    bool running=true; // While this is true, program will keep on running

    while(running) {
        int pilihan=1;

        // Menu UI
        printf("\nMAIN MENU\n");
        printf("1. Enkripsi\n");
        printf("2. Dekripsi\n");
        printf("3. Exit\n");
        std::cout << "Pilihan: "; std::cin >> pilihan; std::cin.ignore();

        std::string plaintext="";
        int key=1;
        std::cout << "Text: "; std::getline(std::cin,plaintext);
        std::cout << "Key: "; std::cin >> key;

        switch(pilihan) {
            case 1: std::cout << "Encryption = " << ShiftCipher::encrypt(plaintext,key);
                break;
                
            case 2: std::cout << "Decryption = " << ShiftCipher::decrypt(plaintext,key);
                break;

            case 3: // Exit program
                printf("Selamat tinggal...");
                running=false;
                break;

            default: // Error handling
                printf("(X) Ada kesalahan dalam memilih, silahkan coba lagi!");
                system("pause");
                break;
        }
    }
}