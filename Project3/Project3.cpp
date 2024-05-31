#include<iostream>
#include<string>

int main(){
    int command;
    int key;
    std::string input_message{};

    std::cout << "(1)-Encrypt\t(2)-Decrypt";
    std::cout << "Enter command: ";
    std::cin >> command;
    std::string output;
    switch(command){
    case 1:
        std::cout << "Enter message: "; std::getline(std::cin >> std::ws, input_message);
        std::cout << "Enter key: "; std::cin >> key;
        for (const char& im: input_message)
        {
            output += im + key;
        }
        std::cout << output;
        break;
    case 2:
        std::cout << "Enter encrypted message: "; std::getline(std::cin >> std::ws, input_message);
        std::cout << "Enter key: "; std::cin >> key;
        for (const char& im: input_message)
        {
            output += im - key;
        }
        std::cout << output;
        break;
    default:
        break;
    }
    return 0;
}
