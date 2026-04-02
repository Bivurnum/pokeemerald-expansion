SpaInterior_MapScripts::
# 6 "data/maps/SpaInterior/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SpaInterior_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 13 "data/maps/SpaInterior/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SpaInterior_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SpaInterior_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 7 "data/maps/SpaInterior/scripts.pory"
	switch VAR_SPA_INTRO_STATE
# 8 "data/maps/SpaInterior/scripts.pory"
	case 2, SpaInterior_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

SpaInterior_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 9 "data/maps/SpaInterior/scripts.pory"
	setobjectxyperm RED_ID, 24, 15
# 10 "data/maps/SpaInterior/scripts.pory"
	setobjectxyperm BLUE_ID, 31, 11
	return

SpaInterior_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 14 "data/maps/SpaInterior/scripts.pory"
	map_script_2 VAR_SPA_INTRO_STATE, 2, SpaInterior_OnFrame_0
	.2byte 0


SpaInterior_OnTransition_0::
# 19 "data/maps/SpaInterior/scripts.pory"
	setobjectxyperm RED_ID, 24, 15
# 20 "data/maps/SpaInterior/scripts.pory"
	setobjectxyperm BLUE_ID, 31, 11
	return


SpaInterior_OnFrame_0::
# 25 "data/maps/SpaInterior/scripts.pory"
	lock
# 26 "data/maps/SpaInterior/scripts.pory"
	applymovement LOCALID_PLAYER, SpaInterior_OnFrame_0_Movement_0
# 29 "data/maps/SpaInterior/scripts.pory"
	waitmovement LOCALID_PLAYER
# 30 "data/maps/SpaInterior/scripts.pory"
	playse SE_PIN
# 31 "data/maps/SpaInterior/scripts.pory"
	applymovement RED_ID, SpaInterior_OnFrame_0_Movement_1
# 35 "data/maps/SpaInterior/scripts.pory"
	waitmovement 0
# 36 "data/maps/SpaInterior/scripts.pory"
	delay 60
# 37 "data/maps/SpaInterior/scripts.pory"
	applymovement RED_ID, SpaInterior_OnFrame_0_Movement_2
# 40 "data/maps/SpaInterior/scripts.pory"
	applymovement LOCALID_PLAYER, SpaInterior_OnFrame_0_Movement_0
# 43 "data/maps/SpaInterior/scripts.pory"
	waitmovement LOCALID_PLAYER
# 44 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_0
# 45 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 46 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 47 "data/maps/SpaInterior/scripts.pory"
	delay 30
# 48 "data/maps/SpaInterior/scripts.pory"
	turnobject RED_ID, DIR_EAST
# 49 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_1
# 50 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 51 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 52 "data/maps/SpaInterior/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 53 "data/maps/SpaInterior/scripts.pory"
	delay 30
# 54 "data/maps/SpaInterior/scripts.pory"
	applymovement BLUE_ID, SpaInterior_OnFrame_0_Movement_3
# 59 "data/maps/SpaInterior/scripts.pory"
	waitmovement 0
# 60 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_2
# 61 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 62 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 63 "data/maps/SpaInterior/scripts.pory"
	delay 8
# 64 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_3
# 65 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 66 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 67 "data/maps/SpaInterior/scripts.pory"
	delay 8
# 68 "data/maps/SpaInterior/scripts.pory"
	playse SE_LEDGE
# 69 "data/maps/SpaInterior/scripts.pory"
	applymovement BLUE_ID, SpaInterior_OnFrame_0_Movement_4
# 72 "data/maps/SpaInterior/scripts.pory"
	waitmovement 0
# 73 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_4
# 74 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 75 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 76 "data/maps/SpaInterior/scripts.pory"
	delay 8
# 77 "data/maps/SpaInterior/scripts.pory"
	playse SE_LEDGE
# 78 "data/maps/SpaInterior/scripts.pory"
	applymovement RED_ID, SpaInterior_OnFrame_0_Movement_5
# 81 "data/maps/SpaInterior/scripts.pory"
	waitmovement 0
# 82 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_5
# 83 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 84 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 85 "data/maps/SpaInterior/scripts.pory"
	delay 8
# 86 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_6
# 87 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 88 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 89 "data/maps/SpaInterior/scripts.pory"
	delay 8
# 90 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_7
# 91 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 92 "data/maps/SpaInterior/scripts.pory"
	turnobject RED_ID, DIR_SOUTH
# 93 "data/maps/SpaInterior/scripts.pory"
	delay 8
# 94 "data/maps/SpaInterior/scripts.pory"
	turnobject BLUE_ID, DIR_SOUTH
# 95 "data/maps/SpaInterior/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 96 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_8
# 110 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_9
# 115 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 116 "data/maps/SpaInterior/scripts.pory"
	turnobject BLUE_ID, DIR_WEST
# 117 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_10
# 120 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 121 "data/maps/SpaInterior/scripts.pory"
	turnobject RED_ID, DIR_EAST
# 122 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_11
# 125 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 126 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 127 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_12
# 130 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_13
# 134 "data/maps/SpaInterior/scripts.pory"
	turnobject RED_ID, DIR_SOUTH
# 135 "data/maps/SpaInterior/scripts.pory"
	turnobject BLUE_ID, DIR_SOUTH
# 136 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 137 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_14
# 138 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 139 "data/maps/SpaInterior/scripts.pory"
	applymovement RED_ID, SpaInterior_OnFrame_0_Movement_6
# 145 "data/maps/SpaInterior/scripts.pory"
	applymovement BLUE_ID, SpaInterior_OnFrame_0_Movement_7
# 151 "data/maps/SpaInterior/scripts.pory"
	applymovement LOCALID_PLAYER, SpaInterior_OnFrame_0_Movement_8
# 159 "data/maps/SpaInterior/scripts.pory"
	waitmovement LOCALID_PLAYER
# 160 "data/maps/SpaInterior/scripts.pory"
	delay 30
# 161 "data/maps/SpaInterior/scripts.pory"
	applymovement BLUE_ID, SpaInterior_OnFrame_0_Movement_0
# 164 "data/maps/SpaInterior/scripts.pory"
	waitmovement 0
# 165 "data/maps/SpaInterior/scripts.pory"
	applymovement BLUE_ID, SpaInterior_OnFrame_0_Movement_9
# 168 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_15
# 170 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 171 "data/maps/SpaInterior/scripts.pory"
	delay 90
# 172 "data/maps/SpaInterior/scripts.pory"
	turnobject BLUE_ID, DIR_SOUTH
# 173 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_16
# 178 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_17
# 183 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_18
# 185 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 186 "data/maps/SpaInterior/scripts.pory"
	applymovement BLUE_ID, SpaInterior_OnFrame_0_Movement_10
# 191 "data/maps/SpaInterior/scripts.pory"
	applymovement RED_ID, SpaInterior_OnFrame_0_Movement_11
# 196 "data/maps/SpaInterior/scripts.pory"
	applymovement LOCALID_PLAYER, SpaInterior_OnFrame_0_Movement_12
# 201 "data/maps/SpaInterior/scripts.pory"
	waitmovement LOCALID_PLAYER
# 202 "data/maps/SpaInterior/scripts.pory"
	setvar VAR_SPA_INTRO_STATE, 3
# 203 "data/maps/SpaInterior/scripts.pory"
	warp MAP_SPA_MOUNTAIN, 0
# 204 "data/maps/SpaInterior/scripts.pory"
	waitstate
	return


SpaInterior_EventScript_KimonoRed::
	return


SpaInterior_EventScript_KimonoBlue::
	return


SpaInterior_EventScript_CynthiaSick::
# 216 "data/maps/SpaInterior/scripts.pory"
	lock
# 217 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_EventScript_CynthiaSick_Text_0
# 218 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 219 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 220 "data/maps/SpaInterior/scripts.pory"
	releaseall
	end


# 26 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_0:
# 27 "data/maps/SpaInterior/scripts.pory"
	walk_up
	step_end

# 31 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_1:
# 32 "data/maps/SpaInterior/scripts.pory"
	face_down
# 33 "data/maps/SpaInterior/scripts.pory"
	emote_exclamation_mark
	step_end

# 37 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_2:
# 38 "data/maps/SpaInterior/scripts.pory"
	walk_down
	step_end

# 54 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_3:
# 55 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 55 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 55 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 55 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 55 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 56 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 56 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 56 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 56 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 56 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 56 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 57 "data/maps/SpaInterior/scripts.pory"
	delay_8
	step_end

# 69 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_4:
# 70 "data/maps/SpaInterior/scripts.pory"
	jump_in_place_left
	step_end

# 78 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_5:
# 79 "data/maps/SpaInterior/scripts.pory"
	jump_in_place_right
	step_end

# 139 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_6:
# 140 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 140 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 140 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 140 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 140 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 140 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 141 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 141 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 141 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 141 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 141 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 141 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 141 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 141 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 141 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 141 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 142 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 142 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 142 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 142 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 142 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 142 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 142 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 143 "data/maps/SpaInterior/scripts.pory"
	face_up
	step_end

# 145 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_7:
# 146 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 146 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 146 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 146 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 146 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 146 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 146 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 147 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 147 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 147 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 147 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 147 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 147 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 147 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 147 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 147 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 147 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 148 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 148 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 148 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 148 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 148 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 148 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 149 "data/maps/SpaInterior/scripts.pory"
	face_up
	step_end

# 151 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_8:
# 152 "data/maps/SpaInterior/scripts.pory"
	delay_16
# 153 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 155 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 155 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 155 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 155 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 155 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 155 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 155 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 155 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 155 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 155 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 156 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 156 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 156 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 156 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 156 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 157 "data/maps/SpaInterior/scripts.pory"
	face_up
	step_end

# 165 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_9:
# 166 "data/maps/SpaInterior/scripts.pory"
	walk_in_place_up
# 166 "data/maps/SpaInterior/scripts.pory"
	walk_in_place_up
# 166 "data/maps/SpaInterior/scripts.pory"
	walk_in_place_up
# 166 "data/maps/SpaInterior/scripts.pory"
	walk_in_place_up
	step_end

# 186 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_10:
# 187 "data/maps/SpaInterior/scripts.pory"
	delay_16
# 188 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 188 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 189 "data/maps/SpaInterior/scripts.pory"
	set_invisible
	step_end

# 191 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_11:
# 192 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 193 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 193 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 193 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 194 "data/maps/SpaInterior/scripts.pory"
	set_invisible
	step_end

# 196 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_12:
# 197 "data/maps/SpaInterior/scripts.pory"
	delay_16
# 198 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 199 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 199 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 199 "data/maps/SpaInterior/scripts.pory"
	walk_up
	step_end

SpaInterior_OnFrame_0_Text_0:
# 44 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}Welcome!\nYou must be the new temple apprentice.\pYou've arrived at a good time.\nEverything's so exciting!\pCome with me.\pI'll introduce you to my partner.$"

SpaInterior_OnFrame_0_Text_1:
# 49 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}URESHI!!!!!$"

SpaInterior_OnFrame_0_Text_2:
# 60 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}What do you want, Itami?!$"

SpaInterior_OnFrame_0_Text_3:
# 64 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}New apprentice, I'd like you to\nmeet Ureshi.\pWhile I'm keeping the temple clean\nand proper, she's outside playing\lin the dirt.$"

SpaInterior_OnFrame_0_Text_4:
# 73 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}Humph!\nI keep the plants healthy and\lthe grounds beautiful.\pAt least I get some sun instead of\nsitting inside all day.$"

SpaInterior_OnFrame_0_Text_5:
# 82 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}Harumph!$"

SpaInterior_OnFrame_0_Text_6:
# 86 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}Aren't you going to tell our\nnew apprentice about the excitement\laround here?$"

SpaInterior_OnFrame_0_Text_7:
# 90 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}I was just about to!$"

SpaInterior_OnFrame_0_Text_8:
# 96 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}Ahem.\n"
	.string "As you know, hundreds of years ago\l"
	.string "this temple was a place for\l"
	.string "mythical Pokémon to come and be cared\l"
	.string "for by the temple stewards.\p"
	.string "It has been many ages since any\n"
	.string "mythical Pokémon have been seen.\l"
	.string "However, just recently some Pokémon\l"
	.string "with strange patterns have been\l"
	.string "showing up in droves on the mountain!\p"
	.string "Isn't that inte--?$"

SpaInterior_OnFrame_0_Text_9:
# 110 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}So we called in an expert on\n"
	.string "Pokémon mythology.\l"
	.string "She's out there right now\l"
	.string "figuring out what to do.$"

SpaInterior_OnFrame_0_Text_10:
# 117 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}What was her name?\n"
	.string "Korrina?$"

SpaInterior_OnFrame_0_Text_11:
# 122 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}No, no,\n"
	.string "I think it was Candice.$"

SpaInterior_OnFrame_0_Text_12:
# 127 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}In any case, she's been out there\n"
	.string "a long time.\l"
	.string "Do you think we should check on her?$"

SpaInterior_OnFrame_0_Text_13:
# 130 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}Why, Ureshi!\n"
	.string "I do believe that is the first good\l"
	.string "idea you've had all day.\l"
	.string "Let's go find her.$"

SpaInterior_OnFrame_0_Text_14:
# 137 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}You should come too, apprentice.$"

SpaInterior_OnFrame_0_Text_15:
# 168 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}Oh, Clair! Can you hear us?\n"
	.string "Come meet our new apprentice!$"

SpaInterior_OnFrame_0_Text_16:
# 173 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}That's peculiar.\n"
	.string "She ALWAYS responds to me.\p"
	.string "Do you think something could've\n"
	.string "happened to her?$"

SpaInterior_OnFrame_0_Text_17:
# 178 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}You're right.\n"
	.string "This is concerning.\p"
	.string "I know she told us not to go out there,\n"
	.string "but should we check on her?$"

SpaInterior_OnFrame_0_Text_18:
# 183 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}There's no harm in taking a peek, right?\n"
	.string "Come on.$"

SpaInterior_EventScript_CynthiaSick_Text_0:
# 217 "data/maps/SpaInterior/scripts.pory"
	.string "She's sleeping peacefully.$"
