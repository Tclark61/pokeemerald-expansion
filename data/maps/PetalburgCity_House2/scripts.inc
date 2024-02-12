PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_Jasper::
	faceplayer
	lock
	goto_if_set FLAG_BEAT_CHAMPION, PetalburgCity_House2_EventScript_Jasper_AsksChampion
	msgbox PetalburgCity_House2_Text_JasperIntro, MSGBOX_NPC
	release
	end

PetalburgCity_House2_EventScript_Jasper_AsksChampion::
	goto_if_set FLAG_BEAT_CREATION_TRIO, PetalburgCity_House2_EventScript_Jasper_ThanksThePlayer
	msgbox PetalburgCity_House2_Text_Jasper_AsksChampion, MSGBOX_NPC
	checkitem ITEM_RUBY
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_House2_EventScript_Jasper_CheckSapphire
	release
	end

PetalburgCity_House2_EventScript_Jasper_CheckSapphire::
	checkitem ITEM_SAPPHIRE
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_House2_EventScript_Jasper_CheckAugurite
	release
	end

PetalburgCity_House2_EventScript_Jasper_CheckAugurite::
	checkitem ITEM_BLACK_AUGURITE
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_House2_EventScript_Jasper_AllShards
	release
	end

PetalburgCity_House2_EventScript_Jasper_AllShards::
	msgbox PetalburgCity_House2_Text_Jasper_AllShards, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_House2_EventScript_Jasper_ReadyToSaveTheWorld
	goto PetalburgCity_House2_EventScript_Jasper_NotReadyToSaveTheWorld

PetalburgCity_House2_EventScript_Jasper_ReadyToSaveTheWorld::
	msgbox PetalburgCity_House2_Text_Jasper_LastTest, MSGBOX_NPC
	trainerbattle_single TRAINER_STEVEN, PetalburgCity_House2_Text_Jasper_FightIntro, PetalburgCity_House2_Text_Jasper_FightDefeat
	msgbox PetalburgCity_House2_Text_Jasper_PostFight, MSGBOX_AUTOCLOSE
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 0  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox PetalburgCity_House2_Text_Jasper_OhWhoopsie, MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	playmoncry SPECIES_PALKIA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	playmoncry SPECIES_DIALGA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	playmoncry SPECIES_GIRATINA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	fadescreen FADE_FROM_BLACK
	msgbox PetalburgCity_House2_Text_Legendary_Ominous, MSGBOX_NPC
	trainerbattle_single TRAINER_ANDRES_2, PetalburgCity_House2_Text_Legendary_FightIntro, PetalburgCity_House2_Text_Legendary_FightDefeat
	msgbox PetalburgCity_House2_Text_Legendary_PostFight, MSGBOX_AUTOCLOSE
	givemon SPECIES_PALKIA 80
	givemon SPECIES_DIALGA 80
	givemon SPECIES_GIRATINA 80 ITEM_GRISEOUS_ORB
	setflag FLAG_BEAT_CREATION_TRIO
	releaseall
	end

PetalburgCity_House2_EventScript_Jasper_NotReadyToSaveTheWorld::
	msgbox PetalburgCity_House2_EventScript_Jasper_Disappointed, MSGBOX_NPC
	release
	end

PetalburgCity_House2_EventScript_Jasper_ThanksThePlayer:
	msgbox PetalburgCity_House2_Text_Jasper_ThanksThePlayer, MSGBOX_NPC
	release
	end

PetalburgCity_House2_Text_Jasper_ThanksThePlayer:
	.string "JASPER: Hey there, {PLAYER}.\n"
	.string "Thank you again for everything!\p"
	.string "Hope you're enjoying life in the\n"
	.string "the world you've saved.$"

PetalburgCity_House2_Text_Jasper_LastTest:
	.string "JASPER: Okay, last test! Before\n"
	.string "we head out, show me everything!$"

PetalburgCity_House2_Text_Jasper_FightIntro:
	.string "JASPER: Now's probably the time to warn you,\n"
	.string "I've also been CHAMPION before.\p"
	.string "Thought you should know.$"

PetalburgCity_House2_Text_Jasper_FightDefeat:
	.string "JASPER: {PLAYER}, yes!\p"
	.string "Once we heal up, our teams combined\n"
	.string "can defeat the Creation Trio!$"

PetalburgCity_House2_Text_Jasper_PostFight:
	.string "JASPER: Okay, now to heal up.\n"
	.string "Let's head on out to the POKECENTER,\p"
	.string "and get ready to fight. And remember,\n"
	.string "be careful with handling those shards.\p"
	.string "If they touch, you'll probably summon\n"
	.string "the Trio early.\p"
	.string "... ... ... ... ...\p"
	.string "Sorry, what's that now?\n"
	.string "You think they touched during our fight?\p"
	.string "Hahaha, that's a good one. That'd be bad.\n"
	.string "So there's no way...$"

PetalburgCity_House2_Text_Jasper_OhWhoopsie:
	.string "So, I think we've made mistakes.\n"
	.string "But I don't see them yet...\p"
	.string "Maybe we're ok?$"

PetalburgCity_House2_Text_Legendary_Ominous:
	.string "JASPER?: ... ... ... ...\p"
	.string "Pitiful.\p"
	.string "You are but dust in the scheme\n"
	.string "of our machinations.\p"
	.string "We will create the world of dreams,\n"
	.string "a world re-formed in our own images.\p"
	.string "This vessel? He is gone.\n"
	.string "We have consumed him for his weakness.\p"
	.string "Now, you are next. It's time for you\n"
	.string "to learn your place, child.$"

PetalburgCity_House2_Text_Legendary_FightIntro:
	.string "... ... ...$"

PetalburgCity_House2_Text_Legendary_FightDefeat:
	.string "... ... ...?!\n"
	.string "Impossible.\p"
	.string "No speck of dirt should be capable\n"
	.string "of touching us. This is a mistake.\p"
	.string "How could it be... A mere human.\n"
	.string "Perhaps even as GODS...\p"
	.string "Have we grown arrogant?\p"
	.string "We are beginning to understand.\n"
	.string "Perhaps interfering in this world...\p"
	.string "The struggle of mankind is more fearsome\n"
	.string "than we thought.\p"
	.string "Changing the world to our perfect ideal...\n"
	.string "Would we lose that struggle in the process?\p"
	.string "We will wait on our plans.\n"
	.string "There is beauty in the world we haven't seen.\p"
	.string "Perhaps you, child... You might be able to show\n"
	.string "us more of this beauty.\p"
	.string "Show us a world worth preserving, {PLAYER}.$"

PetalburgCity_House2_Text_Legendary_PostFight:
	.string "!\p"
	.string "JASPER: {PLAYER}, what happened?\n"
	.string "Did you do it?!\p"
	.string "... ... ... ...\p"
	.string "I see. {PLAYER}, I don't know if\n"
	.string "I can ever thank you enough. No.\p"
	.string "I don't know if ANYONE can ever\n"
	.string "thank you enough.\p"
	.string "You've given the world hope for\n"
	.string "a beautiful tomorrow. Thank you.\p"
	.string "Though they may not understand it,\n"
	.string "the world will forever be in your debt.$"

PetalburgCity_House2_Text_NormanBecameGymLeader:
	.string "NORMAN became our town's new\n"
	.string "GYM LEADER.\p"
	.string "I think he called his family over from\n"
	.string "somewhere far away.$"

PetalburgCity_House2_Text_Jasper_AsksChampion:
	.string "JASPER: Hey, CHAMPION. Got any shards?$"

PetalburgCity_House2_Text_JasperIntro:
	.string "Hey there: My name is JASPER.\n"
	.string "I'm on the hunt for rare shards.\p"
	.string "If you find one, and get strong enough\n"
	.string "to help me out, let me know.\p"
	.string "How strong, you ask? I don't know...\n"
	.string "Maybe if you become CHAMPION.$"

PetalburgCity_House2_Text_Jasper_AllShards:
	.string "JASPER: {PLAYER}, you did it!\n"
	.string "Those are all the shards I need!\p"
	.string "And you've become CHAMPION... Wow.\n"
	.string "Let me explain my plan.\p"
	.string "For a while, there have been oddities\n"
	.string "throughout the region...\p"
	.string "Gym Leaders aren't who they're supposed\n"
	.string "to be, the routes have changed,\p"
	.string "and many people have disappeared.\n"
	.string "I've been investigating why.\p"
	.string "Finally, I reached a conclusion:\n"
	.string "The Creation Trio have been meddling.\p"
	.string "To prevent worse effects, we need to find\n"
	.string "their shards and summon their avatars.\p"
	.string "If we restrain the avatars, we can\n"
	.string "save the world. Are you ready?$"

PetalburgCity_House2_EventScript_Jasper_Disappointed:
	.string "No? That's... Disappointing,\n"
	.string "but I guess safe is better than sorry.\p"
	.string "Hurry though, the rift is growing\n"
	.string "more by the minute.$"

