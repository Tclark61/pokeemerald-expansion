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
	goto PetalburgCity_House2_EventScript_Jasper_NotReadyToSaveTheWorld

PetalburgCity_House2_EventScript_Jasper_NotReadyToSaveTheWorld::
	msgbox PetalburgCity_House2_EventScript_Jasper_Disappointed, MSGBOX_NPC
	release
	end

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
	.string "{PLAYER}, you did it!\n"
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

