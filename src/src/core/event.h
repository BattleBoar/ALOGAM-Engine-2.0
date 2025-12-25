#pragma once
#include <functional>
#include <unordered_map>
#include <vector>

enum class EventType {
    WindowClose,
    WindowResize, 
    KeyPressed,
    KeyReleased,
    KeyRepeat,
    MouseMoved,
    MouseButtonPressed,
    MouseButtonReleased,
    MouseScrolled
    JostikMoved,
    JostikButtonPressed,
    JostikButtonReleased
};

struct Event {
    EventType type;
    union {
        struct { int width, height; } resize; 
        struct { int key; int scancode; int action; int mods; } key;
        struct { float x, y; } mouse;
        struct { float x, y; } jostik;
        struct { int button; int action; int mods; } mouseButton;
        struct { float xoffset, yoffset; } scroll;
    };
};

