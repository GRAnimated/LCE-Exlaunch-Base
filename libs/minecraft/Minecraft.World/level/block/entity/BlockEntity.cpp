#include "Minecraft.World/level/block/entity/BlockEntity.h"

BlockEntity::BlockEntity() {
    mLevel = nullptr;
    mIsRemoved = false;
    mPos = BlockPos::zero;
    mData = -1;
    mBlock = nullptr;
}

void BlockEntity::setLevel(Level* level) {
    mLevel = level;
}

bool BlockEntity::hasLevel() {
    if (mLevel)
        return true;
    return false;
}

void BlockEntity::load(CompoundTag* tag) {
    mPos = BlockPos(tag->getInt(L"x"), tag->getInt(L"y"), tag->getInt(L"z"));
}