#pragma once

#ifndef APP_HPP
#define APP_HPP 1

class App {
public:
    enum Scene {MAIN_MENU, GAME, END_GAME};
    enum State {RUNNING, CLOSED, PAUSED};

    // Deleted
    App operator=(App& other) = delete;

    // Destructor
    ~App();

    // Modifiers
    static void setScene(App::Scene scene);
    static void setState(App::State state);

    // Accessors
    static App::Scene getScene();
    static App::State getState();
    static bool isRunning();
    
    // Functions
    static void quit();
    static void init();
    static void update();
    static void render();
    static void pause();

private:
    App();
    class Impl;
    static std::unique_ptr<App::Impl> impl;
};

#endif