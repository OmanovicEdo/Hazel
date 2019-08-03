#pragma once

#ifdef HZ_PLATFORM_WINDOWS

//heap allocate since sandbox can be large
extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv) {
	
	Hazel::Log::Init(); //move to engine init later
	int a = 10;
	HZ_CORE_WARN("initialize core log");
	HZ_INFO("hello var={0}", a);

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif