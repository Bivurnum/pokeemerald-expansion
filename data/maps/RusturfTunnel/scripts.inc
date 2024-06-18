# 6 "data/maps/RusturfTunnel/scripts.pory"

# 7 "data/maps/RusturfTunnel/scripts.pory"
.equ LOCALID_WANDAS_BF, 1
# 8 "data/maps/RusturfTunnel/scripts.pory"
.set LOCALID_BRINEY, 5
# 9 "data/maps/RusturfTunnel/scripts.pory"
.set LOCALID_GRUNT, 6
# 10 "data/maps/RusturfTunnel/scripts.pory"
.set LOCALID_PEEKO, 7
# 11 "data/maps/RusturfTunnel/scripts.pory"
.equ LOCALID_WANDA, 10
# 12 "data/maps/RusturfTunnel/scripts.pory"
.set LOCALID_RIVAL1, 11
# 13 "data/maps/RusturfTunnel/scripts.pory"

# 14 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_MapScripts::
# 15 "data/maps/RusturfTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RusturfTunnel_OnTransition
# 16 "data/maps/RusturfTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RusturfTunnel_OnFrame
# 17 "data/maps/RusturfTunnel/scripts.pory"
	.byte 0
# 18 "data/maps/RusturfTunnel/scripts.pory"

# 19 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_OnFrame:
# 20 "data/maps/RusturfTunnel/scripts.pory"
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 7, RusturfTunnel_EventScript_ClearTunnelScene
# 21 "data/maps/RusturfTunnel/scripts.pory"
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 8, RusturfTunnel_EventScript_ClearTunnelScene
# 22 "data/maps/RusturfTunnel/scripts.pory"
	.2byte 0
# 23 "data/maps/RusturfTunnel/scripts.pory"

# 24 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_OnTransition:
# 25 "data/maps/RusturfTunnel/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 26 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_RUSTURF_TUNNEL_STATE, 2, RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos
# 27 "data/maps/RusturfTunnel/scripts.pory"
	end
# 28 "data/maps/RusturfTunnel/scripts.pory"

# 29 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos::
# 30 "data/maps/RusturfTunnel/scripts.pory"
	setobjectxyperm LOCALID_PEEKO, 13, 4
# 31 "data/maps/RusturfTunnel/scripts.pory"
	setobjectxyperm LOCALID_GRUNT, 13, 5
# 32 "data/maps/RusturfTunnel/scripts.pory"
	return
# 33 "data/maps/RusturfTunnel/scripts.pory"

# 34 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Wanda::
# 35 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 36 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 37 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_BoyfriendOnOtherSideOfRock, MSGBOX_DEFAULT
# 38 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 39 "data/maps/RusturfTunnel/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 40 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 41 "data/maps/RusturfTunnel/scripts.pory"
	release
# 42 "data/maps/RusturfTunnel/scripts.pory"
	end
# 43 "data/maps/RusturfTunnel/scripts.pory"

# 44 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandasBoyfriend::
# 45 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 46 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 47 "data/maps/RusturfTunnel/scripts.pory"
	goto_if_set FLAG_TEMP_1, RusturfTunnel_EventScript_AlreadySpokenTo
# 48 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_TEMP_1
# 49 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_WhyCantTheyKeepDigging, MSGBOX_DEFAULT
# 50 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 51 "data/maps/RusturfTunnel/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 52 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 53 "data/maps/RusturfTunnel/scripts.pory"
	release
# 54 "data/maps/RusturfTunnel/scripts.pory"
	end
# 55 "data/maps/RusturfTunnel/scripts.pory"

# 56 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_AlreadySpokenTo::
# 57 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ToGetToVerdanturf, MSGBOX_DEFAULT
# 58 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 59 "data/maps/RusturfTunnel/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 60 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 61 "data/maps/RusturfTunnel/scripts.pory"
	release
# 62 "data/maps/RusturfTunnel/scripts.pory"
	end
# 63 "data/maps/RusturfTunnel/scripts.pory"

# 64 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_ClearTunnelScene::
# 65 "data/maps/RusturfTunnel/scripts.pory"
	lockall
# 66 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_FaceWandasBoyfriend1
# 67 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_FaceWandasBoyfriend2
# 68 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_FaceWandasBoyfriend3
# 69 "data/maps/RusturfTunnel/scripts.pory"
	call RusturfTunnel_EventScript_WandasBoyfriendNotice
# 70 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_YouShatteredBoulderTakeHM, MSGBOX_DEFAULT
# 71 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
# 72 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
# 73 "data/maps/RusturfTunnel/scripts.pory"
	giveitem ITEM_HM_STRENGTH
# 74 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_RECEIVED_HM_STRENGTH
# 75 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ExplainStrength, MSGBOX_DEFAULT
# 76 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 77 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_BoyfriendApproachWanda1
# 78 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_BoyfriendApproachWanda2
# 79 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_BoyfriendApproachWanda3
# 80 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_WandaReunion, MSGBOX_DEFAULT
# 81 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 82 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_WandaAndBoyfriendExit1
# 83 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_WandaAndBoyfriendExit
# 84 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_WandaAndBoyfriendExit
# 85 "data/maps/RusturfTunnel/scripts.pory"
	call RusturfTunnel_EventScript_SetRusturfTunnelOpen
# 86 "data/maps/RusturfTunnel/scripts.pory"
	releaseall
# 87 "data/maps/RusturfTunnel/scripts.pory"
	end
# 88 "data/maps/RusturfTunnel/scripts.pory"

# 89 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_BoyfriendApproachWanda1::
# 90 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend1
# 91 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda1
# 92 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 93 "data/maps/RusturfTunnel/scripts.pory"
	return
# 94 "data/maps/RusturfTunnel/scripts.pory"

# 95 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_BoyfriendApproachWanda2::
# 96 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
# 97 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
# 98 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 99 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDA, Common_Movement_WalkInPlaceFasterDown
# 100 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 101 "data/maps/RusturfTunnel/scripts.pory"
	return
# 102 "data/maps/RusturfTunnel/scripts.pory"

# 103 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_BoyfriendApproachWanda3::
# 104 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
# 105 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
# 106 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 107 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDA, Common_Movement_WalkInPlaceFasterDown
# 108 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 109 "data/maps/RusturfTunnel/scripts.pory"
	return
# 110 "data/maps/RusturfTunnel/scripts.pory"

# 111 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_FaceWandasBoyfriend1::
# 112 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, Common_Movement_WalkInPlaceFasterUp
# 113 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 114 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 115 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 116 "data/maps/RusturfTunnel/scripts.pory"
	return
# 117 "data/maps/RusturfTunnel/scripts.pory"

# 118 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_FaceWandasBoyfriend2::
# 119 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendFaceRight
# 120 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 121 "data/maps/RusturfTunnel/scripts.pory"
	return
# 122 "data/maps/RusturfTunnel/scripts.pory"

# 123 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_FaceWandasBoyfriend3::
# 124 "data/maps/RusturfTunnel/scripts.pory"
	return
# 125 "data/maps/RusturfTunnel/scripts.pory"

# 126 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer::
# 127 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 128 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendApproachPlayer
# 129 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 130 "data/maps/RusturfTunnel/scripts.pory"
	return
# 131 "data/maps/RusturfTunnel/scripts.pory"

# 132 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandaAndBoyfriendExit1::
# 133 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDA, RusturfTunnel_Movement_WandaExit1
# 134 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit1
# 135 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 136 "data/maps/RusturfTunnel/scripts.pory"
	return
# 137 "data/maps/RusturfTunnel/scripts.pory"

# 138 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandaAndBoyfriendExit::
# 139 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchWandaExit
# 140 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDA, RusturfTunnel_Movement_WandaExit
# 141 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit
# 142 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 143 "data/maps/RusturfTunnel/scripts.pory"
	return
# 144 "data/maps/RusturfTunnel/scripts.pory"

# 145 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandasBoyfriendNotice::
# 146 "data/maps/RusturfTunnel/scripts.pory"
	playse SE_PIN
# 147 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, Common_Movement_ExclamationMark
# 148 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 149 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, Common_Movement_Delay48
# 150 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 151 "data/maps/RusturfTunnel/scripts.pory"
	return
# 152 "data/maps/RusturfTunnel/scripts.pory"

# 153 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandaExit1:
# 154 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 155 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 156 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 157 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 158 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 159 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 160 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 161 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 162 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 163 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 164 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 165 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 166 "data/maps/RusturfTunnel/scripts.pory"

# 167 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandaExit:
# 168 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 169 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 170 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 171 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 172 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 173 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 174 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 175 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 176 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 177 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 178 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 179 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 180 "data/maps/RusturfTunnel/scripts.pory"

# 181 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchWandaExit:
# 182 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 183 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 184 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 185 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 186 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 187 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 188 "data/maps/RusturfTunnel/scripts.pory"

# 189 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_Unused1:
# 190 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 191 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 192 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 193 "data/maps/RusturfTunnel/scripts.pory"

# 194 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_Unused2:
# 195 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 196 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 197 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 198 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 199 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 200 "data/maps/RusturfTunnel/scripts.pory"

# 201 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_Unused3:
# 202 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 203 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_down
# 204 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 205 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 206 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 207 "data/maps/RusturfTunnel/scripts.pory"

# 208 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchBoyfriend1:
# 209 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 210 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 211 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 212 "data/maps/RusturfTunnel/scripts.pory"

# 213 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchBoyfriend:
# 214 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 215 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_left
# 216 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 217 "data/maps/RusturfTunnel/scripts.pory"

# 218 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BoyfriendFaceRight:
# 219 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 220 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 221 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 222 "data/maps/RusturfTunnel/scripts.pory"

# 223 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandasBoyfriendExit1:
# 224 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 225 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 226 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 227 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 228 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 229 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 230 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 231 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 232 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 233 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 234 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 235 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 236 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 237 "data/maps/RusturfTunnel/scripts.pory"

# 238 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandasBoyfriendExit:
# 239 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 240 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 241 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 242 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 243 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 244 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 245 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 246 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 247 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 248 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 249 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 250 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 251 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 252 "data/maps/RusturfTunnel/scripts.pory"

# 253 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandasBoyfriendApproachPlayer:
# 254 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 255 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 256 "data/maps/RusturfTunnel/scripts.pory"

# 257 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BoyfriendApproachWanda1:
# 258 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_up
# 259 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_up
# 260 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_up
# 261 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_right
# 262 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 263 "data/maps/RusturfTunnel/scripts.pory"

# 264 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BoyfriendApproachWanda:
# 265 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_right
# 266 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_right
# 267 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_right
# 268 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 269 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 270 "data/maps/RusturfTunnel/scripts.pory"

# 271 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_TunnelBlockagePos1::
# 272 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_TEMP_1, 1
# 273 "data/maps/RusturfTunnel/scripts.pory"
	end
# 274 "data/maps/RusturfTunnel/scripts.pory"

# 275 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_TunnelBlockagePos2::
# 276 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_TEMP_1, 2
# 277 "data/maps/RusturfTunnel/scripts.pory"
	end
# 278 "data/maps/RusturfTunnel/scripts.pory"

# 279 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_TunnelBlockagePos3::
# 280 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_TEMP_1, 3
# 281 "data/maps/RusturfTunnel/scripts.pory"
	end
# 282 "data/maps/RusturfTunnel/scripts.pory"

# 283 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_AquaGruntBackUp::
# 284 "data/maps/RusturfTunnel/scripts.pory"
	lockall
# 285 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ComeAndGetSome, MSGBOX_DEFAULT
# 286 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 287 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_GRUNT, RusturfTunnel_Movement_GruntAndPeekoBackUp
# 288 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PEEKO, RusturfTunnel_Movement_GruntAndPeekoBackUp
# 289 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 290 "data/maps/RusturfTunnel/scripts.pory"
	copyobjectxytoperm LOCALID_GRUNT
# 291 "data/maps/RusturfTunnel/scripts.pory"
	copyobjectxytoperm LOCALID_PEEKO
# 292 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 3
# 293 "data/maps/RusturfTunnel/scripts.pory"
	releaseall
# 294 "data/maps/RusturfTunnel/scripts.pory"
	end
# 295 "data/maps/RusturfTunnel/scripts.pory"

# 296 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_GruntAndPeekoBackUp:
# 297 "data/maps/RusturfTunnel/scripts.pory"
	lock_facing_direction
# 298 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 299 "data/maps/RusturfTunnel/scripts.pory"
	unlock_facing_direction
# 300 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 301 "data/maps/RusturfTunnel/scripts.pory"

# 302 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Peeko::
# 303 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 304 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 305 "data/maps/RusturfTunnel/scripts.pory"
	waitse
# 306 "data/maps/RusturfTunnel/scripts.pory"
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
# 307 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_Peeko, MSGBOX_DEFAULT
# 308 "data/maps/RusturfTunnel/scripts.pory"
	waitmoncry
# 309 "data/maps/RusturfTunnel/scripts.pory"
	release
# 310 "data/maps/RusturfTunnel/scripts.pory"
	end

RusturfTunnel_EventScript_Grunt::
# 314 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 315 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 316 "data/maps/RusturfTunnel/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 317 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_GruntIntro, MSGBOX_DEFAULT
# 318 "data/maps/RusturfTunnel/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_RUSTURF_TUNNEL, RusturfTunnel_Text_GruntDefeat
# 319 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_GruntTakePackage, MSGBOX_DEFAULT
# 320 "data/maps/RusturfTunnel/scripts.pory"
	giveitem ITEM_DEVON_PARTS
# 321 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 322 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PushPlayerAsideForGrunt
# 323 "data/maps/RusturfTunnel/scripts.pory"
	applymovement 6, RusturfTunnel_Movement_GruntEscape
# 324 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 325 "data/maps/RusturfTunnel/scripts.pory"
	removeobject 6
# 326 "data/maps/RusturfTunnel/scripts.pory"
	delay 50
# 327 "data/maps/RusturfTunnel/scripts.pory"
	addobject 5
# 328 "data/maps/RusturfTunnel/scripts.pory"
	addobject 11
# 329 "data/maps/RusturfTunnel/scripts.pory"
	applymovement 11, RusturfTunnel_Movement_RivalApproachPeeko1
# 330 "data/maps/RusturfTunnel/scripts.pory"
	applymovement 5, RusturfTunnel_Movement_BrineyApproachPeeko1
# 331 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 332 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerMoveAsideForBriney
# 333 "data/maps/RusturfTunnel/scripts.pory"
	applymovement 5, RusturfTunnel_Movement_BrineyApproachPeeko2
# 334 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 335 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_PeekoGladToSeeYouSafe, MSGBOX_DEFAULT
# 336 "data/maps/RusturfTunnel/scripts.pory"
	applymovement 5, Common_Movement_FacePlayer
# 337 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 338 "data/maps/RusturfTunnel/scripts.pory"
	message RusturfTunnel_Text_ThankYouLetsGoHomePeeko
# 339 "data/maps/RusturfTunnel/scripts.pory"
	waitmessage
# 340 "data/maps/RusturfTunnel/scripts.pory"
	waitse
# 341 "data/maps/RusturfTunnel/scripts.pory"
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
# 342 "data/maps/RusturfTunnel/scripts.pory"
	waitbuttonpress
# 343 "data/maps/RusturfTunnel/scripts.pory"
	waitmoncry
# 344 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 345 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBrineyExit
# 346 "data/maps/RusturfTunnel/scripts.pory"
	applymovement 11, RusturfTunnel_Movement_RivalWatchBrineyLeave
# 347 "data/maps/RusturfTunnel/scripts.pory"
	applymovement 5, RusturfTunnel_Movement_BrineyExit
# 348 "data/maps/RusturfTunnel/scripts.pory"
	applymovement 7, RusturfTunnel_Movement_PeekoExit
# 349 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 350 "data/maps/RusturfTunnel/scripts.pory"
	removeobject 5
# 351 "data/maps/RusturfTunnel/scripts.pory"
	removeobject 7
# 352 "data/maps/RusturfTunnel/scripts.pory"
	applymovement 11, RusturfTunnel_Movement_RivalApproachPlayer
# 353 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 354 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_LetMeHealYourTeam, MSGBOX_DEFAULT
# 355 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 356 "data/maps/RusturfTunnel/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 357 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_LetsGetOutOfTunnel, MSGBOX_DEFAULT
# 358 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 359 "data/maps/RusturfTunnel/scripts.pory"
	special SpawnCameraObject
# 360 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_LeaveTunnel
# 361 "data/maps/RusturfTunnel/scripts.pory"
	applymovement 11, RusturfTunnel_Movement_LeaveTunnel
# 362 "data/maps/RusturfTunnel/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 363 "data/maps/RusturfTunnel/scripts.pory"
	waitstate
# 364 "data/maps/RusturfTunnel/scripts.pory"
	clearflag FLAG_DEVON_GOODS_STOLEN
# 365 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_RECOVERED_DEVON_GOODS
# 366 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 4
# 367 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_BRINEY_HOUSE_STATE, 1
# 368 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 4
# 369 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 370 "data/maps/RusturfTunnel/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_RIVAL1
# 371 "data/maps/RusturfTunnel/scripts.pory"
	warp MAP_ROUTE116, 47, 9
# 372 "data/maps/RusturfTunnel/scripts.pory"
	waitstate
# 373 "data/maps/RusturfTunnel/scripts.pory"
	release
	end


# 377 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_RivalApproachPeeko1:
# 378 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 379 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 379 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 379 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 379 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
	step_end

# 382 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_RivalWatchBrineyLeave:
# 383 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 384 "data/maps/RusturfTunnel/scripts.pory"
	face_up
# 385 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 386 "data/maps/RusturfTunnel/scripts.pory"
	face_left
	step_end

# 389 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_RivalApproachPlayer:
# 390 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 391 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 391 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 391 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
	step_end

# 394 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_LeaveTunnel:
# 395 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 395 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 395 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 395 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 395 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 395 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 395 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
	step_end

# 409 "data/maps/RusturfTunnel/scripts.pory"

# 410 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PushPlayerAsideForGrunt:
# 411 "data/maps/RusturfTunnel/scripts.pory"
	face_down
# 412 "data/maps/RusturfTunnel/scripts.pory"
	lock_facing_direction
# 413 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 414 "data/maps/RusturfTunnel/scripts.pory"
	unlock_facing_direction
# 415 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_left
# 416 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 417 "data/maps/RusturfTunnel/scripts.pory"

# 418 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerMoveAsideForBriney:
# 419 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 420 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 421 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 422 "data/maps/RusturfTunnel/scripts.pory"

# 423 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_GruntEscape:
# 424 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 425 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 426 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 427 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 428 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 429 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 430 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 431 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 432 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 433 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 434 "data/maps/RusturfTunnel/scripts.pory"

# 435 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BrineyApproachPeeko1:
# 436 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 437 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 438 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 439 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 440 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 441 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 442 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 443 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 444 "data/maps/RusturfTunnel/scripts.pory"

# 445 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BrineyExit:
# 446 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 447 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 448 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 449 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 450 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 451 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 452 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 453 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 454 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 455 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 456 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 457 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 458 "data/maps/RusturfTunnel/scripts.pory"

# 459 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchBrineyExit:
# 460 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 461 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 462 "data/maps/RusturfTunnel/scripts.pory"
	delay_4
# 463 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_left
# 464 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 465 "data/maps/RusturfTunnel/scripts.pory"

# 466 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BrineyApproachPeeko2:
# 467 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 468 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 469 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 470 "data/maps/RusturfTunnel/scripts.pory"

# 471 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PeekoExit:
# 472 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 473 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 474 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 475 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 476 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 477 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 478 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 479 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 480 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 481 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 482 "data/maps/RusturfTunnel/scripts.pory"

# 483 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Mike::
# 484 "data/maps/RusturfTunnel/scripts.pory"
	trainerbattle_single TRAINER_MIKE_2, RusturfTunnel_Text_MikeIntro, RusturfTunnel_Text_MikeDefeat
# 485 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_MikePostBattle, MSGBOX_AUTOCLOSE
# 486 "data/maps/RusturfTunnel/scripts.pory"
	end
# 487 "data/maps/RusturfTunnel/scripts.pory"

# 488 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ComeAndGetSome:
# 489 "data/maps/RusturfTunnel/scripts.pory"
	.string "What, are you coming?\n"
# 490 "data/maps/RusturfTunnel/scripts.pory"
	.string "Come and get some, then!$"
# 491 "data/maps/RusturfTunnel/scripts.pory"

# 492 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_Peeko:
# 493 "data/maps/RusturfTunnel/scripts.pory"
	.string "PEEKO: Pii pihyoh!$"
# 494 "data/maps/RusturfTunnel/scripts.pory"

# 495 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_GruntIntro:
# 496 "data/maps/RusturfTunnel/scripts.pory"
	.string "Grah, keelhaul it all!\p"
# 497 "data/maps/RusturfTunnel/scripts.pory"
	.string "That hostage POKéMON turned out to\n"
# 498 "data/maps/RusturfTunnel/scripts.pory"
	.string "be worthless!\p"
# 499 "data/maps/RusturfTunnel/scripts.pory"
	.string "And to think I made a getaway…\n"
# 500 "data/maps/RusturfTunnel/scripts.pory"
	.string "In this tunnel to nowhere!\p"
# 501 "data/maps/RusturfTunnel/scripts.pory"
	.string "Hey! You!\n"
# 502 "data/maps/RusturfTunnel/scripts.pory"
	.string "So you want to battle me?$"
# 503 "data/maps/RusturfTunnel/scripts.pory"

# 504 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_GruntDefeat:
# 505 "data/maps/RusturfTunnel/scripts.pory"
	.string "Urrrggh! My career in crime comes to\n"
# 506 "data/maps/RusturfTunnel/scripts.pory"
	.string "a dead end!$"
# 507 "data/maps/RusturfTunnel/scripts.pory"

# 508 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_GruntTakePackage:
# 509 "data/maps/RusturfTunnel/scripts.pory"
	.string "This is plain not right…\p"
# 510 "data/maps/RusturfTunnel/scripts.pory"
	.string "The BOSS told me this would be a\n"
# 511 "data/maps/RusturfTunnel/scripts.pory"
	.string "slick-and-easy job to pull.\p"
# 512 "data/maps/RusturfTunnel/scripts.pory"
	.string "All I had to do was steal some package\n"
# 513 "data/maps/RusturfTunnel/scripts.pory"
	.string "from DEVON.\p"
# 514 "data/maps/RusturfTunnel/scripts.pory"
	.string "Tch!\n"
# 515 "data/maps/RusturfTunnel/scripts.pory"
	.string "You want it back that badly, take it!$"
# 516 "data/maps/RusturfTunnel/scripts.pory"

# 517 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_PeekoGladToSeeYouSafe:
# 518 "data/maps/RusturfTunnel/scripts.pory"
	.string "PEEKO!\n"
# 519 "data/maps/RusturfTunnel/scripts.pory"
	.string "Am I glad to see you're safe!$"
# 520 "data/maps/RusturfTunnel/scripts.pory"

# 521 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ThankYouLetsGoHomePeeko:
# 522 "data/maps/RusturfTunnel/scripts.pory"
	.string "PEEKO owes her life to you!\p"
# 523 "data/maps/RusturfTunnel/scripts.pory"
	.string "They call me MR. BRINEY.\n"
# 524 "data/maps/RusturfTunnel/scripts.pory"
	.string "And, you are?\p"
# 525 "data/maps/RusturfTunnel/scripts.pory"
	.string "… … … … … … … …\n"
# 526 "data/maps/RusturfTunnel/scripts.pory"
	.string "… … … … … … … …\p"
# 527 "data/maps/RusturfTunnel/scripts.pory"
	.string "Ah, so you are {PLAYER}{KUN}!\n"
# 528 "data/maps/RusturfTunnel/scripts.pory"
	.string "I sincerely thank you!\p"
# 529 "data/maps/RusturfTunnel/scripts.pory"
	.string "Now, if there's anything that troubles\n"
# 530 "data/maps/RusturfTunnel/scripts.pory"
	.string "you, don't hesitate to tell me!\p"
# 531 "data/maps/RusturfTunnel/scripts.pory"
	.string "You can usually find me in my cottage\n"
# 532 "data/maps/RusturfTunnel/scripts.pory"
	.string "by the sea near PETALBURG WOODS.\p"
# 533 "data/maps/RusturfTunnel/scripts.pory"
	.string "Come, PEEKO, we should make our way\n"
# 534 "data/maps/RusturfTunnel/scripts.pory"
	.string "home.\p"
# 535 "data/maps/RusturfTunnel/scripts.pory"
	.string "PEEKO: Pihyoh!$"
# 536 "data/maps/RusturfTunnel/scripts.pory"

# 537 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_WhyCantTheyKeepDigging:
# 538 "data/maps/RusturfTunnel/scripts.pory"
	.string "… …\p"
# 539 "data/maps/RusturfTunnel/scripts.pory"
	.string "Why can't they keep digging?\n"
# 540 "data/maps/RusturfTunnel/scripts.pory"
	.string "Is the bedrock too hard?\p"
# 541 "data/maps/RusturfTunnel/scripts.pory"
	.string "My beloved awaits me in VERDANTURF\n"
# 542 "data/maps/RusturfTunnel/scripts.pory"
	.string "TOWN just beyond here…\p"
# 543 "data/maps/RusturfTunnel/scripts.pory"
	.string "If RUSTBORO and VERDANTURF were\n"
# 544 "data/maps/RusturfTunnel/scripts.pory"
	.string "joined by this tunnel, I could visit\l"
# 545 "data/maps/RusturfTunnel/scripts.pory"
	.string "her every day…\p"
# 546 "data/maps/RusturfTunnel/scripts.pory"
	.string "But this…\n"
# 547 "data/maps/RusturfTunnel/scripts.pory"
	.string "What am I to do?$"
# 548 "data/maps/RusturfTunnel/scripts.pory"

# 549 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ToGetToVerdanturf:
# 550 "data/maps/RusturfTunnel/scripts.pory"
	.string "To get from RUSTBORO to VERDANTURF,\n"
# 551 "data/maps/RusturfTunnel/scripts.pory"
	.string "you need to go to DEWFORD, then pass\l"
# 552 "data/maps/RusturfTunnel/scripts.pory"
	.string "through SLATEPORT and MAUVILLE…$"
# 553 "data/maps/RusturfTunnel/scripts.pory"

# 554 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_YouShatteredBoulderTakeHM:
# 555 "data/maps/RusturfTunnel/scripts.pory"
	.string "Wow! You shattered that boulder\n"
# 556 "data/maps/RusturfTunnel/scripts.pory"
	.string "blocking the way.\p"
# 557 "data/maps/RusturfTunnel/scripts.pory"
	.string "To show you how much I appreciate it,\n"
# 558 "data/maps/RusturfTunnel/scripts.pory"
	.string "I'd like you to have this HM.$"
# 559 "data/maps/RusturfTunnel/scripts.pory"

# 560 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ExplainStrength:
# 561 "data/maps/RusturfTunnel/scripts.pory"
	.string "That HM contains STRENGTH.\p"
# 562 "data/maps/RusturfTunnel/scripts.pory"
	.string "If a muscular POKéMON were to learn\n"
# 563 "data/maps/RusturfTunnel/scripts.pory"
	.string "that, it would be able to move even\l"
# 564 "data/maps/RusturfTunnel/scripts.pory"
	.string "large boulders.$"
# 565 "data/maps/RusturfTunnel/scripts.pory"

# 566 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_WandaReunion:
# 567 "data/maps/RusturfTunnel/scripts.pory"
	.string "WANDA!\n"
# 568 "data/maps/RusturfTunnel/scripts.pory"
	.string "Now I can see you anytime!\p"
# 569 "data/maps/RusturfTunnel/scripts.pory"
	.string "WANDA: That's…wonderful.\p"
# 570 "data/maps/RusturfTunnel/scripts.pory"
	.string "Please, take some rest at my home.$"
# 571 "data/maps/RusturfTunnel/scripts.pory"

# 572 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_BoyfriendOnOtherSideOfRock:
# 573 "data/maps/RusturfTunnel/scripts.pory"
	.string "On the other side of this rock…\n"
# 574 "data/maps/RusturfTunnel/scripts.pory"
	.string "My boyfriend is there.\p"
# 575 "data/maps/RusturfTunnel/scripts.pory"
	.string "He… He's not just digging the tunnel\n"
# 576 "data/maps/RusturfTunnel/scripts.pory"
	.string "to come see me.\p"
# 577 "data/maps/RusturfTunnel/scripts.pory"
	.string "He works his hands raw and rough\n"
# 578 "data/maps/RusturfTunnel/scripts.pory"
	.string "for the benefit of everyone.$"
# 579 "data/maps/RusturfTunnel/scripts.pory"

# 580 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_MikeIntro:
# 581 "data/maps/RusturfTunnel/scripts.pory"
	.string "What do you call a wild man up in the\n"
# 582 "data/maps/RusturfTunnel/scripts.pory"
	.string "mountains? A mountain man, right?\p"
# 583 "data/maps/RusturfTunnel/scripts.pory"
	.string "So why don't they call a POKéMON in\n"
# 584 "data/maps/RusturfTunnel/scripts.pory"
	.string "the mountains a mountain POKéMON?$"
# 585 "data/maps/RusturfTunnel/scripts.pory"

# 586 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_MikeDefeat:
# 587 "data/maps/RusturfTunnel/scripts.pory"
	.string "My POKéMON…\n"
# 588 "data/maps/RusturfTunnel/scripts.pory"
	.string "Ran out of power…$"
# 589 "data/maps/RusturfTunnel/scripts.pory"

# 590 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_MikePostBattle:
# 591 "data/maps/RusturfTunnel/scripts.pory"
	.string "They halted development here to\n"
# 592 "data/maps/RusturfTunnel/scripts.pory"
	.string "protect POKéMON, right?\l"
# 593 "data/maps/RusturfTunnel/scripts.pory"
	.string "There's a feel-good story!$"

RusturfTunnel_Text_LetMeHealYourTeam::
# 398 "data/maps/RusturfTunnel/scripts.pory"
	.string "Man, you sent that grunt packing! I'll\n"
	.string "bet your POKéMON are tired after that\l"
	.string "battle, though.\l"
	.string "Here. Let me heal your team.$"

RusturfTunnel_Text_LetsGetOutOfTunnel::
# 404 "data/maps/RusturfTunnel/scripts.pory"
	.string "Let's get out of this dark tunnel. It\n"
	.string "echoes so much in here!$"
