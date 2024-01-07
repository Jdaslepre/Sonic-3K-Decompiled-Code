// ---------------------------------------------------------------------
// RSDK Project: S3KT
// Object Name: S3K_AIZIntro
// Object Author:
// Decompiled by: Jd1206 || S3O
// ---------------------------------------------------------------------

#include "S3K_AIZIntro.hpp"

using namespace RSDK;

namespace GameLogic
{

RSDK_REGISTER_OBJECT(S3K_AIZIntro);

void S3K_AIZIntro::Update() { this->state.Run(this); }

void S3K_AIZIntro::LateUpdate() {}

void S3K_AIZIntro::StaticUpdate() {}

void S3K_AIZIntro::Draw() { this->animator.DrawSprite(&this->position, false); }

void S3K_AIZIntro::Create(void *data)
{
    this->active        = ACTIVE_NORMAL;
    this->updateRange.x = TO_FIXED(128);
    this->updateRange.y = TO_FIXED(128);
    this->visible       = true;
    this->drawGroup     = 1;

    if (!sceneInfo->inEditor) {
        this->state.Set(&S3K_AIZIntro::State_Init);
    }
    else
    {
        this->animator.SetAnimation(sVars->aniFrames, 0, false, 0);
    }
}

void S3K_AIZIntro::StageLoad() { sVars->aniFrames.Load("S3K_AIZIntro.bin", SCOPE_STAGE); }

#if RETRO_INCLUDE_EDITOR
void S3K_AIZIntro::EditorDraw() { this->animator.DrawSprite(&this->position, false); }

void S3K_AIZIntro::EditorLoad() { sVars->aniFrames.Load("S3K_AIZIntro.bin", SCOPE_STAGE); }
#endif

void S3K_AIZIntro::StaticLoad(Static *sVars) { RSDK_INIT_STATIC_VARS(S3K_AIZIntro); }

void S3K_AIZIntro::Serialize() {}

void S3K_AIZIntro::State_Init()
{
    SET_CURRENT_STATE();

    this->animator.SetAnimation(sVars->aniFrames, 0, false, 0);
    this->state.Set(&S3K_AIZIntro::State_Init);
}

void S3K_AIZIntro::State_Idle() { SET_CURRENT_STATE(); }

} // namespace GameLogic