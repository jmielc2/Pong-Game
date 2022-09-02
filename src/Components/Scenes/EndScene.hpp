#pragma once

#ifndef END_SCENE_HPP
#define END_SCENE_HPP 1

#include "Scene.hpp"
#include "../../stdafx.hpp"

class EndScene : public Scene {
public:
    void update(sf::Int32 delta);
    void render();
    void reset();
    void pause();
    void close();

    EndScene();
private:
    class Impl;
    std::unique_ptr<Impl> impl;
};

#endif