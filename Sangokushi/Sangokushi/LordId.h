#pragma once
//======================================
//	戦国シミュレーション  城主ID
//======================================
#ifndef __LORD_ID_H
#define __LORD_ID_H

typedef enum {
    LORD_RIKAKU,      // 伊達輝宗
    LORD_RYUBI,    // 上杉謙信
    LORD_ENSHO,    // 武田信玄
    LORD_SOSO,      // 北条氏政
    LORD_RYOFU,  // 徳川家康
    LORD_RYUHYO,       // 織田信長
    LORD_ASHIKAGA,  // 足利義昭
    LORD_MORI,      // 毛利元就
    LORD_CHOSOKABE, // 長宗我部元親
    LORD_SIMAZU,    // 島津義久
    LORD_HASHIBA,   // 羽柴秀吉
    LORD_MAX,       // (種類の数)
    LORD_NONE = -1,
} LordId;

#endif //  __LORD_ID_H