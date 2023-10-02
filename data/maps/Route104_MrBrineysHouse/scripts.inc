.set LOCALID_BRINEY, 1
.set LOCALID_PEEKO, 2

Route104_MrBrineysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
	.byte 0

Route104_MrBrineysHouse_OnTransition:
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
	call_if_eq VAR_BRINEY_HOUSE_STATE, 1, Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos
	call_if_set FLAG_RECEIVED_POKENAV, Route104_MrBrineysHouse_EventScript_HideRustboroRival
	end

Route104_MrBrineysHouse_EventScript_HideRustboroRival::
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	return

Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos::
	setobjectxyperm LOCALID_BRINEY, 9, 3
	setobjectmovementtype LOCALID_BRINEY, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
	setobjectxyperm LOCALID_PEEKO, 9, 6
	setobjectmovementtype LOCALID_PEEKO, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
	return

Route104_MrBrineysHouse_EventScript_Briney::
	lock
	faceplayer
	call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, Route104_MrBrineysHouse_EventScript_SailingIntro
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_MrBrineysHouse_EventScript_SailBothDeliveries
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route104_MrBrineysHouse_EventScript_SailDeliverPackage
	goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
	end

Route104_MrBrineysHouse_EventScript_SailingIntro::
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	msgbox Route104_MrBrineysHouse_Text_WaitUpPeeko, MSGBOX_DEFAULT
	msgbox Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_WhereAreWeBound::
	message Route104_MrBrineysHouse_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 20, 8, MULTI_BRINEY_OFF_DEWFORD, 1, FALSE
	switch VAR_RESULT
	case 0, Route104_MrBrineysHouse_EventScript_SailToDewford
	case 1, Route104_MrBrineysHouse_EventScript_DeclineSailing
	case MULTI_B_PRESSED, Route104_MrBrineysHouse_EventScript_DeclineSailing
	end

Route104_MrBrineysHouse_EventScript_SailBothDeliveries::
	msgbox Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_SailDeliverPackage::
	msgbox Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing::
	msgbox Route104_MrBrineysHouse_Text_DeclineDeliverySail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_DeclineSailing::
	msgbox Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_SailToDewford::
	msgbox Route104_MrBrineysHouse_Text_SetSailForDewford, MSGBOX_DEFAULT
	call EventScript_BackupMrBrineyLocation
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 1
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setflag FLAG_HIDE_ROUTE_104_RIVAL
	warp MAP_ROUTE104, 13, 51
	waitstate
	releaseall
	end

Route104_MrBrineysHouse_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route104_MrBrineysHouse_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route104_MrBrineysHouse_EventScript_Pikachu::
	msgbox Route104_MrBrineysHouse_Text_Pikachu, MSGBOX_NPC
	end

Route104_MrBrineysHouse_EventScript_TerrainMaster::
	lock
	faceplayer
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_MrBrineysHouse_EventScript_TerrainMasterFirstIntro
	goto Route104_MrBrineysHouse_EventScript_TerrainMasterExplains


Route104_MrBrineysHouse_EventScript_TerrainMasterFirstIntro::
	msgbox Route104_MrBrineysHouse_Text_TerrainMasterFirstIntro, MSGBOX_NPC
	setflag FLAG_DELIVERED_STEVEN_LETTER



Route104_MrBrineysHouse_EventScript_TerrainMasterExplains::
	message Route104_MrBrineysHouse_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 14, 0, MULTI_TERRAIN_TYPES, 1, FALSE
	switch VAR_RESULT
	case 0, Route104_MrBrineysHouse_EventScript_TerrainMasterExplains_TrickRoom
	case 1, Route104_MrBrineysHouse_EventScript_TerrainMasterExplains_ElecTerrain
	case 2, Route104_MrBrineysHouse_EventScript_TerrainMasterExplains_GrassyTerrain
	case 3, Route104_MrBrineysHouse_EventScript_TerrainMasterExplains_MistyTerrain
	case 4, Route104_MrBrineysHouse_EventScript_TerrainMasterExplains_PsychicTerrain
	case 5, Route104_MrBrineysHouse_EventScript_TerrainMasterExplains_ExitTopicSelect
	case MULTI_B_PRESSED, Route104_MrBrineysHouse_EventScript_TerrainMasterExplains_ExitTopicSelect
	end



Route104_MrBrineysHouse_EventScript_TerrainMasterExplains_TrickRoom::
	msgbox Route104_MrBrineysHouse_Text_TerrainMasterExplains_TrickRoom, MSGBOX_NPC
	msgbox Route104_MrBrineysHouse_Text_TerrainMasterExplains_AnyOthers, MSGBOX_NPC
	goto Route104_MrBrineysHouse_EventScript_TerrainMasterExplains
	release
	end

Route104_MrBrineysHouse_EventScript_TerrainMasterExplains_ElecTerrain::
	msgbox Route104_MrBrineysHouse_Text_TerrainMasterExplains_ElecTerrain, MSGBOX_NPC
	goto_if_unset FLAG_OBTAINED_SPECIAL_PIKACHU, Route104_MrBrineysHouse_EventScript_TerrainMasterGivesPikachu
	msgbox Route104_MrBrineysHouse_Text_TerrainMasterExplains_AnyOthers, MSGBOX_NPC
	goto Route104_MrBrineysHouse_EventScript_TerrainMasterExplains
	release
	end

Route104_MrBrineysHouse_EventScript_TerrainMasterExplains_GrassyTerrain::
	msgbox Route104_MrBrineysHouse_Text_TerrainMasterExplains_GrassyTerrain, MSGBOX_NPC
	msgbox Route104_MrBrineysHouse_Text_TerrainMasterExplains_AnyOthers, MSGBOX_NPC
	goto Route104_MrBrineysHouse_EventScript_TerrainMasterExplains
	release
	end

Route104_MrBrineysHouse_EventScript_TerrainMasterExplains_PsychicTerrain::
	msgbox Route104_MrBrineysHouse_Text_TerrainMasterExplains_PsychicTerrain, MSGBOX_NPC
	msgbox Route104_MrBrineysHouse_Text_TerrainMasterExplains_AnyOthers, MSGBOX_NPC
	goto Route104_MrBrineysHouse_EventScript_TerrainMasterExplains
	release
	end

Route104_MrBrineysHouse_EventScript_TerrainMasterExplains_MistyTerrain::
	msgbox Route104_MrBrineysHouse_Text_TerrainMasterExplains_MistyTerrain, MSGBOX_NPC
	goto_if_unset FLAG_OBTAINED_SPECIAL_PIKACHU, Route104_MrBrineysHouse_EventScript_TerrainMasterGivesPikachu
	msgbox Route104_MrBrineysHouse_Text_TerrainMasterExplains_AnyOthers, MSGBOX_NPC
	goto Route104_MrBrineysHouse_EventScript_TerrainMasterExplains
	release
	end

Route104_MrBrineysHouse_EventScript_TerrainMasterExplains_ExitTopicSelect::
	msgbox Route104_MrBrineysHouse_Text_TerrainMasterExplains_ExitTopicSelect, MSGBOX_NPC
	release
	end

Route104_MrBrineysHouse_EventScript_TerrainMasterGivesPikachu::
	applymovement 3, Common_Movement_ExclamationMark
	msgbox Route104_MrBrineysHouse_Text_TerrainMasterGivesPikachu, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_Text_TerrainMasterExplains_ExitTopicSelect
	setvar VAR_TEMP_1, SPECIES_PIKACHU_ALOLA_CAP
	givemon SPECIES_PIKACHU_ALOLA_CAP, 10
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route104_MrBrineysHouse_EventScript_SendPikachuParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route104_MrBrineysHouse_EventScript_SendPikachuPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route104_MrBrineysHouse_EventScript_SendPikachuParty::
	call Route104_MrBrineysHouse_EventScript_ReceivedPikachuFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_ReceivedPikachu
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route104_MrBrineysHouse_EventScript_ReceivedPikachu
	end

Route104_MrBrineysHouse_EventScript_SendPikachuPC::
	call Route104_MrBrineysHouse_EventScript_ReceivedPikachuFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_PikachuTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route104_MrBrineysHouse_EventScript_PikachuTransferredToPC
	end

Route104_MrBrineysHouse_EventScript_ReceivedPikachuFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_PIKACHU_ALOLA_CAP
	playfanfare MUS_OBTAIN_ITEM
	message Route104_MrBrineysHouse_Text_ObtainedPikachu
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_PIKACHU
	return

Route104_MrBrineysHouse_EventScript_PikachuTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto Route104_MrBrineysHouse_EventScript_ReceivedPikachu
	end

Route104_MrBrineysHouse_EventScript_ReceivedPikachu::
	msgbox Route104_MrBrineysHouse_Text_ExcitedPikachu, MSGBOX_NPC
	setflag FLAG_OBTAINED_SPECIAL_PIKACHU
	removeobject 4
	msgbox Route104_MrBrineysHouse_Text_ExplainSpecialPikachu, MSGBOX_NPC
	releaseall
	end

Route104_MrBrineysHouse_Text_ExplainSpecialPikachu:
	.string "Heh, this Pikachu has more to it\n"
	.string "than you'd imagine. If you train it\p"
	.string "well, then teach it SURF... You'll\n"
	.string "find out it's true potential.$"

Route104_MrBrineysHouse_Text_ObtainedPikachu:
	.string "{PLAYER} obtained a PIKACHU.$"

Route104_MrBrineysHouse_Text_ExcitedPikachu:
	.string "PIKACHU: Pika pi!$"

Route104_MrBrineysHouse_Text_ReadWhichTopic:
	.string "Which one do you want to learn\n"
	.string "about?$"

Route104_MrBrineysHouse_Text_TerrainMasterGivesPikachu:
	.string "Speaking of... This pikachu next\n"
	.string "to me, they're a special one.\p"
	.string "they've been itching to go on an\n"
	.string "adventure for a while. Would you\p"
	.string "want to take them with you?$"

Route104_MrBrineysHouse_Text_TerrainMasterFirstIntro:
	.string "Hello there, trainer! I'm a guru\n"
	.string "to help you on your journey.\p"
	.string "They call me the terrain master,\n"
	.string "master of all five terrains!\p"
	.string "I can explain any of them to you\n"
	.string "and depending on your interest,\p"
	.string "I might have a present for you...$"

Route104_MrBrineysHouse_Text_TerrainMasterExplains_ExitTopicSelect:
	.string "Aw, some other time then.$"

Route104_MrBrineysHouse_Text_Pikachu:
	.string "PIKACHU: Pika!\p"
	.string "This pikachu seems excited to\n"
	.string "see you.$"

Route104_MrBrineysHouse_Text_TerrainMasterExplains_AnyOthers:
	.string "Anything else you want to learn?$"

Route104_MrBrineysHouse_Text_TerrainMasterExplains_TrickRoom:
	.string "Oh, you want to learn about\n"
	.string "TRICK ROOM? It's a mind bending\p"
	.string "terrain. It switches the order\n"
	.string "in battle, so that the fastest\p"
	.string "pokemon goes last, and the slowest\n"
	.string "goes first! Suddenly your slowness\p"
	.string "turns into a benefit!\n"
	.string "Hope that explains it.$"

Route104_MrBrineysHouse_Text_TerrainMasterExplains_ElecTerrain:
	.string "Oh, you want to learn about\n"
	.string "ELECTRIC TERRAIN? It's a shocking\p"
	.string "terrain! It boosts electric type\n"
	.string "moves by 50%, and prevents pokemon\p"
	.string "from falling asleep. Great for an\n"
	.string "electric heavy team!\p"
	.string "Hope that explains it.$"

Route104_MrBrineysHouse_Text_TerrainMasterExplains_GrassyTerrain:
	.string "Oh, you want to learn about\n"
	.string "GRASSY TERRAIN? This terrain\p"
	.string "blooms with potential! It\n"
	.string "boosts grass moves by 50%, and\p"
	.string "heals every pokemon by 6% every turn.\n"
	.string "Great for sturdy grass types!\p"
	.string "Hope that explains it.$"

Route104_MrBrineysHouse_Text_TerrainMasterExplains_PsychicTerrain:
	.string "Oh, you want to learn about\n"
	.string "PSYCHIC TERRAIN? This terrain\p"
	.string "forsees you winning! It\n"
	.string "boosts psychic moves by 50%,\p"
	.string "and stops pokemon from using\n"
	.string "moves that always attack first\p"
	.string "No more fake out or vacuum wave!$"

Route104_MrBrineysHouse_Text_TerrainMasterExplains_MistyTerrain:
	.string "Oh, you want to learn about\n"
	.string "MISTY TERRAIN? It's a dazzling\p"
	.string "terrain! It boosts fairy type\n"
	.string "moves by 50%, and prevents pokemon\p"
	.string "from getting any status condition.\n"
	.string "great if you want to stop tricks!\p"
	.string "Hope that explains it.$"


Route104_MrBrineysHouse_Text_WaitUpPeeko:
	.string "MR. BRINEY: Hold on, lass!\n"
	.string "Wait up, PEEKO!$"

Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford:
	.string "Hm? You're {PLAYER}{KUN}!\n"
	.string "You saved my darling PEEKO!\l"
	.string "We owe so much to you!\p"
	.string "What's that?\n"
	.string "You want to sail with me?\p"
	.string "Hmhm…\p"
	.string "You have a LETTER bound for DEWFORD\n"
	.string "and a package for SLATEPORT, then?\p"
	.string "Quite the busy life you must lead!\p"
	.string "But, certainly, what you're asking is\n"
	.string "no problem at all.\p"
	.string "You've come to the right man!\n"
	.string "We'll set sail for DEWFORD.$"

Route104_MrBrineysHouse_Text_SetSailForDewford:
	.string "MR. BRINEY: DEWFORD it is, then!\p"
	.string "Anchors aweigh!\n"
	.string "PEEKO, we're setting sail, my darling!$"

Route104_MrBrineysHouse_Text_DeclineDeliverySail:
	.string "MR. BRINEY: Is that so?\n"
	.string "Your deliveries can wait?\p"
	.string "You just go on and tell me whenever\n"
	.string "you want to set sail!$"

Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford:
	.string "MR. BRINEY: Ahoy!\n"
	.string "I know exactly what you want to say!\p"
	.string "You're to deliver a LETTER to DEWFORD\n"
	.string "and a package to SLATEPORT.\p"
	.string "What you need me to do is no problem\n"
	.string "at all--I'm the man for the job!\p"
	.string "First, we'll set sail for DEWFORD.$"

Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford:
	.string "MR. BRINEY: Ahoy!\n"
	.string "I know exactly what you want to say!\p"
	.string "You're to deliver a package to\n"
	.string "CAPT. STERN in SLATEPORT.\p"
	.string "What you need me to do is no problem\n"
	.string "at all--I'm the man for the job!\p"
	.string "First, we'll set sail for DEWFORD.$"

Route104_MrBrineysHouse_Text_WhereAreWeBound:
	.string "MR. BRINEY: Ahoy!\n"
	.string "For you, I'll go out to sea anytime!\p"
	.string "Now, my friend, where are we bound?$"

Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail:
	.string "MR. BRINEY: Is that so?\n"
	.string "Well, PEEKO owes her life to you.\p"
	.string "You just go on and tell me whenever\n"
	.string "you want to set sail!$"

Route104_MrBrineysHouse_Text_Peeko:
	.string "PEEKO: Pii piihyoro!$"

