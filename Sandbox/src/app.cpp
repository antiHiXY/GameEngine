#include <Engine.h>

#include "imgui/imgui.h"

class ExampleLayer : public Engine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{}

	void OnUpdate() override
	{
		if (Engine::Input::IsKeyPressed(ENGN_KEY_TAB))
			ENGN_TRACE("Tab key is pressed (poll)!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Engine::Event& event) override
	{
		if (event.GetEventType() == Engine::EventType::KeyPressed)
		{
			Engine::KeyPressedEvent& e = (Engine::KeyPressedEvent&)event;
			if (e.GetKeyCode() == ENGN_KEY_TAB)
				ENGN_TRACE("Tab key is pressed (event)!");
			ENGN_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};


class Sandbox : public Engine::Application
{
public:
    Sandbox()
    {
		PushLayer(new ExampleLayer());
	}

    ~Sandbox()
    {}

};

Engine::Application* Engine::CreateApplication()
{
    return new Sandbox();
}
