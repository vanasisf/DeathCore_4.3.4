class your_token_item : public ItemScript
{
public: your_token_item() : ItemScript("your_token_item") { }
       
  bool OnUse(Player* player, Item* item, SpellCastTargets const& /*targets*/)
  {
   if (player->GetSession()->GetSecurity() == SEC_VIP)
   {
    player->GetSession()->SendNotification("Você já é VIP!");
    return true;
   }
   else
   {
      QueryResult insertvip = LoginDatabase.PQuery("REPLACE INTO `account_access` VALUES(%u, 1, -1)", player->GetSession()->GetAccountId());
   player->GetSession()->SetSecurity(SEC_VIP);
   player->GetSession()->SendNotification("Agora a sua conta é VIP!");
   player->DestroyItemCount(item->GetEntry(), 1, true, false);
   return true;
     }
       }
};
 
void AddSC_your_token_item()
{
 new your_token_item();
}