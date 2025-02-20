#include "cbase.h"
#include <algorithm>
#include <cstdio>
#include "p4ssutils.h"
#include "dbg.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

//-----------------------------------------------------------------------------
using namespace vgui;

namespace P4ss
{
	void ColorTextP4ss(vgui::Label *label, const wchar_t *text,  const int team)
	{
		Msg("ColorTextP4ss: Fired");
		label->GetTextImage()->ClearColorChangeStream();
		Color color;
		Color secondaryColor;
		if ( team == TF_TEAM_BLUE )
		{
			color = COLOR_TF_BLUE;
			secondaryColor = COLOR_TF_RED;
		}
		else if ( team == TF_TEAM_RED ) 
		{
			color = COLOR_TF_RED;
			secondaryColor = COLOR_TF_BLUE;
		}
		else {
			color = COLOR_TF_SPECTATOR;
			secondaryColor = COLOR_TF_RED;
		}
		// We change the title's text color to match the colors of the matching
		// model panel backgrounds
		const wchar_t *txt = text;
		int iWChars = 0;
		while ( txt && *txt )
		{
			switch ( *txt )
			{
			case 0x06: // Assists
				label->GetTextImage()->AddColorChange( Color( 59, 196, 143, 255 ), iWChars );
				break;
			case 0x07: // Saves
				label->GetTextImage()->AddColorChange( Color( 255, 255, 0, 255 ), iWChars );
				break;
			case 0x08: // Intercepts
				label->GetTextImage()->AddColorChange( Color( 255, 0, 255, 255 ), iWChars );
				break;
			case 0x14: // Steals
				label->GetTextImage()->AddColorChange( Color( 255, 128, 0, 255 ), iWChars );
				break;
			case 0x0F: // Splashes
				label->GetTextImage()->AddColorChange( Color( 91, 212, 180, 255 ), iWChars );
				break;
			case 0x13: // PRIMARY team color
				label->GetTextImage()->AddColorChange( color, iWChars );
				break;
			case 0x11: // SECONDARY team color
				label->GetTextImage()->AddColorChange( secondaryColor, iWChars );
				break;
			case 0x12: // Goals
				label->GetTextImage()->AddColorChange( Color( 59, 196, 59, 255 ), iWChars );
				break;
			default:
				break;
			}

			txt++;
			iWChars++;
		}
	}
}