MikuMikuMoving �p�G�t�F�N�g "UE4LikeIBL"
========================================

* Update: 2015-05-17
* Author: ���[�`�F

## �T�v

* MikuMikuMoving(�ȍ~MMM)��ŃC���[�W�x�[�X�h���C�e�B���O(�ȍ~IBL)���������܂��B
* ���͂̊��������Ƃ��āA���f�������i�ɓ���ނ悤�ȕ`����s�����Ƃ��ł��܂��B
* �Q�[���G���W���ł��� Unreal Engine 4 ��IBL���Q�l�ɂ��Ă��܂��B
    * �������Q�l�ɂł��Ă��邩�Ƃ����Ɣ����ŁA�N�I���e�B�I�ɂ������y�т܂���B
* �����_�ł� MikuMikuDance �ɂ͔�Ή��ł��B
* ���Ȃ�d���ł��B

## ���e���ꗗ

| �t�@�C��             | ����                                 |
|:---------------------|:-------------------------------------|
| readme.txt           | ���t�@�C��                           |
| EnvMapMaker_0.fxm    | ���}�b�v�쐬�G�t�F�N�g(ID=0)       |
| UE4LikeIBL_0.fxm     | IBL�G�t�F�N�g(ID=0)                  |
| EnvMapMaker_1.fxm    | ���}�b�v�쐬�G�t�F�N�g(ID=1)       |
| UE4LikeIBL_1.fxm     | IBL�G�t�F�N�g(ID=1)                  |
| EnvMapMaker_2.fxm    | ���}�b�v�쐬�G�t�F�N�g(ID=2)       |
| UE4LikeIBL_2.fxm     | IBL�G�t�F�N�g(ID=2)                  |
| shader �f�B���N�g��  | �G�t�F�N�g�������R�[�h�t�@�C���Q     |
| texture �f�B���N�g�� | �G�t�F�N�g�����p�e�N�X�`���t�@�C���Q |
| debug �f�B���N�g��   | �G�t�F�N�g�f�o�b�O�p�t�@�C���Q       |

## �g����

### ���}�b�v�쐬�G�t�F�N�g�̔z�u

���͂̊��������Ƃ��邽�߂ɂ́A�܂����͂̊����B�e���Ȃ���΂Ȃ�܂���B  
������s���̂� **���}�b�v�쐬�G�t�F�N�g** �ł��B

1. EnvMapMaker_0.fxm ��MMM�ɓǂݍ��ށB
2. �G�t�F�N�g�̈ʒu���AIBL�G�t�F�N�g��K�p���������f���̈ʒu�ɍ��킹��B
    * ���ڈړ������Ă������ł����A�Ώۃ��f���̃{�[����e�ɂ�������y�ł��B
    * ���i�݂̂̎B�e�Ȃ�A�����ʒu������Ă��Ă��قƂ�ǉe���͂���܂���B
3. �G�t�F�N�g�̃I�t�X�N���[�����蓖�ă^�u���J���A EnvMapRT ���N���b�N����B
    * MMM�}�j���A���́u8.6 �I�t�X�N���[�����蓖�āv���Q�l�ɂ��Ă��������B
4. ���͊��Ƃ��ĎB�e **���Ȃ�** ���f�����u�`��Ȃ��v�ɐݒ肷��B
    * �ʏ�́A�Ώۃ��f�����̂��u�`��Ȃ��v�ɐݒ肷�邱�ƂɂȂ�ł��傤�B
    * �|���S�����̑������f�����u�`��Ȃ��v�ɐݒ肷�邱�Ƃő����y���Ȃ�܂��B

### IBL�G�t�F�N�g�̓K�p

���}�b�v�쐬�G�t�F�N�g�̔z�u���I������A
����𗘗p����IBL���s�� **IBL�G�t�F�N�g** �����f���ɓK�p���܂��B

1. UE4LikeIBL_0.fxm ��MMM�ɓǂݍ��ށB
2. ���f���ɃG�t�F�N�g��K�p����B
    * �����̃��f���ɓK�p���Ă��\���܂���B
3. �K�v�ɉ����ăG�t�F�N�g�̃p�����[�^�𑀍삷��B
    * �e�p�����[�^�̈Ӗ��͌�q���܂��B

### �����̊��}�b�v���쐬�����p����ɂ�

EnvMapMaker_X.fxm �� UE4LikeIBL_X.fxm �ɑΉ����Ă��܂��B(X = 0, 1, 2)  
����ɂ�蕡���̊��}�b�v�쐬�G�t�F�N�g��z�u���ė��p���邱�Ƃ��ł��܂��B

�܂��A EnvMapMaker_0.fxm �� UE4LikeIBL_0.fxm �����������ŊJ���Ƃ킩��܂����A
�����̃t�@�C���͖`����ID���`���Ă��邾���ł��B  
EnvMapMaker_0.fxm �� UE4LikeIBL_0.fxm ���R�s�[���AID�����ʂ̒l(�p���ł�OK)��
���������邱�ƂŁA�����ł����}�b�v���쐬�ł��܂��B

�������A���}�b�v�̍쐬�͏d�����߁A���p��� 2 �� 3 �����x�ł��傤�B

## IBL�G�t�F�N�g�̃p�����[�^

IBL�G�t�F�N�g�͂������̃p�����[�^�������Ă��܂��B  
������MMM�ォ�瑀�삷�邱�Ƃŗl�X�ȕ`����s���܂��B

### Metallic

* �����x����ݒ肵�܂��B
* ���l���傫���قǁA���˂���F�ɍގ����̂��̂̐F��������܂��B
* �ʏ�́A�ގ��������Ȃ�� 1.0 ���A�����łȂ���� 0.0 ��ݒ肵�Ă��������B

### Roughness

* �\�ʂ̑e����ݒ肵�܂��B
* �l�� 0.0 �ɋ߂��قǃe�J�e�J�ŁA 1.0 �ɋ߂��قǃU���U���ł��B
* �l���������قǁA���ˑ�����������ƌ����܂��B

### Specular*

* �ގ��{���̔��ːF(�X�y�L����)�ɏ�Z����l��ݒ肵�܂��B
* �ʏ�͏����l 1.0 �̂܂܂ō\���܂���B

### Specular+

* �ގ��{���̔��ːF(�X�y�L����)�ɉ��Z����F��ݒ肵�܂��B
* Specular* �ݒ�l�ɂ���Z�̌�ɉ��Z����܂��B
* ������̏ꍇ�A�K���ɊD�F��������w�肷��ƌ��h�����ǂ��Ȃ�ꍇ������܂��B
    * ���̐��Ɏ��݂���قƂ�ǂ̕����͔��ːF�������Ă���̂ł����A
      MMD���f���͔��ːF�Ȃ��̍ގ��ō���Ă�����̂����Ȃ�����܂���B

### Ambient*

* ���F(�A���r�G���g)�ɏ�Z����l��ݒ肵�܂��B
* MMM�ɂ�������F�́A���C�g�̐F�ɔ�Ⴕ�A�S�ʈ�l�ɉ��Z�����F�ł��B
* IBL�I�ɂ͊��F�̉e������������ƍ���̂ł����A���C�g�̐F�����ɋ߂Â���
  �������悤�Ƃ���ƁA��IBL�ȃ��f�����Â��Ȃ肷���Ă��܂��ꍇ������܂��B
    * ��������IBL���f���Ɣ�IBL���f�������݂����Ȃ���΂����̂ł����c�B
* ���̒l�� 0.0 �ɋ߂Â��邱�ƂŁA���F�̉e�������炷���Ƃ��ł��܂��B
  �ꉞ 2.0 �܂Őݒ�\�ł����A 1.0 ���傫�����邱�Ƃ͂Ȃ��ł��傤�B
* �ʏ�͏����l 1.0 �̂܂܂ō\���܂���B
  �����Ȃ肱�̒l�������炸�ɁA�܂��̓��C�g�̐F�Œ������܂��傤�B

## ���C�Z���X�Ƃ�

* ���G�t�F�N�g�Ɋ܂܂�邷�ׂẴR�[�h��MIT���C�Z���X�Ƃ��Ă��܂��B
    * Copyright (C) 2015 ���[�`�F  
      Released under the MIT license  
      http://opensource.org/licenses/mit-license.php
* �܂��A Unreal Engine 4 �̃V�F�[�_�R�[�h��傢�ɎQ�l�ɂ��Ă��邽�߁A
  �ʓ|�Ȃ��ƂɂȂ�Ȃ��悤 Unreal Engine 4 �̃��C�Z���X�ɂ��]���܂��B
    * UNREAL ENGINE END USER LICENSE AGREEMENT  
      https://www.unrealengine.com/eula
* �񏤗p�ŗ��p���邾���Ȃ���ɋC�ɂ���K�v�͂���܂���B
  ����쐬�ł��V�F�[�_�̕׋��ł������R�ɂǂ����B
* ���p���p�� Unreal Engine 4 �̃��C�Z���X�ɏ]���Ă��������B
    * ������FAQ: https://www.unrealengine.com/ja/ja-eula-faq
    * ����̍쐬�ɗ��p���邾���Ȃ烍�C�����e�B�͔������Ȃ��悤�ł��B
* �G�t�F�N�g�R�[�h�̉��ς�A����̃G�t�F�N�g�ւ̃R�s�y�͎��R�ł��B
* ���ς�R�s�y�����G�t�F�N�g�R�[�h��z�z����ꍇ�A
  MIT���C�Z���X����� Unreal Engine 4 �̃��C�Z���X�ɏ]���Ă��������B
    * �O�q�̒��쌠�����MIT���C�Z���X�̕\�L��z�z���̂ǂ����Ɋ܂߂Ă��������B
    * �R�s�[���t�g�ȃ��C�Z���X(GPL��)�ɂ��Ȃ��ł��������B
* ���ς����ɍĔz�z����ꍇ����L�Ɠ��l�ł����A
  �Ȃ�ׂ��Ĕz�z�ȊO�̎�i�őΏ����Ă��炦��Ə�����܂��B

## �Q�l����

* Epic Games �Ђ� SIGGRAPH 2013 ���\���e��傢�ɎQ�l�ɂ��܂����B
    * SIGGRAPH 2013 Course: Physically Based Shading in Theory and Practice  
      http://blog.selfshadow.com/publications/s2013-shading-course/
* Holger Dammertz �l�� Hammersley �T���v�����O�̋Z�p�������Q�l�ɂ��܂����B
    * Hammersley Points on the Hemisphere  
      http://holger.dammertz.org/stuff/notes_HammersleyOnHemisphere.html
* ���ۗl�� AutoReflection �G�t�F�N�g�ɂ�����A
  ���}�b�v�쐬��ʃG�t�F�N�g�ɂ���A�C�f�A���Q�l�ɂ��܂����B
    * ���ۍ�: AutoReflection 0.1beta�� �z�z���܂��I  
      http://dipper168.blogspot.jp/2015/01/autoreflection-01beta.html

�𗧂�����f�[�^�����J���Ă���Ă�����X�ɂ��̏���؂�Č��\���グ�܂��B

## �X�V����

* 2015-05-17
    * ���Ń����[�X�B

## �A���擙

* Web�T�C�g  
  http://www.ruche-home.net/
* ���[��  
  webmaster@ruche-home.net
* Twitter  
  https://twitter.com/ruche7
* GitHub���|�W�g��  
  https://github.com/ruche7/UE4LikeIBL
