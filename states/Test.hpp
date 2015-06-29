#ifndef TEST_HPP
# define TEST_HPP
# include "AGameState.hpp"

class TestState : Dot::AGameState
{
public:
	virtual void	init();
	virtual void	clean();
	virtual void	pause();
	virtual void	resume();
	virtual void	handleEvents(Dot::Engine *);
	virtual void	update(Dot::Engine *);
	virtual void	draw(Dot::Engine *);
	static AGameState	* instance();

private:
			TestState() : AGameState() {};
	static TestState	* _instance;
};

#endif
