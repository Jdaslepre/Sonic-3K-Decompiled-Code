// ---------------------------------------------------------------------
// RSDK Project: S3KT
// Object Name: S3K_MenuSetup
// Object Author:
// ---------------------------------------------------------------------

#include "S3K_MenuSetup.hpp"
#include "S3K_SaveMenu.hpp"
#include "../Global/SaveGame.hpp"

using namespace RSDK;

namespace GameLogic
{

RSDK_REGISTER_OBJECT(S3K_MenuSetup);

void S3K_MenuSetup::Update() {}

void S3K_MenuSetup::LateUpdate() {}

void S3K_MenuSetup::StaticUpdate()
{
    char unknown = sVars->unknown1;

    if (unknown == 2) {
        sVars->unknown1 = 1;
    }

    if (unknown == 1 && globals->saveLoaded == STATUS_OK) {
        sVars->unknown1 = 2;
    }
    else if (unknown == 0) {
        // SaveGame::LoadFile(SaveGame::SaveLoadedCB);
        sVars->unknown1 += 1;
    }
}

void S3K_MenuSetup::Draw() {}

void S3K_MenuSetup::Create(void *data)
{
    this->active    = ACTIVE_ALWAYS;
    this->visible   = true;
    this->drawGroup = 4;
}

void S3K_MenuSetup::StageLoad()
{

    if (Graphics::GetVideoSetting(VIDEOSETTING_SCREENCOUNT) > 1)
        Graphics::SetVideoSetting(VIDEOSETTING_SCREENCOUNT, 1);

    sVars->aniFrames.Load("3K_Menu/Fonts.bin", SCOPE_STAGE);

    sVars->unknown1 = 0;
    sVars->unknown2 = ((long)sceneInfo->listData + sceneInfo->listPos * 0x48 + 0x40) + -0x31;

    if (!Stage::CheckSceneFolder("3K_Menu")) {

        if (!Stage::CheckSceneFolder("3K_Menu_Comp"))
            goto LAB_71002e7050;

        paletteBank[0].Copy(1, 128, 128, 96);

        // RSDKTable->ResetEntitySlot(0, S3K_CompMenu::sVars->classID, NULL);
    }
    else {
        RSDKTable->ResetEntitySlot(0, S3K_SaveMenu::sVars->classID, NULL);
    }

LAB_71002e7050:
    globals->recallEntities = 0;
    S3K_MenuSetup::somethingNoSave();
}

#if RETRO_INCLUDE_EDITOR
void S3K_MenuSetup::EditorDraw() {}

void S3K_MenuSetup::EditorLoad() {}
#endif

void S3K_MenuSetup::StaticLoad(Static *sVars)
{
    RSDK_INIT_STATIC_VARS(S3K_MenuSetup);
    sVars->classID = 0;
    sVars->active  = ACTIVE_NEVER;
}

void S3K_MenuSetup::Serialize()
{
    RSDK_EDITABLE_VAR(S3K_MenuSetup, VAR_UINT8, id);
    RSDK_EDITABLE_VAR(S3K_MenuSetup, VAR_VECTOR2, size);
}

void S3K_MenuSetup::somethingNoSave()
{
    memset(globals->noSaveSlot, 0, 0x400);
    globals->replayWriteBuffer[30] = 0;
}

} // namespace GameLogic