RustboroCity_DevonCorp_3F_MapScripts::
# 5 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 8 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 11 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

RustboroCity_DevonCorp_3F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 6 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	return

RustboroCity_DevonCorp_3F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 9 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0


RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
# 17 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setobjectxyperm 2, 3, 2
# 18 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_LEFT
	return


RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
# 23 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	end


RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
# 28 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	lockall
# 29 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
# 30 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	closemessage
# 31 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement 2, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
# 32 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	waitmovement 0
# 33 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 34 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement 4, Common_Movement_QuestionMark
# 35 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	delay 80
# 36 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement 2, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
# 37 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	waitmovement 0
# 38 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 39 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	waitmovement 0
# 40 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
# 41 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	closemessage
# 42 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 43 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement 2, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
# 44 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
# 45 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement 4, RustboroCity_DevonCorp_3F_Movement_RivalFollowToPresident
# 46 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	waitmovement 0
# 47 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
# 48 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	closemessage
# 49 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	fadedefaultbgm
# 50 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement 2, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
# 51 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
# 52 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement 4, RustboroCity_DevonCorp_3F_Movement_RivalApproachDesk
# 53 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	waitmovement 0
# 54 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
# 55 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	giveitem ITEM_LETTER
# 56 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
# 57 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 58 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
# 59 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	waitfanfare
# 60 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setflag FLAG_SYS_POKENAV_GET
# 61 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setflag FLAG_RECEIVED_POKENAV
# 62 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
# 63 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
# 64 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	closemessage
# 65 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 66 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
# 67 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	closemessage
# 68 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	delay 20
# 69 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterDown
# 70 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 71 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	waitmovement 0
# 72 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_MaybeBrineyCanHelp, MSGBOX_DEFAULT
# 73 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	closemessage
# 74 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	loadword 0, RustboroCity_DevonCorp_3F_EventScript_RivalFollowing
# 75 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setfollower 4, CUSTOM_SCRIPT_AND_RUN
# 76 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
# 77 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
# 78 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
# 79 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 80 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 81 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setvar VAR_BRINEY_LOCATION, 1
# 82 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
# 83 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setvar VAR_DEVON_CORP_3F_STATE, 1
# 84 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 6
# 85 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	releaseall
	end


RustboroCity_DevonCorp_3F_EventScript_RivalFollowing::
# 90 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	lock
# 91 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	facefollower
# 92 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_RivalFollowing, MSGBOX_DEFAULT
# 93 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	closemessage
# 94 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	release
	end


# 98 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
RustboroCity_DevonCorp_3F_Movement_Unused:
# 99 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_up
# 100 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_up
# 101 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_up
# 102 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_in_place_faster_left
	step_end

# 105 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
# 106 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 107 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 108 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 109 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_down
# 110 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 111 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 112 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 113 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 114 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 115 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 116 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 117 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 118 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 119 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_in_place_faster_left
	step_end

# 122 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
# 123 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	delay_16
# 124 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_in_place_faster_down
	step_end

# 127 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
# 128 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 129 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 130 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 131 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_down
# 132 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 133 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 134 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 135 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
	step_end

# 138 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
# 139 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_left
# 140 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_left
# 141 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_left
# 142 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_left
# 143 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_up
# 144 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_left
# 145 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_left
# 146 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_left
	step_end

# 149 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
# 150 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 150 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 150 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 150 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 151 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_down
# 152 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 152 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 152 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 152 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 152 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 152 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 152 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 152 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
	step_end

# 155 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
RustboroCity_DevonCorp_3F_Movement_RivalFollowToPresident:
# 156 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 156 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 156 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 156 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 156 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 157 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_down
# 158 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 158 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 158 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 158 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 158 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 158 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 158 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
	step_end

# 161 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
# 162 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	delay_16
# 162 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	delay_16
# 163 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_down
# 164 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_down
# 165 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_in_place_faster_right
	step_end

# 168 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
RustboroCity_DevonCorp_3F_Movement_RivalApproachDesk:
# 169 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	delay_16
# 169 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	delay_16
# 170 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 171 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_down
# 172 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
# 176 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	lock
# 177 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	faceplayer
# 178 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
# 179 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
# 180 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
# 181 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	closemessage
# 182 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 183 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	waitmovement 0
# 184 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	release
	end


RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
# 189 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
# 190 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	giveitem ITEM_EXP_SHARE
# 191 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 192 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setflag FLAG_RECEIVED_EXP_SHARE
# 193 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
# 194 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	closemessage
# 195 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 196 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	waitmovement 0
# 197 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	release
	end


RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
# 202 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
# 203 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	closemessage
# 204 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 205 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	waitmovement 0
# 206 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	release
	end


RustboroCity_DevonCorp_3F_EventScript_Employee::
# 211 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	lock
# 212 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	faceplayer
# 213 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
# 214 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
# 215 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	release
	end


RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
# 220 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
# 221 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	release
	end


RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
# 226 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end


RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor::
# 230 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "I'm MR. STONE, the PRESIDENT of\n"
	.string "the DEVON CORPORATION.\p"
	.string "I'd just got word about you, {PLAYER}!\p"
	.string "You saved our staff not just once,\n"
	.string "but twice!\l"
	.string "With the help of your friends,\l"
	.string "of course.\p"
	.string "I have a favor to ask of an amazing\n"
	.string "group like you.\p"
	.string "I understand that you're delivering\n"
	.string "a package to SLATEPORT's SHIPYARD.\p"
	.string "Well, on the way, could you stop off in\n"
	.string "DEWFORD TOWN?\p"
	.string "I was hoping that you'd deliver a\n"
	.string "LETTER to STEVEN in DEWFORD.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis::
# 247 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "MR. STONE: Now, you should know that\n"
	.string "I am a great PRESIDENT.\p"
	.string "So, I'd never be so cheap as to ask\n"
	.string "a favor for nothing in return.\p"
	.string "That's why I want you two to have\n"
	.string "these!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav::
# 255 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "{PLAYER} received a POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp::
# 259 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "MR. STONE: That device…\p"
	.string "It's a POKéMON NAVIGATOR, or POKéNAV\n"
	.string "for short.\p"
	.string "It's an indispensable tool for any\n"
	.string "TRAINER on an adventure.\p"
	.string "It has a map of the HOENN region.\p"
	.string "You can check the locations of\n"
	.string "DEWFORD and SLATEPORT easily!\p"
	.string "By the way, I've heard that sinister\n"
	.string "criminals--MAGMA and AQUA, I believe--\l"
	.string "have been making trouble far and wide.\p"
	.string "I think it would be best if you rested\n"
	.string "up before you go on your way.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare::
# 275 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "MR. STONE: Oh, and I also heard that you\n"
	.string "have another friend who helped defend\l"
	.string "my staff member in PETALBURG WOODS.\l"
	.string "If you see him, could you tell him to\l"
	.string "come see me?\l"
	.string "I would like to reward him as well.\p"
	.string "Alright, {PLAYER}, {RIVAL}, go with\n"
	.string "caution and care!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou::
# 283 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "MR. STONE: I'm counting on you!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter::
# 287 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "MR. STONE: You delivered my LETTER?\n"
	.string "Thank you kindly!\p"
	.string "This is my way of thanking you.\n"
	.string "It should help you, a TRAINER.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare::
# 294 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "MR. STONE: A POKéMON holding that\n"
	.string "EXP. SHARE will be given some of the\l"
	.string "EXP Points from battle.\p"
	.string "It will get EXP Points even if it didn't\n"
	.string "actually battle.\p"
	.string "I would say EXP. SHARE is quite useful\n"
	.string "for raising weak POKéMON.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends::
# 304 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "MR. STONE: Since my youth, I've immersed\n"
	.string "myself in work.\p"
	.string "Consequently, I'm not familiar with\n"
	.string "trends and that sort of thing.\p"
	.string "But do young people all want to be\n"
	.string "TRAINERS in the POKéMON LEAGUE?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere::
# 313 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "This is the DEVON CORPORATION's\n"
	.string "third floor.\p"
	.string "Our PRESIDENT's OFFICE is on\n"
	.string "this floor.\p"
	.string "Anyway, I can't tell you how much I'm\n"
	.string "grateful for what you've done.\p"
	.string "Um… By the way, that parcel\n"
	.string "you got back for us…\p"
	.string "Could I get you to deliver that to\n"
	.string "the SHIPYARD in SLATEPORT?\p"
	.string "It would be awful if those robbers\n"
	.string "tried to take it again.\p"
	.string "Uh… Hehehe, so, uh, could I count\n"
	.string "on you to do that for me?\p"
	.string "Oh, that's right.\n"
	.string "Could you wait here a second?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe::
# 332 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "Our PRESIDENT would like to have\n"
	.string "a word with you two.\p"
	.string "Please come with me.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead::
# 338 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "Please, go ahead.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard::
# 342 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "If you visit the SHIPYARD in SLATEPORT,\n"
	.string "you should go see CAPT. STERN.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular::
# 347 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "DEVON's new products, the REPEAT BALL\n"
	.string "and TIMER BALL, have become hugely\l"
	.string "popular among TRAINERS.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay::
# 353 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "It's a collection of rare rocks and\n"
	.string "stones assembled by the PRESIDENT.$"

RustboroCity_DevonCorp_3F_Text_MaybeBrineyCanHelp::
# 358 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "{RIVAL}: This is so cool!\n"
	.string "With this map feature, we should have\l"
	.string "an easier time finding our way.\p"
	.string "Looks like DEWFORD is on an island\n"
	.string "across the sea.\l"
	.string "MR. BRINEY is an old seafarer.\l"
	.string "Maybe he can help us.\l"
	.string "Lead the way, {PLAYER}!$"

RustboroCity_DevonCorp_3F_Text_RivalFollowing::
# 367 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "Let's go to MR. BRINEY'S cottage on\n"
	.string "ROUTE 104!$"
