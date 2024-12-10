#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode

	ADD_LADDER,		// Add Ladder Action
	ADD_SNAKE,		// Add Snake Action	
	ADD_CARD,		// Add Card Action	
	EXIT,			// Exit Application
	TO_PLAY_MODE,	// Go to Play Mode
	OPEN_GRID,
	SAVE_GRID,
	COPY_CARD,
	PASTE_CARD,
	CUT_CARD,
	DELETE_GAME_OBJECT,


	//  [2] Actions of Play Mode

	ROLL_DICE,		// Roll Dice Action
	INPUT_DICE_VALUE,
	NEW_GAME,
	TO_DESIGN_MODE,	// Go to Design Mode
	EXIT_PLAY_MODE,

	//  [3] Others

	EMPTY,				// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,			// Inside Grid Area
	STATUS 				// Inside StatusBar Area
};
enum ObjectType { Ladders, Snakes, Cards };
#endif-