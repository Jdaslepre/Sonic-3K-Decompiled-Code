// ---------------------------------------------------------------------
// RSDK Project: S3KT
// Object Name: Halfway
// Object Author:
// ---------------------------------------------------------------------

// #include "GameObjects.hpp"
#include "Halfway.hpp"

using namespace RSDK;

namespace GameLogic
{

RSDK_REGISTER_OBJECT(Halfway);

void Halfway::Update() { this->state.Run(this); }

void Halfway::LateUpdate() {}

void Halfway::StaticUpdate() {}

void Halfway::Draw() { this->animator.DrawSprite(&this->position, false); }

void Halfway::Create(void *data)
{
    if (!sceneInfo->inEditor) {

        if (data == NULL) {
            data = (void *)this->type;
        }
        else {
            this->type = (char)data;
        }

        this->active        = ACTIVE_BOUNDS;
        this->visible       = true;
        this->drawGroup     = 8;
        this->updateRange.x = TO_FIXED(80);
        this->updateRange.y = TO_FIXED(80);

        this->field_0x98 = (this->position).x;
        this->field_0x9c = (this->position).y;

        if (((uint8)data & 0xff) == 1) {
            this->drawGroup = '\t';
            this->state.Set(StateMachine_None);
        }
        else if ((char)data == '\0') {
            this->state.Set(&Halfway::State_DeathEggFall);

            FXFade *fade = CREATE_ENTITY(FXFade, NULL, this->position.x, this->position.y);
            fade->state.Set(StateMachine_None);
            fade->timer     = 512;
            fade->speedIn   = 24;
            fade->drawGroup = Zone::sVars->hudDrawGroup;
            fade->active    = ACTIVE_ALWAYS;
        }

        this->animator.SetAnimation(sVars->aniFrames, this->type, true, 0);
    }
}

void Halfway::StageLoad()
{
    sVars->aniFrames.Load("3K_Halfway/Halfway.bin", SCOPE_STAGE);

    sVars->anotherUnknown   = TO_FIXED(8);
    sVars->somethingUnknown = TO_FIXED(1);

    screenInfo->position.x = 8;
    screenInfo->position.y = sVars->screenPan;
}

#if RETRO_INCLUDE_EDITOR
void Halfway::EditorDraw() {}

void Halfway::EditorLoad() {}
#endif

void Halfway::StaticLoad(Static *sVars)
{
    RSDK_INIT_STATIC_VARS(Halfway);
    sVars->classID = 0;
    sVars->active  = ACTIVE_NEVER;
}

void Halfway::Serialize() { RSDK_EDITABLE_VAR(Halfway, VAR_INT8, type); }

void Halfway::State_DeathEggFall()
{
    SET_CURRENT_STATE();

    uint16 uVar1;
    uint8 uVar2;
    int32 iVar3;
    Entity *pEVar4;
    Entity *pvVar5;
    uint32 uVar6;
    uint32 uVar7;
    uint32 loopPoint_00;
    int iVar8;

    ++this->position.y;
    this->position.y += 0x8000;

    iVar8 = this->field_0xa0;
    if (iVar8 == 0) {
        uVar1 = (*RSDKTable->GetSfx)("Stage/FallL.wav");
        uVar7 = 0xff;
        uVar6 = 0;
        uVar2 = (*RSDKTable->PlaySfx)(uVar1, 0, 0xff);
        // (*RSDKTable->PlayStream)((char *)(ulong)uVar2, uVar6, uVar7, startPos, loopPoint);
        uVar1 = (*RSDKTable->GetSfx)("Stage/FallR.wav");
        uVar7 = 0xff;
        uVar6 = 0;
        uVar2 = (*RSDKTable->PlaySfx)(uVar1, 0, 0xff);
        // (*RSDKTable->PlayStream)((char *)(ulong)uVar2, uVar6, uVar7, startPos, loopPoint);
        iVar8 = *(int *)&this->field_0xa0;
    }
    if (iVar8 * -0x49249249 + 0x12492492U < 0x24924925) {
        pEVar4 = CREATE_ENTITY(Explosion, NULL, (this->position).x, (this->position).y);
        iVar3  = Math::Rand(-0x30, 0x31);
        pEVar4->position.x += (short)iVar3;
        iVar3 = Math::Rand(-0x58, 0x1c);
        pEVar4->position.y += (short)iVar3;
        pEVar4->drawGroup    = 9;
        (pEVar4->velocity).y = 0x8000;
        iVar8                = *(int *)&this->field_0xa0;
    }
    this->field_0xa0 = iVar8 + 1;
    iVar3            = (*RSDKTable->GetEntitySlot)(this);
    pvVar5           = (Entity *)(*RSDKTable->GetEntity)(iVar3 + 1);
    if ((this->position).y < pvVar5->position.y) {
        //return pvVar5;
    }
    //this->position.y = pvVar5->position.y;
    this->field_0xa0 = 0;
    loopPoint_00     = 0;
    this->state.Set(&Halfway::State_DeathEggCrash);
    uVar1 = (*RSDKTable->GetSfx)("Stage/LedgeBreak2.wav");
    uVar7 = 0xff;
    uVar6 = 0;
    uVar2 = (*RSDKTable->PlaySfx)(uVar1, 0, 0xff);
    // (*RSDKTable->PlayStream)((char *)(ulong)uVar2, uVar6, uVar7, loopPoint_00, loopPoint);
    uVar1 = (*RSDKTable->GetSfx)("Stage/DrillShort.wav");
    uVar6 = 0xff;
    uVar2 = (*RSDKTable->PlaySfx)(uVar1, 0, 0xff);
    // uVar2 = (*RSDKTable->PlayStream)((char *)(ulong)uVar2, (uint32)RSDKTable->PlayStream, uVar6, loopPoint_00, loopPoint);
    // return (void *)(ulong)uVar2;
}

void Halfway::State_DeathEggCrash()
{
    SET_CURRENT_STATE();

    int32 iVar1;
    uint8 uVar2;
    long uVar3;
    Entity *pEVar4;
    int32 iVar5;
    float volume;

    volume = (float)this->field_0xa0 * -0.0175 + 1.0;
    if (0.0 <= volume) {
        // uVar2 = (*RSDKTable->PlayStream)((char *)0xffffffff, param_5, param_6, param_7, param_8);
        // uVar3 = (ulong)uVar2;
    }
    else {
        // uVar3 = (*RSDKTable->SetChannelAttributes)(0xff, volume, 1.0, param_3);
    }

    iVar5 = *(int *)&this->field_0xa0;

    if ((iVar5 * -0x55555555 + 0x2aaaaaa8U >> 2 | iVar5 * -0x40000000) < 0x15555555) {
        pEVar4 = CREATE_ENTITY(Explosion, NULL, (this->position).x, (this->position).y);
        iVar1  = Math::Rand(-48, 49);
        pEVar4->position.x += iVar1;
        uVar2 = Math::Rand(-72, 1);
        uVar3 = uVar2;
        pEVar4->position.y += (short)uVar2;
        pEVar4->drawGroup = 9;
        iVar5             = this->field_0xa0;
    }

    *(int *)&this->field_0xa0 = iVar5 + 1;

    if (iVar5 < 32) {
        iVar5 = (sVars->somethingUnknown >> 14);
        iVar1 = Math::Rand(-iVar5, iVar5 + 1);
        screenInfo->position.x += iVar1;
        iVar5 = (sVars->somethingUnknown >> 14);
        uVar2 = Math::Rand(-iVar5, iVar5 + 1);
        uVar3 = uVar2;
        screenInfo->position.y += uVar2;
    }

    iVar5 = sVars->somethingUnknown;
    if (iVar5 > 0) {

        if (iVar5 < 0x42E1)
            iVar5 = 0x42E0;

        sVars->somethingUnknown = iVar5 + -0x2E0;
    }

    if (this->field_0xa0 == 128) {
        Stage::SetScene("Regular Stages", "Mushroom Hill Zone 1");
        Zone::StartFadeOut(8, 0);
    }
}

} // namespace GameLogic