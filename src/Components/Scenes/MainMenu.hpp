#pragma once

#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP 1

#include "Scene.hpp"

class MainMenu : public stp::Scene {
public:
    void update(sf::Int32 delta);
    void render();
    void reset();
    void pause();
    void close();
    void open();

    MainMenu();
private:
    class Impl;
    std::unique_ptr<Impl> impl;
};

#endif