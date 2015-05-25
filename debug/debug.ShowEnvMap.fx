/// @file
/// @brief EnvMapMaker_0.fx �Ő����������}�b�v�̕\���m�F�p�B
/// @author ���[�`�F
///
/// �|���S���ɓ\��t���Ďg�����Ƃ�z�肵�Ă���B

#include "../shader/common.h"

// ���}�b�v�̃R�s�[��e�N�X�`�����T���v����`
UE4LIKEIBL_ENVMAP_DEF(0);

/// ���[���h�r���[�v���W�F�N�V�����}�g���N�X�B
float4x4 WorldViewProjMatrix : WORLDVIEWPROJECTION;

/// ���_�V�F�[�_�o�͍\���́B
struct VSOutput
{
    float4 pos : POSITION;  ///< �ʒu�B
    float2 tex : TEXCOORD0; ///< �e�N�X�`��UV�B
};

/// ���_�V�F�[�_�������s���B
VSOutput RunVS(float4 pos : POSITION, float2 tex : TEXCOORD0)
{
    VSOutput vsOut = (VSOutput)0;

    vsOut.pos = mul(pos, WorldViewProjMatrix);
    vsOut.tex = tex;

    return vsOut;
}

/// �s�N�Z���V�F�[�_�������s���B
float4 RunPS(float2 tex : TEXCOORD0) : COLOR0
{
    // ���}�b�v�e�N�X�`����\��t���ĕԂ�
    return tex2D(ULI_EnvMapSampler, tex);
}

/// �I�u�W�F�N�g�`��e�N�j�b�N�B
technique ObjectTec < string MMDPass = "object"; >
{
    pass DrawObject
    {
        VertexShader = compile vs_3_0 RunVS();
        PixelShader  = compile ps_3_0 RunPS();
    }
}

// �I�u�W�F�N�g�ȊO�͕`�悵�Ȃ�
technique EdgeTec < string MMDPass = "edge"; > { }
technique ShadowTec < string MMDPass = "shadow"; > { }
technique ZplotTec < string MMDPass = "zplot"; > { }
