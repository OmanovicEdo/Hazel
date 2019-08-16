#include <Hazel.h>

class ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer() : Hazel::Layer("Example") {}

	void OnUpdate() override
	{
		//HZ_INFO("ExampleLayer::Update");
	}

	void OnEvent(Hazel::Event& event) override
	{
		HZ_TRACE("{0}", event);
	}
};

class Sandbox : public Hazel::Application {
public:
	Sandbox() 
	{
		auto layer = new ExampleLayer();
		PushLayer(layer);
		PushOverlay(new Hazel::ImGuiLayer());
	}

	~Sandbox() {}
};

Hazel::Application* Hazel::CreateApplication() {
	return new Sandbox();
}
