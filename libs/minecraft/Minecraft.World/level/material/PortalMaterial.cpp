#include "Minecraft.World/level/material/PortalMaterial.h"

PortalMaterial::PortalMaterial(MaterialColor const* color) : Material(color) {}

bool PortalMaterial::isSolid() {
    return false;
}

bool PortalMaterial::blocksLight() {
    return false;
}

bool PortalMaterial::blocksMotion() {
    return false;
}