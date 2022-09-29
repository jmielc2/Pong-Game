#pragma once

#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP 1

#include "Scene.hpp"

class GameScene : public stp::Scene {
public:
    void update(sf::Int32 delta);
    void render();
    void reset();
    void pause();
    void close();
    void open();

    GameScene();
private:
    class Impl;
    std::unique_ptr<Impl> impl;
};

#endif