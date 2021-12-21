#pragma once

#include "Core.h"
#include "Engine/LayerStack.h"
#include "Engine/Events/Event.h"
#include "Engine/Events/ApplicationEvent.h"

#include "Engine/Core/Timestep.h"
#include "Engine/ImGui/ImGuiLayer.h"

#include "Window.h"

namespace Engine
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }

        inline static Application& Get() { return *s_Instance; }
    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;

        float m_LastFrameTime = 0.0f;
    private:
        static Application* s_Instance;
    };

    //// to be defined in CLIENT
    Application* CreateApplication();
}
