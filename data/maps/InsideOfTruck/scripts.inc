InsideOfTruck_MapScripts::
# 2 "data/maps/InsideOfTruck/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
# 3 "data/maps/InsideOfTruck/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, InsideOfTruck_OnResume
	.byte 0


InsideOfTruck_OnLoad::
# 7 "data/maps/InsideOfTruck/scripts.pory"
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, FALSE
# 8 "data/maps/InsideOfTruck/scripts.pory"
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, FALSE
# 9 "data/maps/InsideOfTruck/scripts.pory"
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, FALSE
	end


InsideOfTruck_OnResume::
# 14 "data/maps/InsideOfTruck/scripts.pory"
	setstepcallback STEP_CB_TRUCK
	end


InsideOfTruck_EventScript_SetIntroFlags::
# 19 "data/maps/InsideOfTruck/scripts.pory"
	lockall
# 20 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 21 "data/maps/InsideOfTruck/scripts.pory"
	checkfriendchoice
# 23 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 24 "data/maps/InsideOfTruck/scripts.pory"
	case SPENCER, InsideOfTruck_EventScript_SetIntroFlags_3
# 26 "data/maps/InsideOfTruck/scripts.pory"
	case BREN, InsideOfTruck_EventScript_SetIntroFlags_4
# 28 "data/maps/InsideOfTruck/scripts.pory"
	case KYLE, InsideOfTruck_EventScript_SetIntroFlags_5
InsideOfTruck_EventScript_SetIntroFlags_1:
	end

InsideOfTruck_EventScript_SetIntroFlags_3:
# 25 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SetIntroFlagsSpencer
	goto InsideOfTruck_EventScript_SetIntroFlags_1

InsideOfTruck_EventScript_SetIntroFlags_4:
# 27 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SetIntroFlagsBren
	goto InsideOfTruck_EventScript_SetIntroFlags_1

InsideOfTruck_EventScript_SetIntroFlags_5:
# 29 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SetIntroFlagsKyle
	goto InsideOfTruck_EventScript_SetIntroFlags_1


InsideOfTruck_EventScript_SetIntroFlagsSpencer::
# 35 "data/maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
# 36 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
# 37 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_MOM
# 38 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_RIVAL_MOM
# 39 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_MOM
# 40 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 1
# 41 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
# 42 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
	end


InsideOfTruck_EventScript_SetIntroFlagsBren::
# 47 "data/maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
# 48 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
# 49 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_MOM
# 50 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_RIVAL_MOM
# 51 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_MOM
# 52 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 1
# 53 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
# 54 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
	end


InsideOfTruck_EventScript_SetIntroFlagsKyle::
# 59 "data/maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_KYLES_HOUSE_2F
# 60 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
# 61 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_MOM
# 62 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_MOM
# 63 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_RIVAL_MOM
# 64 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 1
# 65 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 15, 17
# 66 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
	end


InsideOfTruck_EventScript_MovingBox::
# 71 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
	end


InsideOfTruck_Text_BoxPrintedWithMonLogo::
# 75 "data/maps/InsideOfTruck/scripts.pory"
	.string "The box is printed with a POKéMON logo.\p"
	.string "It's a POKéMON brand moving and\n"
	.string "delivery service.$"
