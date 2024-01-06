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
        drawPos.x = this->field_0xcc;
        drawPos.y = this->field_0xd0;
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
    int32 unknown1;
    uint8 unknown2;
    // unknown3 is hiding from us
    int32 unknown4;
    int32 unknown5;
    int32 unknown6;

    // globals[1].replayWriteBuffer[0xCF09] != 2
    if (globals->suppressTitlecard != 2) {
        this->active    = ACTIVE_ALWAYS;
        this->visible   = true;
        this->drawGroup = Zone::sVars->hudDrawGroup + 1;

        if (sceneInfo->inEditor) {
            this->gameNameAnimator.SetAnimation(sVars->aniFrames, 0, false, 3);
            return;
        }

        if (!this->strName.chars)
            this->strName.Init("UNTITLED", 256);

        this->strName.SetSpriteString(sVars->aniFrames, 1);
        int32 stringWidth = this->strName.GetWidth(sVars->aniFrames, 1, 0, this->field_0x80, 0);

        this->storedStrWidth = stringWidth;
        unknown5             = screenInfo->size.x;
        unknown1             = (screenInfo->size).y;
        this->field_0x9c     = 1;
        unknown4             = (int)((float)(unknown1 + -0xe0) * 0.5 * 65536.0);
        unknown1             = unknown4 + 0xb00000;
        unknown5             = (int)((float)(unknown5 + -0x140) * 0.5 * 65536.0);

        this->bannerPos.x = unknown5 + TO_FIXED(96);
        this->bannerPos.y = unknown1 + (int)((float)unknown1 / 11.0) * -11;

        this->field_0x98       = unknown1;
        this->field_0xa0       = (int)((float)unknown1 / 11.0);
        unknown1               = unknown5 + 0x1200000;
        unknown6               = (int)(((float)screenInfo->size.x / 320.0) * 1048576.0);
        this->primaryWordPos.y = unknown4 + 0x780000;
        this->field_0xac       = unknown1;
        this->field_0xb0       = 3;
        this->field_0xb4       = unknown6;
        this->primaryWordPos.x = unknown1 + unknown6 * 0x14;

        if (this->noBanner) {
            unknown2 = screenInfo->size.x;

            if ((int32)unknown2 < 0)
                unknown2 += 1;

            if (stringWidth < 0)
                stringWidth += 1;
            
            *(uint8 *)&this->field_0xac = ((unknown2 >> 1) + (stringWidth >> 1)) * 0x10000;
        }

        this->secondaryWordPos.x = unknown1 + unknown6 * 24;
        this->secondaryWordPos.y = unknown4 + 0x980000;

        this->field_0xc4 = 5;
        this->field_0xd0 = unknown4 + 0xa00000;
        this->field_0xd4 = unknown5 + 0xe80000;
        this->field_0xd8 = 7;
        this->field_0xc0 = unknown1;
        this->field_0xe0 = 90;
        this->field_0xc8 = unknown6;
        this->field_0xcc = unknown5 + 0xe80000 + unknown6 * 28;
        this->field_0xdc = unknown6;

        if (globals[1].replayWriteBuffer[0xcf49] != 4 && globals[1].replayWriteBuffer[0x49] != 2) {
            this->state.Set(&TitleCard::State_Init);
            return;
        }

        sceneInfo->timeEnabled = true;
    }

    this->Reset(0, NULL);
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

    RSDKTable->InitString(&strName, "ZOO", 0);

    pSVar1                  = &sVars->secondaryWord;
    String *pSVar2          = &sVars->strName;
    (sVars->strName).length = strName.length;
    pSVar2->size            = strName.size;
    (sVars->strName).chars  = strName.chars;

    RSDKTable->SetSpriteString(sVars->aniFrames.aniFrames, 1, pSVar1);
    RSDKTable->SetSpriteString(sVars->aniFrames.aniFrames, 1, &sVars->strName);

    // taken from mania
    foreach_all(TitleCard, titleCard) { Zone::sVars->actID = titleCard->actID; }
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
    if (globals[1].replayWriteBuffer[0xcf06] != 6)
        uVar3 = 2;

    uVar1 = 0;
    if (globals[1].replayWriteBuffer[0xcf06] != 5)
        uVar1 = uVar3;

    this->field_0xf8 = uVar1;

    this->fontAnimator.SetAnimation(sVars->aniFrames, 1, false, 0);
    frameID = this->actID;
    uVar2   = this->actID;

    globals[1].replayWriteBuffer[0xcf0a] = 0; // remove this line when the globals are corrected

    if ((globals[1].replayWriteBuffer[0xcf0a] == 0) || (uVar2 != 1)) {
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

    // this used to be globals[1].replayWriteBuffer[0xcf09] != 0
    // but, i'm taking a guess that this is supposed to be
    // globals->supressTitleCard (my globals are messed up in ghidra :<)

    if (globals->suppressTitlecard) {
        this->storedFade = NULL;
        return;
    }

    FXFade *fade = CREATE_ENTITY(FXFade, NULL, this->position.x, this->position.y);
    fade->state.Set(StateMachine_None);
    fade->timer      = 512;
    fade->speedIn    = 32;
    fade->drawGroup  = Zone::sVars->hudDrawGroup;
    fade->active     = true;
    this->storedFade = fade;

    Stage::SetEngineState(ENGINESTATE_PAUSED);
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
        bVar3 = bVar3 >> 1 & 1;
    }
    if (bVar3 == 0) {
        iVar2 = this->field_0xac;
        if (iVar2 < this->primaryWordPos.x) {
            iVar1 = this->primaryWordPos.x - this->field_0xb4;
            if (iVar2 < iVar1) {
                this->primaryWordPos.x = iVar1;
            }
            else {
                uVar4                  = uVar4 | 2;
                this->primaryWordPos.x = iVar2;
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
        if (iVar2 < this->field_0xcc) {
            iVar1 = this->field_0xcc - this->field_0xdc;
            if (iVar1 <= iVar2) {
                this->field_0xcc = iVar2;
                this->field_0xe2 = bVar3 | 8;
                return;
            }
            this->field_0xcc = iVar1;
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

    if (this->storedFade && this->storedFade->classID) {
        return;
    }

    // temp disabled because oml
    this->state.Set(&TitleCard::State_MoveOut);

    // this->state.Set(StateMachine_None);
    // sceneInfo->timeEnabled = true;
    // this->Reset(0, NULL);
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
    uVar7 = (uint8)bVar3;

    if (!bVar3) {
        sceneInfo->timeEnabled = true;
        this->Reset(0, NULL);

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
            this->field_0xe2 = (char)uVar7;
        }

        if ((((uVar7 >> 1 & 1) != 0) && (this->field_0xb0 <= bVar1))
            && (iVar9 = this->primaryWordPos.x + this->field_0xb4 * 2, this->primaryWordPos.x = iVar9,
                this->storedStrWidth + (screenInfo->size).x < iVar9 >> 16)) {
            uVar7            = uVar7 & 0xfffffffd;
            this->field_0xe2 = (char)uVar7;
        }

        if ((((uVar7 >> 2 & 1) != 0) && (this->field_0xc4 <= bVar1))
            && (iVar9 = this->secondaryWordPos.x + this->field_0xc8 * 2, this->secondaryWordPos.x = iVar9,
                this->storedStrWidth + (screenInfo->size).x < iVar9 >> 16)) {
            uVar7            = uVar7 & 0xfffffffb;
            this->field_0xe2 = (char)uVar7;
        }

        if (((uVar7 >> 3 & 1) && this->field_0xd8 <= bVar1)
            && (iVar9 = this->field_0xcc + this->field_0xdc * 2, this->field_0xcc = iVar9, screenInfo->size.x < iVar9 >> 16)) {
            this->field_0xe2 = (uint8)uVar7 & 0xf7;
        }
    }
}

} // namespace GameLogic