/*
    <--------------------------------------------------------------------------->
    - Developer(s): JessiqueBA
    - Complete: %100
    - ScriptName: 'vipmall_security'
    - Comment: Untested.
    - Shared for:Emudevs by Synth
    <--------------------------------------------------------------------------->
*/ 
enum ForbiddenAreas
{
    AREA_VIP_MALL            = 3817,  // Testing Zone
    AREA_VIP_ISLAND          = 4990,  // South Seas (Tanaris)
    AREA_GM_ISLAND           = 876    // GM Island
};
     
class vipmall_security : public PlayerScript
{
public:
    vipmall_security() : PlayerScript("vipmall_security") {}
     
    void OnUpdateZone(Player* player, uint32 newZone, uint32 newArea)
    {
        switch (newArea)
        {
            case AREA_VIP_MALL:
            case AREA_VIP_ISLAND:
                // if player is vip and reach the vipmall..
                if (player->GetSession()->GetSecurity() >= 1) // Or RBAC 'HasPermission(rbac::PERMISSION_NAME);'
                    return;
                player->TeleportTo(0, -2723.567871f, -5356.419434f, 177.281921f, 2.535085f); // Teleport to dueling zone
                break;
            case AREA_GM_ISLAND:
                // Allow acces to GM island only for staff members
                if (player->GetSession()->GetSecurity() >= 2) // Or RBAC 'HasPermission(rbac::PERMISSION_NAME);'
                    return;
                player->TeleportTo(0, -2723.567871f, -5356.419434f, 177.281921f, 2.535085f); // Teleport to dueling zone
                break;
        }
    }
};
     
void AddSC_vipmall_security()
{
    new vipmall_security();
}