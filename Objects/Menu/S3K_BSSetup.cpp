// ---------------------------------------------------------------------
// RSDK Project: S3KT
// Object Name: S3K_BSSetup
// Object Author:
// ---------------------------------------------------------------------

#include "GameObjects.hpp"

using namespace RSDK;

namespace GameLogic
{

RSDK_REGISTER_OBJECT(S3K_BSSetup);

void S3K_BSSetup::Update() { this->state.Run(this); }

void S3K_BSSetup::LateUpdate() {}

void S3K_BSSetup::StaticUpdate() {}

void S3K_BSSetup::Draw()
{
    Animator *puVar1{};
    Animator *animator;
    int alphaR;
    char cVar2;
    uint8 uVar3;
    int32 *pSVar4;  // globals
    int32 *pOVar5;  // svars
    int32 *globals; // globals
    bool bVar7;
    uint32 color;
    int32 uVar8;
    uint8 uVar9;
    uint8 uVar10;
    // code *pcVar11;
    uint8 uVar12;
    long uVar13;
    Vector2 drawPos;

    if (this->angle < 0xC000) {
        RSDKTable->DrawSprite(&this->field_0x198, &this->someDrawPos, false);
        RSDKTable->DrawSprite(&this->field_0x1b8, &this->someOtherDrawPos, false);
    }

    RSDKTable->DrawSprite(&this->logoAnimator, NULL, false);
    this->field_0x80 = 0;

    (*RSDKTable->DrawSprite)(&this->charactersAnimator, (Vector2 *)0x0, 0);
    (*RSDKTable->DrawSprite)((Animator *)&this->tailsAnimator, (Vector2 *)&this->field_0x228, 0);
    (*RSDKTable->DrawSprite)((Animator *)&this->sonicAnimator, (Vector2 *)&this->field_0x230, 0);
    (*RSDKTable->DrawSprite)((Animator *)&this->knuxAnimator, (Vector2 *)&this->field_0x238, 0);
    (*RSDKTable->DrawSprite)((Animator *)&this->eggmanAnimator, (Vector2 *)&this->field_0x240, 0);

    if (this->angle > 0xC000) {
        (*RSDKTable->DrawSprite)((Animator *)&this->field_0x198, &this->someDrawPos, 0);
        (*RSDKTable->DrawSprite)((Animator *)&this->field_0x1b8, &this->someOtherDrawPos, 0);
    }

    if (0 /*globals[1].replayWriteBuffer[0xcf36]*/ != 0)
        RSDKTable->FillScreen(0, 192, 192, 192);

    //

    (*RSDKTable->DrawSprite)((Animator *)&this->starAnimator, (Vector2 *)&this->field_0x1f8, 0);
    this->direction = this->direction ^ 1;
    (*RSDKTable->DrawSprite)((Animator *)&this->starAnimator, (Vector2 *)&this->field_0x200, 0);
    this->direction = this->direction ^ 1;
    drawPos.x       = 0x11e0000;
    drawPos.y       = 0xd00000;
    if (sVars->field35_0x25 != false) {
        drawPos.y = 0xe00000;
    }
    cVar2                                                      = *(char *)&sVars->field21_0x16;
    animator                                                   = &this->numbersAnimator;
    ((Animator *)(animator + (cVar2 == '\v') * 0x20))->frameID = (uint8)sVars->field_0x23 + (sVars->field_0x23 / 10) * -10;
    (*RSDKTable->DrawSprite)((Animator *)(animator + (cVar2 == '\v') * 0x20), &drawPos, 0);
    drawPos.x                                                  = drawPos.x + -0x80000;
    cVar2                                                      = *(char *)&sVars->field21_0x16;
    ((Animator *)(animator + (cVar2 == '\n') * 0x20))->frameID = (uint8)sVars->field_0x22 + (sVars->field_0x22 / 10) * -10;
    (*RSDKTable->DrawSprite)((Animator *)(animator + (cVar2 == '\n') * 0x20), &drawPos, 0);
    drawPos.x                                                  = drawPos.x + -0x80000;
    cVar2                                                      = *(char *)&sVars->field21_0x16;
    ((Animator *)(animator + (cVar2 == '\t') * 0x20))->frameID = (uint8)sVars->field_0x21 + (sVars->field_0x21 / 10) * -10;
    (*RSDKTable->DrawSprite)((Animator *)(animator + (cVar2 == '\t') * 0x20), &drawPos, 0);
    drawPos.x                                                  = drawPos.x + -0x80000;
    cVar2                                                      = *(char *)&sVars->field21_0x16;
    ((Animator *)(animator + (cVar2 == '\b') * 0x20))->frameID = (uint8)sVars->field_0x20 + (sVars->field_0x20 / 10) * -10;
    (*RSDKTable->DrawSprite)((Animator *)(animator + (cVar2 == '\b') * 0x20), &drawPos, 0);
    drawPos.x                                                  = drawPos.x + -0x100000;
    cVar2                                                      = *(char *)&sVars->field21_0x16;
    ((Animator *)(animator + (cVar2 == '\a') * 0x20))->frameID = (uint8)sVars->field_0x1f + (sVars->field_0x1f / 10) * -10;
    (*RSDKTable->DrawSprite)((Animator *)(animator + (cVar2 == '\a') * 0x20), &drawPos, 0);
    drawPos.x                                                    = drawPos.x + -0x80000;
    cVar2                                                        = *(char *)&sVars->field21_0x16;
    ((Animator *)(animator + (cVar2 == '\x06') * 0x20))->frameID = (uint8)sVars->field_0x1e + (sVars->field_0x1e / 10) * -10;
    (*RSDKTable->DrawSprite)((Animator *)(animator + (cVar2 == '\x06') * 0x20), &drawPos, 0);
    drawPos.x                                                    = drawPos.x + -0x80000;
    cVar2                                                        = *(char *)&sVars->field21_0x16;
    ((Animator *)(animator + (cVar2 == '\x05') * 0x20))->frameID = (uint8)sVars->field_0x1d + (sVars->field_0x1d / 10) * -10;
    (*RSDKTable->DrawSprite)((Animator *)(animator + (cVar2 == '\x05') * 0x20), &drawPos, 0);
    drawPos.x                                                    = drawPos.x + -0x80000;
    cVar2                                                        = *(char *)&sVars->field21_0x16;
    ((Animator *)(animator + (cVar2 == '\x04') * 0x20))->frameID = (uint8)sVars->field_0x1c + (sVars->field_0x1c / 10) * -10;
    (*RSDKTable->DrawSprite)((Animator *)(animator + (cVar2 == '\x04') * 0x20), &drawPos, 0);
    drawPos.x                                                    = drawPos.x + -0x100000;
    cVar2                                                        = *(char *)&sVars->field21_0x16;
    ((Animator *)(animator + (cVar2 == '\x03') * 0x20))->frameID = (uint8)sVars->field_0x1b + (sVars->field_0x1b / 10) * -10;
    (*RSDKTable->DrawSprite)((Animator *)(animator + (cVar2 == '\x03') * 0x20), &drawPos, 0);
    drawPos.x                                                    = drawPos.x + -0x80000;
    cVar2                                                        = *(char *)&sVars->field21_0x16;
    ((Animator *)(animator + (cVar2 == '\x02') * 0x20))->frameID = (uint8)sVars->field_0x1a + (sVars->field_0x1a / 10) * -10;
    (*RSDKTable->DrawSprite)((Animator *)(animator + (cVar2 == '\x02') * 0x20), &drawPos, 0);
    drawPos.x                                                    = drawPos.x + -0x80000;
    cVar2                                                        = *(char *)&sVars->field21_0x16;
    ((Animator *)(animator + (cVar2 == '\x01') * 0x20))->frameID = (uint8)sVars->field_0x19 + (sVars->field_0x19 / 10) * -10;
    (*RSDKTable->DrawSprite)((Animator *)(animator + (cVar2 == '\x01') * 0x20), &drawPos, 0);
    drawPos.x                                                  = drawPos.x + -0x80000;
    cVar2                                                      = *(char *)&sVars->field21_0x16;
    ((Animator *)(animator + (cVar2 == '\0') * 0x20))->frameID = (uint8)sVars->field_0x18 + (sVars->field_0x18 / 10) * -10;
    (*RSDKTable->DrawSprite)((Animator *)(animator + (cVar2 == '\0') * 0x20), &drawPos, 0);
    drawPos.x        = drawPos.x + -0x80000;
    this->field_0x80 = 4;
    (*RSDKTable->DrawSprite)(puVar1, &drawPos, 0);

    uVar9  = 0; // globals[1].replayWriteBuffer[0xcf33];
    pSVar4 = 0; // globals + 1;
    if (uVar9 == 0x3b9ac9fe) {
        uVar12 = 999999999;
    }
    else if (uVar9 == 0xb707456) {
        uVar12 = 0xb707457;
    }
    else {
        uVar10 = (int)(uVar9 * 5 + 2) % 0x7e;
        uVar12 = (int)(uVar9 * 3 + 1) % 0x7f;
        uVar3  = (int)(uVar9 * 7 + 3) % 0x7d;
        // *(char *)((long)globals[1].replayWriteBuffer + 0x33cc3) = (char)uVar10;
        // *(char *)(globals[1].replayWriteBuffer + 0xcf31)         = (char)uVar3;
        // *(char *)((long)pSVar4->replayWriteBuffer + 0x33cc1)    = (char)(uVar9 & 0x7f);
        // *(char *)((long)globals[1].replayWriteBuffer + 0x33cc2)  = (char)uVar12;
        uVar12 = (uVar10 & 0xff) * 0x80 + (uVar3 & 0xff) + (uVar12 & 0xff) * 0x4000 + (uVar9 & 0x7f) * 0x200000;
    }

    if (0 == 0 /*globals[1]->replayWriteBuffer[0xcf36] == (uint8)(*(char *)((long)&sVars->field21_0x16 + 1) != '\0')*/) {
        drawPos.y = 0x4c0000;
        if (sVars->field35_0x25 != false) {
            drawPos.y = 0x2e0000;
        }
        drawPos.x         = 0xfa0000;
        this->field_0x160 = 0xb;
        (*RSDKTable->DrawSprite)((Animator *)animator, &drawPos, 0);
        drawPos.x         = drawPos.x + -0x80000;
        this->field_0x160 = uVar12 % 10;
        (*RSDKTable->DrawSprite)((Animator *)animator, &drawPos, 0);
        drawPos.x         = drawPos.x + -0x80000;
        this->field_0x160 = uVar12 / 10 + (uVar12 / 100) * -10;
        (*RSDKTable->DrawSprite)((Animator *)animator, &drawPos, 0);
        drawPos.x         = drawPos.x + -0x80000;
        this->field_0x160 = uVar12 / 100 + (uVar12 / 1000) * -10;
        (*RSDKTable->DrawSprite)((Animator *)animator, &drawPos, 0);
        drawPos.x         = drawPos.x + -0x80000;
        this->field_0x160 = uVar12 / 1000 + (uVar12 / 10000) * -10;
        (*RSDKTable->DrawSprite)((Animator *)animator, &drawPos, 0);
        drawPos.x         = drawPos.x + -0x80000;
        this->field_0x160 = uVar12 / 10000 + (uVar12 / 100000) * -10;
        (*RSDKTable->DrawSprite)((Animator *)animator, &drawPos, 0);
        drawPos.x         = drawPos.x + -0x80000;
        this->field_0x160 = (uVar12 >> 5) / 0xc35 + ((uVar12 >> 5) / 0x7a12) * -10;
        (*RSDKTable->DrawSprite)((Animator *)animator, &drawPos, 0);
        drawPos.x         = drawPos.x + -0x80000;
        this->field_0x160 = uVar12 / 1000000 + (uVar12 / 10000000) * -10;
        (*RSDKTable->DrawSprite)((Animator *)animator, &drawPos, 0);
        drawPos.x         = drawPos.x + -0x80000;
        this->field_0x160 = uVar12 / 10000000 + (uVar12 / 100000000) * -10;
        (*RSDKTable->DrawSprite)((Animator *)animator, &drawPos, 0);
        drawPos.x         = drawPos.x + -0x80000;
        this->field_0x160 = uVar12 / 100000000 + (uVar12 / 1000000000) * -10;
        (*RSDKTable->DrawSprite)((Animator *)animator, &drawPos, 0);
        drawPos.x         = drawPos.x + -0x80000;
        this->field_0x160 = 10;
        (*RSDKTable->DrawSprite)((Animator *)animator, &drawPos, 0);
        uVar8 = 2;
    }
    else {
        if (uVar9 == 0x7ffffff) {
            // globals[1].replayWriteBuffer[0xcf33] = -1;
            uVar9 = 1;
        }
        else {
            uVar13 = (uVar9 + 1);
            if (uVar9 == 0xffffffff) {
                uVar9 = 1;
            }
            else {
                uVar9 = 0;
                do {
                    uVar12 = (uint8)uVar13;
                    uVar9  = uVar9 + 1;
                    uVar13 = uVar13 / 10;
                } while (9 < uVar12);
            }
        }
        uVar9     = uVar9 & 0xff;
        drawPos.x = uVar9 * 0x40000 + 0xd60000;
        drawPos.y = 0x4c0000;
        if (sVars->field35_0x25 != false) {
            drawPos.y = 0x2e0000;
        }
        this->field_0x160 = 0xb;
        (*RSDKTable->DrawSprite)((Animator *)animator, &drawPos, 0);
        drawPos.x = drawPos.x + -0x80000;
        uVar12    = 0; // globals[1].replayWriteBuffer[0xcf33] + 1;
        if (uVar9 == 0) {
            if (0 /*globals[1].replayWriteBuffer[0xcf33]*/ < 0) {
                uVar9 = 1;
            }
            else {
                uVar9  = 0;
                uVar13 = uVar12;
                do {
                    uVar10 = (uint8)uVar13;
                    uVar9  = uVar9 + 1;
                    uVar13 = uVar13 / 10;
                } while (9 < uVar10);
            }
        }
        uVar10 = 1;
        do {
            uVar3 = 0;
            if (uVar10 != 0) {
                uVar3 = uVar12 / uVar10;
            }
            this->field_0x160 = uVar3 % 10;
            (*RSDKTable->DrawSprite)((Animator *)animator, &drawPos, 0);
            drawPos.x = drawPos.x + -0x80000;
            uVar10    = uVar10 * 10;
            uVar9     = uVar9 - 1;
        } while (uVar9 != 0);
        this->field_0x160 = 10;
        (*RSDKTable->DrawSprite)((Animator *)animator, &drawPos, 0);
        if (0 == 1 /*globals[1].replayWriteBuffer[0xcf33] == -1*/) {
            // globals[1].replayWriteBuffer[0xcf33] = 0x7ffffff;
        }
        uVar8 = 1;
    }
    this->field_0x80 = uVar8;
    drawPos.y        = 0x3c0000;
    if (sVars->field35_0x25 != false) {
        drawPos.y = 0x1e0000;
    }
    drawPos.x = 0xd20000;
    (*RSDKTable->DrawSprite)((Animator *)puVar1, &drawPos, 0);
    drawPos.y = 0xb40000;
    if (sVars->field35_0x25 != false) {
        drawPos.y = 0xa40000;
    }
    drawPos.x        = 0xd20000;
    this->field_0x80 = 3;
    (*RSDKTable->DrawSprite)((Animator *)puVar1, &drawPos, 0);
    drawPos.x = *(int32 *)&this->field_0x260;
    puVar1    = &this->messageAnimator;
    drawPos.y = *(int32 *)&this->field_0x264;
    (*RSDKTable->DrawSprite)((Animator *)puVar1, &drawPos, 0);
    drawPos.x += -0x200; // CONCAT22(drawPos.x._2_2_ + -0x200, (undefined2)drawPos.x);
    (*RSDKTable->DrawSprite)((Animator *)puVar1, &drawPos, 0);
    drawPos.x += 0x401; // CONCAT22(drawPos.x._2_2_ + 0x401, (undefined2)drawPos.x);
    (*RSDKTable->DrawSprite)((Animator *)puVar1, &drawPos, 0);
    /*
    pcVar11 = *(code **)&this->state;
    uVar13  = *(ulong *)&this->field_0x68;
    bVar7   = (uVar13 & 1 | pcVar11) != 0;
    if ((pcVar11 != FUN_71002bbc40) || (uVar13 != 0 && bVar7)) {
        if (pcVar11 != FUN_71002bbc80 || uVar13 != 0 && bVar7) {
            return;
        }
        color = 0;
    }
    else {
        color = 0xffffff;
    }
    */
    color = 0;

    alphaR = this->field_0x278;
    (*RSDKTable->FillScreen)(color, alphaR, alphaR + -0x80, alphaR + -0x100);
    return;
}

void S3K_BSSetup::Create(void *data)
{
    this->active  = ACTIVE_NORMAL;
    this->visible = true;

    uint8 drawGroup = 15;

    if (sVars->field_0x25 == 0)
        drawGroup = 1;

    this->drawGroup = drawGroup;
    this->drawFX    = FX_FLIP;

    sceneInfo->timeEnabled = 0;

    sceneInfo->minutes      = 0;
    sceneInfo->milliseconds = 0;
    sceneInfo->seconds      = 0;

    if (!Stage::CheckSceneFolder(("3K_BlueSpheresN"))) {

        this->charactersAnimator.SetAnimation(sVars->aniFrames, 0, true, 0);
        this->tailsAnimator.SetAnimation(sVars->aniFrames, 1, true, 0);
        this->sonicAnimator.SetAnimation(sVars->aniFrames, 2, true, 0);
        this->knuxAnimator.SetAnimation(sVars->aniFrames, 3, true, 0);
        this->eggmanAnimator.SetAnimation(sVars->aniFrames, 4, true, 0);
        this->logoAnimator.SetAnimation(sVars->aniFrames, 5, true, 0);
        this->numbersAnimator.SetAnimation(sVars->aniFrames, 6, true, 0);
        this->numHighlightAnimator.SetAnimation(sVars->aniFrames, 7, true, 0);
        this->starAnimator.SetAnimation(sVars->aniFrames, 9, true, 0);
        this->messageAnimator.SetAnimation(sVars->aniFrames, 12, true, 0);

        this->field_0x1f8 = 0xb5000000b20000;
        this->field_0x200 = 0xb5000000f20000;
        sVars->field_0x17 = 1;

        int32 storeX = this->position.x;
        int32 storeY = this->position.y;

        this->field_0x228 = storeX;
        this->field_0x230 = storeX;
        this->field_0x238 = storeX;
        this->field_0x240 = storeX;
        this->field_0x248 = storeX;
        this->field_0x260 = (this->position.x + 2) << 16;
        this->field_0x22c = storeY;
        this->field_0x234 = storeY;
        this->field_0x23c = storeY;
        this->field_0x244 = storeY;
        this->field_0x24c = storeY;
        this->field_0x264 = 0x280000;

        if (!sceneInfo->inEditor) {
            RSDKTable->CopyPalette(4, sVars->field_0x24 * 4 + ' ', 0, 130, 4);
            this->state.Set(&S3K_BSSetup::State_Title_Init);
            return;
        }
    }
}

void S3K_BSSetup::StageLoad()
{
    int32 *piVar1;
    int iVar2;
    uint8 uVar3;
    uint16 uVar7;
    long lVar9;
    Entity *pEVar10;

    int32 lVar6 = 0;

    bool32 isNewBS = RSDKTable->CheckSceneFolder("3K_BlueSpheresN");

    const char *frames = "3K_BlueSpheres/Menu.bin";
    if (isNewBS != 0) {
        frames = "3K_BlueSpheres/New.bin";
    }

    sVars->aniFrames.Load(frames, SCOPE_STAGE);
    sVars->field_0x25 = isNewBS != 0;

    UIText::sVars->aniFrames.Load("LSelect/Text.bin", SCOPE_STAGE);

    sVars->sfxBeep.Get("Stage/Beep2.wav");
    sVars->sfxStarPost.Get("Global/StarPost.wav");
    sVars->sfxFail.Get("Stage/Fail.wav");
    sVars->sfxEvent.Get("Special/Event.wav");
    sVars->sfxTwinkle.Get("Global/Twinkle.wav");
    sVars->sfxSpecialRing.Get("Global/SpecialRing.wav");

    globals[1].replayWriteBuffer[0xcf36] = globals[1].replayWriteBuffer[0xcf37]; // nasty globals... fix eventually
    globals[1].replayWriteBuffer[0xcf37] = 0;
    sVars->field21_0x16                  = 0x1ff;
    // FUN_71001988d8(0);
    globals->replayWriteBuffer[0x16b58] = -1;
    // lVar6                               = FUN_7100171ea0();

    piVar1 = globals[1].replayWriteBuffer + 0xcf33;
    if (lVar6 == 0) {
        *piVar1 = 0;
    }
    else {
        if (0 == 0 /*(globals[1].replayWriteBuffer + 0xcf38) >> (sVars->field35_0x25 & 0x1f) & 1) == 0*/) {
            if (sVars->field35_0x25 == 0) {
                // *piVar1                              = (uint8) * (byte *)(lVar6 + 0x179);
                // globals[1].replayWriteBuffer[0xcf34] = (uint8) * (byte *)(lVar6 + 0x179);
                iVar2 = globals[1].replayWriteBuffer[0xcf35];
            }
            else {
                // *piVar1                              = (uint8) * (byte *)(lVar6 + 0x17a);
                // globals[1].replayWriteBuffer[0xcf34] = (uint8) * (byte *)(lVar6 + 0x17a);
                iVar2 = globals[1].replayWriteBuffer[0xcf35];
            }
        }
        else {
            globals[1].replayWriteBuffer[0xcf34] = 0x7ffffff;
            iVar2                                = globals[1].replayWriteBuffer[0xcf35];
        }
        if (iVar2 != -1) {
            *piVar1                              = iVar2;
            globals[1].replayWriteBuffer[0xcf35] = -1;
        }
    }
    // FUN_71002bc15c();
    sVars->field34_0x24 = 0;
    uVar3               = globals->playerID >> 1 & 0x7F;
    if (uVar3 != 0) {
        uVar3               = uVar3 | uVar3 >> 1;
        uVar3               = uVar3 | uVar3 >> 2;
        uVar3               = uVar3 | uVar3 >> 4;
        uVar3               = ((uVar3 & 0xaaaaaaaa) >> 1) + (uVar3 & 0x55555555);
        uVar3               = ((uVar3 & 0xcccccccc) >> 2) + (uVar3 & 0x33333333);
        sVars->field34_0x24 = 0x20 - (' ' - ((char)(uVar3 >> 4) + (uVar3 & 0xf)));
    }

    FXFade *fade    = CREATE_ENTITY(FXFade, NULL, 0, 0);
    fade->timer     = 0x200;
    fade->speedIn   = 0x20;
    fade->drawGroup = 15;
    fade->active    = ACTIVE_ALWAYS;

    screenInfo->position.x = 0xD4 - screenInfo->center.x;
    screenInfo->position.y = 0x78 - screenInfo->center.y;
}

#if RETRO_INCLUDE_EDITOR
void S3K_BSSetup::EditorDraw()
{
    this->logoAnimator.SetAnimation(sVars->aniFrames, 0, true, 0);
    this->charactersAnimator.SetAnimation(sVars->aniFrames, 1, true, 0);
    this->tailsAnimator.SetAnimation(sVars->aniFrames, 2, true, 0);
    this->sonicAnimator.SetAnimation(sVars->aniFrames, 3, true, 0);
    this->knuxAnimator.SetAnimation(sVars->aniFrames, 4, true, 0);
    this->eggmanAnimator.SetAnimation(sVars->aniFrames, 5, true, 0);

    this->logoAnimator.DrawSprite(NULL, false);
    this->charactersAnimator.DrawSprite(NULL, false);
    this->tailsAnimator.DrawSprite(NULL, false);
    this->sonicAnimator.DrawSprite(NULL, false);
    this->knuxAnimator.DrawSprite(NULL, false);
    this->eggmanAnimator.DrawSprite(NULL, false);
}

void S3K_BSSetup::EditorLoad()
{
    sVars->aniFrames.Load("3K_BlueSpheres/Menu.bin", SCOPE_STAGE);
    sVars->field_0x25 = 0;
}
#endif

void S3K_BSSetup::StaticLoad(Static *sVars)
{
    RSDK_INIT_STATIC_VARS(S3K_BSSetup);
    sVars->classID = 0;
    sVars->active  = ACTIVE_NEVER;
}

void S3K_BSSetup::Serialize() {}

void S3K_BSSetup::State_Title_Init()
{
    SET_CURRENT_STATE();

    uint16 uVar1;
    int32 rand2;
    int32 rand;
    Entity *entity;
    int timer;

    timer = 100;

    do {
        // uVar1          = S3K_BSMenuElement;
        rand  = (*RSDKTable->Rand)(-0x1200, 0x1200);
        rand2 = (*RSDKTable->Rand)(-0xb00, 0xb00);
        // entity         = (*RSDKTable->CreateEntity)(uVar1, (void *)0x8, rand << 0x10, rand2 << 0x10);
        rand  = (*RSDKTable->Rand)(2, 0x20);
        timer = timer + -1;
        // entity->alpha  = 0x100;
        // entity->zdepth = rand << 0x10;
    } while (timer != 0);
    timer = 0x1e;
    do {
        // uVar1          = S3K_BSMenuElement;
        rand  = (*RSDKTable->Rand)(-0x380, 0x380);
        rand2 = (*RSDKTable->Rand)(-0x380, 0x380);
        // entity         = (*RSDKTable->CreateEntity)(uVar1, (void *)0x8, rand << 0x10, rand2 << 0x10);
        rand  = (*RSDKTable->Rand)(2, 0x20);
        timer = timer + -1;
        // entity->alpha  = 0x100;
        // entity->zdepth = rand << 0x10;
    } while (timer != 0);

    this->state.Set(&S3K_BSSetup::State_Title);
    // FUN_71002bc650(this);
}

void S3K_BSSetup::State_Title()
{
    SET_CURRENT_STATE();

    int32 iVar1;

    (*RSDKTable->ProcessAnimation)((Animator *)&this->logoAnimator);
    ++this->field_0x278;
    if ((/*(*(char *)(DAT_710334c988 + 0x22) != '\0') &&*/ (this->field_0x120 == 0x39)) && (this->field_0x12a == 2)) {
        (*RSDKTable->SetSpriteAnimation)(sVars->aniFrames.aniFrames, 0xf, (Animator *)&this->field_0x198, 1, 0);
        (*RSDKTable->SetSpriteAnimation)(sVars->aniFrames.aniFrames, 0x10, (Animator *)&this->field_0x1b8, 1, 0);
        this->groundVel            = 0x800;
        this->angle                = 0x4000;
        iVar1                      = (*RSDKTable->Sin256)(0x40);
        (this->someDrawPos).x      = iVar1 * 0x3000 + 0x760000;
        iVar1                      = (*RSDKTable->Sin256)(this->angle >> 8);
        (this->someDrawPos).y      = iVar1 * -0x2000 + 0x8e0000;
        iVar1                      = (*RSDKTable->Sin256)(this->angle >> 8);
        (this->someOtherDrawPos).x = iVar1 * -0x3000 + 0x1340000;
        iVar1                      = (*RSDKTable->Sin256)(this->angle >> 8);
        (this->someOtherDrawPos).y = iVar1 * 0x2000 + 0x560000;
        Music::PlayTrack(0);

        this->state.Set(&S3K_BSSetup::State_Title2);

        sVars->sfxSpecialRing.Play(false, 255);
        this->field_0x12e = 0x3e;
    }
    return;
}

void S3K_BSSetup::State_Title2()
{
    SET_CURRENT_STATE();

    int32 iVar1;
    int iVar2;

    (*RSDKTable->ProcessAnimation)((Animator *)&this->logoAnimator);
    if (this->angle < 0x10001) {
        iVar2           = this->groundVel + this->angle;
        this->angle     = iVar2;
        this->groundVel = this->groundVel + -0x24;
    }
    else {
        this->angle = 0x10000;
        (*RSDKTable->SetSpriteAnimation)(sVars->aniFrames.aniFrames, 0, (Animator *)&this->charactersAnimator, 1, 0);
        (*RSDKTable->SetSpriteAnimation)(sVars->aniFrames.aniFrames, 6, (Animator *)&this->numbersAnimator, 1, 0);
        (*RSDKTable->SetSpriteAnimation)(sVars->aniFrames.aniFrames, 7, (Animator *)&this->numHighlightAnimator, 1, 0);
        (*RSDKTable->SetSpriteAnimation)(sVars->aniFrames.aniFrames, 9, (Animator *)&this->starAnimator, 1, 0);
        this->field_0x1f8 = 0xb5000000b20000;
        this->field_0x200 = 0xb5000000f20000;
        // *(undefined *)((long)&sVars->field21_0x16 + 1) = 1;
        sVars->field21_0x16 = 1;
        this->field_0x12e   = 0x42;
        this->state.Set(&S3K_BSSetup::State_Menu);
        iVar2 = this->angle;
    }
    iVar1                      = (*RSDKTable->Sin256)(iVar2 >> 8);
    (this->someDrawPos).x      = iVar1 * 0x3000 + 0x760000;
    iVar1                      = (*RSDKTable->Sin256)(this->angle >> 8);
    (this->someDrawPos).y      = iVar1 * -0x2000 + 0x8e0000;
    iVar1                      = (*RSDKTable->Sin256)(this->angle >> 8);
    (this->someOtherDrawPos).x = iVar1 * -0x3000 + 0x1340000;
    iVar1                      = (*RSDKTable->Sin256)(this->angle >> 8);
    (this->someOtherDrawPos).y = iVar1 * 0x2000 + 0x560000;

    (*RSDKTable->ProcessAnimation)((Animator *)&this->field_0x198);
    (*RSDKTable->ProcessAnimation)((Animator *)&this->field_0x1b8);
}

void S3K_BSSetup::State_Menu()
{
    SET_CURRENT_STATE();

    bool bVar11;
    int32 iVar12;
    bool32 bVar13;
    uint8 uVar14;
    int iVar15;
    uint8 bVar16;
    char cVar17;
    int iVar18;
    uint8 uVar19;
    int iVar20;
    int iVar21;
    uint8 uVar22;
    uint8 uVar23;

    if (sVars->field35_0x25 == true) {
        (*RSDKTable->ProcessAnimation)((Animator *)&this->logoAnimator);
        *(int *)&this->field_0x278 = *(int *)&this->field_0x278 + 1;
        if (0/**(char *)(DAT_710334c988 + 0x22)*/ == '\0') {
            return;
        }
        iVar15                     = this->field_0x27c;
        *(int *)&this->field_0x27c = iVar15 + -1;
        if (iVar15 < 1) {
            iVar12 = 0; // (*RSDKTable->RandSeeded)(0, 5, (int32 *)&ObjectZone->field_0x920);
            if (iVar12 == 0) {
                iVar12 = 0x18;
            }
            else {
                iVar12 = 0; // (*RSDKTable->RandSeeded)(0x3c, 0x97, (int32 *)&ObjectZone->field_0x920);
            }
            *(int32 *)&this->field_0x27c      = iVar12;
            this->field_0x120 = 0x3d;
        }
    }
    if (globals[1].replayWriteBuffer[0xcf36] == 0) {
        (*RSDKTable->ProcessAnimation)((Animator *)&this->tailsAnimator);
        (*RSDKTable->ProcessAnimation)((Animator *)&this->sonicAnimator);
        (*RSDKTable->ProcessAnimation)((Animator *)&this->knuxAnimator);
        (*RSDKTable->ProcessAnimation)((Animator *)&this->eggmanAnimator);
        (*RSDKTable->ProcessAnimation)((Animator *)&this->field_0x198);
        (*RSDKTable->ProcessAnimation)((Animator *)&this->field_0x1b8);
    }
    (*RSDKTable->ProcessAnimation)((Animator *)&this->starAnimator);

    // more code
}

} // namespace GameLogic