JurassicPark_Beach_Docks_MapScripts::
	.byte 0


General_EventScript_Cutout::
# 5 "data/maps/JurassicPark_Beach_Docks/scripts.pory"
	lock
# 6 "data/maps/JurassicPark_Beach_Docks/scripts.pory"
	goto_if_set FLAG_TEMP_1, General_EventScript_Cutout_2
# 14 "data/maps/JurassicPark_Beach_Docks/scripts.pory"
	msgbox General_EventScript_Cutout_Text_1
# 19 "data/maps/JurassicPark_Beach_Docks/scripts.pory"
	setflag FLAG_TEMP_1
General_EventScript_Cutout_1:
# 21 "data/maps/JurassicPark_Beach_Docks/scripts.pory"
	release
	end

General_EventScript_Cutout_2:
# 8 "data/maps/JurassicPark_Beach_Docks/scripts.pory"
	msgbox General_EventScript_Cutout_Text_0
	goto General_EventScript_Cutout_1


General_EventScript_Cutout_Text_0:
# 9 "data/maps/JurassicPark_Beach_Docks/scripts.pory"
	.string "Yep, still cardboard.$"

General_EventScript_Cutout_Text_1:
# 15 "data/maps/JurassicPark_Beach_Docks/scripts.pory"
	.string "As you approach the hut,\n"
	.string "you start to notice…\p"
	.string "That this is just a cardboard cutout.$"
