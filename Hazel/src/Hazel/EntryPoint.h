#pragma once

#ifdef HZ_PLATFORM_WINDOWS

//heap allocate since sandbox can be large
extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv) {
	
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif