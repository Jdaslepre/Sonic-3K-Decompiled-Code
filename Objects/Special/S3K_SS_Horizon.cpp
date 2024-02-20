// ---------------------------------------------------------------------
// RSDK Project: S3KT
// Object Name: S3K_SS_Horizon
// Decompiled by: Jd1206 || S3O
// ---------------------------------------------------------------------

#include "Game.hpp"

using namespace RSDK;

namespace GameLogic
{

RSDK_REGISTER_OBJECT(S3K_SS_Horizon);

// Standard Entity Events

void S3K_SS_Horizon::Update() {}

void S3K_SS_Horizon::LateUpdate() {}

void S3K_SS_Horizon::StaticUpdate() {}

void S3K_SS_Horizon::Draw() { this->animator.DrawSprite(&this->position, false); }

void S3K_SS_Horizon::Create(void *data)
{
    this->active        = ACTIVE_NORMAL;
    this->updateRange.x = TO_FIXED(80);
    this->updateRange.y = TO_FIXED(80);
    this->visible       = true;
    this->drawGroup     = 1;

    // instead of destroying the object, S3O instead checks if you're in the RSDK editor, and
    // only sets the animation if so
    if (sceneInfo->inEditor)
        this->animator.SetAnimation(sVars->aniFrames, 0, false, 0);
}

void S3K_SS_Horizon::StageLoad() 
{
    // thought this object load 3K_Special/S3K_SS_Horizon.bin? you thought wrong
    sVars->aniFrames.Load("S3K_SS_Horizon.bin", SCOPE_STAGE);

    // it isnt reset in a dedicated slot either, this code just doesnt exist in origins
    // (SLOT_SPECIAL_HORIZON isnt defined so this code doesnt work)
    // RSDKTable->ResetEntitySlot(SLOT_SPECIAL_HORIZON, sVars->classID, NULL);
}

#if RETRO_INCLUDE_EDITOR
void S3K_SS_Horizon::EditorDraw() {}

void S3K_SS_Horizon::EditorLoad() {}
#endif

void S3K_SS_Horizon::StaticLoad(Static *sVars) {}

void S3K_SS_Horizon::Serialize() {}

} // namespace GameLogic