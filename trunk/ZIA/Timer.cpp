#include "Timer.h"

Timer::Timer()
{
	_startTicks = 0;
	_pausedTicks = 0;
	_paused = false;
	_started = false;
}


Timer::~Timer()
{
	;
}

const clock_t	Timer::tickTac()
{
	return clock() * TICK_FACTOR_MS;
}

void	Timer::start()
{
	this->_started = true;
	this->_paused = false;
	this->_startTicks = this->tickTac();
}

void	Timer::stop()
{
	this->_started = false;
	this->_paused = false;
}

bool	Timer::isStarted()
{
	return (this->_started);
}

bool	Timer::isPaused()
{
	return (this->_paused);
}

const clock_t	Timer::getTicks()
{
	if(this->_started == true)
		if(this->_paused == true)
		{
			return this->_pausedTicks;
		}
		else
		{
			return this->tickTac() - this->_startTicks;
		}
		return 0;
}

void	Timer::pause()
{
	if((this->_started == true) && (this->_paused == false))
	{
		this->_paused = true;
		this->_pausedTicks = this->tickTac() - this->_startTicks;
	}
}

void Timer::unPause()
{
	if(this->_paused == true)
	{
		this->_paused = false;
		this->_startTicks = this->tickTac() - this->_pausedTicks;
		this->_pausedTicks = 0;
	}
}
