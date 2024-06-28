# 18 "data/maps/RusturfTunnel/scripts.pory"

# 19 "data/maps/RusturfTunnel/scripts.pory"
.equ LOCALID_WANDAS_BF, 1
# 20 "data/maps/RusturfTunnel/scripts.pory"
.set LOCALID_BRINEY, 5
# 21 "data/maps/RusturfTunnel/scripts.pory"
.set LOCALID_GRUNT, 6
# 22 "data/maps/RusturfTunnel/scripts.pory"
.set LOCALID_PEEKO, 7
# 23 "data/maps/RusturfTunnel/scripts.pory"
.equ LOCALID_WANDA, 10
# 24 "data/maps/RusturfTunnel/scripts.pory"
.set LOCALID_RIVAL1, 11
# 25 "data/maps/RusturfTunnel/scripts.pory"

# 26 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_MapScripts::
# 27 "data/maps/RusturfTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RusturfTunnel_OnTransition
# 28 "data/maps/RusturfTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RusturfTunnel_OnFrame
# 29 "data/maps/RusturfTunnel/scripts.pory"
	.byte 0
# 30 "data/maps/RusturfTunnel/scripts.pory"

# 31 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_OnFrame:
# 32 "data/maps/RusturfTunnel/scripts.pory"
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 8, RusturfTunnel_EventScript_ClearTunnelScene
# 33 "data/maps/RusturfTunnel/scripts.pory"
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 9, RusturfTunnel_EventScript_ClearTunnelScene
# 34 "data/maps/RusturfTunnel/scripts.pory"
	.2byte 0
# 35 "data/maps/RusturfTunnel/scripts.pory"

# 36 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_OnTransition:
# 37 "data/maps/RusturfTunnel/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 38 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_RUSTURF_TUNNEL_STATE, 2, RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos
# 39 "data/maps/RusturfTunnel/scripts.pory"
	end
# 40 "data/maps/RusturfTunnel/scripts.pory"

# 41 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos::
# 42 "data/maps/RusturfTunnel/scripts.pory"
	setobjectxyperm LOCALID_PEEKO, 13, 4
# 43 "data/maps/RusturfTunnel/scripts.pory"
	setobjectxyperm LOCALID_GRUNT, 13, 5
# 44 "data/maps/RusturfTunnel/scripts.pory"
	return
# 45 "data/maps/RusturfTunnel/scripts.pory"

# 46 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Wanda::
# 47 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 48 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 49 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_BoyfriendOnOtherSideOfRock, MSGBOX_DEFAULT
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
RusturfTunnel_EventScript_WandasBoyfriend::
# 57 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 58 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 59 "data/maps/RusturfTunnel/scripts.pory"
	goto_if_set FLAG_TEMP_1, RusturfTunnel_EventScript_AlreadySpokenTo
# 60 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_TEMP_1
# 61 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_WhyCantTheyKeepDigging, MSGBOX_DEFAULT
# 62 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 63 "data/maps/RusturfTunnel/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 64 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 65 "data/maps/RusturfTunnel/scripts.pory"
	release
# 66 "data/maps/RusturfTunnel/scripts.pory"
	end
# 67 "data/maps/RusturfTunnel/scripts.pory"

# 68 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_AlreadySpokenTo::
# 69 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ToGetToVerdanturf, MSGBOX_DEFAULT
# 70 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 71 "data/maps/RusturfTunnel/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 72 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 73 "data/maps/RusturfTunnel/scripts.pory"
	release
# 74 "data/maps/RusturfTunnel/scripts.pory"
	end
# 75 "data/maps/RusturfTunnel/scripts.pory"

# 76 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_ClearTunnelScene::
# 77 "data/maps/RusturfTunnel/scripts.pory"
	lockall
# 78 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_FaceWandasBoyfriend1
# 79 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_FaceWandasBoyfriend2
# 80 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_FaceWandasBoyfriend3
# 81 "data/maps/RusturfTunnel/scripts.pory"
	call RusturfTunnel_EventScript_WandasBoyfriendNotice
# 82 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_YouShatteredBoulderTakeHM, MSGBOX_DEFAULT
# 83 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
# 84 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
# 85 "data/maps/RusturfTunnel/scripts.pory"
	giveitem ITEM_HM_STRENGTH
# 86 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_RECEIVED_HM_STRENGTH
# 87 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ExplainStrength, MSGBOX_DEFAULT
# 88 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 89 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_BoyfriendApproachWanda1
# 90 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_BoyfriendApproachWanda2
# 91 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_BoyfriendApproachWanda3
# 92 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_WandaReunion, MSGBOX_DEFAULT
# 93 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 94 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_WandaAndBoyfriendExit1
# 95 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_WandaAndBoyfriendExit
# 96 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_WandaAndBoyfriendExit
# 97 "data/maps/RusturfTunnel/scripts.pory"
	call RusturfTunnel_EventScript_SetRusturfTunnelOpen
# 98 "data/maps/RusturfTunnel/scripts.pory"
	releaseall
# 99 "data/maps/RusturfTunnel/scripts.pory"
	end
# 100 "data/maps/RusturfTunnel/scripts.pory"

# 101 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_BoyfriendApproachWanda1::
# 102 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend1
# 103 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda1
# 104 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 105 "data/maps/RusturfTunnel/scripts.pory"
	return
# 106 "data/maps/RusturfTunnel/scripts.pory"

# 107 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_BoyfriendApproachWanda2::
# 108 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
# 109 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
# 110 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 111 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDA, Common_Movement_WalkInPlaceFasterDown
# 112 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 113 "data/maps/RusturfTunnel/scripts.pory"
	return
# 114 "data/maps/RusturfTunnel/scripts.pory"

# 115 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_BoyfriendApproachWanda3::
# 116 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
# 117 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
# 118 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 119 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDA, Common_Movement_WalkInPlaceFasterDown
# 120 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 121 "data/maps/RusturfTunnel/scripts.pory"
	return
# 122 "data/maps/RusturfTunnel/scripts.pory"

# 123 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_FaceWandasBoyfriend1::
# 124 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, Common_Movement_WalkInPlaceFasterUp
# 125 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 126 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 127 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 128 "data/maps/RusturfTunnel/scripts.pory"
	return
# 129 "data/maps/RusturfTunnel/scripts.pory"

# 130 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_FaceWandasBoyfriend2::
# 131 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendFaceRight
# 132 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 133 "data/maps/RusturfTunnel/scripts.pory"
	return
# 134 "data/maps/RusturfTunnel/scripts.pory"

# 135 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_FaceWandasBoyfriend3::
# 136 "data/maps/RusturfTunnel/scripts.pory"
	return
# 137 "data/maps/RusturfTunnel/scripts.pory"

# 138 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer::
# 139 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 140 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendApproachPlayer
# 141 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 142 "data/maps/RusturfTunnel/scripts.pory"
	return
# 143 "data/maps/RusturfTunnel/scripts.pory"

# 144 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandaAndBoyfriendExit1::
# 145 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDA, RusturfTunnel_Movement_WandaExit1
# 146 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit1
# 147 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 148 "data/maps/RusturfTunnel/scripts.pory"
	return
# 149 "data/maps/RusturfTunnel/scripts.pory"

# 150 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandaAndBoyfriendExit::
# 151 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchWandaExit
# 152 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDA, RusturfTunnel_Movement_WandaExit
# 153 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit
# 154 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 155 "data/maps/RusturfTunnel/scripts.pory"
	return
# 156 "data/maps/RusturfTunnel/scripts.pory"

# 157 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandasBoyfriendNotice::
# 158 "data/maps/RusturfTunnel/scripts.pory"
	playse SE_PIN
# 159 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, Common_Movement_ExclamationMark
# 160 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 161 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, Common_Movement_Delay48
# 162 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 163 "data/maps/RusturfTunnel/scripts.pory"
	return
# 164 "data/maps/RusturfTunnel/scripts.pory"

# 165 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandaExit1:
# 166 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 167 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 168 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 169 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 170 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 171 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
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
	step_end
# 178 "data/maps/RusturfTunnel/scripts.pory"

# 179 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandaExit:
# 180 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 181 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 182 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 183 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 184 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 185 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 186 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 187 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 188 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 189 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 190 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 191 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 192 "data/maps/RusturfTunnel/scripts.pory"

# 193 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchWandaExit:
# 194 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 195 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 196 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 197 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 198 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 199 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 200 "data/maps/RusturfTunnel/scripts.pory"

# 201 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_Unused1:
# 202 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 203 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 204 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 205 "data/maps/RusturfTunnel/scripts.pory"

# 206 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_Unused2:
# 207 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 208 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 209 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 210 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 211 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 212 "data/maps/RusturfTunnel/scripts.pory"

# 213 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_Unused3:
# 214 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 215 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_down
# 216 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 217 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 218 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 219 "data/maps/RusturfTunnel/scripts.pory"

# 220 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchBoyfriend1:
# 221 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 222 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 223 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 224 "data/maps/RusturfTunnel/scripts.pory"

# 225 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchBoyfriend:
# 226 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 227 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_left
# 228 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 229 "data/maps/RusturfTunnel/scripts.pory"

# 230 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BoyfriendFaceRight:
# 231 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 232 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 233 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 234 "data/maps/RusturfTunnel/scripts.pory"

# 235 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandasBoyfriendExit1:
# 236 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 237 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 238 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 239 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 240 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 241 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 242 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 243 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 244 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 245 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 246 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 247 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 248 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 249 "data/maps/RusturfTunnel/scripts.pory"

# 250 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandasBoyfriendExit:
# 251 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 252 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 253 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 254 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 255 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 256 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 257 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 258 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 259 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 260 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 261 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 262 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 263 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 264 "data/maps/RusturfTunnel/scripts.pory"

# 265 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandasBoyfriendApproachPlayer:
# 266 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 267 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 268 "data/maps/RusturfTunnel/scripts.pory"

# 269 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BoyfriendApproachWanda1:
# 270 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_up
# 271 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_up
# 272 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_up
# 273 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_right
# 274 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 275 "data/maps/RusturfTunnel/scripts.pory"

# 276 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BoyfriendApproachWanda:
# 277 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_right
# 278 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_right
# 279 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_right
# 280 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 281 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 282 "data/maps/RusturfTunnel/scripts.pory"

# 283 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_TunnelBlockagePos1::
# 284 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_TEMP_1, 1
# 285 "data/maps/RusturfTunnel/scripts.pory"
	end
# 286 "data/maps/RusturfTunnel/scripts.pory"

# 287 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_TunnelBlockagePos2::
# 288 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_TEMP_1, 2
# 289 "data/maps/RusturfTunnel/scripts.pory"
	end
# 290 "data/maps/RusturfTunnel/scripts.pory"

# 291 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_TunnelBlockagePos3::
# 292 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_TEMP_1, 3
# 293 "data/maps/RusturfTunnel/scripts.pory"
	end
# 294 "data/maps/RusturfTunnel/scripts.pory"

# 295 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_AquaGruntBackUp::
# 296 "data/maps/RusturfTunnel/scripts.pory"
	lockall
# 297 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ComeAndGetSome, MSGBOX_DEFAULT
# 298 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 299 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_GRUNT, RusturfTunnel_Movement_GruntAndPeekoBackUp
# 300 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PEEKO, RusturfTunnel_Movement_GruntAndPeekoBackUp
# 301 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 302 "data/maps/RusturfTunnel/scripts.pory"
	copyobjectxytoperm LOCALID_GRUNT
# 303 "data/maps/RusturfTunnel/scripts.pory"
	copyobjectxytoperm LOCALID_PEEKO
# 304 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 3
# 305 "data/maps/RusturfTunnel/scripts.pory"
	releaseall
# 306 "data/maps/RusturfTunnel/scripts.pory"
	end
# 307 "data/maps/RusturfTunnel/scripts.pory"

# 308 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_GruntAndPeekoBackUp:
# 309 "data/maps/RusturfTunnel/scripts.pory"
	lock_facing_direction
# 310 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 311 "data/maps/RusturfTunnel/scripts.pory"
	unlock_facing_direction
# 312 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 313 "data/maps/RusturfTunnel/scripts.pory"

# 314 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Peeko::
# 315 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 316 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 317 "data/maps/RusturfTunnel/scripts.pory"
	waitse
# 318 "data/maps/RusturfTunnel/scripts.pory"
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
# 319 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_Peeko, MSGBOX_DEFAULT
# 320 "data/maps/RusturfTunnel/scripts.pory"
	waitmoncry
# 321 "data/maps/RusturfTunnel/scripts.pory"
	release
# 322 "data/maps/RusturfTunnel/scripts.pory"
	end

RusturfTunnel_EventScript_Grunt::
# 326 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 327 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 328 "data/maps/RusturfTunnel/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 329 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_GruntIntro, MSGBOX_DEFAULT
# 330 "data/maps/RusturfTunnel/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_RUSTURF_TUNNEL, RusturfTunnel_Text_GruntDefeat
# 331 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_GruntTakePackage, MSGBOX_DEFAULT
# 332 "data/maps/RusturfTunnel/scripts.pory"
	giveitem ITEM_DEVON_PARTS
# 333 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 334 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PushPlayerAsideForGrunt
# 335 "data/maps/RusturfTunnel/scripts.pory"
	applymovement 6, RusturfTunnel_Movement_GruntEscape
# 336 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 337 "data/maps/RusturfTunnel/scripts.pory"
	removeobject 6
# 338 "data/maps/RusturfTunnel/scripts.pory"
	delay 50
# 339 "data/maps/RusturfTunnel/scripts.pory"
	addobject 5
# 340 "data/maps/RusturfTunnel/scripts.pory"
	addobject 11
# 341 "data/maps/RusturfTunnel/scripts.pory"
	applymovement 11, RusturfTunnel_Movement_RivalApproachPeeko1
# 342 "data/maps/RusturfTunnel/scripts.pory"
	applymovement 5, RusturfTunnel_Movement_BrineyApproachPeeko1
# 343 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 344 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerMoveAsideForBriney
# 345 "data/maps/RusturfTunnel/scripts.pory"
	applymovement 5, RusturfTunnel_Movement_BrineyApproachPeeko2
# 346 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 347 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_PeekoGladToSeeYouSafe, MSGBOX_DEFAULT
# 348 "data/maps/RusturfTunnel/scripts.pory"
	applymovement 5, Common_Movement_FacePlayer
# 349 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 350 "data/maps/RusturfTunnel/scripts.pory"
	message RusturfTunnel_Text_ThankYouLetsGoHomePeeko
# 351 "data/maps/RusturfTunnel/scripts.pory"
	waitmessage
# 352 "data/maps/RusturfTunnel/scripts.pory"
	waitse
# 353 "data/maps/RusturfTunnel/scripts.pory"
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
# 354 "data/maps/RusturfTunnel/scripts.pory"
	waitbuttonpress
# 355 "data/maps/RusturfTunnel/scripts.pory"
	waitmoncry
# 356 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 357 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBrineyExit
# 358 "data/maps/RusturfTunnel/scripts.pory"
	applymovement 11, RusturfTunnel_Movement_RivalWatchBrineyLeave
# 359 "data/maps/RusturfTunnel/scripts.pory"
	applymovement 5, RusturfTunnel_Movement_BrineyExit
# 360 "data/maps/RusturfTunnel/scripts.pory"
	applymovement 7, RusturfTunnel_Movement_PeekoExit
# 361 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 362 "data/maps/RusturfTunnel/scripts.pory"
	removeobject 5
# 363 "data/maps/RusturfTunnel/scripts.pory"
	removeobject 7
# 364 "data/maps/RusturfTunnel/scripts.pory"
	applymovement 11, RusturfTunnel_Movement_RivalApproachPlayer
# 365 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 366 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_LetMeHealYourTeam, MSGBOX_DEFAULT
# 367 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 368 "data/maps/RusturfTunnel/scripts.pory"
	call Common_EventScript_FieldPartyHeal
# 369 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_LetsGetOutOfTunnel, MSGBOX_DEFAULT
# 370 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 371 "data/maps/RusturfTunnel/scripts.pory"
	special SpawnCameraObject
# 372 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_LeaveTunnel
# 373 "data/maps/RusturfTunnel/scripts.pory"
	applymovement 11, RusturfTunnel_Movement_LeaveTunnel
# 374 "data/maps/RusturfTunnel/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 375 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 376 "data/maps/RusturfTunnel/scripts.pory"
	special RemoveCameraObject
# 377 "data/maps/RusturfTunnel/scripts.pory"
	clearflag FLAG_DEVON_GOODS_STOLEN
# 378 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_RECOVERED_DEVON_GOODS
# 379 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 4
# 380 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_BRINEY_HOUSE_STATE, 1
# 381 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 4
# 382 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 383 "data/maps/RusturfTunnel/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_RIVAL1
# 384 "data/maps/RusturfTunnel/scripts.pory"
	warp MAP_ROUTE116, 47, 9
# 385 "data/maps/RusturfTunnel/scripts.pory"
	waitstate
# 386 "data/maps/RusturfTunnel/scripts.pory"
	release
	end


# 390 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_RivalApproachPeeko1:
# 391 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 391 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 391 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 392 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 393 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 393 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 393 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 393 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
	step_end

# 396 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_RivalWatchBrineyLeave:
# 397 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 398 "data/maps/RusturfTunnel/scripts.pory"
	face_up
# 399 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 399 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 399 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 400 "data/maps/RusturfTunnel/scripts.pory"
	face_left
	step_end

# 403 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_RivalApproachPlayer:
# 404 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 405 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 405 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 405 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
	step_end

# 408 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_LeaveTunnel:
# 409 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 409 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 409 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 409 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 409 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 409 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 409 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
	step_end

# 423 "data/maps/RusturfTunnel/scripts.pory"

# 424 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PushPlayerAsideForGrunt:
# 425 "data/maps/RusturfTunnel/scripts.pory"
	face_down
# 426 "data/maps/RusturfTunnel/scripts.pory"
	lock_facing_direction
# 427 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 428 "data/maps/RusturfTunnel/scripts.pory"
	unlock_facing_direction
# 429 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_left
# 430 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 431 "data/maps/RusturfTunnel/scripts.pory"

# 432 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerMoveAsideForBriney:
# 433 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 434 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 435 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 436 "data/maps/RusturfTunnel/scripts.pory"

# 437 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_GruntEscape:
# 438 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 439 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 440 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 441 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 442 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 443 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 444 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 445 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 446 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 447 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 448 "data/maps/RusturfTunnel/scripts.pory"

# 449 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BrineyApproachPeeko1:
# 450 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 451 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 452 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 453 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 454 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 455 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 456 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 457 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 458 "data/maps/RusturfTunnel/scripts.pory"

# 459 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BrineyExit:
# 460 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 461 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 462 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 463 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 464 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 465 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 466 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 467 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 468 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 469 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 470 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 471 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 472 "data/maps/RusturfTunnel/scripts.pory"

# 473 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchBrineyExit:
# 474 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 475 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 476 "data/maps/RusturfTunnel/scripts.pory"
	delay_4
# 477 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_left
# 478 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 479 "data/maps/RusturfTunnel/scripts.pory"

# 480 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BrineyApproachPeeko2:
# 481 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 482 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 483 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 484 "data/maps/RusturfTunnel/scripts.pory"

# 485 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PeekoExit:
# 486 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 487 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 488 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 489 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 490 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 491 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 492 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 493 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 494 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 495 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 496 "data/maps/RusturfTunnel/scripts.pory"

# 497 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Mike::
# 498 "data/maps/RusturfTunnel/scripts.pory"
	trainerbattle_single TRAINER_MIKE_2, RusturfTunnel_Text_MikeIntro, RusturfTunnel_Text_MikeDefeat
# 499 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_MikePostBattle, MSGBOX_AUTOCLOSE
# 500 "data/maps/RusturfTunnel/scripts.pory"
	end
# 501 "data/maps/RusturfTunnel/scripts.pory"

# 502 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ComeAndGetSome:
# 503 "data/maps/RusturfTunnel/scripts.pory"
	.string "What, are you coming?\n"
# 504 "data/maps/RusturfTunnel/scripts.pory"
	.string "Come and get some, then!$"
# 505 "data/maps/RusturfTunnel/scripts.pory"

# 506 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_Peeko:
# 507 "data/maps/RusturfTunnel/scripts.pory"
	.string "PEEKO: Pii pihyoh!$"
# 508 "data/maps/RusturfTunnel/scripts.pory"

# 509 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_GruntIntro:
# 510 "data/maps/RusturfTunnel/scripts.pory"
	.string "Grah, keelhaul it all!\p"
# 511 "data/maps/RusturfTunnel/scripts.pory"
	.string "That hostage POKéMON turned out to\n"
# 512 "data/maps/RusturfTunnel/scripts.pory"
	.string "be worthless!\p"
# 513 "data/maps/RusturfTunnel/scripts.pory"
	.string "And to think I made a getaway…\n"
# 514 "data/maps/RusturfTunnel/scripts.pory"
	.string "In this tunnel to nowhere!\p"
# 515 "data/maps/RusturfTunnel/scripts.pory"
	.string "Hey! You!\n"
# 516 "data/maps/RusturfTunnel/scripts.pory"
	.string "So you want to battle me?$"
# 517 "data/maps/RusturfTunnel/scripts.pory"

# 518 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_GruntDefeat:
# 519 "data/maps/RusturfTunnel/scripts.pory"
	.string "Urrrggh! My career in crime comes to\n"
# 520 "data/maps/RusturfTunnel/scripts.pory"
	.string "a dead end!$"
# 521 "data/maps/RusturfTunnel/scripts.pory"

# 522 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_GruntTakePackage:
# 523 "data/maps/RusturfTunnel/scripts.pory"
	.string "This is plain not right…\p"
# 524 "data/maps/RusturfTunnel/scripts.pory"
	.string "The BOSS told me this would be a\n"
# 525 "data/maps/RusturfTunnel/scripts.pory"
	.string "slick-and-easy job to pull.\p"
# 526 "data/maps/RusturfTunnel/scripts.pory"
	.string "All I had to do was steal some package\n"
# 527 "data/maps/RusturfTunnel/scripts.pory"
	.string "from DEVON.\p"
# 528 "data/maps/RusturfTunnel/scripts.pory"
	.string "Tch!\n"
# 529 "data/maps/RusturfTunnel/scripts.pory"
	.string "You want it back that badly, take it!$"
# 530 "data/maps/RusturfTunnel/scripts.pory"

# 531 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_PeekoGladToSeeYouSafe:
# 532 "data/maps/RusturfTunnel/scripts.pory"
	.string "PEEKO!\n"
# 533 "data/maps/RusturfTunnel/scripts.pory"
	.string "Am I glad to see you're safe!$"
# 534 "data/maps/RusturfTunnel/scripts.pory"

# 535 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ThankYouLetsGoHomePeeko:
# 536 "data/maps/RusturfTunnel/scripts.pory"
	.string "PEEKO owes her life to you!\p"
# 537 "data/maps/RusturfTunnel/scripts.pory"
	.string "They call me MR. BRINEY.\n"
# 538 "data/maps/RusturfTunnel/scripts.pory"
	.string "And, you are?\p"
# 539 "data/maps/RusturfTunnel/scripts.pory"
	.string "… … … … … … … …\n"
# 540 "data/maps/RusturfTunnel/scripts.pory"
	.string "… … … … … … … …\p"
# 541 "data/maps/RusturfTunnel/scripts.pory"
	.string "Ah, so you are {PLAYER}{KUN}!\n"
# 542 "data/maps/RusturfTunnel/scripts.pory"
	.string "I sincerely thank you!\p"
# 543 "data/maps/RusturfTunnel/scripts.pory"
	.string "Now, if there's anything that troubles\n"
# 544 "data/maps/RusturfTunnel/scripts.pory"
	.string "you, don't hesitate to tell me!\p"
# 545 "data/maps/RusturfTunnel/scripts.pory"
	.string "You can usually find me in my cottage\n"
# 546 "data/maps/RusturfTunnel/scripts.pory"
	.string "by the sea near PETALBURG WOODS.\p"
# 547 "data/maps/RusturfTunnel/scripts.pory"
	.string "Come, PEEKO, we should make our way\n"
# 548 "data/maps/RusturfTunnel/scripts.pory"
	.string "home.\p"
# 549 "data/maps/RusturfTunnel/scripts.pory"
	.string "PEEKO: Pihyoh!$"
# 550 "data/maps/RusturfTunnel/scripts.pory"

# 551 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_WhyCantTheyKeepDigging:
# 552 "data/maps/RusturfTunnel/scripts.pory"
	.string "… …\p"
# 553 "data/maps/RusturfTunnel/scripts.pory"
	.string "Why can't they keep digging?\n"
# 554 "data/maps/RusturfTunnel/scripts.pory"
	.string "Is the bedrock too hard?\p"
# 555 "data/maps/RusturfTunnel/scripts.pory"
	.string "My beloved awaits me in VERDANTURF\n"
# 556 "data/maps/RusturfTunnel/scripts.pory"
	.string "TOWN just beyond here…\p"
# 557 "data/maps/RusturfTunnel/scripts.pory"
	.string "If RUSTBORO and VERDANTURF were\n"
# 558 "data/maps/RusturfTunnel/scripts.pory"
	.string "joined by this tunnel, I could visit\l"
# 559 "data/maps/RusturfTunnel/scripts.pory"
	.string "her every day…\p"
# 560 "data/maps/RusturfTunnel/scripts.pory"
	.string "But this…\n"
# 561 "data/maps/RusturfTunnel/scripts.pory"
	.string "What am I to do?$"
# 562 "data/maps/RusturfTunnel/scripts.pory"

# 563 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ToGetToVerdanturf:
# 564 "data/maps/RusturfTunnel/scripts.pory"
	.string "To get from RUSTBORO to VERDANTURF,\n"
# 565 "data/maps/RusturfTunnel/scripts.pory"
	.string "you need to go to DEWFORD, then pass\l"
# 566 "data/maps/RusturfTunnel/scripts.pory"
	.string "through SLATEPORT and MAUVILLE…$"
# 567 "data/maps/RusturfTunnel/scripts.pory"

# 568 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_YouShatteredBoulderTakeHM:
# 569 "data/maps/RusturfTunnel/scripts.pory"
	.string "Wow! You shattered that boulder\n"
# 570 "data/maps/RusturfTunnel/scripts.pory"
	.string "blocking the way.\p"
# 571 "data/maps/RusturfTunnel/scripts.pory"
	.string "To show you how much I appreciate it,\n"
# 572 "data/maps/RusturfTunnel/scripts.pory"
	.string "I'd like you to have this HM.$"
# 573 "data/maps/RusturfTunnel/scripts.pory"

# 574 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ExplainStrength:
# 575 "data/maps/RusturfTunnel/scripts.pory"
	.string "That HM contains STRENGTH.\p"
# 576 "data/maps/RusturfTunnel/scripts.pory"
	.string "If a muscular POKéMON were to learn\n"
# 577 "data/maps/RusturfTunnel/scripts.pory"
	.string "that, it would be able to move even\l"
# 578 "data/maps/RusturfTunnel/scripts.pory"
	.string "large boulders.$"
# 579 "data/maps/RusturfTunnel/scripts.pory"

# 580 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_WandaReunion:
# 581 "data/maps/RusturfTunnel/scripts.pory"
	.string "WANDA!\n"
# 582 "data/maps/RusturfTunnel/scripts.pory"
	.string "Now I can see you anytime!\p"
# 583 "data/maps/RusturfTunnel/scripts.pory"
	.string "WANDA: That's…wonderful.\p"
# 584 "data/maps/RusturfTunnel/scripts.pory"
	.string "Please, take some rest at my home.$"
# 585 "data/maps/RusturfTunnel/scripts.pory"

# 586 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_BoyfriendOnOtherSideOfRock:
# 587 "data/maps/RusturfTunnel/scripts.pory"
	.string "On the other side of this rock…\n"
# 588 "data/maps/RusturfTunnel/scripts.pory"
	.string "My boyfriend is there.\p"
# 589 "data/maps/RusturfTunnel/scripts.pory"
	.string "He… He's not just digging the tunnel\n"
# 590 "data/maps/RusturfTunnel/scripts.pory"
	.string "to come see me.\p"
# 591 "data/maps/RusturfTunnel/scripts.pory"
	.string "He works his hands raw and rough\n"
# 592 "data/maps/RusturfTunnel/scripts.pory"
	.string "for the benefit of everyone.$"
# 593 "data/maps/RusturfTunnel/scripts.pory"

# 594 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_MikeIntro:
# 595 "data/maps/RusturfTunnel/scripts.pory"
	.string "What do you call a wild man up in the\n"
# 596 "data/maps/RusturfTunnel/scripts.pory"
	.string "mountains? A mountain man, right?\p"
# 597 "data/maps/RusturfTunnel/scripts.pory"
	.string "So why don't they call a POKéMON in\n"
# 598 "data/maps/RusturfTunnel/scripts.pory"
	.string "the mountains a mountain POKéMON?$"
# 599 "data/maps/RusturfTunnel/scripts.pory"

# 600 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_MikeDefeat:
# 601 "data/maps/RusturfTunnel/scripts.pory"
	.string "My POKéMON…\n"
# 602 "data/maps/RusturfTunnel/scripts.pory"
	.string "Ran out of power…$"
# 603 "data/maps/RusturfTunnel/scripts.pory"

# 604 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_MikePostBattle:
# 605 "data/maps/RusturfTunnel/scripts.pory"
	.string "They halted development here to\n"
# 606 "data/maps/RusturfTunnel/scripts.pory"
	.string "protect POKéMON, right?\l"
# 607 "data/maps/RusturfTunnel/scripts.pory"
	.string "There's a feel-good story!$"

RusturfTunnel_Text_LetMeHealYourTeam::
# 412 "data/maps/RusturfTunnel/scripts.pory"
	.string "Man, you sent that grunt packing! I'll\n"
	.string "bet your POKéMON are tired after that\l"
	.string "battle, though.\l"
	.string "Here. Let me heal your team.$"

RusturfTunnel_Text_LetsGetOutOfTunnel::
# 418 "data/maps/RusturfTunnel/scripts.pory"
	.string "Let's get out of this dark tunnel.\n"
	.string "It echoes so much in here!$"
