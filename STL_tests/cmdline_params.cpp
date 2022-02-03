#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << argv[0] << '\n';

    if (argc != 2) {
        std::cout << "No input parameters!" << std::endl;
        return 4;
    }
    
    std::cout << argv[1] << '\n';

    return EXIT_SUCCESS;
}