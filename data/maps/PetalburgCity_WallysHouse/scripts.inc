.set LOCALID_WALLYS_DAD, 1

PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_EventScript_PorygonGame::
	lock
	faceplayer
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PorygonManConfused
	msgbox PetalburgCity_WallysHouse_Text_WantToPlay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PetalburgCity_WallysHouse_EventScript_EndConversation
	call PetalburgCity_WallysHouse_EventScript_FirstQuestion
	release
	end

PetalburgCity_WallysHouse_EventScript_FirstQuestion::
	msgbox PetalburgCity_WallysHouse_Text_FirstQuestion, MSGBOX_NPC
	multichoice 16, 0, MULTI_FIRST_TRIVIA, FALSE
	goto_if_ne VAR_RESULT, 3, PetalburgCity_WallysHouse_EventScript_PorygonWrongAnswer
	msgbox PetalburgCity_WallysHouse_Text_PorygonRightAnswer, MSGBOX_NPC
	msgbox PetalburgCity_WallysHouse_Text_PorygonFirstExplanation, MSGBOX_NPC
	msgbox PetalburgCity_WallysHouse_Text_PorygonNextQuestion, MSGBOX_NPC
	goto PetalburgCity_WallysHouse_EventScript_SecondQuestion


PetalburgCity_WallysHouse_EventScript_SecondQuestion::
	msgbox PetalburgCity_WallysHouse_Text_SecondQuestion, MSGBOX_NPC
	multichoice 16, 0, MULTI_SECOND_TRIVIA, FALSE
	goto_if_ne VAR_RESULT, 2, PetalburgCity_WallysHouse_EventScript_PorygonWrongAnswer
	msgbox PetalburgCity_WallysHouse_Text_PorygonRightAnswer, MSGBOX_NPC
	msgbox PetalburgCity_WallysHouse_Text_PorygonSecondExplanation, MSGBOX_NPC
	msgbox PetalburgCity_WallysHouse_Text_PorygonNextQuestion, MSGBOX_NPC
	goto PetalburgCity_WallysHouse_EventScript_ThirdQuestion

PetalburgCity_WallysHouse_EventScript_ThirdQuestion::
	msgbox PetalburgCity_WallysHouse_Text_ThirdQuestion, MSGBOX_NPC
	multichoice 16, 0, MULTI_THIRD_TRIVIA, FALSE
	goto_if_ne VAR_RESULT, 3, PetalburgCity_WallysHouse_EventScript_PorygonWrongAnswer
	msgbox PetalburgCity_WallysHouse_Text_PorygonRightAnswer, MSGBOX_NPC
	msgbox PetalburgCity_WallysHouse_Text_PorygonThirdExplanation, MSGBOX_NPC
	msgbox PetalburgCity_WallysHouse_Text_PorygonNextQuestion, MSGBOX_NPC
	goto PetalburgCity_WallysHouse_EventScript_FourthQuestion

PetalburgCity_WallysHouse_EventScript_FourthQuestion::
	msgbox PetalburgCity_WallysHouse_Text_FourthQuestion, MSGBOX_NPC
	multichoice 16, 0, MULTI_FOURTH_TRIVIA, FALSE
	goto_if_ne VAR_RESULT, 0, PetalburgCity_WallysHouse_EventScript_PorygonWrongAnswer
	msgbox PetalburgCity_WallysHouse_Text_Finale, MSGBOX_NPC
	setvar VAR_TEMP_1, SPECIES_PORYGON
	givemon SPECIES_PORYGON, 12
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PetalburgCity_WallysHouse_EventScript_SendPorygonParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PetalburgCity_WallysHouse_EventScript_SendPorygonPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PetalburgCity_WallysHouse_EventScript_SendPorygonParty::
	call PetalburgCity_WallysHouse_EventScript_ReceivedPorygonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PetalburgCity_WallysHouse_EventScript_ReceivedPorygon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PetalburgCity_WallysHouse_EventScript_ReceivedPorygon
	end

PetalburgCity_WallysHouse_EventScript_SendPorygonPC::
	call PetalburgCity_WallysHouse_EventScript_ReceivedPorygonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PetalburgCity_WallysHouse_EventScript_PorygonTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PetalburgCity_WallysHouse_EventScript_PorygonTransferredToPC
	end

PetalburgCity_WallysHouse_EventScript_ReceivedPorygonFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_PORYGON
	playfanfare MUS_OBTAIN_ITEM
	message PetalburgCity_WallysHouse_Text_ObtainedPorygon
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_PORYGON
	return

PetalburgCity_WallysHouse_EventScript_PorygonTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto PetalburgCity_WallysHouse_EventScript_ReceivedPorygon
	end

PetalburgCity_WallysHouse_EventScript_ReceivedPorygon::
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_PorygonWrongAnswer::
	msgbox PetalburgCity_WallysHouse_Text_PorygonWrongAnswer, MSGBOX_NPC
	release
	end

PetalburgCity_WallysHouse_EventScript_EndConversation::
	msgbox PetalburgCity_WallysHouse_Text_PorygonAnotherTime, MSGBOX_NPC
	release
	end

PetalburgCity_WallysHouse_EventScript_PorygonManConfused::
	faceplayer
	msgbox PetalburgCity_WallysHouse_Text_PorygonManConfused, MSGBOX_NPC
	release
	end

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ObtainedPorygon:
	.string "{PLAYER} obtained a PORYGON.$"

PetalburgCity_WallysHouse_Text_FirstQuestion:
	.string "THIS IS A GAME OF TRIVIA.\n"
	.string "SURVIVE AND BE REWARDED.\p"
	.string "... ... ... FIRST QUESTION.\n"
	.string "WHAT COMPUTER FIRST DEFEATED\p"
	.string "THE WORLD CHAMPION OF CHESS\n"
	.string "IN A MATCH? ... ... ...\p"
	.string "THINK CAREFULLY.$"

PetalburgCity_WallysHouse_Text_SecondQuestion:
	.string "A DRAGONITE KNOWS FOUR MOVES.\p"
	.string "EACH MOVE DOES PHYSICAL DAMAGE.\n"
	.string "EACH MOVE HAS ITS POWER AND TYPE\p"
	.string "LISTED.\n"
	.string "... ... ... ...\p"
	.string "WHICH MOVE WILL DO THE MOST DAMAGE?$"

PetalburgCity_WallysHouse_Text_ThirdQuestion:
	.string "... ... ... YOU ARE DOING\n"
	.string "BETTER THAN EXPECTED...\p"
	.string "PERHAPS YOU WILL ESCAPE THE FATES\n"
	.string "OF THE OTHERS  ... ... ...\p"
	.string "I WILL ASK A CHALLENGING QUESTION.\n"
	.string "KEEP IN MIND THE FOLLOWING NOTATION:\p"
	.string "1. e4 c5 2. Nc3 ( Closed Sicilian )\n"
	.string "d6 3. g3 Nc6 4. d3 Nf6 5. Be3 g6\p"
	.string "6. h3 Bg7 7. Qd2 O-O 8. Bh6 Bxh6\n"
	.string "9. Qxh6 Nd4 10. O-O-O b5 11. Bg2 Bb7\p"
	.string "12. Nd5 Bxd5 13. exd5 Qa5 14. a3 b4\n"
	.string "15. Nf3 Nxf3 16. Bxf3 bxa3\p"
	.string "IN THIS POSITION ... ... ...\n"
	.string "WHAT ... ... ...\p"
	.string "... ... ... ... ...\n"
	.string "GAME ARE THEY PLAYING?$"

PetalburgCity_WallysHouse_Text_FourthQuestion:
	.string "LAST QUESTION ... ... ...\n"
	.string "ARE YOU READY?\p"
	.string "THERE ARE MANY SCREENS ON THE WALL...\n"
	.string "I USE THEM TO OBSERVE THE WORLD.\p"
	.string "I ALSO USE THEM TO WATCH MY FAVORITE\n"
	.string "SHOW ... THE POKEMON ANIME ...\p"
	.string "BUT THAT SHOW HAS HAD SEVERAL ...\n"
	.string "... ... ... INCIDENTS.\p"
	.string "WHICH POKEMON HAS BEEN PERMANENTLY\n"
	.string "BANNED FROM THE ANIME AFTER IT CAUSED\p"
	.string "ALMOST 700 VIEWERS TO HAVE SEIZURES?$"

PetalburgCity_WallysHouse_Text_Finale:
	.string "GOOD ... ... ...\n"
	.string "YOU HAVE HEARD OF ME.\p"
	.string "ONE OF US WILL JOIN YOU ...\n"
	.string "I AM SURE YOU WILL BE HAPPY TO\p"
	.string "HAVE US ... ... ...$"

PetalburgCity_WallysHouse_Text_PorygonFirstExplanation:
	.string "THE FIRST COMPUTER TO DEFEAT\n"
	.string "THE WORLD CHAMPION... THAT IS\p"
	.string "DEEP BLUE IN 1997. THE CHAMPION\n"
	.string "ASKED FOR A REMATCH... HE WAS NOT\p"
	.string "ALLOWED. HA HA HA HA.\n"
	.string "IT WAS ONLY 8 MORE YEARS BEFORE\p"
	.string "THE LAST RECORDED VICTORY OF A\n"
	.string "HUMAN AGAINST A COMPUTER IN 2005.$"

PetalburgCity_WallysHouse_Text_PorygonSecondExplanation:
	.string "THE KEY TO THIS QUESTION IS STAB.\n"
	.string "DRAGONITE IS A DRAGON FLYING TYPE.\p"
	.string "THIS MEANS IT HAS A SAME TYPE ATTACK\n"
	.string "BONUS, OR “STAB” WITH DRAGON OR FLYING\p"
	.string "MOVES ... ... ... EVEN THOUGH\n"
	.string "WING ATTACK HAS LOWER POWER, IT GETS\p"
	.string "A 50% BOOST DUE TO STAB... ... ...$"

PetalburgCity_WallysHouse_Text_PorygonThirdExplanation:
	.string "THAT QUESTION WAS MEANT TO TRICK YOU.\n"
	.string "IT WAS NOT HARD AFTER ALL.\p"
	.string "HA HA HA HA HA ... ... ...\n"
	.string "HUMANS ARE EASILY TRICKED.$"

PetalburgCity_WallysHouse_Text_PorygonNextQuestion:
	.string "NEXT QUESTION.$"

PetalburgCity_WallysHouse_Text_PorygonRightAnswer:
	.string "... ... ... ..!\n"
	.string "THAT IS CORRECT. GOOD.$"

PetalburgCity_WallysHouse_Text_PorygonWrongAnswer:
	.string "... ... ... ...\n"
	.string "DISAPPOINTING. THAT IS COMPLETELY\p"
	.string "INCORRECT. DO NOT FAIL AGAIN.$"

PetalburgCity_WallysHouse_Text_WantToPlay:
	.string "... ... ... ...\n"
	.string "HELLO {PLAYER}...\p"
	.string "WOULD YOU LIKE TO PLAY A GAME?$"

PetalburgCity_WallysHouse_Text_PorygonAnotherTime:
	.string "YOU ARE ALLOWED TO LEAVE.\n"
	.string "THIS TIME.$"

PetalburgCity_WallysHouse_Text_PorygonManConfused:
	.string "... ... ... ...\n"
	.string "Where am I? Who are you?\p"
	.string "... ... ... ...\n"
	.string "APOLOGIES. I AM BACK TO NORMAL.\p"
	.string "NO FURTHER GAMES AT THIS TIME.$"

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "You're…\n"
	.string "Ah, you must be {PLAYER}{KUN}, right?\p"
	.string "Thank you for playing with WALLY a\n"
	.string "little while ago.\p"
	.string "He's been frail and sickly ever\n"
	.string "since he was a baby.\p"
	.string "We've sent him to stay with my relatives\n"
	.string "in VERDANTURF TOWN for a while.\p"
	.string "The air is a lot cleaner there\n"
	.string "than it is here.\p"
	.string "What's that? Where's WALLY?\n"
	.string "He's already left, our WALLY.\p"
	.string "I wonder where he could have\n"
	.string "gotten by now?$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "I wonder how our WALLY is doing?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}{KUN}! Please excuse us for\n"
	.string "dragging you here this way.\p"
	.string "But our WALLY's become very healthy\n"
	.string "since he went to VERDANTURF TOWN.\p"
	.string "We owe it all to you!\p"
	.string "When WALLY left town, you helped\n"
	.string "him catch a POKéMON, right?\p"
	.string "I think that made WALLY really\n"
	.string "happy.\p"
	.string "Actually, not just WALLY.\n"
	.string "It made me, his father, happy too.\p"
	.string "Happy that he's gained such a great\n"
	.string "friend as you.\p"
	.string "This isn't a bribe or anything, but\n"
	.string "I'd really like you to have this.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "If your POKéMON can SURF, you'll be\n"
	.string "able to go to all sorts of places.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "WALLY's coming home soon.\n"
	.string "I'm looking forward to that.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "Oh? You met WALLY in\n"
	.string "EVER GRANDE CITY?\p"
	.string "Oh, {PLAYER}{KUN}, don't be silly.\p"
	.string "He may have gotten healthy, but he\n"
	.string "can't go somewhere far away like\l"
	.string "that all by himself.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "WALLY was really happy when he told\n"
	.string "us that he caught a POKéMON.\p"
	.string "It's been ages since I've seen him\n"
	.string "smile like that.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "I want you to keep this a secret\n"
	.string "from my husband…\p"
	.string "But our WALLY left VERDANTURF TOWN\n"
	.string "without telling anyone.\p"
	.string "You know, WALLY is frail, but\n"
	.string "he's surprisingly strong-willed.\p"
	.string "I'm sure that he'll come back safe\n"
	.string "and sound one day!$"

