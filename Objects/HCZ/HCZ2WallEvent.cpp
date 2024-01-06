// ---------------------------------------------------------------------
// RSDK Project: S3KT
// Object Name: HCZ2WallEvent
// Decompiled by: Jd1206 || S3O
// ---------------------------------------------------------------------

#include "HCZ2WallEvent.hpp"

using namespace RSDK;

namespace GameLogic
{

RSDK_REGISTER_OBJECT(HCZ2WallEvent);

void HCZ2WallEvent::Update() { sVars->state.Run(this); }

void HCZ2WallEvent::LateUpdate()
{
    if (screenInfo->position.x > 0xBFF)
        this->Reset(TYPE_BLANK, NULL);
}

void HCZ2WallEvent::StaticUpdate() {}

void HCZ2WallEvent::Draw() {}

void HCZ2WallEvent::Create(void *data)
{
    if (!sceneInfo->inEditor) {
        this->active    = ACTIVE_NORMAL;
        this->visible   = true;
        this->drawGroup = Zone::sVars->hudDrawGroup;
    }
}

void HCZ2WallEvent::StageLoad()
{
    sVars->sfxRumble.Get("Stage/Rumble.wav");
    sVars->sfxImpact.Get("Stage/Impact4.wav");

    sVars->hitbox.left   = -1040;
    sVars->hitbox.top    = -288;
    sVars->hitbox.right  = 1040;
    sVars->hitbox.bottom = 288;

    TileLayer *moveLayer = RSDKTable->GetTileLayer(*(uint16 *)&Zone::sVars->moveLayer);
    sVars->moveLayer     = moveLayer;

    moveLayer->scrollInfo[0].scrollPos = 0;

    sVars->state.Set(&HCZ2WallEvent::State_Idle);
}

#if RETRO_INCLUDE_EDITOR
void HCZ2WallEvent::EditorDraw()
{ /* draw hitbox with DrawHelpers? */
}

void HCZ2WallEvent::EditorLoad()
{
    sVars->hitbox.left   = -1040;
    sVars->hitbox.top    = -288;
    sVars->hitbox.right  = 1040;
    sVars->hitbox.bottom = 288;
}
#endif

void HCZ2WallEvent::StaticLoad(Static *sVars) { RSDK_INIT_STATIC_VARS(HCZ2WallEvent); }

void HCZ2WallEvent::Serialize() {}

void HCZ2WallEvent::State_Idle()
{
    SET_CURRENT_STATE();

    Player *player = RSDK_GET_ENTITY(SLOT_PLAYER1, Player);

    if (player->position.x > TO_FIXED(1663) && Player::CheckCollisionTouch(player, this, &sVars->hitbox)) {
        player->collisionLayers |= Zone::sVars->moveLayerMask;
        sVars->state.Set(&HCZ2WallEvent::State_Move);
    }
}

void HCZ2WallEvent::State_Move()
{
    SET_CURRENT_STATE();

    Player *player = RSDK_GET_ENTITY(SLOT_PLAYER1, Player);
    int32 timer    = Zone::sVars->timer;
    Entity *pvVar3;
    Entity *pvVar2;

    if (!(timer & 3)) {
        Camera::ShakeScreen(0, 0, 1, 1, 1);
        timer = Zone::sVars->timer;
    }

    if (!(timer & 15)) {
        sVars->sfxRumble.Play(false, 255);
    }

    int32 iVar4 = 0x14000;

    if (player->position.x < TO_FIXED(0xA88))
        iVar4 = 0xE000;

    pvVar3 = (Entity *)RSDKTable->GetEntity(sceneInfo->entitySlot + 1);
    pvVar3->position.x += iVar4;

    pvVar2 = (Entity *)RSDKTable->GetEntity(sceneInfo->entitySlot + 2);
    pvVar2->position.x += iVar4;

    sVars->moveLayer->scrollInfo[0].scrollPos -= iVar4;
    TileLayer *pTVar3 = sVars->moveLayer;
    iVar4             = pTVar3->scrollInfo[0].scrollPos;

    if (iVar4 == -0x601 || iVar4 + 0x601 < 0 != (iVar4 ^ 0x601) < 0) {
        pTVar3->scrollInfo[0].scrollPos = 64000;
        sVars->sfxRumble.Stop();
        sVars->sfxImpact.Play(0, 255);
        Camera::ShakeScreen(0, 0, 7, 1, 1);
        this->Reset(TYPE_BLANK, NULL);
    }

    foreach_active(Player, player)
    {
        player->collisionLayers |= Zone::sVars->moveLayerMask;
        player->moveLayerPosition.x = sVars->moveLayer->scrollInfo[0].scrollPos;
    }
}

} // namespace GameLogic