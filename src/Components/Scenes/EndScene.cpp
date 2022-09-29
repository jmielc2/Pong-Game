#include "../../stdafx.hpp"
#include "EndScene.hpp"

class EndScene::Impl {

};

/////////////////////////////////////////////////

EndScene::EndScene() : impl(new EndScene::Impl()) {
    LOG("End Scene Created");
}

void EndScene::update(sf::Int32 delta) {
    LOG("Updating End Game Scene");
}

void EndScene::pause() {
    
}

void EndScene::render() {

}

void EndScene::reset() {

}

void EndScene::close() {
    LOG("Closing End Game Scene");
}

void EndScene::open() {
    LOG("Opening End Game Scene");
}