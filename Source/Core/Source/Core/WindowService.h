#pragma once

#include "Service.h"
#include "Window.h"

#include <GLFW/glfw3.h>

#include <vector>
#include <memory>

namespace Core
{
    class DefaultWindow : public Window
    {
    public:
        DefaultWindow();
        ~DefaultWindow();

        void OnUpdate() override;
        void Destroy() override;

        GLFWwindow* GetHandle() const override;
        bool ShouldClose() const override;
    
    private:
        GLFWwindow* m_Handle = nullptr;
    };

    class WindowService : public Service
    {
    public:
        WindowService();
        ~WindowService();

        void OnUpdate() override;

        void CreateWindow();

        Window* GetWindow(GLFWwindow* windowId) const;
        Window* GetPrimaryWindow() const;

        bool ShouldPrimaryWindowClose() const;

        void DestroyPrimaryWindow();

    private:
        std::vector<std::unique_ptr<Window>> m_Windows;
        GLFWwindow* m_PrimaryWindow;
    };
}