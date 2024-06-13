Common_EventScript_SetupRivalGfxId::
	checkfriendchoice
	goto_if_eq VAR_RESULT, SPENCER, EventScript_SetupRivalGfxIdSpencer
	goto_if_eq VAR_RESULT, BREN, EventScript_SetupRivalGfxIdBren
	goto_if_eq VAR_RESULT, KYLE, EventScript_SetupRivalGfxIdKyle
	end

EventScript_SetupRivalGfxIdSpencer::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BREN_NORMAL
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_KYLE_NORMAL
	return

EventScript_SetupRivalGfxIdBren::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_KYLE_NORMAL
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_SPENCER_NORMAL
	return

EventScript_SetupRivalGfxIdKyle::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPENCER_NORMAL
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_BREN_NORMAL
	return

Common_EventScript_SetupRivalOnBikeGfxId::
	checkfriendchoice
	goto_if_eq VAR_RESULT, SPENCER, EventScript_SetupRivalOnBikeGfxIdSpencer
	goto_if_eq VAR_RESULT, BREN, EventScript_SetupRivalOnBikeGfxIdBren
	goto_if_eq VAR_RESULT, KYLE, EventScript_SetupRivalOnBikeGfxIdKyle
	end

EventScript_SetupRivalOnBikeGfxIdSpencer::
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BREN_MACH_BIKE
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_KYLE_MACH_BIKE
	return

EventScript_SetupRivalOnBikeGfxIdBren::
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_KYLE_MACH_BIKE
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_SPENCER_MACH_BIKE
	return

EventScript_SetupRivalOnBikeGfxIdKyle::
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_SPENCER_MACH_BIKE
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BREN_MACH_BIKE
	return

@ Unused
Common_EventScript_SetupRivalGfxIdSameGender::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EventScript_SetupRivalGfxIdMale2
	goto_if_eq VAR_RESULT, FEMALE, EventScript_SetupRivalGfxIdFemale2
	end

EventScript_SetupRivalGfxIdMale2::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

EventScript_SetupRivalGfxIdFemale2::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	return
