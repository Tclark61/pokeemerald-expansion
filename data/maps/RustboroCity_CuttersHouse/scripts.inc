RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_IceCreamParlor_EventScript_VendingMachine::
	lockall
	message RustboroCity_IceCreamParlor_Text_WhichDrinkWouldYouLike
	waitmessage
	showmoneybox 0, 0
	goto RustboroCity_IceCreamParlor_EventScript_ChooseDrink
	end

RustboroCity_IceCreamParlor_EventScript_ChooseDrink::
	multichoice 16, 0, MULTI_ICE_CREAM, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, RustboroCity_IceCreamParlor_EventScript_IceCreamCone
	case 1, RustboroCity_IceCreamParlor_EventScript_WhippedCream
	msgbox RustboroCity_IceCreamParlor_Text_DecidedAgainstBuyingDrink, MSGBOX_DEFAULT
	goto RustboroCity_IceCreamParlor_EventScript_ExitVendingMachine
	end

RustboroCity_IceCreamParlor_EventScript_IceCreamCone::
	setvar VAR_TEMP_0, SPECIES_VANILLITE
	goto RustboroCity_IceCreamParlor_EventScript_TryBuy
	end

RustboroCity_IceCreamParlor_EventScript_WhippedCream::
	setvar VAR_TEMP_0, SPECIES_MILCERY
	goto RustboroCity_IceCreamParlor_EventScript_TryBuy
	end

RustboroCity_IceCreamParlor_EventScript_CheckMoneyIceCreamCone::
	checkmoney 800
	return

RustboroCity_IceCreamParlor_EventScript_CheckMoneyWhippedCream::
	checkmoney 1200
	return

RustboroCity_IceCreamParlor_EventScript_RemoveMoneyIceCreamCone::
	removemoney 800
	return

RustboroCity_IceCreamParlor_EventScript_RemoveMoneyWhippedCream::
	removemoney 1200
	return

RustboroCity_IceCreamParlor_EventScript_TryBuy::
	call_if_eq VAR_TEMP_1, 0, RustboroCity_IceCreamParlor_EventScript_CheckMoneyIceCreamCone
	call_if_eq VAR_TEMP_1, 1, RustboroCity_IceCreamParlor_EventScript_CheckMoneyWhippedCream
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_IceCreamParlor_EventScript_NotEnoughMoneyForDrink
	call_if_eq VAR_TEMP_1, 0, RustboroCity_IceCreamParlor_EventScript_RemoveMoneyIceCreamCone
	call_if_eq VAR_TEMP_1, 1, RustboroCity_IceCreamParlor_EventScript_RemoveMoneyWhippedCream
	updatemoneybox
	random 3  @ 1/3 chance of an additional drink dropping
	goto_if_ne VAR_RESULT, 0, RustboroCity_IceCreamParlor_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_IceCreamParlor_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox RustboroCity_IceCreamParlor_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem ITEM_NEVER_MELT_ICE
	bufferspeciesname STR_VAR_1, VAR_TEMP_0
	playse SE_VEND
	msgbox RustboroCity_IceCreamParlor_Text_CanOfDrinkDroppedDown, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_1, 0, RustboroCity_IceCreamParlor_EventScript_ReceiveVanillite
	goto_if_eq VAR_TEMP_1, 1, RustboroCity_IceCreamParlor_EventScript_ReceiveMilcery
	bufferspeciesname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto RustboroCity_IceCreamParlor_EventScript_ChooseNewDrink
	end

RustboroCity_IceCreamParlor_EventScript_ChooseNewDrink::
	message RustboroCity_IceCreamParlor_Text_WhichDrinkWouldYouLike
	waitmessage
	goto RustboroCity_IceCreamParlor_EventScript_ChooseDrink
	end

RustboroCity_IceCreamParlor_EventScript_NotEnoughMoneyForDrink::
	msgbox RustboroCity_IceCreamParlor_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto RustboroCity_IceCreamParlor_EventScript_ExitVendingMachine
	end

RustboroCity_IceCreamParlor_EventScript_NoRoomForDrink::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	goto RustboroCity_IceCreamParlor_EventScript_ExitVendingMachine
	end

RustboroCity_IceCreamParlor_EventScript_ExitVendingMachine::
	hidemoneybox
	releaseall
	end

RustboroCity_IceCreamParlor_EventScript_ReceiveVanillite::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_VANILLITE
	givemon SPECIES_VANILLITE, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_IceCreamParlor_EventScript_ReceiveVanilliteParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_IceCreamParlor_EventScript_ReceiveVanillitePC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_IceCreamParlor_EventScript_ReceiveVanilliteParty::
	call RustboroCity_IceCreamParlor_EventScript_ReceivedVanilliteFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_IceCreamParlor_EventScript_ReceivedVanilliteFanfare
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_IceCreamParlor_EventScript_ReceivedVanilliteFanfare
	end

RustboroCity_IceCreamParlor_EventScript_ReceiveVanillitePC::
	call RustboroCity_IceCreamParlor_EventScript_ReceivedVanilliteFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_IceCreamParlor_EventScript_TransferVanilliteToPC
	call Common_EventScript_NameReceivedBoxMon
	end

RustboroCity_IceCreamParlor_EventScript_TransferVanilliteToPC::
	call Common_EventScript_TransferredToPC
	goto RustboroCity_IceCreamParlor_EventScript_ReceivedVanilliteFanfare
	end

RustboroCity_IceCreamParlor_EventScript_ReceivedVanilliteFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_VANILLITE
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_IceCreamParlor_Text_ObtainedVanillite
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_VANILLITE
	return

RustboroCity_IceCreamParlor_EventScript_ReceiveMilcery::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MILCERY
	givemon SPECIES_MILCERY, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_IceCreamParlor_EventScript_ReceiveMilceryParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_IceCreamParlor_EventScript_ReceiveMilceryPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_IceCreamParlor_EventScript_ReceiveMilceryParty::
	call RustboroCity_IceCreamParlor_EventScript_ReceivedMilceryFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_IceCreamParlor_EventScript_ReceivedMilceryFanfare
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_IceCreamParlor_EventScript_ReceivedMilceryFanfare
	end

RustboroCity_IceCreamParlor_EventScript_ReceiveMilceryPC::
	call RustboroCity_IceCreamParlor_EventScript_ReceivedMilceryFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_IceCreamParlor_EventScript_TransferMilceryToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_IceCreamParlor_EventScript_TransferMilceryToPC
	end

RustboroCity_IceCreamParlor_EventScript_TransferMilceryToPC::
	call Common_EventScript_TransferredToPC
	goto RustboroCity_IceCreamParlor_EventScript_ReceivedMilceryFanfare
	end

RustboroCity_IceCreamParlor_EventScript_ReceivedMilceryFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_MILCERY
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_IceCreamParlor_Text_ObtainedMilcery
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_MILCERY
	return

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_Creamie, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "That determined expression…\n"
	.string "That limber way you move…\l"
	.string "And your well-trained POKéMON…\p"
	.string "You're obviously a skilled TRAINER!\p"
	.string "No, wait, don't say a word.\n"
	.string "I can tell just by looking at you.\p"
	.string "I'm sure that you can put this\n"
	.string "HIDDEN MACHINE to good use.\p"
	.string "No need to be modest or shy.\n"
	.string "Go on, take it!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "That HIDDEN MACHINE, or HM for\n"
	.string "short, is CUT.\p"
	.string "An HM move is one that can be used\n"
	.string "by POKéMON outside of battle.\p"
	.string "Any POKéMON that's learned CUT can\n"
	.string "chop down thin trees if the TRAINER\l"
	.string "has earned the STONE BADGE.\p"
	.string "And, unlike a TM, an HM can be used\n"
	.string "more than once.$"

RustboroCity_CuttersHouse_Text_Creamie:
	.string "I'm addicted to these ice cream\n"
	.string "pokemon. Sometimes if you're lucky,\n"
	.string "they have extra ice they give out\p"
	.string "to customers.$"

RustboroCity_IceCreamParlor_Text_WhichDrinkWouldYouLike:
	.string "MAGLIO: Grumble grumble...\n"
	.string "Welcome to Magliogogliani's famous\p"
	.string "ice cream parlor. Whattya want\n"
	.string "to order today?$"

RustboroCity_IceCreamParlor_Text_CanOfDrinkDroppedDown:
	.string "MAGLIO: Order up for {PLAYER}!\p"
	.string "Here's your {STR_VAR_1}.\n"
	.string "Don't forget to tip.$"

RustboroCity_IceCreamParlor_Text_ExtraCanOfDrinkDroppedDown:
	.string "MAGLIO: Oh, I forgot!\p"
	.string "We found this in the freezer, you\n"
	.string "want it?$"

RustboroCity_IceCreamParlor_Text_NotEnoughMoney:
	.string "MAGLIO: Not enough money…\n"
	.string "Come back next time when you're\p"
	.string "not broke.$"

RustboroCity_IceCreamParlor_Text_DecidedAgainstBuyingDrink:
	.string "Decided against buying a drink.$"

RustboroCity_IceCreamParlor_Text_ObtainedVanillite:
	.string "{PLAYER} obtained an\n"
	.string "ICE CREAM CONE!$"

RustboroCity_IceCreamParlor_Text_ObtainedMilcery:
	.string "{PLAYER} obtained\n"
	.string "WHIPPED CREAM!$"
