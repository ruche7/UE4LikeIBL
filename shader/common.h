/// @file
/// @brief UE4LikeIBL �G�t�F�N�g�̋��ʒ�`�w�b�_�B
/// @author ���[�`�F

#ifndef UE4LIKEIBL_SHADER_COMMON_H
#define UE4LIKEIBL_SHADER_COMMON_H

/// �Βl�B
#define UE4LIKEIBL_PI 3.14159265359f

/// @brief ���}�b�v�����_�����O�ʂ̏c�����B 2 �̗ݏ�l�B
///
/// ���ۂ̕��⍂���͂��̒l�� 2 �{�܂��� 4 �{�ƂȂ�B
#define UE4LIKEIBL_ENVMAP_SIZE 256

/// ���}�b�v�̃e�N�X�`���t�H�[�}�b�g�B
#define UE4LIKEIBL_ENVMAP_FORMAT "A16B16G16R16F"

/// ���}�b�v�����_�����O�ɂ����� Near �N���b�v�l�B
#define UE4LIKEIBL_ENVMAP_NEAR 1.0f

/// ���}�b�v�����_�����O�ɂ����� Far �N���b�v�l�B
#define UE4LIKEIBL_ENVMAP_FAR 65535.0f

/// ���}�b�v�̃L���[�u�e�ʃX�P�[�����O�l�B
#define UE4LIKEIBL_ENVMAP_CUBE_SCALE 0.25f

// ���}�b�v�̃L���[�u�e�ʃ����_�����O�ʒu�ւ̕��s�ړ��ʁB
#define UE4LIKEIBL_ENVMAP_CUBE_TRANS_PX float2(+0.25, +0.25)
#define UE4LIKEIBL_ENVMAP_CUBE_TRANS_NX float2(-0.75, +0.25)
#define UE4LIKEIBL_ENVMAP_CUBE_TRANS_PY float2(-0.25, +0.75)
#define UE4LIKEIBL_ENVMAP_CUBE_TRANS_NY float2(-0.25, -0.25)
#define UE4LIKEIBL_ENVMAP_CUBE_TRANS_PZ float2(-0.25, +0.25)
#define UE4LIKEIBL_ENVMAP_CUBE_TRANS_NZ float2(+0.75, +0.25)

/// ���}�b�v�̃R�s�[��e�N�X�`���Ƃ��̃T���v�����`���邽�߂̃}�N���B
#define UE4LIKEIBL_ENVMAP_DEF \
    shared texture2D ULI_EnvMap : RENDERCOLORTARGET < \
        int Width = (UE4LIKEIBL_ENVMAP_SIZE) * 4; \
        int Height = (UE4LIKEIBL_ENVMAP_SIZE) * 2; \
        string Format = UE4LIKEIBL_ENVMAP_FORMAT; \
        int Miplevels = 1; >; \
    sampler ULI_EnvMapSampler = sampler_state { \
        Texture = <ULI_EnvMap>; \
        MinFilter = LINEAR; \
        MagFilter = LINEAR; \
        AddressU = WRAP; \
        AddressV = CLAMP; }

/// �L���[�u�}�b�v���� Equirectangular projection �}�b�v�ɕϊ����邽�߂̃e�N�X�`���t�@�C���p�X�B
#define UE4LIKEIBL_ENVMAP_TRANS_TEX_NAME "texture/cube_trans.dds"

/// ���}�b�v�̃T���v�����OUV�����O�v�Z���� Look-up �e�N�X�`���t�@�C���p�X�B
#define UE4LIKEIBL_ENVMAP_LOOKUP_TEX_NAME "texture/lookup_envmap.dds"

/// ��BRDF�������O�v�Z���� Look-up �e�N�X�`���t�@�C���p�X�B
#define UE4LIKEIBL_BRDF_TEX_NAME "texture/lookup_brdf.dds"

/// Hammersley ��Y���W�����O�v�Z�����e�N�X�`���t�@�C���p�X�B
#define UE4LIKEIBL_HAMMERSLEY_Y_TEX_NAME "texture/hammersley_y.dds"

/// Hammersley ��Y���W�����O�v�Z�����e�N�X�`���̃T���v�����O���B(������)
#define UE4LIKEIBL_HAMMERSLEY_Y_TEX_SAMPLE_COUNT 1024

/// @brief ���}�b�v�� Hammerslay ���W�T���v�����O���B 16 �ȏォ�� 2 �̗ݏ�l�B
///
/// ���l���傫���قǂ����̂����A 256 �ȏ�ɂ���ƃ��[�v�񐔐����Ɉ���������͗l�B
#define UE4LIKEIBL_ENVMAP_SAMPLE_COUNT 64

#endif // UE4LIKEIBL_SHADER_COMMON_H
