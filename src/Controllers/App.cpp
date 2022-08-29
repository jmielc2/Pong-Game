#include "App.hpp"

class App::Impl {
public:
    static App::Scene scene;
    static App::State state;
    static App app;
    static sf::RenderWindow window;
    static sf::Event event;
    static sf::Clock clock;
    static sf::Int32 deltaTime, prevTime;

    Impl() {};
};

App::Scene App::Impl::scene = App::Scene::MAIN_MENU;
App::State App::Impl::state = App::State::RUNNING;
App App::Impl::app;
sf::RenderWindow App::Impl::window(sf::VideoMode(sf::Vector2u(WINDOW_HEIGHT, WINDOW_WIDTH)), "Pong", sf::Style::Close);
sf::Event App::Impl::event;
sf::Clock App::Impl::clock;
sf::Int32 App::Impl::deltaTime;
sf::Int32 App::Impl::prevTime = 0;

std::unique_ptr<App::Impl> App::impl(new App::Impl());

/////////////////////////////////////////

void App::setScene(App::Scene scene) {
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
        App::impl->state = CLOSED;
        App::impl->window.close();
    }
}

void App::init() {
    LOG("Initializing App");
    App::impl->window.setFramerateLimit(60);

    std::filesystem::path icon("assets/icon.png");
    sf::Image iconFile;
    if (iconFile.loadFromFile(std::filesystem::path("assets/icon.png"))) {
        App::impl->window.setIcon(iconFile.getSize(), iconFile.getPixelsPtr());
    }
    App::impl->clock.restart();
}

void App::update() {    
    // Get Delta Time
    sf::Int32 curTime = App::impl->clock.getElapsedTime().asMilliseconds();
    App::impl->deltaTime = curTime - App::impl->prevTime;
    App::impl->prevTime = curTime;

    if (App::impl->window.pollEvent(App::impl->event)) {
        if (App::impl->event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            App::quit();
        }
    }
}

void App::render() {
    App::impl->window.clear();

    // TODO: Draw Strategy Here
    
    LOG("Delta Time: " + std::to_string(App::impl->deltaTime) + " ms");
    App::impl->window.display();
}

App::App() {
    LOG("Creating App");
}

App::~App() {
    LOG("Destructing App");
}