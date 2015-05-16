/// @file
/// @brief UE4LikeIBL エフェクトの共通定義ヘッダ。
/// @author ルーチェ

#ifndef UE4LIKEIBL_SHADER_COMMON_H
#define UE4LIKEIBL_SHADER_COMMON_H

/// π値。
#define UE4LIKEIBL_PI 3.14159265359f

/// @brief 環境マップレンダリング面の縦横幅。 2 の累乗値。
///
/// 実際の幅や高さはこの値の 2 倍または 4 倍となる。
#define UE4LIKEIBL_ENVMAP_SIZE 256

/// 環境マップのテクスチャフォーマット。
#define UE4LIKEIBL_ENVMAP_FORMAT "A16B16G16R16F"

/// 環境マップレンダリングにおける Near クリップ値。
#define UE4LIKEIBL_ENVMAP_NEAR 1.0f

/// 環境マップレンダリングにおける Far クリップ値。
#define UE4LIKEIBL_ENVMAP_FAR 65535.0f

/// 環境マップのキューブ各面スケーリング値。
#define UE4LIKEIBL_ENVMAP_CUBE_SCALE 0.25f

// 環境マップのキューブ各面レンダリング位置への並行移動量。
#define UE4LIKEIBL_ENVMAP_CUBE_TRANS_PX float2(+0.25, +0.25)
#define UE4LIKEIBL_ENVMAP_CUBE_TRANS_NX float2(-0.75, +0.25)
#define UE4LIKEIBL_ENVMAP_CUBE_TRANS_PY float2(-0.25, +0.75)
#define UE4LIKEIBL_ENVMAP_CUBE_TRANS_NY float2(-0.25, -0.25)
#define UE4LIKEIBL_ENVMAP_CUBE_TRANS_PZ float2(-0.25, +0.25)
#define UE4LIKEIBL_ENVMAP_CUBE_TRANS_NZ float2(+0.75, +0.25)

/// 環境マップのコピー先テクスチャとそのサンプラを定義するためのマクロ。
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

/// キューブマップから Equirectangular projection マップに変換するためのテクスチャファイルパス。
#define UE4LIKEIBL_ENVMAP_TRANS_TEX_NAME "texture/cube_trans.dds"

/// 環境マップのサンプリングUVを事前計算した Look-up テクスチャファイルパス。
#define UE4LIKEIBL_ENVMAP_LOOKUP_TEX_NAME "texture/lookup_envmap.dds"

/// 環境BRDF項を事前計算した Look-up テクスチャファイルパス。
#define UE4LIKEIBL_BRDF_TEX_NAME "texture/lookup_brdf.dds"

/// Hammersley のY座標を事前計算したテクスチャファイルパス。
#define UE4LIKEIBL_HAMMERSLEY_Y_TEX_NAME "texture/hammersley_y.dds"

/// Hammersley のY座標を事前計算したテクスチャのサンプリング数。(＝横幅)
#define UE4LIKEIBL_HAMMERSLEY_Y_TEX_SAMPLE_COUNT 1024

/// @brief 環境マップの Hammerslay 座標サンプリング数。 16 以上かつ 2 の累乗値。
///
/// 数値が大きいほどいいのだが、 256 以上にするとループ回数制限に引っかかる模様。
#define UE4LIKEIBL_ENVMAP_SAMPLE_COUNT 64

#endif // UE4LIKEIBL_SHADER_COMMON_H
