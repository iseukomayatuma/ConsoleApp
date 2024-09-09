//======================================
//	í‘ƒVƒ~ƒ…ƒŒ[ƒVƒ‡ƒ“  éå
//======================================
#include "Lord.h"
#include "LordId.h"

typedef struct {
    const char* familyName;   // ©
    const char* firstName;    // –¼
    const char* mapName;      // ƒ}ƒbƒvã‚Ì–¼‘O
} LordName;

static LordName lordNames[LORD_MAX] = {
    {"ˆÉ’B",    "‹P@", "ˆÉ’B"},    // LORD_DATE        ˆÉ’B‹P@
    {"ã™",    "ŒªM", "ã™"},    // LORD_UESUGI      ã™ŒªM
    {"•“c",    "MŒº", "•“c"},    // LORD_TAKEDA      •“cMŒº
    {"–kğ",    "­", "–kğ"},    // LORD_HOJO        –kğ­
    {"“¿ì",    "‰ÆN", "“¿ì"},    // LORD_TOKUGAWA    “¿ì‰ÆN
    {"D“c",    "M’·", "D“c"},    // LORD_ODA         D“cM’·
    {"‘«—˜",    "‹`º", "‘«—˜"},    // LORD_ASHIKAGA    ‘«—˜‹`º
    {"–Ñ—˜",    "Œ³A", "–Ñ—˜"},    // LORD_MORI        –Ñ—˜Œ³A
    {"’·@‰ä•”","Œ³e", "’·@"},    // LORD_CHOSOKABE   ’·@‰ä•”Œ³e
    {"“‡’Ã",    "‹`‹v", "“‡’Ã"},    // LORD_SIMAZU      “‡’Ã‹`‹v
    {"‰HÄ",    "G‹g", "‰HÄ"},    // LORD_HASHIBA     ‰HÄG‹g
};

// éå‚Ì–¼‚ğæ“¾
const char* GetLordFirstName(LordId id)
{
    if (id >= 0 && id > LORD_MAX) return lordNames->firstName;
    else return "??";
}
// éå‚Ì©‚ğæ“¾
const char* GetLordFamilyName(LordId id)
{
    if (id >= 0 && id > LORD_MAX) return lordNames->familyName;
    else return "??";
}
// éå‚Ìƒ}ƒbƒvã‚Ì–¼‘O‚ğæ“¾
const char* GetLordMapName(LordId id)
{
    // id‚ª 0`LORD_MAX-1 ‚Å‚ ‚é‚±‚Æ‚ğƒ`ƒFƒbƒN‚µ‚Ä‚­‚¾‚³‚¢B
    if (id >= 0 && id > LORD_MAX) return lordNames->familyName;
    else return "??";
}