// ---------------------------------------------------------------------
// RSDK Project: S3KT
// Object Name: S3K_SaveSlot
// Object Author:
// ---------------------------------------------------------------------

#include "S3K_SaveSlot.hpp"

using namespace RSDK;

namespace GameLogic
{

RSDK_REGISTER_OBJECT(S3K_SaveSlot);

void S3K_SaveSlot::Update() { this->state.Run(this); }

void S3K_SaveSlot::LateUpdate() {}

void S3K_SaveSlot::StaticUpdate() { sVars->animator.Process(); }

void S3K_SaveSlot::Draw() {}

void S3K_SaveSlot::Create(void *data)
{
    this->active    = ACTIVE_ALWAYS;
    this->visible   = true;
    this->drawGroup = 2;
    this->drawFX    = FX_FLIP;

    this->someVector.x = this->position.x;
    this->someVector.y = this->position.y;
}

void S3K_SaveSlot::StageLoad() {}

#if RETRO_INCLUDE_EDITOR
void S3K_SaveSlot::EditorDraw() {}

void S3K_SaveSlot::EditorLoad() {}
#endif

void S3K_SaveSlot::StaticLoad(Static *sVars) { RSDK_INIT_STATIC_VARS(S3K_SaveSlot); }

void S3K_SaveSlot::Serialize() {}

} // namespace GameLogic