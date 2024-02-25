#include "Minecraft.World/level/border/WorldBorder.h"
#include "Minecraft.Core/System.h"

// TODO
WorldBorder::WorldBorder(Level* level) {}

__attribute__((noinline)) double WorldBorder::getMinX() {
    double max = getCenterX() + getSize() * -0.5;

    if (max < (double)-mWorldSize)
        max = -mWorldSize;
    return max;
}

__attribute__((noinline)) double WorldBorder::getMaxX() {
    double max = getCenterX() + getSize() * 0.5;

    if (max > (double)mWorldSize)
        max = mWorldSize;
    return max;
}

__attribute__((noinline)) double WorldBorder::getMinZ() {
    double max = getCenterZ() + getSize() * -0.5;

    if (max < (double)-mWorldSize)
        max = -mWorldSize;
    return max;
}

__attribute__((noinline)) double WorldBorder::getMaxZ() {
    double max = getCenterZ() + getSize() * 0.5;

    if (max > (double)mWorldSize)
        max = mWorldSize;
    return max;
}

__attribute__((noinline)) BorderStatus* WorldBorder::getStatus() {
    if (mNextSize < mCurrentSize)
        return gBorderStatusShrinking;

    if (mNextSize > mCurrentSize)
        return gBorderStatusGrowing;

    return gBorderStatusStationary;
}

// TODO: remove early return for match?
__attribute__((noinline)) double WorldBorder::getSize() {
    if (getStatus() != gBorderStatusStationary) {
        double time = (float)(System::processTimeInMilliSecs() - mTime2) / (float)(mTime1 - mTime2);

        if (time < 1.0)
            return mCurrentSize + (time * (mNextSize - mCurrentSize));

        setSize(mNextSize);
    }
    return mCurrentSize;
}

double WorldBorder::getCenterX() {
    return mCenterX;
}

double WorldBorder::getCenterZ() {
    return mCenterZ;
}

std::vector<BorderChangeListener*>* WorldBorder::getListeners() {
    return &mListeners;
}

double WorldBorder::getDamageSafeZone() {
    return mDamageSafeZone;
}

double WorldBorder::getDamagePerBlock() {
    return mDamageAmount;
}
