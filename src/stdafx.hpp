#pragma once

#ifndef STDAFX_H
#define STDAFX_H 1

#define DEBUG 1
#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 800

#if DEBUG
    #include <iostream>
    #define LOG(x) std::cout << "[LOG]: " x << std::endl
#else
    #define LOG(x)
#endif

#include <memory>
#include <vector>
#include <limits>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <filesystem>

#include "Controllers/App.hpp"

#include <SFML/Graphics.hpp>

#endif