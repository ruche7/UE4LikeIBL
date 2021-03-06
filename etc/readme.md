MikuMikuMoving 用エフェクト "UE4LikeIBL"
========================================

* Update: 2015-05-17
* Author: ルーチェ

## 概要

* MikuMikuMoving(以降MMM)上でイメージベースドライティング(以降IBL)を実現します。
* 周囲の環境を光源として、モデルが風景に馴染むような描画を行うことができます。
* ゲームエンジンである Unreal Engine 4 のIBLを参考にしています。
    * 正しく参考にできているかというと微妙で、クオリティ的にも遠く及びません。
* かなり重いです。

## 内容物一覧

| ファイル             | 説明                                 |
|:---------------------|:-------------------------------------|
| readme.txt           | 当ファイル                           |
| EnvMapMaker_0.fxm    | 環境マップ作成エフェクト(ID=0)       |
| UE4LikeIBL_0.fxm     | IBLエフェクト(ID=0)                  |
| EnvMapMaker_1.fxm    | 環境マップ作成エフェクト(ID=1)       |
| UE4LikeIBL_1.fxm     | IBLエフェクト(ID=1)                  |
| EnvMapMaker_2.fxm    | 環境マップ作成エフェクト(ID=2)       |
| UE4LikeIBL_2.fxm     | IBLエフェクト(ID=2)                  |
| shader ディレクトリ  | エフェクト実処理コードファイル群     |
| texture ディレクトリ | エフェクト処理用テクスチャファイル群 |

## 使い方

### 環境マップ作成エフェクトの配置

周囲の環境を光源とするためには、まず周囲の環境を撮影しなければなりません。  
それを行うのが **環境マップ作成エフェクト** です。

1. EnvMapMaker_0.fxm をMMMに読み込む。
2. エフェクトの位置を、IBLエフェクトを適用したいモデルの位置に合わせる。
    * 直接移動させてもいいですが、対象モデルのボーンを親にする方が楽です。
    * 遠景のみの撮影なら、多少位置がずれていてもほとんど影響はありません。
3. エフェクトのオフスクリーン割り当てタブを開き、 EnvMapRT をクリックする。
    * MMMマニュアルの「8.6 オフスクリーン割り当て」を参考にしてください。
4. 周囲環境として撮影 **しない** モデルを「描画なし」に設定する。
    * 通常は、対象モデル自体を「描画なし」に設定することになるでしょう。
    * ポリゴン数の多いモデルを「描画なし」に設定することで多少軽くなります。

### IBLエフェクトの適用

環境マップ作成エフェクトの配置を終えたら、
それを利用してIBLを行う **IBLエフェクト** をモデルに適用します。

1. UE4LikeIBL_0.fxm をMMMに読み込む。
2. モデルにエフェクトを適用する。
    * 複数のモデルに適用しても構いません。
3. 必要に応じてエフェクトのパラメータを操作する。
    * 各パラメータの意味は後述します。

### 複数の環境マップを作成＆利用するには

EnvMapMaker_X.fxm は UE4LikeIBL_X.fxm に対応しています。(X = 0, 1, 2)  
これにより複数の環境マップ作成エフェクトを配置して利用することができます。

また、 EnvMapMaker_0.fxm や UE4LikeIBL_0.fxm をメモ帳等で開くとわかりますが、
これらのファイルは冒頭でIDを定義しているだけです。  
EnvMapMaker_0.fxm と UE4LikeIBL_0.fxm をコピーし、IDを共通の値(英字でもOK)に
書き換えることで、いくつでも環境マップを作成できます。

ただし、環境マップの作成は重いため、実用上は 2 つか 3 つが限度でしょう。

## IBLエフェクトのパラメータ

IBLエフェクトはいくつかのパラメータを持っています。  
それらをMMM上から操作することで様々な描画を行えます。

### Metallic

* 金属度合を設定します。
* 数値が大きいほど、反射する色に材質そのものの色が混ざります。
* 通常は、材質が金属ならば 1.0 を、そうでなければ 0.0 を設定してください。

### Roughness

* 表面の粗さを設定します。
* 値が 0.0 に近いほどテカテカで、 1.0 に近いほどザラザラです。
* 値が小さいほど、反射像がくっきりと見えます。

### Specular*

* 材質本来の反射色(スペキュラ)に乗算する値を設定します。
* 通常は初期値 0.0 のままで構いません。

### Specular+

* 材質本来の反射色(スペキュラ)に加算する色を設定します。
* Specular* 設定値による乗算の後に加算されます。
* 通常は初期値である灰色のままで構いません。
* 光沢を減らしたい場合、まず Roughness 設定値をいじってみてください。

Unreal Engine 4 における反射色は99％の場合 0.5 (灰色)でよいそうですが、
一般的なMMDモデルでは当然ながらそれを考慮した値にはなっていません。  
そこで初期設定値では Specular* 設定値を 0.0 として本来の反射色を無効化し、
Specular+ 設定値を灰色として Unreal Engine 4 の既定値にしています。

### Ambient*

* 環境色(アンビエント)に乗算する値を設定します。
* この値を 0.0 に近づけることで、MMM側の環境色の影響を減らすことができます。
* 通常は初期値 1.0 のままとするか、それよりも減らすことになります。
* いきなりこの値をいじらず、まずはライトの色による調整を試してください。

MMMにおける環境色は、ライトの色に比例し、全面一様に加算される色です。  

IBLも環境色のようなものなので、MMM側の環境色の影響が強すぎると困るのですが、
ライトの色を黒に近づけて調整しようとすると、このエフェクトを適用していない
モデルが逆に暗くなりすぎてしまう場合があります。  
そういった場合にこの設定値をいじることになります。

## ライセンスとか

* 当エフェクトに含まれるすべてのコードはMITライセンスとしています。
    * Copyright (C) 2015 ルーチェ  
      Released under the MIT license  
      http://opensource.org/licenses/mit-license.php
* また、 Unreal Engine 4 のシェーダコードを大いに参考にしているため、
  面倒なことにならないよう Unreal Engine 4 のライセンスにも従います。
    * UNREAL ENGINE END USER LICENSE AGREEMENT  
      https://www.unrealengine.com/eula
* 非商用で利用するだけなら特に気にする必要はありません。
  動画作成でもシェーダの勉強でもご自由にどうぞ。
* 商用利用は Unreal Engine 4 のライセンスに従ってください。
    * 公式のFAQ: https://www.unrealengine.com/ja/ja-eula-faq
    * 動画の作成に利用するだけならロイヤリティは発生しないようです。
* エフェクトコードの改変や、自作のエフェクトへのコピペは自由です。
* 改変やコピペしたエフェクトコードを配布する場合、
  MITライセンスおよび Unreal Engine 4 のライセンスに従ってください。
    * 前述の著作権およびMITライセンスの表記を配布物のどこかに含めてください。
    * コピーレフトなライセンス(GPL等)にしないでください。
* 改変せずに再配布する場合も上記と同様ですが、
  なるべく再配布以外の手段で対処してもらえると助かります。

## 参考文献

* Epic Games 社の SIGGRAPH 2013 発表内容を大いに参考にしました。
    * SIGGRAPH 2013 Course: Physically Based Shading in Theory and Practice  
      http://blog.selfshadow.com/publications/s2013-shading-course/
* Holger Dammertz 様の Hammersley サンプリングの技術文書を参考にしました。
    * Hammersley Points on the Hemisphere  
      http://holger.dammertz.org/stuff/notes_HammersleyOnHemisphere.html
* 柄杓様の AutoReflection エフェクトにおける、
  環境マップ作成を別エフェクトにするアイデアを参考にしました。
    * 柄杓座: AutoReflection 0.1beta版 配布します！  
      http://dipper168.blogspot.jp/2015/01/autoreflection-01beta.html

役立つ資料やデータを公開してくれている方々にこの場を借りて御礼申し上げます。

## 更新履歴

* 2015-05-17
    * 初版リリース。

## 連絡先等

* Webサイト  
  http://www.ruche-home.net/
* メール  
  webmaster@ruche-home.net
* Twitter  
  https://twitter.com/ruche7
* GitHubリポジトリ  
  https://github.com/ruche7/UE4LikeIBL
