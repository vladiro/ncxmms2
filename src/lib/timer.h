/**
 *  This file is a part of ncxmms2, an XMMS2 Client.
 *
 *  Copyright (C) 2011 Pavel Kunavin <tusk.kun@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 */

#ifndef TIMER_H
#define TIMER_H

#include <boost/function.hpp>

namespace ncxmms2
{
	class TimerPrivate;

	class Timer
	{
	public:
		Timer();
		~Timer();
		
		typedef boost::function<void ()> TimeoutFunction;
		void connectTimeoutSignal(const TimeoutFunction& function);
		void start(unsigned int interval);
		void stop();
		
	private:
		Timer(const Timer& other);
		Timer& operator=(const Timer& other);
		TimerPrivate *d;
	};
}

#endif // TIMER_H
