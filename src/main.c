#include "window/window.h"

int main(void) {
    struct Window window = {
        .width = 1600,
        .height = 1000,
        .name = "Game",
    };

    CreateWindow(&window);
    WindowLoop(&window);

    return 0;
}
