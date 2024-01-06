// ---------------------------------------------------------------------
// RSDK Project: S3KT
// Object Name: S3K_FBZSetup
// Object Author:
// ---------------------------------------------------------------------

#include "S3K_FBZSetup.hpp"

using namespace RSDK;

namespace GameLogic
{

RSDK_REGISTER_OBJECT(S3K_FBZSetup);

void S3K_FBZSetup::Update() {}

void S3K_FBZSetup::LateUpdate() {}

void S3K_FBZSetup::StaticUpdate() {}

void S3K_FBZSetup::Draw() {}

void S3K_FBZSetup::Create(void *data) {}

void S3K_FBZSetup::StageLoad()
{
    
    GenericTrigger::sVars->callbacks[0].Set(&S3K_FBZSetup::TriggerExterior);
    GenericTrigger::sVars->callbacks[1].Set(&S3K_FBZSetup::TriggerInterior);
    GenericTrigger::sVars->callbacks[2].Set(&S3K_FBZSetup::TriggerScreenLock);
    GenericTrigger::sVars->callbacks[3].Set(&S3K_FBZSetup::TriggerAbortBoundMarker);
    GenericTrigger::sVars->callbacks[4].Set(&S3K_FBZSetup::TriggerIntro);
}

#if RETRO_INCLUDE_EDITOR
void S3K_FBZSetup::EditorDraw() {}

void S3K_FBZSetup::EditorLoad() {}
#endif

void S3K_FBZSetup::StaticLoad(Static *sVars) { RSDK_INIT_STATIC_VARS(S3K_FBZSetup); }

void S3K_FBZSetup::Serialize() {}

void S3K_FBZSetup::TriggerExterior()
{
    SET_CURRENT_STATE();

    SceneLayer::GetTileLayer(3)->drawGroup[GenericTrigger::sVars->playerID] = 16;
    SceneLayer::GetTileLayer(4)->drawGroup[GenericTrigger::sVars->playerID] = 6;
}

void S3K_FBZSetup::TriggerInterior()
{
    SET_CURRENT_STATE();

    SceneLayer::GetTileLayer(3)->drawGroup[GenericTrigger::sVars->playerID] = 6;
    SceneLayer::GetTileLayer(4)->drawGroup[GenericTrigger::sVars->playerID] = 16;
}

void S3K_FBZSetup::TriggerScreenLock()
{
    SET_CURRENT_STATE();
    // add code
}

void S3K_FBZSetup::TriggerAbortBoundMarker()
{
    SET_CURRENT_STATE();
    // add code
}

// Handles the little um.
// The intro where they jump
// up onto the stage in FBZ

void S3K_FBZSetup::TriggerIntro()
{
    SET_CURRENT_STATE();

    int32 unknown1;

    foreach_active(Player, player)
    {
        if (GenericTrigger::sVars->ptr->activationLimit == 2) {
            player->Action_Roll();

            unknown1 = player->playerID;
            player->position.y += unknown1 * 80;

            player->velocity.x = 0x8000;
            player->velocity.y = -TO_FIXED(8);

            // ?
            // player->velocity.y = unknown1 * -2 + -8;
            // player->position.x += unknown1 * -8;
        }
        else {
            player->animator.SetAnimation(player->aniFrames, Player::ANI_JUMP, true, 0);

            if (player->characterID != Player::PLAYER_CHAR_TAILS)
                player->animator.frameID >>= 1;
        }
    }
}

} // namespace GameLogic