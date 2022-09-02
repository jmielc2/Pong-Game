#pragma once

#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP 1

#include "Scene.hpp"
#include "../../stdafx.hpp"

class MainMenu : public Scene {
public:
    void update(sf::Int32 delta);
    void render();
    void reset();
    void pause();
    void close();

    MainMenu();
private:
    class Impl;
    std::unique_ptr<Impl> impl;
};

#endif