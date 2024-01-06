// ---------------------------------------------------------------------
// RSDK Project: S3KT
// Object Name: S3K_SaveMenu
// Object Author:
// ---------------------------------------------------------------------

#include "S3K_SaveMenu.hpp"
#include "S3K_SaveSlot.hpp"
#include "../Global/Localization.hpp"

using namespace RSDK;

namespace GameLogic
{

RSDK_REGISTER_OBJECT(S3K_SaveMenu);

void S3K_SaveMenu::Update()
{
    this->state.Run(this);

    if (this->stateDraw.Matches(StateMachine_None))
        sVars->field16_0x10 += 1;
}

void S3K_SaveMenu::LateUpdate() {}

void S3K_SaveMenu::StaticUpdate()
{
    int32 someVar1;
    int32 someVar2;

    TileLayer *BGLayer = RSDKTable->GetTileLayer(RSDKTable->GetTileLayerID("BG"));

    BGLayer->scrollPos               = 0x78 - screenInfo->center.y;
    BGLayer->scrollInfo[0].scrollPos = 0xD8 - screenInfo->center.x;

    if (!S3K_MenuSetup::sVars->unknown2) {
        someVar2 = sVars->field16_0x10;
        someVar1 = someVar2;

        if (someVar2 < 0)
            someVar1 = someVar2 + 1;

        paletteBank[0].Copy(2, ((char)someVar2 - ((uint8)someVar1 & 0xFF)) * 16 + 224, 160, 16); // spooky code
    }

    globals->replayWriteBuffer[0x1ee1c] += 1U & 0x7fff;
}

void S3K_SaveMenu::Draw()
{
    this->stateDraw.Run(this);

    uint8 uVar1;
    uint8 uVar3;
    int32 stringWidth;
    void *pvVar5;
    int32 uVar6; // ulong
    Vector2 local_28;

    local_28.y = TO_FIXED(screenInfo->size.y) - 0x140000;
    stringWidth =
        RSDKTable->GetStringWidth(S3K_MenuSetup::sVars->aniFrames.aniFrames, 1, &this->dataSelectString, 0, this->dataSelectString.length, 0);
    local_28.x = screenInfo->center.x * 0x10000 + stringWidth * -0x8000;
    RSDKTable->DrawText(&this->field151_0x98, &local_28, &this->dataSelectString, 0, (int32)(this->dataSelectString).length, 0, 0, NULL, NULL, true);

    if (this->state.Matches(StateMachine_None)) {
        uVar3 = sVars->field16_0x10;
        uVar1 = uVar3 + 3;
        if (-1 < (int)uVar3) {
            uVar1 = uVar3;
        }
        if ((uVar1 >> 2 & 1) != 0) {
            pvVar5                 = RSDKTable->GetEntity(*(uint16 *)&this->field_0xdc);
            this->animator.frameID = (uint8)(*(char *)((long)pvVar5 + 0x174) != '\x01');
            local_28.y             = *(int *)&this->field_0xd8;
            local_28.x             = (0x68 << 16) | (local_28.x & 0xFFFF); // CONCAT22(0x68, local_28.x);

            this->animator.DrawSprite(&local_28, false);
        }
    }
}

void S3K_SaveMenu::Create(void *data)
{
    this->active    = ACTIVE_ALWAYS;
    this->visible   = true;
    this->drawGroup = 15;
    this->drawFX    = FX_FLIP;

    if (!sceneInfo->inEditor) {
        this->state.Set(&S3K_SaveMenu::State_Init);
        this->stateDraw.Set(&S3K_SaveMenu::Draw_Fade);

        RSDKTable->CopyString(&this->dataSelectString, &Localization::sVars->strings[Localization::STR_DATASELECT]);
        RSDKTable->SetSpriteString(S3K_MenuSetup::sVars->aniFrames.aniFrames, 1, &this->dataSelectString);
        this->field151_0x98.SetAnimation(S3K_MenuSetup::sVars->aniFrames, 1, false, 0);
        this->animator.SetAnimation(S3K_SaveSlot::sVars->aniFrames, 2, false, 0);
        this->fade = 512;
    }
}

void S3K_SaveMenu::StageLoad()
{
    sVars->sfxButton.Get("Stage/Button.wav");
    sVars->sfxSlot.Get("Stage/SlotMachine.wav");
    sVars->sfxBumper.Get("Stage/Bumper3.wav");
    sVars->sfxWarp.Get("Global/SpecialWarp.wav");

    sVars->field16_0x10 = 0;
    sVars->field18_0x15 = 0;
}

#if RETRO_INCLUDE_EDITOR
void S3K_SaveMenu::EditorDraw() {}

void S3K_SaveMenu::EditorLoad() {}
#endif

void S3K_SaveMenu::StaticLoad(Static *sVars)
{
    RSDK_INIT_STATIC_VARS(S3K_SaveMenu);
    sVars->classID = 0;
    sVars->active  = ACTIVE_NEVER;
}

void S3K_SaveMenu::Serialize() {}

void S3K_SaveMenu::State_Init()
{
    SET_CURRENT_STATE();

    char cVar1;
    uint8 uVar2;
    uint8 uVar3;
    S3K_SaveSlot *saveSlot = nullptr;
    bool32 sceneCheck;
    int32 iVar5;
    long lVar6;
    Entity *local_40;
    uint16 local_38;
    bool32 local_34;

    // just. just set it for now
    globals[1].replayWriteBuffer[0xcf56] = 0;

    cVar1 = S3K_MenuSetup::sVars->unknown1;
    if (globals[1].replayWriteBuffer[0xcf56] == 0) {
        if (cVar1 != '\0') {
            this->state.Set(&S3K_SaveMenu::State_FadeIn);

            /*
            foreach_active(S3K_SaveSlot, slot)
            {
                saveSlot = slot;

                if (!slot) // did i do something wrong, or is it checking if !slot in a check for slots
                    goto LAB_71002e34ac;
            }
            /*
            if (S3K_SaveSlot == (S3K_SaveSlot *)0x0) {
                local_38 = 0;
            }
            else {
                local_38 = *(uint16 *)S3K_SaveSlot;
            }
            p_Var7   = RSDKTable->GetAllEntities;
            local_40 = (void *)0x0;
            do {
                local_34 = (*p_Var7)(local_38, &local_40);
                pvVar4   = local_40;
                if (local_34 == 0)
                    goto LAB_71002e34ac;
            } while ((*(char *)((long)local_40 + 0x174) != '\x01') || (*(char *)((long)local_40 + 0x175) != '\0'));
            */

            // something's def wrong here

            // this->field_0xd8 = saveSlot->position.x;
            // iVar5            = RSDKTable->GetEntitySlot(saveSlot);
            // this->field_0xdc = iVar5;
            // *(undefined *)((long)pvVar4 + 0x176) = 1;
            RSDKTable->BreakForeachLoop();
        LAB_71002e34ac:
            Music::PlayTrack(0);

            uVar2 = 0x430 - screenInfo->size.x;
            uVar3 = this->field_0xda - screenInfo->center.x;

            if ((int)uVar3 <= (int)uVar2)
                uVar2 = uVar3;

            screenInfo->position.x = uVar2 & ((int)uVar2 >> 0x1F ^ 0xffffffffU);
        }
    }
    else if (cVar1 != '\0') {
        // p_Var8 = RSDKTable->NotifyCallback;
        if (globals[1].replayWriteBuffer[0xcf49] == 2) {
            // if (p_Var8 != (_func_285 *)0x0) {
            // (*p_Var8)(0x3ea, 0, 0, 0);
            // (*RSDKTable->NotifyCallback)(0x3ed, 0, 0, 0);
        }
    }
    else {
        // if (p_Var8 != (_func_285 *)0x0) {
        // (*p_Var8)(0x3ea, 0, 0, 0);
        // }

        /*
        lVar6 = FUN_7100198458((long)*(char *)(globals->replayWriteBuffer + 0x16b58));
        if (*(byte *)(lVar6 + 0xbc) < 6) {
            iVar5 = *(int32 *)(&DAT_7100ee5bfc + (long)(int)(char)*(byte *)(lVar6 + 0xbc) * 4);
        }
        else {
            iVar5 = 0;
        }

        */

        // globals->playerID = iVar5;
        Stage::SetScene("Regular Stages", "");
        // sceneInfo->listPos += *(short *)(lVar6 + 0x176);

        if (!Stage::CheckValidScene) {
            Stage::SetScene("Regular Stages", "");
            // *(undefined2 *)(lVar6 + 0x176) = 0;
        }
    }

    // this->state.Set(&S3K_SaveMenu::GoToStage);
    this->fade = 0x280;
}

/*
void S3K_SaveMenu::State_Init()
{
    SET_CURRENT_STATE();

    int32 uVar2;
    int32 uVar3;

    this->state.Set(&S3K_SaveMenu::State_FadeIn);

    uVar2 = 0x430 - screenInfo->size.x;
    uVar3 = this->field_0xda - screenInfo->center.x;

    if ((int)uVar3 <= (int)uVar2)
        uVar2 = uVar3;

    screenInfo->position.x = uVar2 & ((int)uVar2 >> 0x1f ^ 0xffffffffU);
    Music::PlayTrack(0);
}
*/

void S3K_SaveMenu::State_FadeIn()
{
    SET_CURRENT_STATE();

    this->fade -= 16;

    if (this->fade > 0)
        return;

    this->state.Set(&S3K_SaveMenu::State_Navigate);
    this->stateDraw.Set(StateMachine_None);

    Graphics::FillScreen(0, 0, 0, 0);
}

void S3K_SaveMenu::State_Navigate() { SET_CURRENT_STATE(); }

void S3K_SaveMenu::Draw_Fade()
{
    SET_CURRENT_STATE();
    Graphics::FillScreen(0, this->fade, this->fade - 128, this->fade - 256);
}

} // namespace GameLogic