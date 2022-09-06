#include "MainMenu.hpp"

class MainMenu::Impl {
    
};

////////////////////////////////////

MainMenu::MainMenu() : impl(new MainMenu::Impl()) {
    LOG("Main Menu Created");
}

void MainMenu::update(sf::Int32 delta) {
    LOG("Updating Main Menu Scene");
}

void MainMenu::pause() {
    return;
}

void MainMenu::render() {

}

void MainMenu::reset() {

}

void MainMenu::close() {
    LOG("Closing Main Menu Scene");
}

void MainMenu::open() {
    LOG("Opening Main Menu Scene");
}