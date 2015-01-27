#include "ScriptPCH.h"
#include "Chat.h"

/* Ranks */
#define OWNER "Owner"
#define ADMINISTRATOR "Admin"
#define HEAD_OF_STAFF "Head GM"
#define DEVELOPER "Developer"
#define GAMEMASTER "Senior GM"
#define JUNIOR_GM "Junior GM"
#define TRIAL_GM "Trial GM"
#define MODERATOR "Trial GM"
#define VIP "VIP"
#define PLAYER "Player"

using namespace std;

std::string GetNameLink(Player* player)
{
	std::string name = player->GetName();
	std::string color;
	std::string icon;
	switch(player->getClass()) 
	{
	case CLASS_DEATH_KNIGHT:
		color = "|cffC41F3B";
		icon  = "|TInterface/ICONS/Spell_Deathknight_ClassIcon.png:16|t";
		break;
	case CLASS_DRUID:
		color = "|cffFF7D0A";
		icon  = "|TInterface/ICONS/INV_Misc_MonsterClaw_04.png:16|t";
		break;
	case CLASS_HUNTER:
		color = "|cffABD473";
		icon  = "|TInterface/ICONS/INV_Weapon_Bow_07.png:16|t";
		break;
	case CLASS_MAGE:
		color = "|cff69CCF0";
		icon  = "|TInterface/ICONS/INV_Staff_13.png:16|t";
		break;
	case CLASS_PALADIN:
		color = "|cffF58CBA";
		icon  = "|TInterface/ICONS/Spell_Holy_DivineIntervention.png:16|t";
		break;
	case CLASS_PRIEST:
		color = "|cffFFFFFF";
		icon  = "|TInterface/ICONS/INV_Staff_30.png:16|t";
		break;
	case CLASS_ROGUE:
		color = "|cffFFF569";
		icon  = "|TInterface/ICONS/INV_ThrowingKnife_04.png:16|t";
		break;
	case CLASS_SHAMAN:
		color = "|cff0070DE";
		icon  = "|TInterface/ICONS/Spell_Nature_BloodLust.png:16|t";
		break;
	case CLASS_WARLOCK:
		color = "|cff9482C9";
		icon  = "|TInterface/ICONS/Spell_Nature_Drowsy.png:16|t";
		break;
	case CLASS_WARRIOR:
		color = "|cffC79C6E";
		icon  = "|TInterface/ICONS/INV_Sword_27.png:16|t";
		break;
	case CLASS_MONK:
		color = "|cffABD473";
		icon  = "|TInterface/ICONS/INV_Chest_Cloth_57.png:16|t";
		break;
	}
	return ""+icon+" |Hplayer:"+name+"|h"+color+name+"|h";
}

void _SendWorldChat(Player* player, string message)
{
	size_t stringpos;

	if(message.find("|TInterface") != string::npos)
		return;

	if(message.find("\n") != string::npos )
		return;

	if((stringpos = message.find("|Hquest:")) != string::npos)
		return;

	if((stringpos = message.find("|Htrade:")) != string::npos)
		return;

	if((stringpos = message.find("|Htalent:")) != string::npos)
		return;

	if((stringpos = message.find("|Henchant:")) != string::npos)
		return;

	if((stringpos = message.find("|Hachievement:")) != string::npos)
		return;

	if((stringpos = message.find("|Hglyph:")) != string::npos)
		return;

	if((stringpos = message.find("|Hspell:")) != string::npos)
		return;

	if((stringpos = message.find("Hitem:")) != string::npos)
		return;

	if(message.find("|c") != string::npos && message.find("|r") != string::npos)
		return;

	if(message.find("|c") != string::npos && message.find("|h") != string::npos)
		return;

   uint8 cheksSize = 118;//Change these if you want to add more words to the array.
    std::string checks[118];//Change these if you want to add more words to the array.
    // Strony (Sites)
    // Strony (Sites)
	checks[0] ="http://";
	checks[1] =".com";
	checks[2] =".net";
	checks[3] =".org";
	checks[4] ="www.";
	checks[5] ="wow-";
	checks[6] ="-wow";
	checks[7] ="no-ip";
	checks[8] =".zapto";
	checks[9] =".biz";
	checks[10] =".servegame";
	checks[11] =".br";
	checks[12] ="com.br";

	checks[13] ="h t t p : / /";
	checks[14] =". c o m";
	checks[15] =". n e t";
	checks[16] =". o r g";
	checks[17] ="w w w .";
	checks[18] =" w o w -";
	checks[19] ="- w o w";
	checks[20] ="n o - i p";
	checks[21] =". z a p t o";
	checks[22] =". b i z";
	checks[23] =". s e r v e g a m e";
	checks[24] =". b r";
	checks[25] ="c o m . b r";

	checks[26] ="h  t  t  p  :  /  /";
	checks[27] =".  c  o  m";
	checks[28] =".  n  e  t";
	checks[29] =".  o  r  g";
	checks[30] ="w  w  w  .";
	checks[31] =" w  o  w  -";
	checks[32] ="-  w  o  w";
	checks[33] ="n  o  -  i  p";
	checks[34] =".  z  a  p  t  o";
	checks[35] =".  b  i  z";
	checks[36] =".  s  e  r  v  e  g  a  m  e";
	checks[37] =".  b  r";
	checks[38] ="c  o  m  .  b  r";
	
	checks[39] ="h   t   t   p   :   /   /";
	checks[40] =".   c   o   m";
	checks[41] =".   n   e   t";
	checks[42] =".   o   r   g";
	checks[43] ="w   w   w   .";
	checks[44] =" w   o   w   -";
	checks[45] ="-   w   o   w";
	checks[46] ="n   o   -   i   p";
	checks[47] =".   z   a   p   t   o";
	checks[48] =".   b   i   z";
	checks[49] =".   s   e   r   v   e   g   a   m   e";
	checks[50] =".   b   r";
	checks[51] ="   c   o   m   .   b   r";
	
	checks[52] ="h    t    t    p   :   /   /";
	checks[53] =".    c    o    m";
	checks[54] =".    n    e   t";
	checks[55] =".    o    r    g";
	checks[56] ="w    w    w    .";
	checks[57] ="w    o    w    -";
	checks[58] ="-    w    o    w";
	checks[59] ="n    o    -    i    p";
	checks[60] =".    z    a    p    t    o";
	checks[61] =".    b    i     z";
	checks[62] =".    s    e    r    v    e    g    a    m    e";
	checks[63] =".    b    r";
	checks[64] ="c    o    m    .    b    r";
	
	checks[65] ="trevon";
	checks[66] ="megawow";
	checks[67] ="fatalwow";
	checks[68] ="uniforgiven-wow";
	checks[69] ="wow-autolouco";
	checks[70] ="heaven-wow";
	checks[71] ="fireballwow";
	checks[72] ="wowbrasilpa";
	checks[73] ="fatalitywow";
	checks[74] ="demonic-wow";
	checks[75] ="revenge-wow";
	checks[76] ="heavenwow";
	checks[77] ="undead-wow";
	checks[78] ="linebr";
	checks[79] ="azralon";
	checks[80] ="black-wow";
	checks[81] ="trevonwow";
	
	checks[82] ="t r e v o n";
	checks[83] ="m e g a w o w";
	checks[84] ="f a t a l w o w";
	checks[85] ="u n i f o r g i v e n - w o w";
	checks[86] ="w o w - a u t o l o u c o";
	checks[87] ="h e a v e n - w o w";
	checks[88] ="f i r e b a l l w o w";
	checks[89] ="w o w b r a s i l  p a";
	checks[90] ="f a t a l i t y w o w";
	checks[91] ="d e m o n i c - w o w";
	checks[92] ="r e v e n g e - w o w";
	checks[93] ="h e a v e n w o w";
	checks[94] ="u n d e a d - w o w";
	checks[95] ="l i n e b r";
	checks[96] ="a z r a l o n";
	checks[97] ="b l a c k - w o w";
	checks[98] ="t r e v o n w o w";
	
	checks[99] ="t  r  e  v  o  n";
	checks[100] ="m  e  g  a  w  o  w";
	checks[101] ="f  a  t  a  l  w  o  w";
	checks[102] ="u  n  i  f  o  r  g  i  v  e  n  -  w  o  w";
	checks[103] ="w  o  w  -  a  u  t  o   l o  u  c  o";
	checks[104] ="h  e  a  v  e  n  -  w  o  w";
	checks[105] ="f  i  r  e  b  a  l  l  w  o  w";
	checks[106] ="w  o  w  b  r  a  s  i  l  p  a";
	checks[107] ="f  a  t  a  l  i  t  y  w  o  w";
	checks[108] ="d  e  m  o  n  i  c  -  w  o  w";
	checks[109] ="r  e  v  e  n  g  e  -  w  o  w";
	checks[110] ="h  e  a  v  e  n  w  o  w";
	checks[111] ="u  n  d  e  a  d  -  w  o  w";
	checks[112] ="l  i  n  e  b  r";
	checks[113] ="a  z  r  a  l  o  n";
	checks[114] ="b  l  a  c  k  -  w  o  w";
	checks[115] ="t  r  e  v  o  n  w  o  w";
	
	checks[116] =" [The Lightbringer's Redemption]";
    checks[117] ="[The Lightbringer's Redemption]";

	for (int i = 0; i < cheksSize; ++i)
	{
		if (message.find(checks[i]) != string::npos)
		{
			std::string say = "";
			std::string str = "";
			say = message;
			ChatHandler(player->GetSession()).PSendSysMessage("|cffFF0000Mensagem Bloqueada.. Impossível divulgar ou usar palavras obcenas.");
			SessionMap ss = sWorld->GetAllSessions();
			for (SessionMap::const_iterator itr = ss.begin(); itr != ss.end(); ++itr)
				if (itr->second->GetSecurity() > 0)
					str = "[Anti Divulgação][" + string(player->GetName()) + "][" + say + "]";
			WorldPacket data(SMSG_NOTIFICATION, (str.size()+1));
			data << str;
			sWorld->SendGlobalGMMessage(&data);
			return;
		}
	}

	string msg;
	ostringstream chat_string;

	switch(player->GetSession()->GetSecurity())
	{
	case SEC_PLAYER:
		if (player->GetTeam() == ALLIANCE)
		{
			msg += " |TInterface/ICONS/INV_BannerPVP_02.png:16|t [Jogador] ";
			msg += GetNameLink(player);
			msg += ":|#0000FF";
		}
		else
		{
			msg += " |TInterface/ICONS/INV_BannerPVP_01.png:16|t[Jogador] ";
			msg += GetNameLink(player);
			msg += ":|#FF0000";
		}
		break;
			// Jogador Vip
	case SEC_VIP:
		msg += " |TInterface/ICONS/Ability_Warrior_StalwartProtector.png:16|t [V.I.P] ";
		msg += GetNameLink(player);
		msg += ":|#FFFF00";
		break;
			// Moderador - Divulgador
	case SEC_MODERATOR:
		msg += " |TInterface/ICONS/Achievement_Dungeon_UtgardePinnacle.png:16|t [Divulgador] ";
		msg += GetNameLink(player);
		msg += ":|#00FF00";
		break;
			// Game Master Suporte
	case SEC_TRIAL_GM:
		msg += " |TInterface/ICONS/Achievement_Dungeon_UtgardePinnacle_10man.png:16|t [Game Master - Suporte] ";
		msg += GetNameLink(player);
		msg += ":|#990000";
		break;
			// Game Master Evento
	case SEC_JUNIOR_GM:
		msg += " |TInterface/ICONS/Achievement_Dungeon_UtgardePinnacle_Heroic.png:16|t [Game Master - Evento] ";
		msg += GetNameLink(player);
		msg += ":|#99FF00";
		break;
		// Game Master Lider
	case SEC_GAMEMASTER:
		msg += " |TInterface/ICONS/Achievement_Dungeon_UtgardePinnacle_Normal.png:16|t [Game Master - Lider] ";
		msg += GetNameLink(player);
		msg += ":|#FF3300";
		break;
		// Programador
	case SEC_DEVELOPER:
		msg += " |TInterface/ICONS/Achievement_Dungeon_UtgardePinnacle_25man.png:16|t [Programador] ";
		msg += GetNameLink(player);
		msg += ":|#CC0000";
		break;
		// Sub-Administrador
	case SEC_HEAD_OF_STAFF:
		msg += " |TInterface/ICONS/Achievement_Dungeon_UlduarRaid_IronDwarf_01.png:16|t [Sub-Administrador] ";
		msg += GetNameLink(player);
		msg += ":|#660000";
		break;
		// Administrador
	case SEC_ADMINISTRATOR:
		msg += " |TInterface/ICONS/Ability_Rogue_MasterOfSubtlety.png:16|t [Administrador] ";
		msg += GetNameLink(player);
		msg += ":|#333333";
		break;
		// Dono do Servidor
	case SEC_CONSOLE:
		msg += " |TInterface/ICONS/Ability_Rogue_MasterOfSubtlety.png:16|t ";
		msg += GetNameLink(player);
		msg += ":|#333333";
		break;
	}

	chat_string << msg << " " << message;

	char c_msg[1024];

	snprintf(c_msg, 1024, chat_string.str().c_str());

	sWorld->SendGlobalText(c_msg, NULL);
}

class cs_world_chat : public CommandScript
{
public:
	cs_world_chat() : CommandScript("cs_world_chat"){}

	static bool HandleWorldChatCommand(ChatHandler* pChat, const char * msg)
	{
		if(!*msg)
			return false;

		Player* pPlayer = pChat->GetSession()->GetPlayer();

		_SendWorldChat(pChat->GetSession()->GetPlayer(), msg);
		return true;
	}

	ChatCommand * GetCommands() const
	{
		static ChatCommand World_ChatCommandTable[] = 
		{
			{"chat", SEC_PLAYER, true, &HandleWorldChatCommand, "", NULL},
			{NULL, 0, false, NULL, "", NULL}
		};
		return World_ChatCommandTable;
	}
};

void AddSC_cs_world_chat()
{
	new cs_world_chat;
}