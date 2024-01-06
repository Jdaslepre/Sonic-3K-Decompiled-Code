// ---------------------------------------------------------------------
// RSDK Project: S3KT
// Object Name: S3K_BS_SpheresSetup
// Object Author:
// ---------------------------------------------------------------------

#include "S3K_BS_SpheresSetup.hpp"

using namespace RSDK;

namespace GameLogic
{

RSDK_REGISTER_OBJECT(S3K_BS_SpheresSetup);

void S3K_BS_SpheresSetup::Update() {}

void S3K_BS_SpheresSetup::LateUpdate() {}

void S3K_BS_SpheresSetup::StaticUpdate()
{
    uint8 uVar1;
    int32 uVar2;
    uint16 src;
    short sVar3;
    short sVar4;
    uint8 uVar5;

    if (sVars->field12_0x14 == 0) {
        RSDKTable->CreateEntity(sVars->classID, NULL, 0, 0);
    }

    sVars->field12_0x14 = 1;
    uVar1               = sVars->field7_0xa + 1;
    sVars->field7_0xa   = uVar1 & 7;
    uVar5               = uVar1 >> 1 & 3;
    src                 = 0x8a;

    if (uVar5 != 0) {
        src = (short)uVar5 * 0x10 + 0x9a;
    }
    if ((uVar1 & 1) != 0) {
        src = 0x9a;
    }

    RSDKTable->CopyTile(80, src, 16);
    sVars->field5_0x6 -= 1;

    if (sVars->field5_0x6 < 0) {
        sVars->field5_0x6 = 3;
        uVar2             = sVars->field6_0x8 + 1 & 0x1F;
        sVars->field6_0x8 = uVar2;
        RSDKTable->CopyTile(96, uVar2 * 18 + 218, 18);
    }

    sVar4             = sVars->field8_0xc - 1;
    sVars->field8_0xc = sVar4;


    /*
    *   if (sVar4 < 0) {
    pOVar6->field8_0xc = 0;
    (*RSDKTable->SetPaletteEntry)
              ('\0',0xb8,*(uint32 *)(&DAT_7101c443a8 + (long)pOVar6->field9_0xe * 4));
    sVar4 = ObjectS3K_BS_SpheresSetup->field9_0xe + 1;
    ObjectS3K_BS_SpheresSetup->field9_0xe = sVar4;
    (*RSDKTable->SetPaletteEntry)('\0',0xb9,*(uint32 *)(&DAT_7101c443a8 + (long)sVar4 * 4));
    sVar4 = ObjectS3K_BS_SpheresSetup->field9_0xe + 1;
    ObjectS3K_BS_SpheresSetup->field9_0xe = sVar4;
    (*RSDKTable->SetPaletteEntry)('\0',0xba,*(uint32 *)(&DAT_7101c443a8 + (long)sVar4 * 4));
    sVar4 = ObjectS3K_BS_SpheresSetup->field9_0xe + 1;
    ObjectS3K_BS_SpheresSetup->field9_0xe = sVar4;
    (*RSDKTable->SetPaletteEntry)('\0',0xbb,*(uint32 *)(&DAT_7101c443a8 + (long)sVar4 * 4));
    sVar4 = ObjectS3K_BS_SpheresSetup->field9_0xe + 1;
    ObjectS3K_BS_SpheresSetup->field9_0xe = sVar4;
    (*RSDKTable->SetPaletteEntry)('\0',0xbc,*(uint32 *)(&DAT_7101c443a8 + (long)sVar4 * 4));
    sVar4 = ObjectS3K_BS_SpheresSetup->field9_0xe + 1;
    ObjectS3K_BS_SpheresSetup->field9_0xe = sVar4;
    (*RSDKTable->SetPaletteEntry)('\0',0xbd,*(uint32 *)(&DAT_7101c443a8 + (long)sVar4 * 4));
    sVar4 = ObjectS3K_BS_SpheresSetup->field9_0xe + 1;
    ObjectS3K_BS_SpheresSetup->field9_0xe = sVar4;
    (*RSDKTable->SetPaletteEntry)('\0',0xbe,*(uint32 *)(&DAT_7101c443a8 + (long)sVar4 * 4));
    pOVar6 = ObjectS3K_BS_SpheresSetup;
    sVar4 = 0;
    if ((short)(ObjectS3K_BS_SpheresSetup->field9_0xe + 1) < 0x7e) {
      sVar4 = ObjectS3K_BS_SpheresSetup->field9_0xe + 1;
    }
    ObjectS3K_BS_SpheresSetup->field9_0xe = sVar4;
  }
  sVar4 = pOVar6->field10_0x10 + -1;
  pOVar6->field10_0x10 = sVar4;
  if (-1 < sVar4) {
    return;
  }
  sVar4 = pOVar6->field11_0x12;
  pOVar6->field10_0x10 = 3;
  (*RSDKTable->SetPaletteEntry)
            ('\0',0xa1,*(uint32 *)(&DAT_7101c445a0 + (long)(short)(sVar4 + 0x28) * 4));
  (*RSDKTable->SetPaletteEntry)
            ('\0',0xa2,*(uint32 *)(&DAT_7101c445a0 + (long)(short)(sVar4 + 0x29) * 4));
  (*RSDKTable->SetPaletteEntry)
            ('\0',0xa3,*(uint32 *)(&DAT_7101c445a0 + (long)(short)(sVar4 + 0x2a) * 4));
  (*RSDKTable->SetPaletteEntry)
            ('\0',0xa4,*(uint32 *)(&DAT_7101c445a0 + (long)(short)(sVar4 + 0x2b) * 4));
  (*RSDKTable->SetPaletteEntry)
            ('\0',0xa5,*(uint32 *)(&DAT_7101c445a0 + (long)(short)(sVar4 + 0x2c) * 4));
  sVar4 = ObjectS3K_BS_SpheresSetup->field11_0x12;
  (*RSDKTable->SetPaletteEntry)
            ('\0',0xa6,*(uint32 *)(&DAT_7101c445a0 + (long)(short)(sVar4 + 0x14) * 4));
  (*RSDKTable->SetPaletteEntry)
            ('\0',0xa7,*(uint32 *)(&DAT_7101c445a0 + (long)(short)(sVar4 + 0x15) * 4));
  (*RSDKTable->SetPaletteEntry)
            ('\0',0xa8,*(uint32 *)(&DAT_7101c445a0 + (long)(short)(sVar4 + 0x16) * 4));
  (*RSDKTable->SetPaletteEntry)
            ('\0',0xa9,*(uint32 *)(&DAT_7101c445a0 + (long)(short)(sVar4 + 0x17) * 4));
  (*RSDKTable->SetPaletteEntry)
            ('\0',0xaa,*(uint32 *)(&DAT_7101c445a0 + (long)(short)(sVar4 + 0x18) * 4));
  sVar4 = ObjectS3K_BS_SpheresSetup->field11_0x12;
  (*RSDKTable->SetPaletteEntry)('\0',0xab,*(uint32 *)(&DAT_7101c445a0 + (long)sVar4 * 4));
  (*RSDKTable->SetPaletteEntry)
            ('\0',0xac,*(uint32 *)(&DAT_7101c445a0 + (long)(short)(sVar4 + 1) * 4));
  (*RSDKTable->SetPaletteEntry)
            ('\0',0xad,*(uint32 *)(&DAT_7101c445a0 + (long)(short)(sVar4 + 2) * 4));
  (*RSDKTable->SetPaletteEntry)
            ('\0',0xae,*(uint32 *)(&DAT_7101c445a0 + (long)(short)(sVar4 + 3) * 4));
  (*RSDKTable->SetPaletteEntry)
            ('\0',0xaf,*(uint32 *)(&DAT_7101c445a0 + (long)(short)(sVar4 + 4) * 4));
  sVar4 = ObjectS3K_BS_SpheresSetup->field11_0x12 + 10;
  sVar3 = 0;
  if (sVar4 < 500) {
    sVar3 = sVar4;
  }
  ObjectS3K_BS_SpheresSetup->field11_0x12 = sVar3;
  return;
    */
}

void S3K_BS_SpheresSetup::Draw() {}

void S3K_BS_SpheresSetup::Create(void *data)
{
    this->visible = true;
    this->active  = ACTIVE_NORMAL;
    // pEVar2[1].rotation = 0; currently missing the entity struct
    this->drawGroup = Zone::sVars->hudDrawGroup;
    this->state.Set(&S3K_BS_SpheresSetup::State_Normal);
}

void S3K_BS_SpheresSetup::StageLoad() {}

#if RETRO_INCLUDE_EDITOR
void S3K_BS_SpheresSetup::EditorDraw() {}

void S3K_BS_SpheresSetup::EditorLoad() {}
#endif

void S3K_BS_SpheresSetup::StaticLoad(Static *sVars) { RSDK_INIT_STATIC_VARS(S3K_BS_SpheresSetup); }

void S3K_BS_SpheresSetup::Serialize() {}

void S3K_BS_SpheresSetup::State_Normal()
{
    SET_CURRENT_STATE();

    bool32 bVar1;
    int32 iVar2;
    int32 iVar3;
    bool32 bVar4;

    // FUN_7100198808();

    Player *player = RSDK_GET_ENTITY(SLOT_PLAYER1, Player);

    iVar2 = (player->position).y;
    iVar3 = 0; // Zone::sVars->field_0x248;
    bVar1 = (iVar2 + 0x400000 < 0) == ((iVar2 > INT_MAX - 0x400000) && (0x400000 > 0));
    bVar4 = false;

    if (bVar1) {
        bVar4 = iVar2 - iVar3 < 0;
    }

   if ((!bVar1 || iVar2 != iVar3) && bVar4 == (bVar1 && (iVar2 - iVar3) < 0)) {
        player->velocity.x = 0;
        player->velocity.y = 0;
        player->state.Set(StateMachine_None);
        // player->stateGravity.Set(&Player::State_Gravitynull);
        Player::Gravity_False(player);
        this->state.Set(&S3K_BS_SpheresSetup::State_FadeOut);
    }
}


void S3K_BS_SpheresSetup::State_FadeOut()
{
    SET_CURRENT_STATE();

    // lots of code

    Stage::LoadScene();
}



} // namespace GameLogic