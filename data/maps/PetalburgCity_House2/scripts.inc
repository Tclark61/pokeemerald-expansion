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

