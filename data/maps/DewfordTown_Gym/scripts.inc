# 3 "data/maps/DewfordTown_Gym/scripts.pory"

# 4 "data/maps/DewfordTown_Gym/scripts.pory"
.set LOCALID_RIVAL1, 9
# 5 "data/maps/DewfordTown_Gym/scripts.pory"

# 6 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_MapScripts::
# 7 "data/maps/DewfordTown_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
# 8 "data/maps/DewfordTown_Gym/scripts.pory"
	.byte 0
# 9 "data/maps/DewfordTown_Gym/scripts.pory"

# 10 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_OnTransition:
# 11 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 12 "data/maps/DewfordTown_Gym/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 13 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 14 "data/maps/DewfordTown_Gym/scripts.pory"

# 15 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel::
# 16 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
# 17 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
# 18 "data/maps/DewfordTown_Gym/scripts.pory"
	copyvar VAR_0x8001, VAR_0x8000
# 19 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
# 20 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
# 21 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
# 22 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
# 23 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
# 24 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
# 25 "data/maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_Rival1::
# 29 "data/maps/DewfordTown_Gym/scripts.pory"
	lock
# 30 "data/maps/DewfordTown_Gym/scripts.pory"
	applymovement 9, Common_Movement_FacePlayer
# 31 "data/maps/DewfordTown_Gym/scripts.pory"
	waitmovement 0
# 32 "data/maps/DewfordTown_Gym/scripts.pory"
	compare VAR_TEMP_3, 5
	goto_if_eq DewfordTown_Gym_EventScript_Rival1_2
# 35 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_Rival1_3
# 40 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_FindingDeadEnds, MSGBOX_DEFAULT
# 41 "data/maps/DewfordTown_Gym/scripts.pory"
	setvar VAR_TEMP_3, 5
DewfordTown_Gym_EventScript_Rival1_1:
# 43 "data/maps/DewfordTown_Gym/scripts.pory"
	release
	end

DewfordTown_Gym_EventScript_Rival1_2:
# 33 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_HeHasToBeHereSomewhere, MSGBOX_DEFAULT
	goto DewfordTown_Gym_EventScript_Rival1_1

DewfordTown_Gym_EventScript_Rival1_3:
# 36 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_WhoaYouBeatTheGym, MSGBOX_DEFAULT
# 37 "data/maps/DewfordTown_Gym/scripts.pory"
	setvar VAR_TEMP_3, 5
	goto DewfordTown_Gym_EventScript_Rival1_1


# 65 "data/maps/DewfordTown_Gym/scripts.pory"

# 66 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetLightsOn::
# 67 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 0
# 68 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 69 "data/maps/DewfordTown_Gym/scripts.pory"

# 70 "data/maps/DewfordTown_Gym/scripts.pory"
@ Brightest
# 71 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel1::
# 72 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 1
# 73 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 74 "data/maps/DewfordTown_Gym/scripts.pory"

# 75 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel2::
# 76 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 2
# 77 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 78 "data/maps/DewfordTown_Gym/scripts.pory"

# 79 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel3::
# 80 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 3
# 81 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 82 "data/maps/DewfordTown_Gym/scripts.pory"

# 83 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel4::
# 84 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 4
# 85 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 86 "data/maps/DewfordTown_Gym/scripts.pory"

# 87 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel5::
# 88 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 5
# 89 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 90 "data/maps/DewfordTown_Gym/scripts.pory"

# 91 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel6::
# 92 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 6
# 93 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 94 "data/maps/DewfordTown_Gym/scripts.pory"

# 95 "data/maps/DewfordTown_Gym/scripts.pory"
@ Darkest
# 96 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel7::
# 97 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 7
# 98 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 99 "data/maps/DewfordTown_Gym/scripts.pory"

# 100 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrightenRoom::
# 101 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
# 102 "data/maps/DewfordTown_Gym/scripts.pory"
	nop1
# 103 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
# 104 "data/maps/DewfordTown_Gym/scripts.pory"
	copyvar VAR_0x8001, VAR_0x8000
# 105 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
# 106 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
# 107 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
# 108 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
# 109 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
# 110 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers
# 111 "data/maps/DewfordTown_Gym/scripts.pory"

# 112 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_NoLightChange::
# 113 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 114 "data/maps/DewfordTown_Gym/scripts.pory"

# 115 "data/maps/DewfordTown_Gym/scripts.pory"
@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
# 116 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
# 117 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 118 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 6
# 119 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 120 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 121 "data/maps/DewfordTown_Gym/scripts.pory"

# 122 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
# 123 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 124 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 5
# 125 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 126 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 127 "data/maps/DewfordTown_Gym/scripts.pory"

# 128 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
# 129 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 130 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 4
# 131 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 132 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 133 "data/maps/DewfordTown_Gym/scripts.pory"

# 134 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
# 135 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 136 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 3
# 137 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 138 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 139 "data/maps/DewfordTown_Gym/scripts.pory"

# 140 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
# 141 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 142 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 2
# 143 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 144 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 145 "data/maps/DewfordTown_Gym/scripts.pory"

# 146 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
# 147 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 148 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 1
# 149 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 150 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 151 "data/maps/DewfordTown_Gym/scripts.pory"

# 152 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
# 153 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 154 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 0
# 155 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 156 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 157 "data/maps/DewfordTown_Gym/scripts.pory"

# 158 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CountTrainersDefeated::
# 159 "data/maps/DewfordTown_Gym/scripts.pory"
	setvar VAR_0x8000, 0
# 160 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
# 161 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 162 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckJocelyn::
# 163 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
# 164 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 165 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckLaura::
# 166 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
# 167 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 168 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckBrenden::
# 169 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
# 170 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 171 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckCristian::
# 172 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
# 173 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 174 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckLilith::
# 175 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
# 176 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 177 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_StopCountingTrainers::
# 178 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 179 "data/maps/DewfordTown_Gym/scripts.pory"

# 180 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Brawly::
# 181 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
# 182 "data/maps/DewfordTown_Gym/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 183 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
# 184 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
# 185 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
# 186 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 187 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 188 "data/maps/DewfordTown_Gym/scripts.pory"

# 189 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrawlyDefeated::
# 190 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
# 191 "data/maps/DewfordTown_Gym/scripts.pory"
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
# 192 "data/maps/DewfordTown_Gym/scripts.pory"
	waitmessage
# 193 "data/maps/DewfordTown_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 194 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
# 195 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_BADGE02_GET
# 196 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_PETALBURG_GYM_STATE, 1
# 197 "data/maps/DewfordTown_Gym/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
# 198 "data/maps/DewfordTown_Gym/scripts.pory"
	setvar VAR_0x8008, 2
# 199 "data/maps/DewfordTown_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 200 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_GiveBulkUp
# 201 "data/maps/DewfordTown_Gym/scripts.pory"
	closemessage
# 202 "data/maps/DewfordTown_Gym/scripts.pory"
	delay 30
# 203 "data/maps/DewfordTown_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 204 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
# 205 "data/maps/DewfordTown_Gym/scripts.pory"
	waitfanfare
# 206 "data/maps/DewfordTown_Gym/scripts.pory"
	closemessage
# 207 "data/maps/DewfordTown_Gym/scripts.pory"
	delay 30
# 208 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
# 209 "data/maps/DewfordTown_Gym/scripts.pory"
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
# 210 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
# 211 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 212 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 213 "data/maps/DewfordTown_Gym/scripts.pory"

# 214 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GiveBulkUp::
# 215 "data/maps/DewfordTown_Gym/scripts.pory"
	giveitem ITEM_TM_BULK_UP
# 216 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 217 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
# 218 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_BULK_UP
# 219 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 220 "data/maps/DewfordTown_Gym/scripts.pory"

# 221 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GiveBulkUp2:
# 222 "data/maps/DewfordTown_Gym/scripts.pory"
	giveitem ITEM_TM_BULK_UP
# 223 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
# 224 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
# 225 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_BULK_UP
# 226 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 227 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 228 "data/maps/DewfordTown_Gym/scripts.pory"

# 229 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrawlyRematch::
# 230 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
# 231 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
# 232 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 233 "data/maps/DewfordTown_Gym/scripts.pory"

# 234 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Takao::
# 235 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
# 236 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
# 237 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 238 "data/maps/DewfordTown_Gym/scripts.pory"

# 239 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_TakaoBrightenRoom::
# 240 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 241 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 242 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 243 "data/maps/DewfordTown_Gym/scripts.pory"

# 244 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Jocelyn::
# 245 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
# 246 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
# 247 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 248 "data/maps/DewfordTown_Gym/scripts.pory"

# 249 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_JocelynBrightenRoom::
# 250 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 251 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 252 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 253 "data/maps/DewfordTown_Gym/scripts.pory"

# 254 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Laura::
# 255 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
# 256 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
# 257 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 258 "data/maps/DewfordTown_Gym/scripts.pory"

# 259 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_LauraBrightenRoom::
# 260 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 261 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 262 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 263 "data/maps/DewfordTown_Gym/scripts.pory"

# 264 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Brenden::
# 265 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
# 266 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
# 267 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 268 "data/maps/DewfordTown_Gym/scripts.pory"

# 269 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrendenBrightenRoom::
# 270 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 271 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 272 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 273 "data/maps/DewfordTown_Gym/scripts.pory"

# 274 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Cristian::
# 275 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
# 276 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
# 277 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 278 "data/maps/DewfordTown_Gym/scripts.pory"

# 279 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CristianBrightenRoom::
# 280 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 281 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 282 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 283 "data/maps/DewfordTown_Gym/scripts.pory"

# 284 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Lilith::
# 285 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
# 286 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
# 287 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 288 "data/maps/DewfordTown_Gym/scripts.pory"

# 289 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_LilithBrightenRoom::
# 290 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 291 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 292 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 293 "data/maps/DewfordTown_Gym/scripts.pory"

# 294 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymGuide::
# 295 "data/maps/DewfordTown_Gym/scripts.pory"
	lock
# 296 "data/maps/DewfordTown_Gym/scripts.pory"
	faceplayer
# 297 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymGuidePostVictory
# 298 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 299 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 300 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 301 "data/maps/DewfordTown_Gym/scripts.pory"

# 302 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymGuidePostVictory::
# 303 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 304 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 305 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 306 "data/maps/DewfordTown_Gym/scripts.pory"

# 307 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_LeftGymStatue::
# 308 "data/maps/DewfordTown_Gym/scripts.pory"
	lockall
# 309 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
# 310 "data/maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_GymStatue
# 311 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 312 "data/maps/DewfordTown_Gym/scripts.pory"

# 313 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_RightGymStatue::
# 314 "data/maps/DewfordTown_Gym/scripts.pory"
	lockall
# 315 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
# 316 "data/maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_GymStatue
# 317 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 318 "data/maps/DewfordTown_Gym/scripts.pory"

# 319 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymStatueCertified::
# 320 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 321 "data/maps/DewfordTown_Gym/scripts.pory"
	releaseall
# 322 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 323 "data/maps/DewfordTown_Gym/scripts.pory"

# 324 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymStatue::
# 325 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 326 "data/maps/DewfordTown_Gym/scripts.pory"
	releaseall
# 327 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 328 "data/maps/DewfordTown_Gym/scripts.pory"

# 329 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymGuideAdvice:
# 330 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Hey, how's it going, CHAMPION-\n"
# 331 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "bound {PLAYER}?\p"
# 332 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "DEWFORD's GYM LEADER BRAWLY commands\n"
# 333 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "FIGHTING-type POKéMON.\p"
# 334 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Going against him with NORMAL-type\n"
# 335 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "POKéMON is asking for trouble.\p"
# 336 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "FIGHTING POKéMON will lay a serious\n"
# 337 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "smack down on NORMAL POKéMON,\l"
# 338 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "so be careful!\p"
# 339 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "What's worse, the GYM is as dark as\n"
# 340 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "the ocean floor.\p"
# 341 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "But it will get brighter after defeating\n"
# 342 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "the TRAINERS in your way.\p"
# 343 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Hey, okay, go for it!$"
# 344 "data/maps/DewfordTown_Gym/scripts.pory"

# 345 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymGuidePostVictory:
# 346 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Whoah! It's turned too bright in here!\p"
# 347 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Your future is bright, too!$"
# 348 "data/maps/DewfordTown_Gym/scripts.pory"

# 349 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_TakaoIntro:
# 350 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Might is right!\n"
# 351 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Come on!$"
# 352 "data/maps/DewfordTown_Gym/scripts.pory"

# 353 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_TakaoDefeat:
# 354 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Not enough power…$"
# 355 "data/maps/DewfordTown_Gym/scripts.pory"

# 356 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_TakaoPostBattle:
# 357 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Your skill overcame my strength!\n"
# 358 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Your technique is commendable!$"
# 359 "data/maps/DewfordTown_Gym/scripts.pory"

# 360 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_JocelynIntro:
# 361 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "There's no need for BRAWLY to be\n"
# 362 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "involved!\p"
# 363 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'll crush you!$"
# 364 "data/maps/DewfordTown_Gym/scripts.pory"

# 365 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_JocelynDefeat:
# 366 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "But… How?\n"
# 367 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "How could I lose so easily?$"
# 368 "data/maps/DewfordTown_Gym/scripts.pory"

# 369 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_JocelynPostBattle:
# 370 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'm not going to waste this loss.\n"
# 371 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'll use it to motivate me to train!\p"
# 372 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "One day I'll become a GYM LEADER…\p"
# 373 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "No, I'll become the POKéMON LEAGUE\n"
# 374 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "CHAMPION!$"
# 375 "data/maps/DewfordTown_Gym/scripts.pory"

# 376 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LauraIntro:
# 377 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Don't you dare brush me off!\n"
# 378 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "It's not my fault if you cry!$"
# 379 "data/maps/DewfordTown_Gym/scripts.pory"

# 380 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LauraDefeat:
# 381 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Waaaaaaah!\n"
# 382 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I lost!$"
# 383 "data/maps/DewfordTown_Gym/scripts.pory"

# 384 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LauraPostBattle:
# 385 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I battle in the dark to make my heart\n"
# 386 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "stronger.\p"
# 387 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "But because it's so dark, I can never\n"
# 388 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "see BRAWLY's face…$"
# 389 "data/maps/DewfordTown_Gym/scripts.pory"

# 390 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LilithIntro:
# 391 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Ufufu…\n"
# 392 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Are you stumbling around in the dark?$"
# 393 "data/maps/DewfordTown_Gym/scripts.pory"

# 394 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LilithDefeat:
# 395 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Oh, you…\n"
# 396 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I don't want to know you!$"
# 397 "data/maps/DewfordTown_Gym/scripts.pory"

# 398 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LilithPostBattle:
# 399 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "You deserve to stay lost and end up\n"
# 400 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "back at the entrance again!$"
# 401 "data/maps/DewfordTown_Gym/scripts.pory"

# 402 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrendenIntro:
# 403 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'll show you the gumption of\n"
# 404 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "a sailing man!$"
# 405 "data/maps/DewfordTown_Gym/scripts.pory"

# 406 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrendenDefeat:
# 407 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "How'd this happen?\n"
# 408 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "It's not like me to lose this way!$"
# 409 "data/maps/DewfordTown_Gym/scripts.pory"

# 410 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrendenPostBattle:
# 411 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Oh, aye! You're worthy of seeing\n"
# 412 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "our GYM LEADER.$"
# 413 "data/maps/DewfordTown_Gym/scripts.pory"

# 414 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_CristianIntro:
# 415 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "If you mean to pass, it has to be\n"
# 416 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "through me!$"
# 417 "data/maps/DewfordTown_Gym/scripts.pory"

# 418 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_CristianDefeat:
# 419 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Grrrrr!\n"
# 420 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Vastly overpowered!$"
# 421 "data/maps/DewfordTown_Gym/scripts.pory"

# 422 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_CristianPostBattle:
# 423 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "You win!\n"
# 424 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Go after that BADGE!$"
# 425 "data/maps/DewfordTown_Gym/scripts.pory"

# 426 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyIntro:
# 427 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'm BRAWLY!\n"
# 428 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "DEWFORD's GYM LEADER!\p"
# 429 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I've been churned in the rough waves\n"
# 430 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "of these parts, and I've grown tough\l"
# 431 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "in the pitch-black cave!\p"
# 432 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "So you wanted to challenge me?\n"
# 433 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Let me see what you're made of!$"
# 434 "data/maps/DewfordTown_Gym/scripts.pory"

# 435 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyDefeat:
# 436 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Whoah, wow! You made a much bigger\n"
# 437 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "splash than I expected!\p"
# 438 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "You swamped me!\p"
# 439 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Okay, you've got me.\n"
# 440 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Take this GYM BADGE!$"
# 441 "data/maps/DewfordTown_Gym/scripts.pory"

# 442 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_ReceivedKnuckleBadge:
# 443 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "{PLAYER} received the KNUCKLE BADGE\n"
# 444 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "from BRAWLY.$"
# 445 "data/maps/DewfordTown_Gym/scripts.pory"

# 446 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
# 447 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "The KNUCKLE BADGE makes all POKéMON\n"
# 448 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "up to Level 30, even those you get in\l"
# 449 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "trades, obey without question.\p"
# 450 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "And, you'll be able to use the HM move\n"
# 451 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "FLASH outside of battle.\p"
# 452 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "If you'd like, use this TECHNICAL\n"
# 453 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "MACHINE, too.$"
# 454 "data/maps/DewfordTown_Gym/scripts.pory"

# 455 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_ExplainBulkUp:
# 456 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "That TM08 contains BULK UP.\p"
# 457 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "It's a move that raises both ATTACK\n"
# 458 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "and DEFENSE stats.\p"
# 459 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "… … … … … …$"
# 460 "data/maps/DewfordTown_Gym/scripts.pory"

# 461 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_RegisteredBrawly:
# 462 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Registered GYM LEADER BRAWLY\n"
# 463 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "in the POKéNAV.$"
# 464 "data/maps/DewfordTown_Gym/scripts.pory"

# 465 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyPostBattle:
# 466 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I can see your talent becoming a giant\n"
# 467 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "wave to cause a storm of astonishment\l"
# 468 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "among TRAINERS one day!$"
# 469 "data/maps/DewfordTown_Gym/scripts.pory"

# 470 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymStatue:
# 471 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "DEWFORD TOWN POKéMON GYM$"
# 472 "data/maps/DewfordTown_Gym/scripts.pory"

# 473 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymStatueCertified:
# 474 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "DEWFORD TOWN POKéMON GYM\p"
# 475 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "BRAWLY'S CERTIFIED TRAINERS:\n"
# 476 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "{PLAYER}$"
# 477 "data/maps/DewfordTown_Gym/scripts.pory"

# 478 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyPreRematch:
# 479 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "BRAWLY: A wave may draw back, but it\n"
# 480 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "always returns to the shore.\p"
# 481 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "A giant wave of a talent like you…\n"
# 482 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I knew you would return!\p"
# 483 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Show me how much higher\n"
# 484 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "you've gone!$"
# 485 "data/maps/DewfordTown_Gym/scripts.pory"

# 486 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyRematchDefeat:
# 487 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Wow!\n"
# 488 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Swamped again!$"
# 489 "data/maps/DewfordTown_Gym/scripts.pory"

# 490 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyPostRematch:
# 491 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "BRAWLY: Battling is vast and it's deep.\n"
# 492 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "You can't see the bottom.\l"
# 493 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "It's just like the sea of HOENN!$"
# 494 "data/maps/DewfordTown_Gym/scripts.pory"

# 495 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
# 496 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "BRAWLY: A wave may draw back, but it\n"
# 497 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "always returns to the shore.\p"
# 498 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "A giant wave of a talent like you…\n"
# 499 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I knew you would return!\p"
# 500 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Oh? You only have one POKéMON\n"
# 501 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "that can battle.\p"
# 502 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'm sorry, but I'd like you to come back\n"
# 503 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "with at least two POKéMON.$"

DewfordTown_Gym_Text_FindingDeadEnds::
# 47 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I don't know how I'm supposed to look\n"
	.string "for STEVEN in here.\l"
	.string "I keep finding dead ends in the dark!$"

DewfordTown_Gym_Text_WhoaYouBeatTheGym::
# 52 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Whoa! You beat the gym and turned all\n"
	.string "the lights on?\l"
	.string "Nice!\p"
	.string "You didn't happen to see STEVEN in\n"
	.string "there, did you?\l"
	.string "No?\l"
	.string "That's too bad.\l"
	.string "I'll keep looking.$"

DewfordTown_Gym_Text_HeHasToBeHereSomewhere::
# 61 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "He has to be around here SOMEWHERE!$"
