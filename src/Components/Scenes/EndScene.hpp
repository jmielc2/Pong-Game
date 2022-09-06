#pragma once

#ifndef END_SCENE_HPP
#define END_SCENE_HPP 1

#include "Scene.hpp"
#include "../../stdafx.hpp"

class EndScene : public stp::Scene {
public:
    void update(sf::Int32 delta);
    void render();
    void reset();
    void pause();
    void close();
    void open();

    EndScene();
private:
    class Impl;
    std::unique_ptr<Impl> impl;
};

#endif