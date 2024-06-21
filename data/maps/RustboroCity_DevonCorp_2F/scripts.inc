# 4 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 5 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
.set LOCALID_FOSSIL_SCIENTIST, 5
# 6 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 7 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_MapScripts::
# 8 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_2F_OnTransition
# 9 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.byte 0
# 10 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 11 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_OnTransition:
# 12 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 13 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 14 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 15 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 16 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_SetFossilReady::
# 17 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 2
# 18 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 19 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 20 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_TalkToPokemonScientist::
# 21 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 22 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 23 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 24 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon, MSGBOX_DEFAULT
# 25 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 26 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 27 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 28 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_BallScientist::
# 29 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 30 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 31 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 32 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls
# 33 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls, MSGBOX_DEFAULT
# 34 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 35 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 36 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 37 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls::
# 38 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls, MSGBOX_DEFAULT
# 39 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 40 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 41 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 42 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_PokenavScientist::
# 43 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 44 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 45 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 46 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_DevonCorp_2F_EventScript_HasPokenav
# 47 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_IMadePokenav, MSGBOX_DEFAULT
# 48 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 49 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 50 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 51 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_HasPokenav::
# 52 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav, MSGBOX_DEFAULT
# 53 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 54 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 55 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 56 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_PokemonDreamsScientist::
# 57 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 58 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 59 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 60 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams, MSGBOX_DEFAULT
# 61 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 62 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 63 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 64 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FossilScientist::
# 65 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 66 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 67 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 2, RustboroCity_DevonCorp_2F_EventScript_FossilMonReady
# 68 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_StillRegenerating
# 69 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
# 70 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_ROOT_FOSSIL
# 71 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil
# 72 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_CLAW_FOSSIL
# 73 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil
# 74 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 75 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end

RustboroCity_DevonCorp_2F_EventScript_Rival2::
# 79 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 80 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement 7, Common_Movement_FacePlayer
# 81 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 82 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_TEMP_2, 5
	goto_if_ne RustboroCity_DevonCorp_2F_EventScript_Rival2_2
# 87 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_StopAndSmellTheFlowers, MSGBOX_DEFAULT
RustboroCity_DevonCorp_2F_EventScript_Rival2_1:
# 89 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 90 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement 7, Common_Movement_FaceRight
# 91 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 92 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
	end

RustboroCity_DevonCorp_2F_EventScript_Rival2_2:
# 83 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_IllGetToItSoon, MSGBOX_DEFAULT
# 84 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_2, 5
	goto RustboroCity_DevonCorp_2F_EventScript_Rival2_1


# 110 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 111 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
@ This whole section has needless duplication and could be condensed considerably
# 112 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil::
# 113 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 114 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playse SE_PIN
# 115 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
# 116 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 117 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
# 118 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 119 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
# 120 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
# 121 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_CLAW_FOSSIL
# 122 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
# 123 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
# 124 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 125 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 126 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil::
# 127 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ROOT_FOSSIL
# 128 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 129 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_ROOT_FOSSIL
# 130 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
# 131 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 1
# 132 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 133 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 134 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 135 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil::
# 136 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 137 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playse SE_PIN
# 138 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
# 139 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 140 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
# 141 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 142 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
# 143 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
# 144 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_ROOT_FOSSIL
# 145 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
# 146 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
# 147 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 148 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 149 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil::
# 150 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CLAW_FOSSIL
# 151 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 152 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_CLAW_FOSSIL
# 153 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
# 154 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 2
# 155 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 156 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 157 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 158 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil::
# 159 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_OhIsThatSo, MSGBOX_DEFAULT
# 160 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 161 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 162 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 163 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_StillRegenerating::
# 164 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
# 165 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 166 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 167 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 168 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FossilMonReady::
# 169 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 1, RustboroCity_DevonCorp_2F_EventScript_LileepReady
# 170 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 2, RustboroCity_DevonCorp_2F_EventScript_AnorithReady
# 171 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 172 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 173 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_LileepReady::
# 174 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
# 175 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
# 176 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep
# 177 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 178 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 179 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_AnorithReady::
# 180 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
# 181 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
# 182 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith
# 183 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 184 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 185 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep::
# 186 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LILEEP
# 187 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_LILEEP, 20
# 188 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty
# 189 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC
# 190 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 191 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 192 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 193 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty::
# 194 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
# 195 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 196 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
# 197 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 198 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 199 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
# 200 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 201 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 202 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC::
# 203 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
# 204 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 205 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
# 206 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 207 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
# 208 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 209 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 210 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC::
# 211 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 212 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
# 213 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 214 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 215 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare::
# 216 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
# 217 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 218 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
# 219 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 220 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitfanfare
# 221 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LILEEP
# 222 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 223 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 224 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep::
# 225 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 226 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
# 227 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 228 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 229 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 230 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith::
# 231 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ANORITH
# 232 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_ANORITH, 20
# 233 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty
# 234 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC
# 235 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 236 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 237 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 238 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty::
# 239 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
# 240 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 241 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
# 242 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 243 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 244 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
# 245 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 246 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 247 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC::
# 248 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
# 249 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 250 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
# 251 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 252 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
# 253 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 254 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 255 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC::
# 256 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 257 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
# 258 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 259 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 260 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare::
# 261 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
# 262 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 263 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
# 264 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 265 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitfanfare
# 266 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ANORITH
# 267 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 268 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 269 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith::
# 270 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 271 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
# 272 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 273 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 274 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 275 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ChooseFossil::
# 276 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne
# 277 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 278 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 17, 6, MULTI_FOSSIL, FALSE
# 279 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	switch VAR_RESULT
# 280 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 0, RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil
# 281 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 1, RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil
# 282 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 2, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
# 283 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
# 284 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 285 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 286 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil::
# 287 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
# 288 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 289 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 290 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil::
# 291 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
# 292 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 293 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 294 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect::
# 295 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 296 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 297 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 298 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_MatchCallScientist::
# 299 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 300 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 301 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 302 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_ge VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_DevonCorp_2F_EventScript_WorkOnNext
# 303 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature, MSGBOX_DEFAULT
# 304 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 305 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 306 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 307 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_WorkOnNext::
# 308 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext, MSGBOX_DEFAULT
# 309 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 310 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 311 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 312 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon:
# 313 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "We're developing a device for talking\n"
# 314 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "with POKéMON.\p"
# 315 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But we haven't had much success…$"
# 316 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 317 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls:
# 318 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm developing new kinds of\n"
# 319 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "POKé BALLS…\p"
# 320 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But I haven't made much headway…$"
# 321 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 322 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls:
# 323 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "We finally made new kinds of\n"
# 324 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "POKé BALLS!\p"
# 325 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The REPEAT BALL makes it easier to\n"
# 326 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "catch POKéMON you've caught before.\p"
# 327 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The TIMER BALL gets better at catching\n"
# 328 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "POKéMON the longer a battle runs.\p"
# 329 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Both are proudly developed by\n"
# 330 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the DEVON CORPORATION.\p"
# 331 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Please give them a try!$"
# 332 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 333 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_IMadePokenav:
# 334 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I made the POKéNAV!\p"
# 335 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "As an engineer, I feel blessed to have\n"
# 336 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "made something so great!$"
# 337 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 338 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav:
# 339 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, wow!\n"
# 340 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "That's a POKéNAV!\p"
# 341 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "It came about as a result of our\n"
# 342 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "PRESIDENT's desire to learn about\l"
# 343 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the feelings of POKéMON.\p"
# 344 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Would you like me to describe its\n"
# 345 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "features in detail?\p"
# 346 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "No, no. I think you'll find out just by\n"
# 347 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "trying the POKéNAV out.$"
# 348 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 349 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams:
# 350 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm trying to develop a device that\n"
# 351 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "visually reproduces the dreams of\l"
# 352 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "POKéMON…\p"
# 353 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it's not going well.$"
# 354 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 355 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils:
# 356 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I've been trying to develop a device\n"
# 357 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "that resurrects POKéMON from fossils…\p"
# 358 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "And, it's working!$"
# 359 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 360 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife:
# 361 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Wait! That thing you have there…\n"
# 362 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Is that a POKéMON fossil?\p"
# 363 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Would you like to bring that POKéMON\n"
# 364 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "back to life?\p"
# 365 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I can with my newly developed\n"
# 366 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "FOSSIL REGENERATOR.$"
# 367 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 368 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_OhIsThatSo:
# 369 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, is that so?\p"
# 370 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "DEVON's technological expertise\n"
# 371 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "is outstanding, I tell you.$"
# 372 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 373 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne:
# 374 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, now that's a surprise!\n"
# 375 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "You have not one, but two, fossils?\p"
# 376 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Unfortunately, my machine can only\n"
# 377 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "regenerate one POKéMON at a time.\p"
# 378 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Would you like to pick one of your\n"
# 379 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "fossils for regeneration?$"
# 380 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 381 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher:
# 382 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Excellent!\n"
# 383 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Let's do this right away.\p"
# 384 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{PLAYER} handed the {STR_VAR_1} to\n"
# 385 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the DEVON RESEARCHER.$"
# 386 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 387 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime:
# 388 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The FOSSIL REGENERATOR, which I made,\n"
# 389 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "is incredible.\p"
# 390 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it has one drawback--it takes\n"
# 391 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "a long time to work.\p"
# 392 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "So, uh… How about you go for a stroll\n"
# 393 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "and look around for a while?$"
# 394 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 395 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife:
# 396 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Thanks for waiting!\p"
# 397 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Your fossilized POKéMON has been\n"
# 398 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "brought back to life!\p"
# 399 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The fossil was an ancient POKéMON.\n"
# 400 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{STR_VAR_2}, it was!$"
# 401 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 402 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher:
# 403 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{PLAYER} received {STR_VAR_2} from\n"
# 404 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the DEVON RESEARCHER.$"
# 405 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 406 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
@ Unused
# 407 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_TooManyPokemon:
# 408 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Uh-oh, you've got too many POKéMON.\n"
# 409 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "You have no room for this one.$"
# 410 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 411 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature:
# 412 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm trying to develop a new feature\n"
# 413 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "for the POKéNAV…\p"
# 414 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it's not going well.$"
# 415 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 416 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext:
# 417 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Well, now what shall I work on\n"
# 418 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "developing next?\p"
# 419 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Our company allows us to make our\n"
# 420 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "inspirations into reality.\p"
# 421 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "One couldn't ask for a better\n"
# 422 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "environment as an engineer.$"

RustboroCity_DevonCorp_2F_Text_IllGetToItSoon::
# 96 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Watching this scientist work is so\n"
	.string "fascinating!\l"
	.string "He says he can ressurect fossils into\l"
	.string "living POKéMON.\l"
	.string "… … …\l"
	.string "No, I haven't seen the president yet.\p"
	.string "Don't worry.\n"
	.string "I'll get to it soon.$"

RustboroCity_DevonCorp_2F_Text_StopAndSmellTheFlowers::
# 105 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "You seem to be taking your time too.\n"
	.string "It's good to stop and smell the flowers\l"
	.string "every now and again.$"
