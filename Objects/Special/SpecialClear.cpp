// ---------------------------------------------------------------------
// RSDK Project: S3KT
// Object Name: SpecialClear
// Object Author:
// ---------------------------------------------------------------------

#include "GameObjects.hpp"

using namespace RSDK;

namespace GameLogic
{

RSDK_REGISTER_OBJECT(SpecialClear);

void SpecialClear::Update()
{
    this->state.Run(this);

    int32 unknown1 = Math::Sin512((Zone::sVars->timer & 0x1FU) << 4);

    int32 unknown2 = (unknown1 >> 3) + 64;
    int32 unknown3 = (unknown1 >> 3) + 65;

    if (unknown2 > -1)
        unknown3 = unknown2;

    this->alpha = unknown3 >> 1;
}

void SpecialClear::LateUpdate() {}

void SpecialClear::StaticUpdate() {}

void SpecialClear::Draw() {}

void SpecialClear::Create(void *data)
{
    if (!sceneInfo->inEditor) {

        if (data)
            this->type = VOID_TO_INT(data);

        this->active        = ACTIVE_NORMAL;
        this->visible       = true;
        this->updateRange.x = 0x800000;
        this->updateRange.y = 0x800000;
        this->drawGroup     = Zone::sVars->hudDrawGroup - (globals[1].replayWriteBuffer[0xcf49] != 3);

        this->someVector.x = this->position.x;
        this->someVector.y = this->position.y;

        this->state.Set(&SpecialClear::State_Init);

        this->animator.SetAnimation(sVars->aniFrames, this->type, true, 0);

        int32 *piVar1 = &globals->replayWriteBuffer[0x1ACBB];
        int32 iVar2   = *piVar1;
        *piVar1       = iVar2 * 100;
        globals->replayWriteBuffer[0x1acbc] *= 50000;

        uint8 uVar6 = 0;
        if (iVar2 * 100 > 4999) {
            uVar6 = ((uint8)globals->replayWriteBuffer[0x1ec5c] >> 6 ^ 0xffffffff) & 1;
        }
        sVars->field_0x14 = uVar6;
        if (*piVar1 < 5000) {
            uVar6 = 0;
        }
        else {
            uVar6 = (uint8)(globals[1].replayWriteBuffer[0xcf4f] != 0);
        }
        sVars->field21_0x20 = (short)uVar6;
        sVars->field22_0x22 = (short)(uVar6 >> 0x10);
        // ActClear::sVars->field_0x4a = 1;
    }
}

void SpecialClear::StageLoad()
{
    sVars->aniFrames.Load("3K_HPZ/SpecialClear.bin", SCOPE_STAGE);

    sVars->sfxScoreAdd.Get("Global/ScoreAdd.wav");
    sVars->sfxScoreTotal.Get("Global/ScoreTotal.wav");
    sVars->sfxEvent.Get("Special/Event.wav");
    sVars->sfxContinue.Get("Special/Continue.wav");
    sVars->sfxTwinkle.Get("Global/Twinkle.wav");
    sVars->sfxSuperEmerald.Get("Stage/SuperEmerald.wav");

    sVars->field16_0x18 = 0;
}

#if RETRO_INCLUDE_EDITOR
void SpecialClear::EditorDraw()
{
    this->animator.SetAnimation(sVars->aniFrames, 0, true, 0);
    this->animator.DrawSprite(&this->position, false);
}

void SpecialClear::EditorLoad() { sVars->aniFrames.Load("3K_HPZ/SpecialClear.bin", SCOPE_STAGE); }
#endif

void SpecialClear::StaticLoad(Static *sVars)
{
    RSDK_INIT_STATIC_VARS(SpecialClear);
    sVars->classID = 0;
    sVars->active  = ACTIVE_NEVER;
}

void SpecialClear::Serialize() { RSDK_EDITABLE_VAR(SpecialClear, VAR_INT8, type); }

void SpecialClear::State_Init()
{
    SET_CURRENT_STATE();

    //

    bool32 bVar1;
    int32 iVar2;
    // ulong uVar3;
    int32 iVar4;
    uint16 aniFrames;
    uint8 uVar5;
    bool32 bVar6;
    uint8 uVar7;
    int32 iVar8;
    uint8 uVar9;
    Entity *some_entity;
    // undefined8 uVar10;
    uint16 listID;
    // _func_202 *p_Var11;
    Vector2 *local_70;

    //

    this->visible = true;
    this->active  = ACTIVE_NORMAL;
    // this->state.Set(&SpecialClear::State_dosomethingidk);
}

} // namespace GameLogic