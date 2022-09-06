#pragma once

#ifndef PAGE_HPP
#define PAGE_HPP 1

#include "../../stdafx.hpp"

namespace stp {
    class Scene {
    public:
        virtual void update(sf::Int32 delta) = 0;
        virtual void render() = 0;
        virtual void reset() = 0;
        virtual void pause() = 0;
        virtual void close() = 0;
        virtual void open() = 0;
    };
};

#endif