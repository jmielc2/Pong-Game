#include "MainMenu.hpp"

class MainMenu::Impl {
    
};

////////////////////////////////////

MainMenu::MainMenu() : impl(new MainMenu::Impl()) {

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
    
}