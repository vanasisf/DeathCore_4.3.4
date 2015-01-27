
// Chat Icons
//CHAT_ICON = 0
//VENDOR_ICON = 1
//FLIGHT_ICON = 2
//TRAINER_ICON = 3
//GEAR_ICON = 4
//GEAR_ICON_2 = 5
//BANK_ICON = 6
//CHAT_DOTS_ICON = 7
//TABARD_ICON = 8
//SWORDS_ICON = 9
//GOLD_DOT_ICON = 10

#define ERROR_COMBAT "|cffff0000Você está em Combate!|r"

class Tele : public CreatureScript
{
public:
	Tele() : CreatureScript("Tele") { }

	bool OnGossipHello(Player* plr, Creature* crt)
	{
		if(plr->isInCombat())
		{	
			ChatHandler(plr->GetSession()).PSendSysMessage(ERROR_COMBAT);
			return false;
		}
		else 
		{
			plr->ADD_GOSSIP_ITEM(0, "|TInterface\\icons\\Achievement_Reputation_01:30|t  Global Mall", GOSSIP_SENDER_MAIN, 1);
			/*plr->ADD_GOSSIP_ITEM(0, "|TInterface\\icons\\Achievement_BG_winWSG:30|t  Dueling Zone", GOSSIP_SENDER_MAIN, 2);*/
			/*plr->ADD_GOSSIP_ITEM(0, "|TInterface\\icons\\INV_Misc_Wrench_01:30|t  Profession Area", GOSSIP_SENDER_MAIN, 3);*/
			plr->ADD_GOSSIP_ITEM(0, "|TInterface\\icons\\INV_Mask_01:30|t  Transmogrification Area", GOSSIP_SENDER_MAIN, 4);
			plr->ADD_GOSSIP_ITEM(0, "|TInterface\\ICONS\\ACHIEVEMENT_ARENA_2V2_1:30|t Gurubashi Arena", GOSSIP_SENDER_MAIN, 5);
			plr->SEND_GOSSIP_MENU(1, crt->GetGUID());
			return true;
		}
	}

	bool OnGossipSelect(Player* plr, Creature* crt, uint32 /*sender*/, uint32 actions)
	{
		switch (actions)
		{
			case 1: // Global Mall
				plr->CLOSE_GOSSIP_MENU();
				plr->TeleportTo(0, -2723.567871f, -5356.419434f, 177.281921f, 2.535085f);
				break;

		    case 2: // Dueling Zone
				plr->CLOSE_GOSSIP_MENU();
				plr->TeleportTo(0, -3575.618652f, -5004.466797f, 33.229931f, 5.351537f);
				break;

			case 3: // Profession Area
				plr->CLOSE_GOSSIP_MENU();
				plr->TeleportTo(571, 5829.209473f, 476.326782f,658.231628f, 4.316894f);
				break;
				
			case 4: // Transmogrification Area
				plr->CLOSE_GOSSIP_MENU();
				plr->TeleportTo(530, -1841.091187f, 5384.616699f, -12.427767f, 2.012928f);
				break;

			case 5: // Gurubashi Arena
				plr->CLOSE_GOSSIP_MENU();
				plr->TeleportTo(0, -13225.893555f, 232.465149f, 33.310444f, 1.121269f);
				break;

		}
		return true;
	}
};

void AddSC_Tele()
{
	new Tele();
}