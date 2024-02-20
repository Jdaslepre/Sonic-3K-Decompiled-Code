// ---------------------------------------------------------------------
// RSDK Project: S3KT
// Object Name: TitleCard
// Decompiled by: Jd1206 || S3O
// ---------------------------------------------------------------------

#include "GameObjects.hpp"

using namespace RSDK;

namespace GameLogic
{

RSDK_REGISTER_OBJECT(TitleCard);

void TitleCard::Update() { this->state.Run(this); }

void TitleCard::LateUpdate() {}

void TitleCard::StaticUpdate() {}

void TitleCard::Draw()
{
    uint16 stringLength = 0;
    String *string      = NULL;
    Vector2 drawPos;

    if (!this->noBanner) {
        drawPos.x = this->bannerPos.x;
        drawPos.y = this->bannerPos.y;
        Graphics::DrawRect((drawPos.x >> 16) - 32, 0, 64, drawPos.y >> 16, 0xE00000, 255, FX_NONE, true);
        this->gameNameAnimator.DrawSprite(&drawPos, true);
    }

    // originally (this->actID - 2) > 2, didn't wanna work for
    // some reason so here's some custom stuff
    if (this->actID < 3) {
        drawPos.x = this->actIDPos.x;
        drawPos.y = this->actIDPos.y;
        this->actIDAnimator.DrawSprite(&drawPos, true);
    }

    this->strName.GetWidth(sVars->aniFrames, 1, 0, (int32)(this->strName).length, 0);

    drawPos.x = this->primaryWordPos.x;
    drawPos.y = this->primaryWordPos.y;
    this->fontAnimator.DrawString(&drawPos, &this->strName, 0, (int32)(this->strName).length, 2, 0, 0, true);

    if (this->actID < 3) {
        drawPos.x    = this->secondaryWordPos.x;
        drawPos.y    = this->secondaryWordPos.y;
        string       = &sVars->secondaryWord;
        stringLength = sVars->secondaryWord.length;
    }
    else if (this->actID != 3) {
        drawPos.x    = this->secondaryWordPos.x;
        drawPos.y    = this->secondaryWordPos.y;
        string       = &sVars->strName;
        stringLength = sVars->strName.length;
    }

    this->fontAnimator.DrawString(&drawPos, string, 0, (int32)stringLength, 2, 0, 0, true);
}

void TitleCard::Create(void *data)
{
    int32 unknown2;
    int32 unknown6;

    if (globals->storedOverrideUnknown == 2) {
        this->Destroy();
    }
    else {
        this->active    = ACTIVE_ALWAYS;
        this->visible   = true;
        this->drawGroup = Zone::sVars->hudDrawGroup + 1;

        if (sceneInfo->inEditor) {
            this->gameNameAnimator.SetAnimation(sVars->aniFrames, 0, false, 3);
        }
        else {

            if (!this->strName.chars)
                this->strName.Init("UNTITLED", 256);

            this->strName.SetSpriteString(sVars->aniFrames, 1);
            int32 stringWidth = this->strName.GetWidth(sVars->aniFrames, 1, 0, this->field_0x80, 0);

            this->storedStrWidth = stringWidth;

            this->field_0x9c = 1;

            // Calculate the difference between RSDK and the SEGA Genesis' resolution
            // these specifically use screenInfo->size... instead of preset ones (424, 240)
            int32 screenXCenter = TO_FIXED_F((screenInfo->size.x - 320) / 2);
            int32 screenYCenter = TO_FIXED_F((screenInfo->size.y - 224) / 2);

            // max banner y
            int32 mby = screenYCenter + TO_FIXED(176);

            this->bannerPos.x = screenXCenter + TO_FIXED(96);
            this->bannerPos.y = mby % 11;

            this->field_0x98 = mby; // rename field_0x98 to maxBannerY or something

            this->field_0xa0 = mby / 11.0; // controls the banner y speed based on the screen's Y size

            int32 unknown1         = screenXCenter + TO_FIXED(288);
            unknown6         = (int)(((float)screenInfo->size.x / 320.0) * 1048576.0);
            // unknown6 = TO_FIXED_F((screenInfo->size.x / 320) * 16);

            this->primaryWordPos.x = unknown1 + unknown6 * 20;
            this->primaryWordPos.y = screenYCenter + TO_FIXED(120);
            this->field_0xac       = screenXCenter + TO_FIXED(288); // max x position of the first word (Zone name)
            this->field_0xb0       = 3;
            this->field_0xb4       = unknown6;

            // sorry for this horrible looking code, it's not *that* bad i think...
            if (this->noBanner)
                this->field_0xac = TO_FIXED((screenInfo->size.x + (screenInfo->size.x < 0) + stringWidth + (stringWidth < 0)) >> 1);

            this->secondaryWordPos.x = unknown1 + unknown6 * 24;
            this->secondaryWordPos.y = screenYCenter + TO_FIXED(0x98);

            this->field_0xc4 = 5;
            this->actIDPos.y = screenYCenter + TO_FIXED(0xA0);
            this->field_0xd4 = screenXCenter + TO_FIXED(0xE8);
            this->field_0xd8 = 7;
            this->field_0xc0 = unknown1;
            this->field_0xe0 = 90;
            this->field_0xc8 = unknown6;
            this->actIDPos.x = screenXCenter + TO_FIXED(0xE8) + unknown6 * 28;
            this->field_0xdc = unknown6;

            if (globals->skipSaveSelect == 4 || globals->skipSaveSelect == 2)
                sceneInfo->timeEnabled = true;
            else
                this->state.Set(&TitleCard::State_Init);
        }
    }
}

void TitleCard::StageLoad()
{
    String strName;

    sVars->aniFrames.Load("3K_Global/TitleCard.bin", SCOPE_STAGE);
    strName.Init("ZONE", 0);

    String *pSVar1              = &sVars->secondaryWord;
    sVars->secondaryWord.length = strName.length;
    pSVar1->size                = strName.size;
    sVars->secondaryWord.chars  = strName.chars;

    strName.Init("ZOO", 0);
    // RSDKTable->InitString(&strName, "ZOO", 0);

    pSVar1                  = &sVars->secondaryWord;
    String *pSVar2          = &sVars->strName;
    (sVars->strName).length = strName.length;
    pSVar2->size            = strName.size;
    (sVars->strName).chars  = strName.chars;
    pSVar1->SetSpriteString(sVars->aniFrames, 1);
    sVars->strName.SetSpriteString(sVars->aniFrames, 1);
}

#if RETRO_INCLUDE_EDITOR
void TitleCard::EditorDraw() {}

void TitleCard::EditorLoad() {}
#endif

void TitleCard::StaticLoad(Static *sVars) { RSDK_INIT_STATIC_VARS(TitleCard); }

void TitleCard::Serialize()
{
    RSDK_EDITABLE_VAR(TitleCard, VAR_STRING, strName);
    RSDK_EDITABLE_VAR(TitleCard, VAR_UINT8, actID);
    RSDK_EDITABLE_VAR(TitleCard, VAR_BOOL, noBanner);
}

void TitleCard::State_Init()
{
    SET_CURRENT_STATE();

    uint8 uVar1;
    SpriteAnimation aniFrames;
    int32 uVar2;
    int32 frameID;
    uint8 uVar3;

    this->gameNameAnimator.SetAnimation(sVars->aniFrames, 0, false, 0);

    uVar3 = 1;
    if (globals->starpostStyle != 6)
        uVar3 = 2;

    uVar1 = 0;
    if (globals->starpostStyle != 5)
        uVar1 = uVar3;

    this->field_0xf8 = uVar1;

    this->fontAnimator.SetAnimation(sVars->aniFrames, 1, false, 0);
    frameID = this->actID;
    uVar2   = this->actID;

    if (!globals->atlCameraBoundsL[0] || uVar2 != 1) {
        aniFrames = sVars->aniFrames;

        if (uVar2 > 4)
            frameID = uVar2 - 5;
    }
    else {
        this->actID = 0;
        aniFrames   = sVars->aniFrames;
        frameID     = 0;
    }

    this->actIDAnimator.SetAnimation(aniFrames, 2, false, frameID);

    NotifyCallback(NOTIFY_TITLECARD_INIT, 0, 0, 0);

    this->state.Set(&TitleCard::State_MoveIn);

    if (globals->storedOverrideUnknown) {
        this->storedFade = NULL;
    }
    else {
        FXFade *fade = CREATE_ENTITY(FXFade, NULL, this->position.x, this->position.y);
        fade->state.Set(StateMachine_None);
        fade->timer      = 512;
        fade->speedIn    = 32;
        fade->drawGroup  = Zone::sVars->hudDrawGroup;
        fade->active     = true;
        this->storedFade = fade;

        Stage::SetEngineState(ENGINESTATE_PAUSED);
    }
}

void TitleCard::State_MoveIn()
{
    SET_CURRENT_STATE();

    int iVar1;
    int iVar2;
    uint8 bVar3;
    uint8 uVar4;

    bVar3 = this->field_0xe2; // timer?
    uVar4 = (uint8)bVar3;
    if (bVar3 == 0xf) {
        this->state.Set(&TitleCard::State_Wait);
        return;
    }
    if (((bVar3 & 1) == 0) && (iVar2 = this->field_0x98, *(short *)&this->field_0x96 < iVar2)) {
        iVar1 = this->field_0xa0 + this->bannerPos.y;
        if (iVar1 < iVar2) {
            this->bannerPos.y = iVar1;
            goto LAB_71001a56ac;
        }
        uVar4             = bVar3 | 1;
        this->bannerPos.y = iVar2;
        this->field_0xe2  = (char)uVar4;
        bVar3             = bVar3 & 2;
    }
    else {
    LAB_71001a56ac:
        bVar3 >>= 1 & 1;
    }
    if (bVar3 == 0) {
        if (this->field_0xac < this->primaryWordPos.x) {
            if (this->field_0xac < (this->primaryWordPos.x - this->field_0xb4)) {
                this->primaryWordPos.x -= this->field_0xb4;
            }
            else {
                uVar4                  = uVar4 | 2;
                this->primaryWordPos.x = this->field_0xac;
                this->field_0xe2       = (char)uVar4;
            }
        }
    }
    bVar3 = (uint8)uVar4;
    if ((uVar4 >> 2 & 1) == 0) {
        iVar2 = this->field_0xc0;
        if (iVar2 < this->secondaryWordPos.x) {
            iVar1 = this->secondaryWordPos.x - this->field_0xc8;
            if (iVar1 <= iVar2) {
                bVar3                    = bVar3 | 4;
                this->secondaryWordPos.x = iVar2;
                this->field_0xe2         = bVar3;
                uVar4                    = uVar4 & 8;
                goto joined_r0x0071001a5758;
            }
            this->secondaryWordPos.x = iVar1;
        }
    }
    uVar4 = uVar4 >> 3 & 1;
joined_r0x0071001a5758:
    if (uVar4 == 0) {
        iVar2 = this->field_0xd4;
        if (iVar2 < this->actIDPos.x) {
            iVar1 = this->actIDPos.x - this->field_0xdc;
            if (iVar1 <= iVar2) {
                this->actIDPos.x = iVar2;
                this->field_0xe2 = bVar3 | 8;
                return;
            }
            this->actIDPos.x = iVar1;
        }
    }
}

void TitleCard::State_Wait()
{
    SET_CURRENT_STATE();

    if ((char)this->field_0xe0 > 0) {
        this->field_0xe0 -= 1;
        return;
    }

    if (this->storedFade)
        this->storedFade->state.Set(&FXFade::State_FadeIn);

    this->state.Set(&TitleCard::State_WaitFade);

    Stage::SetEngineState(ENGINESTATE_REGULAR);
}

void TitleCard::State_WaitFade()
{
    SET_CURRENT_STATE();

    if (this->storedFade && this->storedFade->classID)
        return;

    this->state.Set(&TitleCard::State_MoveOut);
}

void TitleCard::State_MoveOut()
{
    SET_CURRENT_STATE();

    uint8 bVar1;
    int32 uVar2;
    uint8 bVar3;
    Zone *pOVar4;
    GlobalVariables *pSVar5;
    TileLayer *pTVar6;
    uint8 uVar7;

    int32 iVar9 = 0;
    void *local_70;
    uint16 local_68;
    bool32 local_64;
    void *pvVar6;

    Camera *camera;

    bVar3 = this->field_0xe2;
    uVar7 = bVar3;

    if (!bVar3) {
        sceneInfo->timeEnabled = true;
        this->Destroy();

        if (globals->atlEnabled) {

            foreach_active(Player, player)
            {

                if (!player->sidekick) {
                    camera         = RSDK_GET_ENTITY(SLOT_CAMERA1, Camera);
                    player->camera = camera;
                }
                else {
                    camera = player->camera;
                }

                if (!iVar9 && camera) {
                    camera->state.Set(&Camera::State_FollowXY);
                    // uVar2 = *(undefined4 *)&camera->field_0xf8;
                    camera->target     = player;
                    camera->velocity.x = 0;
                    camera->velocity.y = 0;
                    camera->position.x = 0;
                    camera->position.y = 0;
                    // *(undefined4 *)&camera->field_0xec  = 0;
                    // *(undefined4 *)&camera->field_0xf0  = uVar2;
                    camera->position.x = player->position.x;
                    camera->position.y = player->position.y;

                    // *(undefined4 *)(DAT_710314ba60 + 4) = 0x100000;
                    // *(undefined4 *)(DAT_710314ba60 + 8) = 0x100000;
                }

                /*
                *(int32 *)(&ObjectZone->field_0x1d8 + (ulong) * (ushort *)((long)pvVar6 + 0x1b6) * 4) = (screenInfo->position).x;
                *(int *)(&ObjectZone->field_0x218 + (ulong) * (ushort *)((long)pvVar6 + 0x1b6) * 4) =
                    *(int *)(&ObjectZone->field_0x1d8 + (ulong) * (ushort *)((long)pvVar6 + 0x1b6) * 4) << 0x10;
                pOVar4 = ObjectZone;
                if (camera) {
                    *(undefined4 *)&camera->field_0xfc = *(undefined4 *)(&ObjectZone->field_0x1d8 + (ulong) * (ushort *)((long)pvVar6 + 0x1b6) * 4);
                }
                pTVar6 = (*RSDKTable->GetTileLayer)(*(uint16 *)&pOVar4->field_0x2d4);
                *(uint *)(&ObjectZone->field_0x1e8 + (ulong) * (ushort *)((long)pvVar6 + 0x1b6) * 4) = (uint)pTVar6->width << 4;
                *(int *)(&ObjectZone->field_0x228 + (ulong) * (ushort *)((long)pvVar6 + 0x1b6) * 4) =
                    *(int *)(&ObjectZone->field_0x1e8 + (ulong) * (ushort *)((long)pvVar6 + 0x1b6) * 4) << 0x10;
                *(undefined4 *)(ObjectZone->fgDrawGroup + (ulong) * (ushort *)((long)pvVar6 + 0x1b6) * 4 + -0x71) = 1;
                *(undefined4 *)(ObjectZone->fgDrawGroup + (ulong) * (ushort *)((long)pvVar6 + 0x1b6) * 4 + -0x61) = 1;
                */
            }

            globals->atlEnabled        = 0;
            globals->suppressTitlecard = 0; // replayWriteBuffer[0xcf09]

            // Zone::sVars->field_0x2ac = 0;
            // Zone::sVars->field_0x20      = 0;
        }
    }
    else {
        bVar1            = this->field_0xe1 + 1;
        this->field_0xe1 = bVar1;

        if ((((bVar3 & 1) != 0) && (this->field_0x9c <= bVar1))
            && (iVar9 = this->bannerPos.y + this->field_0xa0 * -2, this->bannerPos.y = iVar9, iVar9 < 0)) {
            uVar7 &= 0xfe;
            this->field_0xe2 = uVar7;
        }

        if ((((uVar7 >> 1 & 1) != 0) && (this->field_0xb0 <= bVar1))
            && (iVar9 = this->primaryWordPos.x + this->field_0xb4 * 2, this->primaryWordPos.x = iVar9,
                this->storedStrWidth + (screenInfo->size).x < iVar9 >> 16)) {
            uVar7            = uVar7 & 0xfffffffd;
            this->field_0xe2 = uVar7;
        }

        if ((((uVar7 >> 2 & 1) != 0) && (this->field_0xc4 <= bVar1))
            && (iVar9 = this->secondaryWordPos.x + this->field_0xc8 * 2, this->secondaryWordPos.x = iVar9,
                this->storedStrWidth + (screenInfo->size).x < iVar9 >> 16)) {
            uVar7            = uVar7 & 0xfffffffb;
            this->field_0xe2 = uVar7;
        }

        if (((uVar7 >> 3 & 1) && this->field_0xd8 <= bVar1)
            && (iVar9 = this->actIDPos.x + this->field_0xdc * 2, this->actIDPos.x = iVar9, screenInfo->size.x < iVar9 >> 16)) {
            this->field_0xe2 = (uint8)uVar7 & 0xf7;
        }
    }
}

} // namespace GameLogic