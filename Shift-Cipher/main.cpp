#include "Shift.cpp"

int main() {
    system("cls");
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

        switch(pilihan) {
            case 1: 
                std::cout << "Text: "; std::getline(std::cin,plaintext);
                std::cout << "Key: "; std::cin >> key;
                std::cout << "Encryption = " << ShiftCipher::encrypt(plaintext,key) << "\n";
                break;
                
            case 2: 
                std::cout << "Text: "; std::getline(std::cin,plaintext);
                std::cout << "Key: "; std::cin >> key;
                std::cout << "Decryption = " << ShiftCipher::decrypt(plaintext,key) << "\n";
                break;

            case 3: // Exit program
                system("cls");
                printf("Selamat tinggal...\n");
                system("pause");
                running=false;
                break;

            default: // Error handling
                printf("(X) Ada kesalahan dalam memilih, silahkan coba lagi!\n");
                system("pause");
                break;
        }
    }
}