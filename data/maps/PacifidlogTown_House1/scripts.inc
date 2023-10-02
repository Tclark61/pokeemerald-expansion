PacifidlogTown_House1_MapScripts::
	.byte 0

PacifidlogTown_House1_EventScript_Man::
	goto_if_set FLAG_UNUSED_0x49A PacifidlogTown_House1_EventScript_ManWishesGoodLuck
	msgbox PacifidlogTown_House1_Text_FirstTalk, MSGBOX_NPC
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_HM03
	waitfanfare
	setflag FLAG_UNUSED_0x49A
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET     
	end

PacifidlogTown_House1_EventScript_ManWishesGoodLuck::
	msgbox PacifidlogTown_House1_Text_ManWishesGoodLuck, MSGBOX_NPC
	end

PacifidlogTown_House1_EventScript_Woman::
	msgbox PacifidlogTown_House1_Text_SixDotsOpenThreeDoors, MSGBOX_NPC
	end

PacifidlogTown_House1_Text_ManWishesGoodLuck:
	.string "That move is SURF! It'll help you\n"
	.string "navigate the water. You have to\p"
	.string "teach it to a pokemon though!$"

PacifidlogTown_House1_Text_FirstTalk:
	.string "You're headed for the CHAMPION?\n"
	.string "That's a bold goal! But...\p"
	.string "The only way forward is up that\n"
	.string "waterfall. Here, I bet I can help.$\p"

PacifidlogTown_House1_Text_SixDotsOpenThreeDoors:
	.string "It's said that all magikarps dream\n"
	.string "of being strong enough to swim up\p"
	.string "a waterfall. I've never seen one do it,\n"
	.string "though. I think they'd evolve beforehand.\p"
	.string "Shame, it'd be nice to see one day.$"

