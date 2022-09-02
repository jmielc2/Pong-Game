#pragma once

#ifndef SCENE_FACTORY_HPP
#define SCENE_FACTORY_HPP 1

#include "../stdafx.hpp"
#include "../Components/Scenes/MainMenu.hpp"
#include "../Components/Scenes/GameScene.hpp"
#include "../Components/Scenes/EndScene.hpp"

class SceneFactory {
public:
    static Scene* fetchScene(App::Scene scene);
}

#endif