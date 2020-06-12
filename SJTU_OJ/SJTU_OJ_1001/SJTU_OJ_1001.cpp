#include <iostream>

int main()
{
    int body_height, chair_height, apple_count;
    int iter;
    int apple_height, avaliable_apple = 0;
    int avaliable_height = 0;

    std::cin >> body_height >> chair_height >> apple_count;
    avaliable_height = body_height + chair_height;

    for (iter = 0;iter < apple_count;iter++) {
        std::cin >> apple_height;
        if (apple_height <= avaliable_height) {
            avaliable_apple++;
        }
    }
    std::cout << avaliable_apple << std::endl;
}
