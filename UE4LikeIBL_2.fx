/// @file
/// @brief UE4���ۂ�������IBL���ۂ��G�t�F�N�g�B
/// @author ���[�`�F

/// ���}�b�v�e�N�X�`��ID�B
#define UE4LIKEIBL_ENVMAP_ID 2

#ifdef MIKUMIKUMOVING
#include "shader/UE4LikeIBL_MMM.fxsub"
#else // MIKUMIKUMOVING
#include "shader/UE4LikeIBL_MME.fxsub"
#endif // MIKUMIKUMOVING
