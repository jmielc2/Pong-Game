#include "stdafx.hpp"

int main() {
    App::init();
    do {
        App::render();
        App::update();
    } while (App::isRunning());
    App::quit();

    return 0;
}