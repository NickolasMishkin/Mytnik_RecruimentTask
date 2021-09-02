#pragma once

class Inventory;

namespace ui
{
	class Window;
}

class Application final
{
public:
	Application();
	~Application();

	void Initialize();
	void Run();

	ui::Window* GetMainWindow() const;
	const std::string& GetDataPath() const;

private:
	void SetDataPath( const char* dataPath );

	std::string m_dataPath;

	std::unique_ptr< ui::Window > m_mainWindow;
	std::unique_ptr< RenderContext > m_renderContext;
};
