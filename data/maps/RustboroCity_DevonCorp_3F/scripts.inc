RustboroCity_DevonCorp_3F_MapScripts::
# 5 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 9 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 12 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

RustboroCity_DevonCorp_3F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 6 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 7 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	return

RustboroCity_DevonCorp_3F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 10 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 13 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0


RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
# 18 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setobjectxyperm 2, 3, 2
# 19 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_LEFT
	return


RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
# 24 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	end


RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
# 29 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	lockall
# 30 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
# 31 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	closemessage
# 32 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement 2, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
# 33 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	waitmovement 0
# 34 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 35 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement 4, Common_Movement_QuestionMark
# 36 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	delay 80
# 37 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement 2, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
# 38 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	waitmovement 0
# 39 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 40 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	waitmovement 0
# 41 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
# 42 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	closemessage
# 43 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 44 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement 2, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
# 45 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
# 46 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement 4, RustboroCity_DevonCorp_3F_Movement_RivalFollowToPresident
# 47 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	waitmovement 0
# 48 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
# 49 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	closemessage
# 50 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	fadedefaultbgm
# 51 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement 2, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
# 52 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
# 53 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement 4, RustboroCity_DevonCorp_3F_Movement_RivalApproachDesk
# 54 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	waitmovement 0
# 55 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
# 56 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	giveitem ITEM_LETTER
# 57 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
# 58 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 59 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
# 60 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	waitfanfare
# 61 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setflag FLAG_SYS_POKENAV_GET
# 62 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setflag FLAG_RECEIVED_POKENAV
# 63 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
# 64 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
# 65 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	closemessage
# 66 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 67 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
# 68 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	closemessage
# 69 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	delay 20
# 70 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterDown
# 71 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 72 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	waitmovement 0
# 73 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_MaybeBrineyCanHelp, MSGBOX_DEFAULT
# 74 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	closemessage
# 75 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	loadword 0, RustboroCity_DevonCorp_3F_EventScript_RivalFollowing
# 76 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setfollower 4, CUSTOM_SCRIPT_AND_RUN
# 77 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
# 78 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
# 79 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
# 80 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 81 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 82 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setvar VAR_BRINEY_LOCATION, 1
# 83 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
# 84 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setvar VAR_DEVON_CORP_3F_STATE, 1
# 85 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 6
# 86 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	releaseall
	end


RustboroCity_DevonCorp_3F_EventScript_RivalFollowing::
# 91 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	lock
# 92 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	facefollower
# 93 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_RivalFollowing, MSGBOX_DEFAULT
# 94 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	closemessage
# 95 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	release
	end


# 99 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
RustboroCity_DevonCorp_3F_Movement_Unused:
# 100 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_up
# 101 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_up
# 102 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_up
# 103 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_in_place_faster_left
	step_end

# 106 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
# 107 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 108 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 109 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 110 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_down
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
	walk_right
# 120 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_in_place_faster_left
	step_end

# 123 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
# 124 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	delay_16
# 125 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_in_place_faster_down
	step_end

# 128 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
# 129 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 130 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 131 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 132 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_down
# 133 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 134 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 135 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 136 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
	step_end

# 139 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
# 140 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_left
# 141 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_left
# 142 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_left
# 143 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_left
# 144 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_up
# 145 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_left
# 146 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_left
# 147 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_left
	step_end

# 150 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
# 151 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 151 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 151 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 151 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 152 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_down
# 153 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 153 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 153 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 153 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 153 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 153 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 153 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 153 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
	step_end

# 156 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
RustboroCity_DevonCorp_3F_Movement_RivalFollowToPresident:
# 157 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 157 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 157 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 157 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 157 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 158 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_down
# 159 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 159 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 159 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 159 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 159 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 159 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 159 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
	step_end

# 162 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
# 163 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	delay_16
# 163 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	delay_16
# 164 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_down
# 165 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_down
# 166 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_in_place_faster_right
	step_end

# 169 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
RustboroCity_DevonCorp_3F_Movement_RivalApproachDesk:
# 170 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	delay_16
# 170 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	delay_16
# 171 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_right
# 172 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_down
# 173 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
# 177 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	lock
# 178 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	faceplayer
# 179 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
# 180 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
# 181 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
# 182 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	closemessage
# 183 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 184 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	waitmovement 0
# 185 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	release
	end


RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
# 190 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
# 191 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	giveitem ITEM_EXP_SHARE
# 192 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 193 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	setflag FLAG_RECEIVED_EXP_SHARE
# 194 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
# 195 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	closemessage
# 196 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 197 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	waitmovement 0
# 198 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	release
	end


RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
# 203 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
# 204 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	closemessage
# 205 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 206 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	waitmovement 0
# 207 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	release
	end


RustboroCity_DevonCorp_3F_EventScript_Employee::
# 212 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	lock
# 213 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	faceplayer
# 214 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
# 215 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
# 216 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	release
	end


RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
# 221 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
# 222 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	release
	end


RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
# 227 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end


RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor::
# 231 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
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
# 248 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "MR. STONE: Now, you should know that\n"
	.string "I am a great PRESIDENT.\p"
	.string "So, I'd never be so cheap as to ask\n"
	.string "a favor for nothing in return.\p"
	.string "That's why I want you two to have\n"
	.string "these!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav::
# 256 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "{PLAYER} received a POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp::
# 260 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
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
# 276 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "MR. STONE: Oh, and I also heard that you\n"
	.string "have another friend who helped defend\l"
	.string "my staff member in PETALBURG WOODS.\l"
	.string "If you see him, could you tell him to\l"
	.string "come see me?\l"
	.string "I would like to reward him as well.\p"
	.string "Alright, {PLAYER}, {RIVAL}, go with\n"
	.string "caution and care!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou::
# 284 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "MR. STONE: I'm counting on you!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter::
# 288 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "MR. STONE: You delivered my LETTER?\n"
	.string "Thank you kindly!\p"
	.string "This is my way of thanking you.\n"
	.string "It should help you, a TRAINER.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare::
# 295 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "MR. STONE: A POKéMON holding that\n"
	.string "EXP. SHARE will be given some of the\l"
	.string "EXP Points from battle.\p"
	.string "It will get EXP Points even if it didn't\n"
	.string "actually battle.\p"
	.string "I would say EXP. SHARE is quite useful\n"
	.string "for raising weak POKéMON.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends::
# 305 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "MR. STONE: Since my youth, I've immersed\n"
	.string "myself in work.\p"
	.string "Consequently, I'm not familiar with\n"
	.string "trends and that sort of thing.\p"
	.string "But do young people all want to be\n"
	.string "TRAINERS in the POKéMON LEAGUE?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere::
# 314 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
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
# 333 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "Our PRESIDENT would like to have\n"
	.string "a word with you two.\p"
	.string "Please come with me.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead::
# 339 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "Please, go ahead.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard::
# 343 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "If you visit the SHIPYARD in SLATEPORT,\n"
	.string "you should go see CAPT. STERN.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular::
# 348 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "DEVON's new products, the REPEAT BALL\n"
	.string "and TIMER BALL, have become hugely\l"
	.string "popular among TRAINERS.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay::
# 354 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "It's a collection of rare rocks and\n"
	.string "stones assembled by the PRESIDENT.$"

RustboroCity_DevonCorp_3F_Text_MaybeBrineyCanHelp::
# 359 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "{RIVAL}: This is so cool!\n"
	.string "With this map feature, we should have\l"
	.string "an easier time finding our way.\p"
	.string "Looks like DEWFORD is on an island\n"
	.string "across the sea.\l"
	.string "MR. BRINEY is an old seafarer.\l"
	.string "Maybe he can help us.\l"
	.string "Lead the way, {PLAYER}!$"

RustboroCity_DevonCorp_3F_Text_RivalFollowing::
# 368 "data/maps/RustboroCity_DevonCorp_3F/scripts.pory"
	.string "Let's go to MR. BRINEY'S cottage on\n"
	.string "ROUTE 104!$"
