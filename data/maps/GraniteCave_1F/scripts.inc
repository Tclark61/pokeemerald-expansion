GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	setflag FLAG_EXITED_CAVE
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_Mailman::
	lock
	faceplayer
	checkitem ITEM_OAKS_PARCEL
	goto_if_set FLAG_FOUND_PARCEL, GraniteCave_1F_EventScript_TiredMailman
	goto_if_eq VAR_RESULT, FALSE, GraniteCave_1F_EventScript_MailmanGivesParcel
	goto_if_eq VAR_RESULT, TRUE, GraniteCave_1F_EventScript_TiredMailman
	release
	end

GraniteCave_1F_EventScript_MailmanGivesParcel::
	msgbox GraniteCave_1F_Text_MailmanGivesParcel, MSGBOX_NPC
	giveitem ITEM_OAKS_PARCEL
	release
	end

GraniteCave_1F_EventScript_TiredMailman::
	msgbox GraniteCave_1F_Text_TiredMailman, MSGBOX_NPC
	release
	end

GraniteCave_1F_Text_MailmanGivesParcel:
	.string "Huff... Puff...\n"
	.string "Hey, did you just come from\p"
	.string "Petalburg? Huff... Puff...\n"
	.string "I'm supposed to deliver a\p"
	.string "parcel to someone near there...\n"
	.string "Huff... Puff... but I'm so tired.\p"
	.string "What if you gave the package\n"
	.string "so I don't have to? That's a\p"
	.string "great idea! Here you go!$"

GraniteCave_1F_Text_TiredMailman:
	.string "Huff... Puff...\n"
	.string "I'm catching my breath before\p"
	.string "I walk all the way back to\n"
	.string "EverGrande City...$"

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Hey, you.\n"
	.string "It gets awfully dark ahead.\l"
	.string "It'll be tough trying to explore.\p"
	.string "That guy who came by earlier…\n"
	.string "TYLER, I think it was.\p"
	.string "He knew how to use FLASH, so he ought\n"
	.string "to be all right, but…\p"
	.string "Well, for us HIKERS, helping out those\n"
	.string "that we meet is our motto.\p"
	.string "Here you go, I'll pass this on to you.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Teach that hidden move FLASH to\n"
	.string "a POKéMON and use it.\p"
	.string "It lights up even the inky darkness\n"
	.string "of caves.\p"
	.string "But, to use it, you need the GYM BADGE\n"
	.string "from DEWFORD's POKéMON GYM.$"

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "You're at the end of the cave...\n"
	.string "But now you have to get through me!\p"
	.string "My POKEMON are the BEST!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "Get it? Best?$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "I use UNOWN that spell out BEST.\n"
	.string "C'mon, I'm funny. Right? Right?$"

