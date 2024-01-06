// ---------------------------------------------------------------------
// RSDK Project: S3KT
// Object Name: GenericTrigger
// Decompiled by: Jd1206
// ---------------------------------------------------------------------

#include "GameObjects.hpp"

using namespace RSDK;

namespace GameLogic
{

RSDK_REGISTER_OBJECT(GenericTrigger);

void GenericTrigger::Update()
{
    if (this->interaction) {
        this->visible = DebugMode::sVars->debugActive;
        this->ran     = false;

        foreach_active(Player, player)
        {
            if ((!player->sidekick || this->allPlayers) && Player::CheckCollisionTouch(player, this, &this->hitbox)) {
                this->ran       = true;
                sVars->playerID = player->playerID;
                sVars->ptr      = this;
                sVars->callbacks[this->triggerID].Run(this);
            }
        }

        if (this->ran) {
            this->activationLimit--;
            if (this->activationLimit <= 0) {
                if (!this->activationLimit)
                    this->Destroy();
            }
        }
    }
}

void GenericTrigger::LateUpdate() {}

void GenericTrigger::StaticUpdate() {}

void GenericTrigger::Draw() {}

void GenericTrigger::Create(void *data)
{
    if (!sceneInfo->inEditor) {
        this->triggerID &= 0xF;

        this->updateRange.x = this->size.x;
        this->updateRange.y = this->size.y;
        this->active        = ACTIVE_BOUNDS;
        this->drawGroup     = Zone::sVars->hudDrawGroup;

        this->hitbox.left   = -(this->size.x >> 16);
        this->hitbox.right  = (this->size.x >> 16);
        this->hitbox.top    = -(this->size.y >> 16);
        this->hitbox.bottom = (this->size.y >> 16);
    }
}

void GenericTrigger::StageLoad() {}

#if RETRO_INCLUDE_EDITOR
void GenericTrigger::EditorDraw() {}

void GenericTrigger::EditorLoad() {}
#endif

void GenericTrigger::StaticLoad(Static *sVars) { RSDK_INIT_STATIC_VARS(GenericTrigger); }

void GenericTrigger::Serialize()
{
    RSDK_EDITABLE_VAR(GenericTrigger, VAR_VECTOR2, size);
    RSDK_EDITABLE_VAR(GenericTrigger, VAR_UINT8, triggerID);
    RSDK_EDITABLE_VAR(GenericTrigger, VAR_INT32, activationLimit);
    RSDK_EDITABLE_VAR(GenericTrigger, VAR_INT32, parameter);
    RSDK_EDITABLE_VAR(GenericTrigger, VAR_BOOL, allPlayers);
}

} // namespace GameLogic