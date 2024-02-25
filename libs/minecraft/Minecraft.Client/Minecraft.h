#pragma once

#include <string>

class DataFixerUpper;
class MultiPlayerGameMode;
class LevelRenderer;
class LocalPlayer;
class ParticleEngine;
class ProgressRenderer;
class GameRenderer;
class EntityRenderDispatcher;
class ItemInHandRenderer;
class BlockColors;
class ItemColors;
class TextureAtlas;
class ItemRenderer;
class BlockRenderDispatcher;
class Gui;
class Options;
class SoundEngine;
class TexturePackRepository;
class File;
class McRegionLevelStorageSource;
class StatsCounter;
class FrameTimer;
class ClientMasterGameMode;
class GhostController;
class Textures;
class Font;

class Minecraft {
public:
    static Minecraft* GetInstance();
    Minecraft(class Component*, class Canvas*, class MinecraftApplet*, int, int, bool);
    void run();
    inline void init();
    static inline void currentTimeMillis();
    static void start(const std::wstring& str1, const std::wstring& str2);
    static void startAndConnectTo(const std::wstring& arg1, const std::wstring& arg2, const std::wstring& arg3);

    DataFixerUpper* mFixerUpper;
    MultiPlayerGameMode* mMultiPlayerGameMode;
    bool byte_10;
    bool byte_11;
    void* qword_18;
    int dword_20;
    int dword_24;
    int dword_28;
    int dword_2c;
    void* qword_30;
    char byte_38;
    void* qword_40;
    void* qword_48;
    LevelRenderer* mLevelRenderer;
    LocalPlayer* mLocalPlayer;
    void* qword_60;
    void* qword_68;
    void* qword_70;
    char gap_78[64];
    void* qword_b8;
    void* qword_c0;
    void* qword_c8;
    void* qword_d0;
    int dword_d8;
    char gap_DC[52];
    short word_110;
    short word_112;
    char gap_114[20];
    void* qword_128;
    void* qword_130;
    void* qword_138;
    void* qword_140;
    int dword_148;
    void* qword_150;
    void* qword_158;
    char gap_160[16];
    ParticleEngine* mParticleEngine;
    void* qword_178;
    void* qword_180;
    void* qword_188;
    char gap_190[8];
    void* qword_198;
    char byte_1a0;
    bool mHasRenderedTick;
    Textures* mTextures;
    Font* mDefaultFont;
    Font* mAlternateFont;
    void* qword_1c0;
    ProgressRenderer* mProgressRenderer;
    GameRenderer* mGameRenderer;
    EntityRenderDispatcher* mEntityRenderDispatcher;
    ItemInHandRenderer* mItemInHandRenderer;
    BlockColors* mBlockColors;
    ItemColors* mItemColors;
    TextureAtlas* mBlockAtlas;
    ItemRenderer* mItemRenderer;
    BlockRenderDispatcher* mBlockRenderDispatcher;
    void* qword_210;
    void* qword_218;
    int dword_220;
    Gui* mGui;
    char byte_230;
    void* qword_238;
    Options* mOptions;
    void* qword_248;
    SoundEngine* mSoundEngine;
    void* qword_258;
    TexturePackRepository* mTexturePackRepository;
    File* mSaves;
    char gap_270[16];
    McRegionLevelStorageSource* mMcRegionLevelStorageSource;
    StatsCounter* mStatsCounter1;
    StatsCounter* mStatsCounter2;
    StatsCounter* mStatsCounter3;
    StatsCounter* mStatsCounter4;
    void* qword_2a8;
    void* qword_2b0;
    void* qword_2b8;
    int dword_2c0;
    char byte_2c4;
    char gap_2C5[3];
    void* qword_2c8;
    void* qword_2d0;
    void* qword_2d8;
    void* qword_2e0;
    int dword_2e8;
    FrameTimer* mFrameTimer;
    char gap_2F8[8];
    void* qword_300;
    char gap_308[24];
    char byte_320;
    void* qword_328;
    void* qword_330;
    void* qword_338;
    void* qword_340;
    void* qword_348;
    void* qword_350;
    void* qword_358;
    void* qword_360;
    ClientMasterGameMode* mClientMasterGameMode;
    char gap_370[8];
    GhostController* mGhostController;
    void* qword_380;
    void* qword_388;
    void* qword_390;
};