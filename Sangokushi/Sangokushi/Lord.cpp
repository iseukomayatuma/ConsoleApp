//======================================
//	戦国シミュレーション  城主
//======================================
#include "Lord.h"

typedef struct {
    const char* mapName;      // マップ上の名前
} LordName;

static LordName lordNames[LORD_MAX] = {
    {"田中"},    // LORD_DATE        伊達輝宗
    {"神山"},    // LORD_UESUGI      上杉謙信
    {"岡田"},    // LORD_TAKEDA      武田信玄
    {"増永"},    // LORD_HOJO        北条氏政
    {"富田"},    // LORD_TOKUGAWA    徳川家康
    {"小山"},    // LORD_ODA         織田信長
    {"大谷"},    // LORD_ASHIKAGA    足利義昭
    {"久保"},    // LORD_MORI        毛利元就
    {"コマさん"},    // LORD_CHOSOKABE   長宗我部元親
    {"義孝"},    // LORD_SIMAZU      島津義久
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