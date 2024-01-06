// ---------------------------------------------------------------------
// RSDK Project: S3KT
// Object Name: ScreenWrap
// Decompiled by: Jd1206
// ---------------------------------------------------------------------

#include "GameObjects.hpp"

using namespace RSDK;

namespace GameLogic
{

RSDK_REGISTER_OBJECT(ScreenWrap);

void ScreenWrap::Update() {}

void ScreenWrap::LateUpdate() {}

void ScreenWrap::StaticUpdate() {}

void ScreenWrap::Draw() {}

void ScreenWrap::Create(void *data)
{
    char cVar1;
    short uVar2;
    int iVar3;
    uint16 layerStuff;
    TileLayer *layer;

    if (!sceneInfo->inEditor) {
        this->active  = ACTIVE_NORMAL;
        this->visible = false;

        layerStuff       = RSDKTable->GetTileLayerID("FG High");
        this->field_0x6c = 0;

        if (this->deactivated)
            this->active = ACTIVE_NEVER;

        cVar1 = this->field_0x80;
        layer = RSDKTable->GetTileLayer(layerStuff);
        if (cVar1 == '\0') {
            layerStuff       = layer->height;
            this->field_0x68 = 0;
            this->someheight = layerStuff << 4;
            this->buffer.x   = this->field_0x68 - this->field_0x78;

            this->state.Set(&ScreenWrap::State_Vertical);

            if (!sVars->ptr)
                sVars->ptr = this;
        }
        else {
            uVar2          = layer->width;
            this->buffer.x = 0;
            iVar3          = 0;
            if (*(short *)&this->field_0x7a != 0) {
                iVar3 = (int)uVar2 / (int)*(short *)&this->field_0x7a;
            }
            *(short *)&this->field_0x76 = (short)(iVar3 << 4);

            this->state.Set(&ScreenWrap::State_Horizontal);

            if (!sVars->ptr)
                sVars->ptr = this;
        }
    }
}

void ScreenWrap::StageLoad() {}

#if RETRO_INCLUDE_EDITOR
void ScreenWrap::EditorDraw() {}

void ScreenWrap::EditorLoad() {}
#endif

void ScreenWrap::StaticLoad(Static *sVars)
{
    RSDK_INIT_STATIC_VARS(ScreenWrap);
}

void ScreenWrap::Serialize()
{
    RSDK_EDITABLE_VAR(ScreenWrap, VAR_UINT8, type);
    RSDK_EDITABLE_VAR(ScreenWrap, VAR_VECTOR2, buffer);
    RSDK_EDITABLE_VAR(ScreenWrap, VAR_BOOL, deactivated);
}

void ScreenWrap::State_Vertical() {}

void ScreenWrap::State_Horizontal()
{
    SET_CURRENT_STATE();

    int iVar1;
    int iVar2;
    short sVar3;
    int iVar5;
    long lVar6;
    int iVar7;
    Player *local_50;
    uint16 plr;
    bool32 local_44;

    if (Zone::sVars->timer > 1) {
        if (!Player::sVars) {
            plr = 0;
        }
        else {
            plr = Player::sVars->classID;

            local_50 = (Player *)0x0;
            local_44 = (*RSDKTable->GetActiveEntities)(plr, (void **)local_50);
            while (local_44 != 0) {
                iVar1 = (this->buffer).x;
                iVar2 = (local_50->position).x;
                iVar5 = iVar1 + 3;
                if (-1 < iVar1) {
                    iVar5 = iVar1;
                }
                sVar3 = *(short *)((long)&(this->buffer).y + 2);
                if (iVar2 < iVar5 >> 2) {
                    iVar1                     = (sVar3 + -1) * iVar1;
                    *(int *)&this->field_0xa4 = iVar1;
                    (local_50->position).x    = (local_50->position).x + iVar1;
                    lVar6                     = *(long *)&local_50->camera;
                    if (lVar6 != 0) {
                        *(int *)(lVar6 + 8) = *(int *)(lVar6 + 8) + *(int *)&this->field_0xa4;
                    }
                    // *(uint *)&this->field_0xa0 = (uint)(ushort)local_50->outerBox;
                    // pOVar4                     = ObjectScreenWrap + 2;
                LAB_71001505e4:
                    this->state.Run(this);
                    this->field_0xa0 = 0xffffffff;
                }
                else if (iVar1 * sVar3 - (iVar5 >> 2) < iVar2) {
                    iVar1                     = (sVar3 + -1) * iVar1;
                    *(int *)&this->field_0xa4 = iVar1;
                    (local_50->position).x    = (local_50->position).x - iVar1;
                    lVar6                     = *(long *)&local_50->camera;
                    if (lVar6 != 0) {
                        *(int *)(lVar6 + 8) = *(int *)(lVar6 + 8) - *(int *)&this->field_0xa4;
                    }
                    // this->field_0xa0 = local_50->outerbox;
                    // pOVar4                     = (ObjectScreepWrap *)&ObjectScreenWrap[2].field_0x18;
                    goto LAB_71001505e4;
                }
                local_44 = (*RSDKTable->GetActiveEntities)(plr, (void **)local_50);
            }
            /*
            if (DAT_710314bb18 == (uint16 *)0x0) {
                plr = 0;
            }
            else {
                plr = *DAT_710314bb18;
            }
            */
            RSDKTable->GetActiveEntities = RSDKTable->GetActiveEntities;
            local_50                     = (Player *)0x0;
            local_44                     = 0;
        LAB_7100150710:
            local_44 = (*RSDKTable->GetActiveEntities)(plr, (void **)local_50);
            if (local_44 != 0) {
                iVar5 = (this->buffer).x;
                iVar2 = (local_50->position).x;
                iVar1 = iVar5 + 3;
                if (-1 < iVar5) {
                    iVar1 = iVar5;
                }
                iVar7 = (int)*(short *)((long)&(this->buffer).y + 2);
                if (iVar1 >> 2 <= iVar2)
                    goto code_r0x007100150748;
                iVar5                     = (iVar7 + -1) * iVar5;
                *(int *)&this->field_0xa4 = iVar5;
                iVar5                     = (local_50->position).x + iVar5;
                goto LAB_7100150704;
            }
            /*
            if (DAT_710334da88 == (uint16 *)0x0) {
                plr = 0;
            }
            else {
                plr = *DAT_710334da88;
            }
            */
            RSDKTable->GetActiveEntities = RSDKTable->GetActiveEntities;
            local_50                     = (Player *)0x0;
            local_44                     = 0;
        LAB_71001507c8:
            local_44 = (*RSDKTable->GetActiveEntities)(plr, (void **)local_50);
            if (local_44 != 0) {
                iVar5 = (this->buffer).x;
                iVar2 = (local_50->position).x;
                iVar1 = iVar5 + 3;
                if (-1 < iVar5) {
                    iVar1 = iVar5;
                }
                iVar7 = (int)*(short *)((long)&(this->buffer).y + 2);
                if (iVar1 >> 2 <= iVar2)
                    goto code_r0x007100150800;
                iVar5                     = (iVar7 + -1) * iVar5;
                *(int *)&this->field_0xa4 = iVar5;
                iVar5                     = (local_50->position).x + iVar5;
                goto LAB_71001507bc;
            }
        }
        return;
    code_r0x007100150748:
        if (iVar5 * iVar7 - (iVar1 >> 2) < iVar2) {
            iVar5                     = (iVar7 + -1) * iVar5;
            *(int *)&this->field_0xa4 = iVar5;
            iVar5                     = (local_50->position).x - iVar5;
        LAB_7100150704:
            (local_50->position).x = iVar5;
        }
        goto LAB_7100150710;
    code_r0x007100150800:
        if (iVar5 * iVar7 - (iVar1 >> 2) < iVar2) {
            iVar5                     = (iVar7 + -1) * iVar5;
            *(int *)&this->field_0xa4 = iVar5;
            iVar5                     = (local_50->position).x - iVar5;
        LAB_71001507bc:
            (local_50->position).x = iVar5;
        }
        goto LAB_71001507c8;
    }
}

} // namespace GameLogic