#include "../stdafx.hpp"
#include "App.hpp"
#include "../Components/Scenes/MainMenu.hpp"
#include "../Components/Scenes/GameScene.hpp"
#include "../Components/Scenes/EndScene.hpp"

class App::Impl {
public:
    class SceneManager;

    static App::Scene scene;
    static App::State state;
    static App app;
    static sf::RenderWindow window;
    static sf::Event event;
    static sf::Clock clock;
    static sf::Int32 deltaTime, prevTime;
    static App::Impl::SceneManager scenes;

    Impl() {};
};

class App::Impl::SceneManager {
public:
    stp::Scene* fetchScene(App::Scene scene) {
        return App::Impl::SceneManager::scenes.at(scene);
    }

    void loadScenes() {
        scenes.emplace(App::Scene::MAIN_MENU, new MainMenu());
        scenes.emplace(App::Scene::GAME, new GameScene());
        scenes.emplace(App::Scene::END_GAME, new EndScene());
    }

    SceneManager() {}

private:
    std::map<App::Scene, stp::Scene*> scenes;
};

App::Scene App::Impl::scene = App::Scene::MAIN_MENU;
App::State App::Impl::state = App::State::RUNNING;
App App::Impl::app;
sf::RenderWindow App::Impl::window(sf::VideoMode(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT)), "Pong", sf::Style::Close);
sf::Event App::Impl::event;
sf::Clock App::Impl::clock;
sf::Int32 App::Impl::deltaTime;
sf::Int32 App::Impl::prevTime = 0;
App::Impl::SceneManager App::Impl::scenes;

std::unique_ptr<App::Impl> App::impl(new App::Impl());

/////////////////////////////////////////

void App::setScene(App::Scene scene) {
    stp::Scene* curScene = App::impl->scenes.fetchScene(App::getScene());
    curScene->close();
    curScene = App::impl->scenes.fetchScene(scene);
    curScene->open();
    App::impl->scene = scene;
}

void App::setState(App::State state) {
    App::impl->state = state;
}

App::Scene App::getScene() {
    return App::impl->scene;
}

App::State App::getState() {
    return App::impl->state;
}

bool App::isRunning() {
    return App::impl->state != App::State::CLOSED && App::impl->window.isOpen();
}

void App::quit() {
    if (App::State::CLOSED != App::getState()) {
        LOG("Quitting App");
        App::setState(App::State::CLOSED);
        App::impl->window.close();
    }
}

void App::init() {
    LOG("Initializing App");
    App::impl->window.setFramerateLimit(60);

    // Load App Icon
    std::filesystem::path iconPath("assets/icon.png");
    sf::Image iconFile;
    if (iconFile.loadFromFile(iconPath)) {
        App::impl->window.setIcon(iconFile.getSize(), iconFile.getPixelsPtr());
    }

    // Load App Scenes
    App::impl->scenes.loadScenes();
    App::setScene(App::Scene::MAIN_MENU);

    App::impl->clock.restart();
}

void App::update() {    
    // Get Delta Time
    sf::Int32 curTime = App::impl->clock.getElapsedTime().asMilliseconds();
    App::impl->deltaTime = curTime - App::impl->prevTime;
    App::impl->prevTime = curTime;

    // Update App
    App::impl->scenes.fetchScene(App::getScene())->update(App::impl->deltaTime);
    if (App::impl->window.pollEvent(App::impl->event)) {
        if (App::impl->event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            App::quit();
            return;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            switch (App::getScene()) {
            case (App::Scene::MAIN_MENU):
                App::setScene(App::Scene::GAME);
                break;
            case (App::Scene::GAME):
                App::setScene(App::Scene::END_GAME);
                break;
            case (App::Scene::END_GAME):
                App::setScene(App::Scene::MAIN_MENU);
                break;
            }
        }
    }
}

void App::render() {
    App::impl->window.clear();

    App::impl->scenes.fetchScene(App::getScene())->render();
    
    LOG("Delta Time: " + std::to_string(App::impl->deltaTime) + " ms");
    App::impl->window.display();
}

void App::pause() {
    App::impl->scenes.fetchScene(App::getScene())->pause();
}

App::App() {
    LOG("Creating App");
}

App::~App() {
    LOG("Destructing App");
}