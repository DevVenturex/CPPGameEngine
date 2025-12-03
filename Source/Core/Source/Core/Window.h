#pragma once

#include <GLFW/glfw3.h>

namespace Core
{
    class Window
    {
    public:
        Window() = default;
        virtual ~Window() = default;

        virtual void OnUpdate() = 0;
        virtual void Destroy() = 0;

        virtual GLFWwindow* GetHandle() const = 0;

        virtual bool ShouldClose() const = 0;
    };
}