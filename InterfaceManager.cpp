#include "InterfaceManager.h"
#include "GUIManager.h"
#include "Objects/DefaultState.h"

namespace ed
{
	InterfaceManager::InterfaceManager(GUIManager* gui) :
		Renderer(&Pipeline, &Objects, &Parser, &Messages),
		Pipeline(&Parser),
		Objects(&Parser, &Renderer),
		Parser(&Pipeline, &Objects, &Renderer, &Messages, gui)
	{
		m_ui = gui;

		Plugins.Init(); // load plugins (TODO: maybe move this to the splash screen)
	}
	InterfaceManager::~InterfaceManager()
	{
		Plugins.Destroy();
	}
	void InterfaceManager::OnEvent(const SDL_Event& e)
	{}
	void InterfaceManager::Update(float delta)
	{}
}