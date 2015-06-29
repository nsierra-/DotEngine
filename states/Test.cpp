#include "Test.hpp"
#include "Logger.hpp"

TestState	* TestState::_instance = nullptr;

void	TestState::init()
{
	Dot::Logger::debug("testState init");
}

void	TestState::clean()
{
	Dot::Logger::debug("testState clean");
}

void	TestState::pause()
{
	Dot::Logger::debug("testState pause");
}

void	TestState::resume()
{
	Dot::Logger::debug("testState resume");
}

void	TestState::handleEvents(Dot::Engine *)
{
	Dot::Logger::debug("testState handleEvents");
}

void	TestState::update(Dot::Engine *)
{
	Dot::Logger::debug("testState update");
}

void	TestState::draw(Dot::Engine *)
{
	Dot::Logger::debug("testState draw");
}

Dot::AGameState	* TestState::instance()
{
	if (_instance == nullptr)
		_instance = new TestState();
	return _instance;
}
