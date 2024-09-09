//======================================
//	戦国シミュレーション  城主
//======================================
#include "Lord.h"

typedef struct {
    const char* mapName;      // マップ上の名前
} LordName;

static LordName lordNames[LORD_MAX] = {
    {"伊達"},    // LORD_DATE        伊達輝宗
    {"上杉"},    // LORD_UESUGI      上杉謙信
    {"武田"},    // LORD_TAKEDA      武田信玄
    {"北条"},    // LORD_HOJO        北条氏政
    {"徳川"},    // LORD_TOKUGAWA    徳川家康
    {"織田"},    // LORD_ODA         織田信長
    {"足利"},    // LORD_ASHIKAGA    足利義昭
    {"毛利"},    // LORD_MORI        毛利元就
    {"長宗我部"},    // LORD_CHOSOKABE   長宗我部元親
    {"島津"},    // LORD_SIMAZU      島津義久
    {"羽柴"},    // LORD_HASHIBA     羽柴秀吉
};

// 城主の名を取得
const char* GetLordFirstName(LordId id)
{
    if (0 <= id && id < LORD_MAX) {
        return lordNames[id].mapName;
    }
    return "??";
}
// 城主のマップ上の名前を取得
const char* GetLordMapName(LordId id)
{
    if (0 <= id && id < LORD_MAX) {
        return lordNames[id].mapName;
    }
    return "??";
}