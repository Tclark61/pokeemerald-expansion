GraniteCave_B2F_MapScripts::
	.byte 0

GraniteCave_B2F_EventScript_SpecialEgg::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, GraniteCave_B2F_EventScript_ReceivedEgg
	msgbox GraniteCave_B2F_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GraniteCave_B2F_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, GraniteCave_B2F_EventScript_NoRoomForEgg
	msgbox GraniteCave_B2F_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message GraniteCave_B2F_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_CELEBI
	release
	end

GraniteCave_B2F_EventScript_ReceivedEgg::
	msgbox GraniteCave_B2F_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

GraniteCave_B2F_EventScript_NoRoomForEgg::
	msgbox GraniteCave_B2F_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

GraniteCave_B2F_EventScript_DeclineEgg::
	msgbox GraniteCave_B2F_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

GraniteCave_B2F_Text_EverySoOftenEggFoundAtDayCare:
	.string "CHEYANNE: This game got way harder.\n"
	.string "Hopefully this EGG will help.\p"
	.string "Anyway, you go on ahead.\n"
	.string "I'm gonna take a nap here.$"

GraniteCave_B2F_Text_HaveEggWillYouTakeIt:
	.string "CHEYANNE: Hey, {PLAYER}.\n"
	.string "I'm hiding out from work here,\p"
	.string "so that they don't have me clean\n"
	.string "up anyone else's mess.\p"
	.string "In the meantime...\n"
	.string "I have here an EGG.\p"
	.string "I've heard rumors it's really rare...\n"
	.string "But I have a feeling it's for you.\l"
	.string "Will you take this EGG to hatch?$"

GraniteCave_B2F_Text_HopeYoullWalkPlentyWithEgg:
	.string "CHEYANNE: Nice! Hope you walk a lot\n"
	.string "with this here EGG!$"

GraniteCave_B2F_Text_ReceivedTheEgg:
	.string "{PLAYER} received the EGG.$"

GraniteCave_B2F_Text_NoRoomForThisEgg:
	.string "Oh? You've too many POKéMON.\n"
	.string "There's no room for this EGG…$"

GraniteCave_B2F_Text_AsYouWishThen:
	.string "As you wish, then…\p"
	.string "If you have a change of heart about\n"
	.string "hatching this EGG, I will be here.$"

