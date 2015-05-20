/// @file
/// @brief UE4っぽい感じのIBLっぽいエフェクト。
/// @author ルーチェ

/// 環境マップテクスチャID。
#define UE4LIKEIBL_ENVMAP_ID 2

#ifdef MIKUMIKUMOVING
#include "shader/UE4LikeIBL_MMM.fxsub"
#else // MIKUMIKUMOVING
#include "shader/UE4LikeIBL_MME.fxsub"
#endif // MIKUMIKUMOVING
