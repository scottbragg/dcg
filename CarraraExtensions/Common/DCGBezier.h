/*  Carrara plug-in utilities
    Copyright (C) 2000 Eric Winemiller

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    
    http://digitalcarversguild.com/
    email: ewinemiller @ digitalcarversguild.com (remove space)
*/
#ifndef __DCGBezier__
#define __DCGBezier__

#include "MCBezierPath.h"
#include "IMFResponder.h"

#if CP_PRAGMA_ONCE
#pragma once
#endif     

class DCGBezier  
{
public:
	DCGBezier()
	{
		InitCurve();
	};
	~DCGBezier(){};

protected:
	TMCBezierCurve fBezierCurve;
	virtual void InitCurve();
	virtual MCCOMErr MCCOMAPI Read(IShTokenStream* stream, ReadAttributeProc readUnknown, void* privData);
	virtual MCCOMErr MCCOMAPI Write(IShTokenStream* stream);
	virtual MCCOMErr MCCOMAPI HandleEvent(MessageID message, IMFResponder* source, void* data);  
};

#endif