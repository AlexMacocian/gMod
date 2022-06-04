/*
This file is part of Universal Modding Engine.


Universal Modding Engine is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Universal Modding Engine is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Universal Modding Engine.  If not, see <http://www.gnu.org/licenses/>.
*/



#ifndef uMod_MAIN_H_
#define uMod_MAIN_H_

#define WINVER _WIN32_WINNT_WINXP
#define _WIN32_WINNT _WIN32_WINNT_WINXP
#define _WIN32_WINDOWS _WIN32_WINNT_WINXP
#define NTDDI_VERSION NTDDI_WINXP
//#define NTDDI_LONGHORN NTDDI_WINXP
#define WIN32_LEAN_AND_MEAN


#include <windows.h>

#include <cstdlib>
#include <cstdio>

#include <d3d9.h>
#include <d3dx9.h>

#include <d3d10_1.h>
#include <d3d10.h>
#include <D3D10Misc.h>
#include <d3dx10.h>
//#include "detours.h"


#include "../uMod_GlobalDefines.h"
#include "../uMod_Error.h"
#include "../uMod_Utils.h"

#include "uMod_Defines.h"

#include "uMod_TextureFunction.h"

#include "uMod_DXMain_dll.h"


#include "uMod_ArrayHandler.h"
#include "uMod_TextureServer.h"
#include "uMod_TextureClient.h"

/**
 * global variable: HINSTANCE
 */
extern HINSTANCE             gl_hThisInstance;

/**
 * gloabal variable: pointer to TextureServer
 */
extern uMod_TextureServer*    gl_TextureServer;

/**
 * gloabal variable: pointer to the server thread
 */
extern HANDLE                gl_ServerThread;

/**
 * gloabal variable: error state. This is not supported at the moment.
 */
extern unsigned int gl_ErrorState;

#endif
