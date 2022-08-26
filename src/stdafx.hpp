#pragma once

#ifndef STDAFX_H
#define STDAFX_H 1

#define DEBUG 1

#if DEBUG
    #include <iostream>
    #define LOG(x) std::cout << x << std::endl
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
#include <SFML/Graphics.hpp>

#endif