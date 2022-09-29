#include "GameScene.hpp"
#include "../../stdafx.hpp"

class GameScene::Impl {

};

/////////////////////////////////////////////////

GameScene::GameScene() : impl(new GameScene::Impl()) {
    LOG("Game Scene Created");
}

void GameScene::update(sf::Int32 delta) {
    LOG("Updating Game Scene");
}

void GameScene::pause() {
    
}

void GameScene::render() {

}

void GameScene::reset() {

}

void GameScene::close() {
    LOG("Closing Game Scene");
}

void GameScene::open() {
    LOG("Opening Game Scene");
}