EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

EverGrandeCity_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

EverGrandeCity_EventScript_VictoryRoadSign::
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_LevelCapTriggerPerson::
	faceplayer
	lock
	msgbox EverGrandeCity_Text_Congrats
	release
	end

EverGrandeCity_EventScript_CitySign::
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_PokemonLeagueSign::
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_SetVisitedEverGrande::
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_TEMP_1, 1
	end

EverGrandeCity_EventScript_Zach::
	trainerbattle_single TRAINER_ZACH_2, EverGrandeCity_Text_ZachIntroText, EverGrandeCity_Text_ZachDefeatText
	msgbox EverGrandeCity_Text_Zach_PostFight, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_Text_ZachIntroText:
	.string "Coincidence seeing you here!\n"
	.string "Last time I saw you was in the WOODS!\p"
	.string "I've become stronger since then, though.\n"
	.string "Don't worry, my moves are still the same.\p"
	.string "No tricks, only damage!$"

EverGrandeCity_Text_ZachDefeatText:
	.string "That's an A level team you've built!\n"
	.string "You have some strong moves!$"

EverGrandeCity_Text_Zach_PostFight:
	.string "Hey, do me a favor. If you see\n"
	.string "a guy named GEOFF or TYLER up ahead,\p"
	.string "break their kneecaps for me.\n"
	.string "Don't worry, they'll understand.$"

EverGrandeCity_Text_Congrats:
	.string "You made it! Congratulations!$"

EverGrandeCity_Text_EnteringVictoryRoad:
	.string "ENTERING VICTORY ROAD$"

EverGrandeCity_Text_EnteringPokemonLeague:
	.string "ENTERING POKéMON LEAGUE\n"
	.string "CENTER GATE$"

EverGrandeCity_Text_CitySign:
	.string "EVER GRANDE CITY\p"
	.string "“The paradise of flowers, the sea,\n"
	.string "and POKéMON.”$"

