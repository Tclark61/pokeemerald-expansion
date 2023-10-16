EverGrandeCity_GlaciasRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_GlaciasRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_GlaciasRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_GlaciasRoom_OnWarp
	.byte 0

EverGrandeCity_GlaciasRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_GlaciasRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 2, EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 3
	releaseall
	end

EverGrandeCity_GlaciasRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 3, EverGrandeCity_GlaciasRoom_EventScript_CloseDoor
	end

EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_GlaciasRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_GlaciasRoom_EventScript_Glacia::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_GlaciasRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_GlaciasRoom_Text_Defeat
	goto EverGrandeCity_GlaciasRoom_EventScript_Defeated
	end

EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_GlaciasRoom_EventScript_Defeated::
	setflag FLAG_DEFEATED_ELITE_4_GLACIA
	special HealPlayerParty
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_GlaciasRoom_Text_IntroSpeech:
	.string "TYLER: Welcome, {PLAYER}{KUN}.\p"
	.string "I've been watching your progress…\n"
	.string "That was superb work, \l"
	.string "finding the OLD ROD.\p"
	.string "And the way you defeated DRAKE!\p"
	.string "I have nothing but admiration.\n"
	.string "You overcame that difficult situation\n"
	.string "by working as one with your POKéMON.\p"
	.string "I hope you've enjoyed the journey\n"
	.string "to reach this final battle!\l"
	.string "This is where your achievements\n"
	.string "are put to the test against the\l"
	.string "best I can throw at you.\p"
	.string "Now!\p"
	.string "Who can craft the greatest plans\n"
	.string "and make their POKEMON shine?\p"
	.string "Show me right here and now!$"

EverGrandeCity_GlaciasRoom_Text_Defeat:
	.string "... That's checkmate.\p"
	.string "That was excellent work.\n"
	.string "I've been beaten completely.\l"
	.string "It stings a little...\n"
	.string "And yet it was utterly glorious!\p"
	.string "Kudos to you, {PLAYER}{KUN}!\p"
	.string "You are a masterful POKéMON\n"
	.string "TRAINER!\p"
	.string "You've come so far, in such a short\n"
	.string "time. That being said, I have news.\p"
	.string "I have the role of CHAMPION...\n"
	.string "Or at least I did, until yesterday.\p"
	.string "Unfortunately for you, there is still\n"
	.string "one more TRAINER for you to fight...\p"
	.string "One who arrived before you.\n"
	.string "Still, if anyone can win, it's you!\n"
	.string "Let me heal your pokemon.\p"
	.string "Prepare for your true final battle,\n"
	.string "{PLAYER}!$\p"

EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech:
	.string "TYLER: The POKéMON you sent into\n"
	.string "battle…\p"
	.string "At times they danced like a spring\n"
	.string "breeze, and at times they struck\l"
	.string "like lightning.\p"
	.string "You are on the precipice of victory,\n"
	.string "{PLAYER}!\p"
	.string "Go forth!$"