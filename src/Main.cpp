#include "stdafx.hpp"

int main() {
    App::init();
    LOG("-- STARTING APP UPDATE LOOP --");
    do {
        App::render();
        App::update();
    } while (App::isRunning());
    App::quit();

    return 0;
}