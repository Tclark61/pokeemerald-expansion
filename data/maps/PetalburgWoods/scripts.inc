.set LOCALID_GRUNT, 3
.set LOCALID_DEVON_EMPLOYEE, 4

PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_GRUNT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Foongus1::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	msgbox PetalburgWoods_Text_WeirdBall, MSGBOX_DEFAULT
	setwildbattle SPECIES_FOONGUS, 14
	waitse
	playmoncry SPECIES_FOONGUS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	removeobject 11
	setflag FLAG_PETALBURG_WOODS_FOONGUS1
	releaseall
	end

PetalburgWoods_EventScript_BiancaSign::
	msgbox PetalburgWoods_Text_BiancaSign, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_ItemfinderGuy::
	faceplayer
	lock
	goto_if_set FLAG_GOT_ITEMFINDER, PetalburgWoods_EventScript_ItemfinderGuy_AsksAboutItems
	goto PetalburgWoods_EventScript_ItemfinderGuy_GivesItemfinder

PetalburgWoods_EventScript_ItemfinderGuy_GivesItemfinder::
	msgbox Route110_Text_BrendanTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_BrendanExplainItemfinder, MSGBOX_DEFAULT
	setflag FLAG_GOT_ITEMFINDER
	release
	end

PetalburgWoods_EventScript_ItemfinderGuy_AsksAboutItems::
	msgbox PetalburgWoods_Text_ItemfinderGuy_AsksAboutItems, MSGBOX_NPC
	release
	end

PetalburgWoods_EventScript_Foongus2::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	msgbox PetalburgWoods_Text_WeirdBall, MSGBOX_DEFAULT
	setwildbattle SPECIES_FOONGUS, 14
	waitse
	playmoncry SPECIES_FOONGUS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	removeobject 12
	setflag FLAG_PETALBURG_WOODS_FOONGUS2
	releaseall
	end

PetalburgWoods_EventScript_Voltorb::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	msgbox PetalburgWoods_Text_WeirdBall, MSGBOX_DEFAULT
	setwildbattle SPECIES_VOLTORB_HISUIAN, 15
	waitse
	playmoncry SPECIES_VOLTORB_HISUIAN, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	removeobject 13
	setflag FLAG_PETALBURG_WOODS_VOLTORB
	releaseall
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_Azurill::
	lock
	faceplayer
	msgbox PetalburgWoods_Text_SuspiciousPokemon, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_HiddenForest::
	lock
	faceplayer
	msgbox PetalburgWoods_Text_HiddenForest, MSGBOX_NPC
	release
	end


PetalburgWoods_EventScript_Sign_NorthWest::
	msgbox PetalburgWoods_Text_Sign_NorthWest, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign_East::
	msgbox PetalburgWoods_Text_Sign_East, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign_South::
	msgbox PetalburgWoods_Text_Sign_South, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign_North::
	msgbox PetalburgWoods_Text_Sign_North, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign_NorthEmphatic::
	msgbox PetalburgWoods_Text_Sign_NorthEmphatic, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Zach::
	trainerbattle_single TRAINER_ZACH_1, PetalburgWoods_Text_ZachIntroText, PetalburgWoods_Text_ZachDefeatText, PetalburgWoods_EventScript_TryRegisterZach
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_ZachRematch
	setvar VAR_0x8004, TRAINER_ZACH_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterZach2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterZach::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterZach
	release
	end

PetalburgWoods_EventScript_RegisterZach::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_ZACH_1
	release
	end

PetalburgWoods_EventScript_TryRegisterZach2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterZach2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterZach2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_ZACH_1
	release
	end

PetalburgWoods_EventScript_ZachRematch::
	trainerbattle_rematch TRAINER_ZACH_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_ItemfinderGuy_AsksAboutItems:
	.string "A lot of items can be hidden.\n"
	.string "Use the ITEMFINDER to check.\p"
	.string "Otherwise, you'll be missing out on value.$"

PetalburgWoods_Text_BiancaSign:
	.string "BIANCA's house$"

PetalburgWoods_Text_HiddenForest:
	.string "Up ahead is FORTREE CITY.\n"
	.string "However, very few people have entered.\p"
	.string "Here's a piece of advice for you:\n"
	.string "Don't just think with your eyes.\p"
	.string "If you follow the signs, and trust\n"
	.string "your gut instead of what makes sense,\p"
	.string "I'm sure you'll find what you need.$"

PetalburgWoods_Text_SuspiciousPokemon:
	.string "Oh! Didn't see you there.\n"
	.string "Uh...\p"
	.string "Pika... Chu?$" 

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Hmmm…\n"
	.string "Not a one to be found…$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Hello, have you seen any POKéMON\n"
	.string "called SHROOMISH around here?\p"
	.string "I really love that POKéMON.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "I was going to ambush you, but you\n"
	.string "had to dawdle in PETALBURG WOODS\l"
	.string "forever, didn't you?\p"
	.string "I got sick of waiting, so here I am!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "You! DEVON RESEARCHER!\p"
	.string "Hand over those papers!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Aiyeeeh!\p"
	.string "You're a POKéMON TRAINER, aren't you?\n"
	.string "You've got to help me, please!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "Hunh? What do you think you're doing?\n"
	.string "What, you're going to protect him?\p"
	.string "No one who crosses TEAM AQUA\n"
	.string "gets any mercy, not even a kid!\p"
	.string "Come on and battle me!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "You're kidding me! You're tough!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Grrr… You've got some nerve\n"
	.string "meddling with TEAM AQUA!\l"
	.string "Come on and battle me again!\p"
	.string "I wish I could say that, but I'm out of\n"
	.string "POKéMON…\p"
	.string "And, hey, we of TEAM AQUA are also\n"
	.string "after something in RUSTBORO.\p"
	.string "I'll let you go today!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Whew…\n"
	.string "That was awfully close!\p"
	.string "Thanks to you, he didn't rob me of\n"
	.string "these important papers.\p"
	.string "I know, I'll give you a GREAT BALL as\n"
	.string "my thanks!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "Didn't that TEAM AQUA thug say\n"
	.string "they were after something in\l"
	.string "RUSTBORO, too?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "Uh-oh! It's a crisis!\n"
	.string "I can't be wasting time!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "You're loaded with items.\n"
	.string "I can't give you this GREAT BALL.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "I caught a whole bunch of POKéMON!\p"
	.string "Go, go, go!\n"
	.string "My BUG POKéMON team!$"

PetalburgWoods_Text_ICouldntWin:
	.string "I have all these POKéMON,\n"
	.string "but I couldn't win…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "I caught a bunch of POKéMON.\n"
	.string "Now I'm out of POKé BALLS.$"

PetalburgWoods_Text_ZachIntroText:
	.string "Don't think when you battle!\n"
	.string "Just pick the strongest move and win!$"

PetalburgWoods_Text_ZachDefeatText:
	.string "But my moves did more damage.\n"
	.string "Something isn't adding up...$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "If your moves do a lot of damage,\n"
	.string "you don't need to think so hard.\p"
	.string "POKéMON is best when it's simple.$"

PetalburgWoods_Text_IWantRematch1:
	.string "Are you free on Mondays?\n"
	.string "I'm making a volleyball team!\p"
	.string "Take my number if you're interested!$"

PetalburgWoods_Text_IWantRematch2:
	.string "I want a rematch when my BUG \n"
	.string "POKéMON grow up!\p"
	.string "I'm registering you in my POKéNAV!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "My BUG POKéMON have grown.\n"
	.string "I'll be popular again.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "I can't be popular if I lose.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "You get to be popular if you have\n"
	.string "strong POKéMON, right?\l"
	.string "So, I've been training hard.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Yo, there!\n"
	.string "Do you smell that fragrance?\p"
	.string "That's a POKéMON's SWEET SCENT.\n"
	.string "If you use SWEET SCENT outside,\n"
	.string "POKéMON will notice.\p"
	.string "It's the easiest way to catch\n"
	.string "a new party member.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "One day, this forest will be open\n"
	.string "to the public, and this will expand.\p"
	.string "I think right now it hasn't been made.\p"
	.string "... Wait a minute! It's open now!$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Oh, neat!\n"
	.string "That's the BADGE from RUSTBORO GYM!\p"
	.string "You must be a TRAINER.\n"
	.string "You should try using this item.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "It's a MIRACLE SEED.\n"
	.string "If a POKéMON holds that item, its\l"
	.string "GRASS-type moves become stronger.\p"
	.string "Besides MIRACLE SEED, I think there are\n"
	.string "other convenient items for POKéMON\l"
	.string "to hold.$"

PetalburgWoods_Text_Sign_NorthWest:
	.string "The sign has an arrow pointing\n"
	.string "to the northwest.$"

PetalburgWoods_Text_Sign_East:
	.string "The sign has an arrow pointing\n"
	.string "to the east.$"

PetalburgWoods_Text_Sign_South:
	.string "The sign has an arrow pointing\n"
	.string "to the south.$"

PetalburgWoods_Text_Sign_SouthWest:
	.string "The sign has an arrow pointing\n"
	.string "to the southwest.$"

PetalburgWoods_Text_Sign_North:
	.string "The sign has an arrow pointing\n"
	.string "to the north.$"

PetalburgWoods_Text_Sign_NorthEmphatic:
	.string "The sign has an arrow pointing\n"
	.string "to the north.\p"
	.string "... ... ... There's an\n"
	.string "exclamation point written!$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "TRAINER TIPS\p"
	.string "In order to MEGA EVOLVE, you must\n"
	.string "give a POKéMON their MEGA STONE.\p"
	.string "Then, during battle, before you pick\n"
	.string "a move, you will see a glowing symbol.\p"
	.string "Press START to highlight it, and then\n"
	.string "the POKéMON will MEGA EVOLVE!$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "{UP_ARROW} FORTREE CITY$"

PetalburgWoods_Text_WeirdBall:
	.string "This isn't an item!\n"
	.string "It's a POKéMON!$"
