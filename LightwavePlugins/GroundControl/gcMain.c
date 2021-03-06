/*  Ground Control - plug-in for LightWave
Copyright (C) 2014 Eric Winemiller

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
#include "boolean.h"
#include <lwobjimp.h>
#include <lwimageio.h>
#include "gcMain.h"


int main()
{
	
}

XCALL_( int ) gcMeshLoad( long , GlobalFunc *, void *,void * );
XCALL_( int ) gcImageLoad( long , GlobalFunc *, void *,void * );


ServerRecord ServerDesc[] = {
	{ LWOBJECTIMPORT_CLASS, "Ground Control", (ActivateFunc*)gcMeshLoad },
	{ LWIMAGELOADER_CLASS, "Ground Control", (ActivateFunc*)gcImageLoad },
	{ NULL }
};

