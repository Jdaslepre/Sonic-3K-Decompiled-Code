// ---------------------------------------------------------------------
// RSDK Project: S3KT
// Object Name: S3K_SS_Palette
// Decompiled by: Jd1206 || S3O
// ---------------------------------------------------------------------

#include "Game.hpp"

using namespace RSDK;

namespace GameLogic
{

RSDK_REGISTER_OBJECT(S3K_SS_Palette);

// Standard Entity Events

void S3K_SS_Palette::Update() {}

void S3K_SS_Palette::LateUpdate() {}

void S3K_SS_Palette::StaticUpdate() {}

void S3K_SS_Palette::Draw() {}

void S3K_SS_Palette::Create(void *data)
{
    // S3O doesn't destroy this object, like Sonic Mania
}

void S3K_SS_Palette::StageLoad()
{
    sVars->skyAlpha   = 256;
    sVars->globeAlpha = 128;

    foreach_all(S3K_SS_Palette, palette)
    {
        if (palette->useStageConfig) {
            // Used for Randomized modes
            sVars->startColorID = 16 * palette->paletteID;
        }
        else {
            // Used for the 32 Bonus Stages
            paletteBank[1].SetEntry(0, palette->playfieldA);
            paletteBank[1].SetEntry(1, palette->playfieldB);
            paletteBank[1].SetEntry(2, palette->bgColor1);
            paletteBank[1].SetEntry(3, palette->bgColor2);
            paletteBank[1].SetEntry(4, palette->bgColor3);
        }

        sVars->skyAlpha   = palette->skyAlpha;
        sVars->globeAlpha = palette->globeAlpha;
    }
}

#if RETRO_INCLUDE_EDITOR
void S3K_SS_Palette::EditorDraw()
{
    this->animator.SetAnimation(sVars->aniFrames, 0, true, 0);
    this->animator.DrawSprite(NULL, false);
}

void S3K_SS_Palette::EditorLoad() { sVars->aniFrames.Load("3K_Special/PaletteIcon.bin", SCOPE_STAGE); }
#endif

void S3K_SS_Palette::StaticLoad(Static *sVars) { RSDK_INIT_STATIC_VARS(S3K_SS_Palette); }

void S3K_SS_Palette::Serialize()
{
    RSDK_EDITABLE_VAR(S3K_SS_Palette, VAR_BOOL, useStageConfig);
    RSDK_EDITABLE_VAR(S3K_SS_Palette, VAR_INT32, paletteID);
    RSDK_EDITABLE_VAR(S3K_SS_Palette, VAR_UINT8, skyAlpha);
    RSDK_EDITABLE_VAR(S3K_SS_Palette, VAR_UINT8, globeAlpha);
    RSDK_EDITABLE_VAR(S3K_SS_Palette, VAR_COLOR, playfieldA);
    RSDK_EDITABLE_VAR(S3K_SS_Palette, VAR_COLOR, playfieldB);
    RSDK_EDITABLE_VAR(S3K_SS_Palette, VAR_COLOR, bgColor1);
    RSDK_EDITABLE_VAR(S3K_SS_Palette, VAR_COLOR, bgColor2);
    RSDK_EDITABLE_VAR(S3K_SS_Palette, VAR_COLOR, bgColor3);
}

} // namespace GameLogic