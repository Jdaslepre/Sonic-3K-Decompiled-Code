// ---------------------------------------------------------------------
// RSDK Project: S3KT
// Object Name: S3K_CompMenu
// Decompiled by: Jd1206 || S3O
// ---------------------------------------------------------------------

#include "S3K_CompMenu.hpp"

using namespace RSDK;

namespace GameLogic
{

RSDK_REGISTER_OBJECT(S3K_CompMenu);

void S3K_CompMenu::Update() {}

void S3K_CompMenu::LateUpdate() {}

void S3K_CompMenu::StaticUpdate() {}

void S3K_CompMenu::Draw() {}

void S3K_CompMenu::Create(void *data)
{
    this->active    = ACTIVE_ALWAYS;
    this->visible   = true;
    this->drawGroup = 15;
    this->drawFX    = FX_FLIP;

    if (!sceneInfo->inEditor) {
        // this->state.Set(&S3K_CompMenu::State_Init);
        // this->stateDraw.Set(&S3K_CompMenu::Draw_Fade);
    }
}

void S3K_CompMenu::StageLoad()
{
    sVars->sfxButton.Get("Stage/Button.wav");
    sVars->sfxStarPost.Get("Global/StarPost.wav");
    sVars->sfxFail  .Get("Global/Fail.wav");
    sVars->sfxEvent.Get("Special/Event.wav");
   
    // UIText->aniFrames.Load("3K_Menu/Fonts.bin", SCOPE_STAGE);

    sVars->field20_0x14 = 0;
    sVars->field_0x24   = 0;
}

#if RETRO_INCLUDE_EDITOR
void S3K_CompMenu::EditorDraw() {}

void S3K_CompMenu::EditorLoad() {}
#endif

void S3K_CompMenu::StaticLoad(Static *sVars)
{
    RSDK_INIT_STATIC_VARS(S3K_CompMenu);
    sVars->classID = 0;
    sVars->active  = ACTIVE_NEVER;
}

void S3K_CompMenu::Serialize() {}

} // namespace GameLogic