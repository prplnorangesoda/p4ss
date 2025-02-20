//========= Contributed by 4v4 PASS Time developers. ============//
//
// Purpose: Utility functions for interacting with TF2 Hud Elements.
//
// $NoKeywords: $
//=============================================================================//

#ifndef P4SSUTILS_H
#define P4SSUTILS_H
#include "c_tf_player.h"
#ifdef _WIN32
#pragma once
#endif

#include "tf_controls.h"
#include "GameEventListener.h"

namespace P4ss 
{
	void ColorTextP4ss(vgui::Label * label, const wchar_t * text, const int team = TF_TEAM_RED);

}

#endif // P4SSUTILS_H  