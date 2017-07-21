#ifndef DIRECTX_HELPER_H
#define DIRECTX_HELPER_H
// System includes
//#include <windows.h>
#include "wrl.h"
//// DirectX includes
//#include <d3d11.h>
////#include <d3dcompiler.h>
//#include <DirectXMath.h>
//#include <DirectXColors.h>
//
//// STL includes
//#include <iostream>
//#include <string>

// Link library dependencies
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
//#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "winmm.lib")

namespace BAME
{
	// Safely release a COM object.
	template <typename T>
	inline void SafeRelease(T& ptr)
	{
		if (ptr != NULL)
		{
			ptr->Release();
			ptr = NULL;
		}
	}
}
#endif
