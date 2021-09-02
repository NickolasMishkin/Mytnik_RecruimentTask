#include "pch.h"
#include "../framework/window.h"
#include "application.h"

Application::Application() = default;
Application::~Application() = default;

void Application::Initialize()
{
	m_renderContext = std::make_unique<RenderContext>( sf::VideoMode( 1920, 1080 ), "Recruitment task" );

	SetDataPath( "../../data/" );

	if( m_mainWindow = std::make_unique<ui::Window>() )
	{
		// here you can create your layout
	}
}

void Application::Run()
{
	while( m_renderContext->isOpen() )
	{
		InputEvent event;
		while( m_renderContext->pollEvent( event ) )
		{
			if( event.type == InputEvent::Closed )
			{
				m_renderContext->close();
			}
			else
			{
				m_mainWindow->ProcessInput( event );
			}
		}

		m_renderContext->clear();
		{
			m_mainWindow->Draw( *m_renderContext );
		}
		m_renderContext->display();
	}

}

ui::Window* Application::GetMainWindow() const
{
	return m_mainWindow.get();
}

const std::string& Application::GetDataPath() const
{
	return m_dataPath;
}

void Application::SetDataPath( const char* dataPath )
{
	m_dataPath = dataPath;
}

