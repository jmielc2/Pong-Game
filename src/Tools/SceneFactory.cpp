#include "SceneFactory.hpp"

Scene* SceneFactory::fetchScene(App::Scene scene) {
    Scene* res = nullptr;
    switch (scene) {
    case(App::Scene::MAIN_MENU):
        res = new MainMenu();
        break;
    case(App::Scene::GAME):
        res = new GameScene();
        break;
    case(App::Scene::END_GAME):
        res = new EndScene();
        break;
    }
    return res;
}