#pragma once

// Memory leak detection using NEW keyword instead of new
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#define NEW new( _NORMAL_BLOCK, __FILE__, __LINE__ )
#include <crtdbg.h>
#else
#define NEW new
#endif

// STL
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <chrono>

// Containers
#include <string>

// SDL2 library
#include "SDL.h"

// Rarely updated classes
#include "logger.h"

