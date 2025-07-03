#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: ./convert {up|down} {string...}\n";
        return 1;
    }

    std::string command = argv[1];

    std::string input;
    for (int i = 2; i < argc; ++i) {
        input.append(argv[i]);
        if (i != argc - 1) input += " ";
    }

    if (command == "up") {
        std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    } else if (command == "down") {
        std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    } else {
        std::cerr << "Invalid command. Use 'up' or 'down'.\n";
        return 1;
    }

    std::cout << input << std::endl;
    return 0;
}
