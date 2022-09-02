#pragma once

#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP 1

#include "Scene.hpp"
#include "../../stdafx.hpp"

class GameScene : public Scene {
public:
    void update(sf::Int32 delta);
    void render();
    void reset();
    void pause();
    void close();

    GameScene();
private:
    class Impl;
    std::unique_ptr<Impl> impl;
};

#endif