GraniteCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, GraniteCave_B1F_SetHoleWarp
	.byte 0

GraniteCave_B1F_EventScript_AngryFisherman::
	msgbox GraniteCave_B1F_Text_AngryFisherman, MSGBOX_NPC
	end

GraniteCave_B1F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, GraniteCave_B1F_Text_ZanderIntro, GraniteCave_B1F_Text_ZanderDefeat
	msgbox GraniteCave_B1F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCave_B1F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_GRANITE_CAVE_B2F
	end

GraniteCave_B1F_Text_AngryFisherman:
	.string "I'm so angry! I finally found\n"
	.string "the perfect cave fishing spot\p"
	.string "and now I dropped my rod\n"
	.string "in the lake!$"

GraniteCave_B1F_Text_ZanderIntro:
	.string "Did...\n"
	.string "something move in the water?!$"

GraniteCave_B1F_Text_ZanderDefeat:
	.string "Sensei Larry, forgive me!\n"
	.string "I lost my wits!$"

GraniteCave_B1F_Text_ZanderPostBattle:
	.string "I get freaked out every time I see\n"
	.string "anything move…\p"
	.string "I shouldn't have come here to train…$"

