/// @file
/// @brief EnvMapMaker_0.fx で生成した環境マップの表示確認用。
/// @author ルーチェ
///
/// 板ポリゴンに貼り付けて使うことを想定している。

#include "../shader/common.h"

// 環境マップのコピー先テクスチャ＆サンプラ定義
UE4LIKEIBL_ENVMAP_DEF(0);

/// ワールドビュープロジェクションマトリクス。
float4x4 WorldViewProjMatrix : WORLDVIEWPROJECTION;

/// 頂点シェーダ出力構造体。
struct VSOutput
{
    float4 pos : POSITION;  ///< 位置。
    float2 tex : TEXCOORD0; ///< テクスチャUV。
};

/// 頂点シェーダ処理を行う。
VSOutput RunVS(float4 pos : POSITION, float2 tex : TEXCOORD0)
{
    VSOutput vsOut = (VSOutput)0;

    vsOut.pos = mul(pos, WorldViewProjMatrix);
    vsOut.tex = tex;

    return vsOut;
}

/// ピクセルシェーダ処理を行う。
float4 RunPS(float2 tex : TEXCOORD0) : COLOR0
{
    // 環境マップテクスチャを貼り付けて返す
    return tex2D(ULI_EnvMapSampler, tex);
}

/// オブジェクト描画テクニック。
technique ObjectTec < string MMDPass = "object"; >
{
    pass DrawObject
    {
        VertexShader = compile vs_3_0 RunVS();
        PixelShader  = compile ps_3_0 RunPS();
    }
}

// オブジェクト以外は描画しない
technique EdgeTec < string MMDPass = "edge"; > { }
technique ShadowTec < string MMDPass = "shadow"; > { }
technique ZplotTec < string MMDPass = "zplot"; > { }
